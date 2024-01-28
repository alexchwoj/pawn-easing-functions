#pragma option -d3

#include <a_samp>
#include <sscanf2>
#include <Pawn.CMD>

#define PEF_DEBUG

#include <pawn-easing-functions>

new 
    PlayerText:g_tdGreenBackground,
    PlayerText:g_tdBlackBackground,
    PlayerText:g_tdTitle,
    PlayerText:g_tdContent
;

main()
{
	print("\npawn-easing-functions\n");
}

public OnPlayerConnect(playerid)
{
    g_tdGreenBackground = CreatePlayerTextDraw(playerid, 642.000000, 119.000000, "_");
    PlayerTextDrawFont(playerid, g_tdGreenBackground, 1);
    PlayerTextDrawLetterSize(playerid, g_tdGreenBackground, 0.587500, 5.450003);
    PlayerTextDrawTextSize(playerid, g_tdGreenBackground, 638.500000, 46.500000);
    PlayerTextDrawSetOutline(playerid, g_tdGreenBackground, 1);
    PlayerTextDrawSetShadow(playerid, g_tdGreenBackground, 0);
    PlayerTextDrawAlignment(playerid, g_tdGreenBackground, 1);
    PlayerTextDrawColor(playerid, g_tdGreenBackground, -1);
    PlayerTextDrawBackgroundColor(playerid, g_tdGreenBackground, 0);
    PlayerTextDrawBoxColor(playerid, g_tdGreenBackground, 1975124479);
    PlayerTextDrawUseBox(playerid, g_tdGreenBackground, 1);
    PlayerTextDrawSetProportional(playerid, g_tdGreenBackground, 1);
    PlayerTextDrawSetSelectable(playerid, g_tdGreenBackground, 0);

    g_tdBlackBackground = CreatePlayerTextDraw(playerid, 642.000000, 119.000000, "_");
    PlayerTextDrawFont(playerid, g_tdBlackBackground, 1);
    PlayerTextDrawLetterSize(playerid, g_tdBlackBackground, 0.587500, 5.450003);
    PlayerTextDrawTextSize(playerid, g_tdBlackBackground, 638.000000, 46.500000);
    PlayerTextDrawSetOutline(playerid, g_tdBlackBackground, 1);
    PlayerTextDrawSetShadow(playerid, g_tdBlackBackground, 0);
    PlayerTextDrawAlignment(playerid, g_tdBlackBackground, 1);
    PlayerTextDrawColor(playerid, g_tdBlackBackground, -1);
    PlayerTextDrawBackgroundColor(playerid, g_tdBlackBackground, 0);
    PlayerTextDrawBoxColor(playerid, g_tdBlackBackground, 589242623);
    PlayerTextDrawUseBox(playerid, g_tdBlackBackground, 1);
    PlayerTextDrawSetProportional(playerid, g_tdBlackBackground, 1);
    PlayerTextDrawSetSelectable(playerid, g_tdBlackBackground, 0);

    g_tdTitle = CreatePlayerTextDraw(playerid, 506.000000, 122.000000, "GEFORCE EXPERIENCE");
    PlayerTextDrawFont(playerid, g_tdTitle, 1);
    PlayerTextDrawLetterSize(playerid, g_tdTitle, 0.300000, 1.450000);
    PlayerTextDrawTextSize(playerid, g_tdTitle, 798.500000, 46.500000);
    PlayerTextDrawSetOutline(playerid, g_tdTitle, 0);
    PlayerTextDrawSetShadow(playerid, g_tdTitle, 0);
    PlayerTextDrawAlignment(playerid, g_tdTitle, 1);
    PlayerTextDrawColor(playerid, g_tdTitle, 0xFFFFFF00);
    PlayerTextDrawBackgroundColor(playerid, g_tdTitle, 255);
    PlayerTextDrawBoxColor(playerid, g_tdTitle, 50);
    PlayerTextDrawUseBox(playerid, g_tdTitle, 0);
    PlayerTextDrawSetProportional(playerid, g_tdTitle, 1);
    PlayerTextDrawSetSelectable(playerid, g_tdTitle, 0);

    g_tdContent = CreatePlayerTextDraw(playerid, 506.000000, 137.000000, "This is a example.");
    PlayerTextDrawFont(playerid, g_tdContent, 1);
    PlayerTextDrawLetterSize(playerid, g_tdContent, 0.229167, 1.250000);
    PlayerTextDrawTextSize(playerid, g_tdContent, 798.500000, 46.500000);
    PlayerTextDrawSetOutline(playerid, g_tdContent, 0);
    PlayerTextDrawSetShadow(playerid, g_tdContent, 0);
    PlayerTextDrawAlignment(playerid, g_tdContent, 1);
    PlayerTextDrawColor(playerid, g_tdContent, 0xFFFFFF00);
    PlayerTextDrawBackgroundColor(playerid, g_tdContent, 255);
    PlayerTextDrawBoxColor(playerid, g_tdContent, 50);
    PlayerTextDrawUseBox(playerid, g_tdContent, 0);
    PlayerTextDrawSetProportional(playerid, g_tdContent, 1);
    PlayerTextDrawSetSelectable(playerid, g_tdContent, 0);

    PlayerTextDrawShow(playerid, g_tdGreenBackground);
    PlayerTextDrawShow(playerid, g_tdBlackBackground);
    PlayerTextDrawShow(playerid, g_tdTitle);
    PlayerTextDrawShow(playerid, g_tdContent);
	return 1;
}

