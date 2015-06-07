#include "Mods.h"

int _r = 0;
int _g = 0;
int _b = 0;
int _a = 255;

//_chatCol[ChatID][R,G,B,A] Yourchat = 0, Enemy = 1, Team = 2
//int _chatCol[3][4] = { { 255, 0, 255, 255 }, { 0, 255, 0, 255 }, { 0, 255, 255, 255 } };

bool TrHUD_eventPostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	
	ATrHUD *that = (ATrHUD *)dwCallingObject;

	//TODO Create config loading

	/*
	//Friend chat, enemy chat, team chat
	FColor *FCColor = new FColor();
	FColor *ECColor = new FColor();
	FColor *TCColor = new FColor();

	FCColor->R = _chatCol[0][0];
	FCColor->G = _chatCol[0][1];
	FCColor->B = _chatCol[0][2];
	FCColor->A = _chatCol[0][3];

	ECColor->R = _chatCol[1][0];
	ECColor->G = _chatCol[1][1];
	ECColor->B = _chatCol[1][2];
	ECColor->A = _chatCol[1][3];

	TCColor->R = _chatCol[2][0];
	TCColor->G = _chatCol[2][1];
	TCColor->B = _chatCol[2][2];
	TCColor->A = _chatCol[2][3];

	that->FriendlyChatColor = *FCColor;
	that->EnemyChatColor = *ECColor;
	that->TeamChatColor = *TCColor;
	
	*/

	// Create an FColor, set Alpha from config
	FColor *a = new FColor();
	_a = g_config.damNumA;
	a->A = _a;

	if (g_config.showRainbow == true){
		//TODO switch statement should be replaced with a while statement
		switch (g_config.rainbowBulletInt) {
		case 0:
			_r = 255;
			_g = 0;
			_b = 0;
			break;
		case 1:
			_g = 125;
			break;
		case 2:
			_g = 255;
			break;
		case 3:
			_r = 125;
			break;
		case 4:
			_r = 0;
			break;
		case 5:
			_b = 125;
			break;
		case 6:
			_b = 255;
			break;
		case 7:
			_g = 125;
			break;
		case 8:
			_g = 0;
			break;
		case 9:
			_r = 125;
			break;
		case 10:
			_r = 255;
			break;
		case 11:
			_b = 125;
			break;
		case 12:
			_b = 0;
			break;
		}

		//Apply settings
		a->R = _r;
		a->G = _g;
		a->B = _b;
		
		that->m_OverheadNumberColorMax = *a;
		that->m_OverheadNumberColorMin = *a;
	}
	else
	{
		//grab config colors
		_r = g_config.damNumR;
		_g = g_config.damNumG;
		_b = g_config.damNumB;

		a->R = _r;
		a->G = _g;
		a->B = _b;

		that->m_OverheadNumberColorMax = *a;
		that->m_OverheadNumberColorMin = *a;
	}
	

	return(false);

}
