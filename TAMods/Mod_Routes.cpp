#include "Mods.h"
#include <time.h>

unsigned const ROUTE_SAVES_MAX = 1200;
unsigned const ROUTE_SAVES_INTERVAL = 100; // Save location every 100ms. 0.1 seconds * 1200 dots = 120 seconds record

struct position
{
	float time;
	FVector loc;
	unsigned int health;
	unsigned int eta;
};
std::vector<position> route;

bool recording;
std::string className;
//std::string mapName;
int classHealth;

void routeRec()
{
	if (recording)
		routeStopRec();
	else
		routeStartRec();
}

void routeStartRec()
{
	APawn *pawn = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->Pawn;
	if (!pawn)
		return;

	route.clear();
	route.insert(route.begin(), { pawn->WorldInfo->TimeSeconds, pawn->Location, pawn->Health });
	classHealth = pawn->HealthMax;
	className = ((ATrPawn *)pawn)->GetFamilyInfo()->GetStringName();
	recording = true;
}

void routeStopRec()
{
	recording = false;
}

void routeReset()
{
	recording = false;
	route.clear();
}

void routePawnTick(ATrPawn* pawn)
{
	if (recording)
	{
		float time = pawn->WorldInfo->TimeSeconds;
		if (time - route.at(0).time >= ROUTE_SAVES_INTERVAL / 1000.0f)
		{
			route.insert(route.begin(), { time, pawn->Location, pawn->Health });

			if (route.size() > ROUTE_SAVES_MAX)
				route.resize(ROUTE_SAVES_MAX);
		}
	}
}

void routeFlagGrab(float grabtime)
{
	if (!recording)
		return;

	//recording = false;
	
	int eta = 5;

	for (size_t i = 0; i < route.size(); i++)
	{
		if (grabtime - route.at(i).time >= eta)
		{
			route.at(i).eta = eta;
			eta += 5;
		}
		else if (route.at(i).eta)
			route.at(i).eta = NULL;
	}
	// Exact ETA for the first point
	route.back().eta = int(round(grabtime - route.back().time));
}

void UpdateRouteOverheadNumbers(ATrHUD *that)
{
	if (g_config.routeDrawInterval <= 0)
		return;

	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	for (size_t i = 0; i < route.size(); i++)
	{
		position &curr = route.at(i);

		// Only draw a dot every x milliseonds but always draw ones with ETA or damage taken
		if (!curr.eta
			&& i + 1 < route.size()
			&& curr.health >= route.at(i + 1).health
			&& i % int(g_config.routeDrawInterval < ROUTE_SAVES_INTERVAL ? 1 : g_config.routeDrawInterval / ROUTE_SAVES_INTERVAL) != 0)
		{
			continue;
		}

		if (that->TrPlayerOwner)
		{
			overhead_number_location.X = curr.loc.X;
			overhead_number_location.Y = curr.loc.Y;
			overhead_number_location.Z = curr.loc.Z + 30.0f;
			that->TrPlayerOwner->eventGetPlayerViewPoint(&view_location, &view_rotation);

			// Only draw if visible
			if (Geom::dot(Geom::rotationToVector(view_rotation), Geom::normal(Geom::sub(overhead_number_location, view_location))) >= 0.0f)
			{
				overhead_number_location = that->Canvas->Project(overhead_number_location);

				wchar_t buff[1];
				wsprintf(buff, L"%s", ".");
				
				unsigned char c = 255 * curr.health / classHealth;
				FColor col = { c, c, 255, 140 };

				if (i + 1 < route.size())
				{
					if (curr.health < route.at(i + 1).health) // damage taken (self impulse)
						col = { 255, 0, 0, 200 };
					else if (curr.health > route.at(i + 1).health) // gaining health (regen)
						col = { 0, 255, 255 - c, 140 };
				}

				if (i + 1 == route.size()) // route start
					that->DrawColoredMarkerText(FString(L"Start"), { 255, 202, 0, 160 }, overhead_number_location, that->Canvas, 1.0f, 1.0f);
				else
					that->DrawColoredMarkerText(buff, col, overhead_number_location, that->Canvas, 0.6f, 0.6f);

				if (curr.eta)
				{
					overhead_number_location.X = curr.loc.X;
					overhead_number_location.Y = curr.loc.Y;
					overhead_number_location.Z = curr.loc.Z + 280.0f;

					overhead_number_location = that->Canvas->Project(overhead_number_location);

					wchar_t buff[3];
					wsprintf(buff, L"%d", curr.eta);

					FColor col = { 0, 255, 255, 200 };

					that->DrawColoredMarkerText(buff, col, overhead_number_location, that->Canvas, 0.9f, 0.9f);
				}
			}
		}
	}
}