forward AnimationEntryPhases(playerid, phase);
public AnimationEntryPhases(playerid, phase)
{
    switch(phase)
    {
        case 0: PlayerText_MoveTextSize(playerid, g_tdBlackBackground, 498.0, 500, EASE_OUT_QUART);
        case 1:
        {
            PlayerText_PlaceOnTop(playerid, g_tdTitle);
            PlayerText_PlaceOnTop(playerid, g_tdContent);

            PlayerText_InterpolateColor(playerid, g_tdTitle, 0xFFFFFFFF, 250, EASE_OUT_QUAD);
            PlayerText_InterpolateColor(playerid, g_tdContent, 0xFFFFFFFF, 250, EASE_OUT_QUAD);

            SetTimerEx("AnimationExitPhases", 2000, false, "ii", playerid, 0);
        }
    }
}

forward AnimationExitPhases(playerid, phase);
public AnimationExitPhases(playerid, phase)
{
    switch(phase)
    {
        case 0:
        {
            PlayerText_InterpolateColor(playerid, g_tdTitle, 0xFFFFFF00, 250, EASE_OUT_QUAD);
            PlayerText_InterpolateColor(playerid, g_tdContent, 0xFFFFFF00, 250, EASE_OUT_QUAD);

            SetTimerEx("AnimationExitPhases", 300, false, "ii", playerid, 1);
            SetTimerEx("AnimationExitPhases", 500, false, "ii", playerid, 2);
        }
        case 1: PlayerText_MoveTextSize(playerid, g_tdBlackBackground, 638.0, 500, EASE_OUT_QUART);
        case 2: PlayerText_MoveTextSize(playerid, g_tdGreenBackground, 638.0, 500, EASE_OUT_QUART);
    }
}

cmd:geforce(playerid, const params[])
{
    PlayerText_MoveTextSize(playerid, g_tdGreenBackground, 495.0, 500, EASE_OUT_QUINT);
    SetTimerEx("AnimationEntryPhases", 300, false, "ii", playerid, 0);
    SetTimerEx("AnimationEntryPhases", 1000, false, "ii", playerid, 1);
    return 1;
}

cmd:color(playerid, const params[])
{
    PlayerText_PlaceOnTop(playerid, g_tdTitle);
    PlayerText_PlaceOnTop(playerid, g_tdContent);

    PlayerText_InterpolateColor(playerid, g_tdTitle, 0xFFFFFFFF, 250, EASE_OUT_QUAD);
    PlayerText_InterpolateColor(playerid, g_tdContent, 0xFFFFFFFF, 250, EASE_OUT_QUAD);
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