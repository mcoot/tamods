#include "Mods.h"

unsigned const ROUTE_MAX_POINTS = 960;
unsigned const ROUTE_POINTS_PER_SEC = 8; // 960 / 8 = minimum of 120 seconds record
unsigned const ROUTE_MIN_DISTANCE_TO_PREV = 300;

struct position
{
	float time;
	FVector loc;
	unsigned int health;
	unsigned int eta;
};
std::vector<position> route;

bool recording;
int classHealth;

void routeStartRec()
{
	APawn *pawn = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->Pawn;
	if (!pawn)
		return;

	route.clear();
	route.insert(route.begin(), { pawn->WorldInfo->RealTimeSeconds, pawn->Location, pawn->Health });
	classHealth = pawn->HealthMax;
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
		float time = pawn->WorldInfo->RealTimeSeconds;
		if (time - route.at(0).time > 1.0f / ROUTE_POINTS_PER_SEC)
		{
			// Skip if too close to previously saved location
			if (Geom::distance3D(pawn->Location, route.at(0).loc) < ROUTE_MIN_DISTANCE_TO_PREV)
				return;

			route.insert(route.begin(), { time, pawn->Location, pawn->Health });

			if (route.size() > ROUTE_MAX_POINTS)
				route.resize(ROUTE_MAX_POINTS);
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
	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	for (size_t i = 0; i < route.size(); i++)
	{
		position &curr = route.at(i);

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