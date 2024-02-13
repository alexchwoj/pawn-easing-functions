#pragma option -d3

#include <a_samp>
#include <sscanf2>
#include <Pawn.CMD>
#include <pawn-easing-functions>

new g_iAnimator = -1;

new
    PlayerText:g_ptdLoadBarBG,
    PlayerText:g_ptdLoadBar
;

main()
{
	print("\npawn-easing-functions\n");
}

public OnPlayerConnect(playerid)
{
    g_ptdLoadBarBG = CreatePlayerTextDraw(playerid, 283.999969, 411.925964, "box");
    PlayerTextDrawLetterSize(playerid, g_ptdLoadBarBG, 0.0, 1.066666);
    PlayerTextDrawTextSize(playerid, g_ptdLoadBarBG, 376.000000, 0.0);
    PlayerTextDrawAlignment(playerid, g_ptdLoadBarBG, 1);
    PlayerTextDrawColor(playerid, g_ptdLoadBarBG, -1);
    PlayerTextDrawUseBox(playerid, g_ptdLoadBarBG, 1);
    PlayerTextDrawBoxColor(playerid, g_ptdLoadBarBG, 404431103);
    PlayerTextDrawSetShadow(playerid, g_ptdLoadBarBG, 0);
    PlayerTextDrawBackgroundColor(playerid, g_ptdLoadBarBG, 255);
    PlayerTextDrawFont(playerid, g_ptdLoadBarBG, 1);
    PlayerTextDrawSetProportional(playerid, g_ptdLoadBarBG, 1);

    g_ptdLoadBar = CreatePlayerTextDraw(playerid, 284.700012, 412.726013, "box");
    PlayerTextDrawLetterSize(playerid, g_ptdLoadBar, 0.0, 0.876665);
    PlayerTextDrawTextSize(playerid, g_ptdLoadBar, 282.13, 0.0);
    PlayerTextDrawAlignment(playerid, g_ptdLoadBar, 1);
    PlayerTextDrawColor(playerid, g_ptdLoadBar, -1);
    PlayerTextDrawUseBox(playerid, g_ptdLoadBar, 1);
    PlayerTextDrawBoxColor(playerid, g_ptdLoadBar, -239180033);
    PlayerTextDrawSetShadow(playerid, g_ptdLoadBar, 0);
    PlayerTextDrawBackgroundColor(playerid, g_ptdLoadBar, 255);
    PlayerTextDrawFont(playerid, g_ptdLoadBar, 1);
    PlayerTextDrawSetProportional(playerid, g_ptdLoadBar, 1);
	return 1;
}

cmd:progressbar(playerid, const params[])
{
    if (g_iAnimator != -1)
        PlayerText_StopMove(g_iAnimator);
    
    PlayerTextDrawShow(playerid, g_ptdLoadBarBG);

    g_iAnimator = PlayerText_InterpolateTextSize(playerid, g_ptdLoadBar, 282.13, 375.38, 1000, EASE_OUT_CUBIC);
    return 1;
}

public Animator_OnFinish(playerid, animator, type)
{
    if (animator == g_iAnimator && type == ANIMATOR_TEXT_SIZE)
    {
        PlayerTextDrawHide(playerid, g_ptdLoadBarBG);
        PlayerTextDrawHide(playerid, g_ptdLoadBar);
    }
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