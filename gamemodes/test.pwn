#pragma option -d3

#include <a_samp>

main()
{
	print("pawn-easing-functions");
}

public OnPlayerConnect(playerid)
{
	GameTextForPlayer(playerid,"~w~pawn-easing-functions", 5000, 5);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp(cmdtext, "/test1", true) == 0)
	{
    	return 1;
	}
	return 0;
}

public OnPlayerSpawn(playerid)
{
	SetPlayerInterior(playerid, 0);
	TogglePlayerControllable(playerid, false);
	SetCameraBehindPlayer(playerid);
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerInterior(playerid, 14);
	SetPlayerPos(playerid,258.4893, -41.4008, 1002.0234);
	SetPlayerFacingAngle(playerid, 270.0);
	SetPlayerCameraPos(playerid, 256.0815, -43.0475, 1004.0234);
	SetPlayerCameraLookAt(playerid, 258.4893, -41.4008, 1002.0234);
	return 1;
}

public OnGameModeInit()
{
	ShowPlayerMarkers(1);
	ShowNameTags(1);
	AddPlayerClass(0, 0.0, 0.0, 1000.0, 0.0, 0, 0, 0, 0, -1, -1);
	return 1;
}