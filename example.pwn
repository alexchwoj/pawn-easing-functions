#pragma option -d3

#include <a_samp>
#include <sscanf2>
#include <Pawn.CMD>
#include <pawn-easing-functions>

new PlayerText:g_tdPlayerTextdraw;
new g_iAnimator = -1;

main()
{
	print("\npawn-easing-functions\n");
}

public OnPlayerConnect(playerid)
{
    g_tdPlayerTextdraw = CreatePlayerTextDraw(playerid, -90.0, 150.0, "pawn-easing-functions");
	PlayerTextDrawFont(playerid, g_tdPlayerTextdraw, 1);
	PlayerTextDrawLetterSize(playerid, g_tdPlayerTextdraw, 0.237499, 1.299999);
	PlayerTextDrawTextSize(playerid, g_tdPlayerTextdraw, 166.000000, 166.000000);
	PlayerTextDrawSetOutline(playerid, g_tdPlayerTextdraw, 0);
	PlayerTextDrawSetShadow(playerid, g_tdPlayerTextdraw, 0);
	PlayerTextDrawAlignment(playerid, g_tdPlayerTextdraw, 2);
	PlayerTextDrawColor(playerid, g_tdPlayerTextdraw, -1);
	PlayerTextDrawBackgroundColor(playerid, g_tdPlayerTextdraw, 471604479);
	PlayerTextDrawBoxColor(playerid, g_tdPlayerTextdraw, 471604479);
	PlayerTextDrawUseBox(playerid, g_tdPlayerTextdraw, 1);
	PlayerTextDrawSetProportional(playerid, g_tdPlayerTextdraw, 1);
	return 1;
}

cmd:move(playerid, const params[])
{
    new Float:x, Float:y;
    if (sscanf(params, "ff", x, y))
    {
        return SendClientMessage(playerid, 0xDADADAFF, "Usage: /move <x> <y>");
    }

    if (g_iAnimator != -1)
        PlayerText_StopMove(g_iAnimator);

    g_iAnimator = PlayerText_MoveTo(playerid, g_tdPlayerTextdraw, x, y, 1000, EASE_OUT_CUBIC);
    return 1;
}

cmd:movex(playerid, const params[])
{
    new Float:x;
    if (sscanf(params, "f", x))
    {
        return SendClientMessage(playerid, 0xDADADAFF, "Usage: /movex <x>");
    }

    if (g_iAnimator != -1)
        PlayerText_StopMove(g_iAnimator);

    g_iAnimator = PlayerText_MoveToX(playerid, g_tdPlayerTextdraw, x, 1000, EASE_OUT_CUBIC);
    return 1;
}

cmd:movey(playerid, const params[])
{
    new Float:y;
    if (sscanf(params, "f", y))
    {
        return SendClientMessage(playerid, 0xDADADAFF, "Usage: /movey <y>");
    }

    if (g_iAnimator != -1)
        PlayerText_StopMove(g_iAnimator);

    g_iAnimator = PlayerText_MoveToY(playerid, g_tdPlayerTextdraw, y, 1000, EASE_OUT_CUBIC);
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    SetSpawnInfo(playerid, 0, 0, 1958.33, 1343.12, 15.36, 269.15, 26, 36, 28, 150, 0, 0);
    SpawnPlayer(playerid);
	return 1;
}

public OnGameModeInit()
{
	AddPlayerClass(0, 0.0, 0.0, 1000.0, 0.0, 0, 0, 0, 0, -1, -1);
	return 1;
}