#pragma option -d3

#include <a_samp>
#include <YSF>

new PlayerText:player_textdraw;

stock Float:lerp(Float:start_value, Float:end_value, Float:pct)
{
    return (start_value + (end_value - start_value) * pct);
}

stock Float:easeInOutCubic(Float:t)
{
    return t < 0.5 ? 4 * t * t * t : 1 + (--t) * (2 * (--t)) * (2 * t);
}

stock Float:easeOutBack(Float:t)
{
    return 1 + (--t) * t * (2.70158 * t + 1.70158);
}

new frame_count;
new frame_timer;

forward MoveToLeft(playerid, Float:start_x, Float:start_y, Float:end_x, Float:max, count);
public MoveToLeft(playerid, Float:start_x, Float:start_y, Float:end_x, Float:max, count)
{
	frame_count -= count;

	new Float:pct = floatdiv(frame_count, max);
  	new Float:pos_x = lerp(0.0, end_x, easeInOutCubic(pct));

	PlayerTextDrawSetPos(playerid, player_textdraw, start_x - pos_x, start_y);
	PlayerTextDrawShow(playerid, player_textdraw);

	if (pct <= -1.0)
	{
		frame_count = 0;
		KillTimer(frame_timer);
	}

	return 1;
}

forward WaitToLeft(playerid, Float:start_x, Float:start_y, Float:end_x, Float:max, count);
public WaitToLeft(playerid, Float:start_x, Float:start_y, Float:end_x, Float:max, count)
{
	frame_timer = SetTimerEx("MoveToLeft", 10, true, "dffffd", playerid, 120.0, 150.0, -90.0, max, count);
	return 1;
}

forward MoveToRight(playerid, Float:start_x, Float:start_y, Float:end_x, Float:max, count);
public MoveToRight(playerid, Float:start_x, Float:start_y, Float:end_x, Float:max, count)
{
	frame_count += count;

	new Float:pct = floatdiv(frame_count, max);
  	new Float:pos_x = lerp(0.0, end_x, easeOutBack(pct));

	PlayerTextDrawSetPos(playerid, player_textdraw, start_x + pos_x, start_y);
	PlayerTextDrawShow(playerid, player_textdraw);

	if (pct >= 1.0)
	{
		frame_count = 0;
		KillTimer(frame_timer);
		SetTimerEx("WaitToLeft", 1000, false, "dffffd", playerid, 120.0, 150.0, -90.0, max, count);
	}

	return 1;
}

main()
{
	print("pawn-easing-functions");
}

public OnPlayerConnect(playerid)
{
	player_textdraw = CreatePlayerTextDraw(playerid, -90.0, 150.0, "diego comeme los guebos jaja");
	PlayerTextDrawFont(playerid, player_textdraw, 1);
	PlayerTextDrawLetterSize(playerid, player_textdraw, 0.237499, 1.299999);
	PlayerTextDrawTextSize(playerid, player_textdraw, 166.000000, 166.000000);
	PlayerTextDrawSetOutline(playerid, player_textdraw, 0);
	PlayerTextDrawSetShadow(playerid, player_textdraw, 0);
	PlayerTextDrawAlignment(playerid, player_textdraw, 2);
	PlayerTextDrawColor(playerid, player_textdraw, -1);
	PlayerTextDrawBackgroundColor(playerid, player_textdraw, 471604479);
	PlayerTextDrawBoxColor(playerid, player_textdraw, 471604479);
	PlayerTextDrawUseBox(playerid, player_textdraw, 1);
	PlayerTextDrawSetProportional(playerid, player_textdraw, 1);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp(cmdtext, "/pos", true) == 0)
	{
		PlayerTextDrawSetPos(playerid, player_textdraw, -90.0, 150.0);
		PlayerTextDrawShow(playerid, player_textdraw);
    	return 1;
	}

	if (strcmp(cmdtext, "/test", true) == 0)
	{
		frame_count = 0;
		KillTimer(frame_timer);

		PlayerTextDrawSetPos(playerid, player_textdraw, 100.0, 150.0);

		frame_timer = SetTimerEx("MoveToRight", 10, true, "dffffd", playerid, -90.0, 150.0, 210.0, 300.0, 5);
    	return 1;
	}

	if (strcmp(cmdtext, "/stop", true) == 0)
	{
		KillTimer(frame_timer);
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