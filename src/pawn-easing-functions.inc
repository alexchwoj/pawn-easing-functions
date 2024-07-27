/*

	pawn-easing-functions by alexchwoj
	
	Github: https://github.com/alexchwoj

*/

#if defined _pawn_easing_functions_included
	#endinput
#endif
#define _pawn_easing_functions_included

#if !defined EASING_ANIMATION_FRAMERATE
	#define EASING_ANIMATION_FRAMERATE 30
#endif

#define MAX_ANIMATORS 1024
#define ANIMATION_UPDATE_RATE (1000 / EASING_ANIMATION_FRAMERATE)

#include <a_samp>

#if !defined _YSF_included
	#include <YSF>
#endif

#if defined _INC_open_mp
	#if !defined PlayerTextDrawGetBackgroundCol
		#define PlayerTextDrawGetBackgroundCol PlayerTextDrawGetBackgroundColour
	#endif
#else
	#if !defined PlayerTextDrawColour
		#define PlayerTextDrawColour PlayerTextDrawColor
	#endif

	#if !defined PlayerTextDrawBoxColour
		#define PlayerTextDrawBoxColour PlayerTextDrawBoxColor
	#endif

	#if !defined PlayerTextDrawBackgroundColour
		#define PlayerTextDrawBackgroundColour PlayerTextDrawBackgroundColor
	#endif

	#if !defined PlayerTextDrawGetColour
		#define PlayerTextDrawGetColour PlayerTextDrawGetColor
	#endif

	#if !defined PlayerTextDrawGetBoxColour
		#define PlayerTextDrawGetBoxColour PlayerTextDrawGetBoxColor
	#endif
#endif

#define PlayerText_InterpolateColour PlayerText_InterpolateColor
#define PlayerText_InterpolateBoxColour PlayerText_InterpolateBoxColor
#define PlayerText_InterpolateBGColour PlayerText_InterpolateBGColor

new g_iLargestAnimatorId = -1;

#define EASING_FUNC_PI 3.14159265

#define EASE_IN_SINE __addressof(easeInSine)
#define EASE_OUT_SINE __addressof(easeOutSine)
#define EASE_IN_OUT_SINE __addressof(easeInOutSine)
#define EASE_IN_QUAD __addressof(easeInQuad)
#define EASE_OUT_QUAD __addressof(easeOutQuad)
#define EASE_IN_OUT_QUAD __addressof(easeInOutQuad)
#define EASE_IN_CUBIC __addressof(easeInCubic)
#define EASE_OUT_CUBIC __addressof(easeOutCubic)
#define EASE_IN_OUT_CUBIC __addressof(easeInOutCubic)
#define EASE_IN_QUART __addressof(easeInQuart)
#define EASE_OUT_QUART __addressof(easeOutQuart)
#define EASE_IN_OUT_QUART __addressof(easeInOutQuart)
#define EASE_IN_QUINT __addressof(easeInQuint)
#define EASE_OUT_QUINT __addressof(easeOutQuint)
#define EASE_IN_OUT_QUINT __addressof(easeInOutQuint)
#define EASE_IN_EXPO __addressof(easeInExpo)
#define EASE_OUT_EXPO __addressof(easeOutExpo)
#define EASE_IN_OUT_EXPO __addressof(easeInOutExpo)
#define EASE_IN_CIRC __addressof(easeInCirc)
#define EASE_OUT_CIRC __addressof(easeOutCirc)
#define EASE_IN_OUT_CIRC __addressof(easeInOutCirc)
#define EASE_IN_BACK __addressof(easeInBack)
#define EASE_OUT_BACK __addressof(easeOutBack)
#define EASE_IN_OUT_BACK __addressof(easeInOutBack)
#define EASE_IN_ELASTIC __addressof(easeInElastic)
#define EASE_OUT_ELASTIC __addressof(easeOutElastic)
#define EASE_IN_OUT_ELASTIC __addressof(easeInOutElastic)
#define EASE_IN_BOUNCE __addressof(easeInBounce)
#define EASE_OUT_BOUNCE __addressof(easeOutBounce)
#define EASE_IN_OUT_BOUNCE __addressof(easeInOutBounce)
#define EASE_NONE __addressof(easeNone)

enum eAnimatorTypes 
{
	ANIMATOR_POSITION,
	ANIMATOR_LETTER_SIZE,
	ANIMATOR_TEXT_SIZE,
	ANIMATOR_FULL_SIZE,
	ANIMATOR_COLOR,
	ANIMATOR_BOX_COLOR,
	ANIMATOR_BACKGROUND_COLOR
}

enum _:eAnimatorData
{
	bool:e_bValid,
	Float:e_fStartX,
	Float:e_fStartY,
	Float:e_fTargetX,
	Float:e_fTargetY,
	PlayerText:e_tdTextdraw,
	e_iPlayerid,
	Float:e_fDuration,
	e_iTick,
	e_iEase,
	e_iType,
	e_iColor,
	e_iTargetColor
}

new g_rgeAnimators[MAX_ANIMATORS + 1][eAnimatorData];

forward Animator_OnFinish(playerid, animator, type);

// Easing functions
stock Float:easeInSine(Float:t)
{
	return floatsin( 1.5707963 * t );
}

stock Float:easeOutSine(Float:t)
{
	return 1.0 + floatsin( 1.5707963 * (t - 1) );
}

stock Float:easeInOutSine(Float:t)
{
	return 0.5 * (1.0 + floatsin( 3.1415926 * (t - 0.5) ) );
}

stock Float:easeInQuad(Float:t)
{
    return t * t;
}

stock Float:easeOutQuad(Float:t)
{ 
    return t * (2.0 - t);
}

stock Float:easeInOutQuad(Float:t)
{
    return t < 0.5 ? 2.0 * t * t : t * (4.0 - 2.0 * t) - 1.0;
}

stock Float:easeInCubic(Float:t)
{
    return t * t * t;
}

stock Float:easeOutCubic(Float:t)
{
    return 1.0 + (--t) * t * t;
}

stock Float:easeInOutCubic(Float:t)
{
    return t < 0.5 ? 4.0 * t * t * t : 1.0 + (--t) * (2.0 * (--t)) * (2.0 * t);
}

stock Float:easeInQuart(Float:t)
{
    t *= t;
    return t * t;
}

stock Float:easeOutQuart(Float:t)
{
    t = (--t) * t;
    return 1.0 - t * t;
}

stock Float:easeInOutQuart(Float:t)
{
    if ( t < 0.5 )
    {
        t *= t;
        return 8.0 * t * t;
    }
    else
    {
        t = (--t) * t;
        return 1.0 - 8.0 * t * t;
    }
}

stock Float:easeInQuint(Float:t)
{
    new Float:t2 = t * t;
    return t * t2 * t2;
}

stock Float:easeOutQuint(Float:t)
{
    new Float:t2 = (--t) * t;
    return 1.0 + t * t2 * t2;
}

stock Float:easeInOutQuint(Float:t)
{
	new Float:t2;
    if ( t < 0.5 )
    {
        t2 = t * t;
        return 16.0 * t * t2 * t2;
    }
    else
    {
        t2 = (--t) * t;
        return 1.0 + 16.0 * t * t2 * t2;
    }
}

stock Float:easeInExpo(Float:t)
{
    return (floatpower( 2.0, 8.0 * t ) - 1.0) / 255.0;
}

stock Float:easeOutExpo(Float:t)
{
    return 1.0 - floatpower( 2.0, -8.0 * t );
}

stock Float:easeInOutExpo(Float:t)
{
	if ( t < 0.5 )
    {
        return (floatpower( 2.0, 16.0 * t ) - 1.0) / 510.0;
    }
    else
    {
        return 1.0 - 0.5 * floatpower( 2.0, -16.0 * (t - 0.5) );
    }
}

stock Float:easeInCirc(Float:t)
{
    return 1.0 - floatsqroot( 1.0 - t );
}

stock Float:easeOutCirc(Float:t)
{
    return floatsqroot( t );
}

stock Float:easeInOutCirc(Float:t)
{
    if ( t < 0.5 )
    {
        return (1.0 - floatsqroot( 1.0 - 2.0 * t )) * 0.5;
    }
    else
    {
        return (1.0 + floatsqroot( 2.0 * t - 1.0 )) * 0.5;
    }
}

stock Float:easeInBack(Float:t)
{
    return t * t * (2.70158 * t - 1.70158);
}

stock Float:easeOutBack(Float:t)
{
    return 1.0 + (--t) * t * (2.70158 * t + 1.70158);
}

stock Float:easeInOutBack(Float:t)
{
	if ( t < 0.5 )
    {
        return t * t * (7.0 * t - 2.5) * 2.0;
    }
    else
	{
        return 1.0 + (--t) * t * 2.0 * (7 * t + 2.5);
    }
}

stock Float:easeInElastic(Float:t)
{
    return t * t * t * t * floatsin(t * EASING_FUNC_PI * 4.5);
}

stock Float:easeOutElastic(Float:t)
{
    new Float:t2 = (t - 1.0) * (t - 1.0);
    return 1.0 - t2 * t2 * floatcos( t * EASING_FUNC_PI * 4.5 );
}

stock Float:easeInOutElastic(Float:t)
{
    new Float:t2;
    if ( t < 0.45 )
    {
        t2 = t * t;
        return 8.0 * t2 * t2 * floatsin( t * EASING_FUNC_PI * 9.0 );
    }
    else if ( t < 0.55 )
    {
        return 0.5 + 0.75 * floatsin( t * EASING_FUNC_PI * 4.0 );
    }
    else
    {
        t2 = (t - 1.0) * (t - 1.0);
        return 1.0 - 8.0 * t2 * t2 * floatsin( t * EASING_FUNC_PI * 9.0 );
    }
}

stock Float:easeInBounce(Float:t)
{
    return floatpower( 2.0, 6.0 * (t - 1.0) ) * floatabs( floatsin( t * EASING_FUNC_PI * 3.5 ) );
}

stock Float:easeOutBounce(Float:t)
{
    return 1.0 - floatpower( 2.0, -6.0 * t ) * floatabs( floatcos( t * EASING_FUNC_PI * 3.5 ) );
}

stock Float:easeInOutBounce(Float:t)
{
	if ( t < 0.5 )
    {
        return 8.0 * floatpower( 2.0, 8.0 * (t - 1.0) ) * floatabs( floatsin( t * EASING_FUNC_PI * 7.0 ) );
    }
    else
    {
        return 1.0 - 8.0 * floatpower( 2.0, -8.0 * t ) * floatabs( floatsin( t * EASING_FUNC_PI * 7.0 ) );
    }
}

stock Float:easeNone(Float:t)
{
	return t;
}

static Float:lerp(Float:start_value, Float:end_value, Float:pct)
{
    return (start_value + (end_value - start_value) * pct);
}

static lerp_rgba(color1, color2, Float:t)
{
    new r1 = (color1 >> 24) & 0xFF;
    new g1 = (color1 >> 16) & 0xFF;
    new b1 = (color1 >> 8) & 0xFF;
    new a1 = color1 & 0xFF;

    new r2 = (color2 >> 24) & 0xFF;
    new g2 = (color2 >> 16) & 0xFF;
    new b2 = (color2 >> 8) & 0xFF;
    new a2 = color2 & 0xFF;

    new r = r1 + floatround((r2 - r1) * t);
    new g = g1 + floatround((g2 - g1) * t);
    new b = b1 + floatround((b2 - b1) * t);
    new a = a1 + floatround((a2 - a1) * t);

    return (r << 24) | (g << 16) | (b << 8) | a;
}

static Animator_GetFreeSlot()
{
	for (new i; i < MAX_ANIMATORS; ++i)
	{
		if (!g_rgeAnimators[i][e_bValid]) {
			if (i > g_iLargestAnimatorId) g_iLargestAnimatorId = i;
		    return i;
		}
	}
    return -1;
}

stock Animator_Destroy(animator_id)
{
	#if defined PEF_DEBUG
		printf("[pawn-easing-functions] Animator_Destroy(animator_id = %i)", animator_id);
	#endif

	// check validity
	if (animator_id >= MAX_ANIMATORS) return 0;

	g_rgeAnimators[animator_id] = g_rgeAnimators[MAX_ANIMATORS];

	// If the destroyed animator's ID is the largest, then find the next largest one.
	if (animator_id >= g_iLargestAnimatorId)
	{
		// do a reverse loop starting from the previous largest.
		for (new i = animator_id; i >= 0; --i)
		{
			if (g_rgeAnimators[i][e_bValid]) {
				g_iLargestAnimatorId = i;
				return 1;
			}
		}
		// If we didn't return at the loop, no animators are left.
		g_iLargestAnimatorId = -1;
	}
	return 1;
}

forward Animator_Process();
public Animator_Process()
{
	// if largest id is less than 0, no animations are running.
	if (g_iLargestAnimatorId < 0) return 1;

	new maxCurrentAnimators = g_iLargestAnimatorId + 1;

	for (new i; i < maxCurrentAnimators; ++i)
	{
		if (g_rgeAnimators[i][e_bValid])
		{
			new elapsed_time = GetTickCount() - g_rgeAnimators[i][e_iTick];
			new Float:t = elapsed_time / g_rgeAnimators[i][e_fDuration];

			new
				ease_addr = g_rgeAnimators[i][e_iEase],
				Float:ease, Float:x, Float:y
			;

			__emit
			{
				push.s t
				push.c 4
				lctrl 6
				add.c 0x24
				lctrl 8
				push.pri
				load.s.pri ease_addr
				sctrl 6
				stor.s.pri ease
			}

			x = lerp(g_rgeAnimators[i][e_fStartX], g_rgeAnimators[i][e_fTargetX], ease);
			y = lerp(g_rgeAnimators[i][e_fStartY], g_rgeAnimators[i][e_fTargetY], ease);

			switch(g_rgeAnimators[i][e_iType])
			{
				case ANIMATOR_POSITION: PlayerTextDrawSetPos(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], x, y);
				case ANIMATOR_LETTER_SIZE: PlayerTextDrawLetterSize(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], x, y);
				case ANIMATOR_TEXT_SIZE: PlayerTextDrawTextSize(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], x, y);
				case ANIMATOR_FULL_SIZE:
				{
					PlayerTextDrawLetterSize(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], x, y);
					PlayerTextDrawTextSize(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], x, y);
				}
				case ANIMATOR_COLOR: PlayerTextDrawColour(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], lerp_rgba(g_rgeAnimators[i][e_iColor], g_rgeAnimators[i][e_iTargetColor], ease));
				case ANIMATOR_BOX_COLOR: PlayerTextDrawBoxColour(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], lerp_rgba(g_rgeAnimators[i][e_iColor], g_rgeAnimators[i][e_iTargetColor], ease));
				case ANIMATOR_BACKGROUND_COLOR: PlayerTextDrawBackgroundColour(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw], lerp_rgba(g_rgeAnimators[i][e_iColor], g_rgeAnimators[i][e_iTargetColor], ease));
			}

			PlayerTextDrawShow(g_rgeAnimators[i][e_iPlayerid], g_rgeAnimators[i][e_tdTextdraw]);

			if (t >= 1.0)
			{
				CallLocalFunction("Animator_OnFinish", "iii", g_rgeAnimators[i][e_iPlayerid], i, g_rgeAnimators[i][e_iType]);
				Animator_Destroy(i);
				continue;
			}
		}
	}
	return 1;
}

stock Animator_Insert(playerid, PlayerText:textdraw, Float:start_x, Float:start_y, Float:x, Float:y, duration = 1000, ease, type, start_color = -1, target_color = -1)
{
	new animator = Animator_GetFreeSlot();
	if (animator == -1)
		return -1;

	#if defined PEF_DEBUG
		printf("[pawn-easing-functions] Created animator: %i", animator);
	#endif

	g_rgeAnimators[animator][e_iType] = type;

	g_rgeAnimators[animator][e_iColor] = start_color;
	g_rgeAnimators[animator][e_iTargetColor] = target_color;

	g_rgeAnimators[animator][e_fStartX] = start_x;
	g_rgeAnimators[animator][e_fStartY] = start_y;

	g_rgeAnimators[animator][e_tdTextdraw] = textdraw;
	g_rgeAnimators[animator][e_iPlayerid] = playerid;
	g_rgeAnimators[animator][e_fDuration] = duration;
	g_rgeAnimators[animator][e_iEase] = ease;

	g_rgeAnimators[animator][e_fTargetX] = x;
	g_rgeAnimators[animator][e_fTargetY] = y;

	g_rgeAnimators[animator][e_iTick] = GetTickCount();
	g_rgeAnimators[animator][e_bValid] = true;
	return animator;
}

stock PlayerText_PlaceOnTop(playerid, PlayerText:textdraw)
{
	new Float:x, Float:y;
	PlayerTextDrawGetPos(playerid, textdraw, x, y);

	PlayerTextDrawSetPos(playerid, textdraw, x, y);
	PlayerTextDrawShow(playerid, textdraw);
	return 1;
}

stock PlayerText_MoveTo(playerid, PlayerText:textdraw, Float:x, Float:y, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetPos(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, x, y, duration, ease, ANIMATOR_POSITION);
}

stock PlayerText_MoveToX(playerid, PlayerText:textdraw, Float:x, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetPos(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, x, start_y, duration, ease, ANIMATOR_POSITION);
}

stock PlayerText_MoveToY(playerid, PlayerText:textdraw, Float:y, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetPos(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, start_x, y, duration, ease, ANIMATOR_POSITION);
}

stock PlayerText_MoveLetterSize(playerid, PlayerText:textdraw, Float:y, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetLetterSize(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, start_x, y, duration, ease, ANIMATOR_LETTER_SIZE);
}

stock PlayerText_MoveTextSize(playerid, PlayerText:textdraw, Float:x, duration = 1000, ease)
{
	new Float:start_x, Float:start_y;
	PlayerTextDrawGetTextSize(playerid, textdraw, start_x, start_y);
	return Animator_Insert(playerid, textdraw, start_x, start_y, x, start_y, duration, ease, ANIMATOR_TEXT_SIZE);
}

stock PlayerText_MoveSize(playerid, PlayerText:textdraw, Float:x, Float:y, duration = 1000, ease)
{
	new Float:start_x, Float:start_y, Float:temp_axis;
	PlayerTextDrawGetTextSize(playerid, textdraw, start_x, temp_axis);
	PlayerTextDrawGetLetterSize(playerid, textdraw, temp_axis, start_y);
	#pragma unused temp_axis

	return Animator_Insert(playerid, textdraw, start_x, start_y, x, y, duration, ease, ANIMATOR_FULL_SIZE);
}

stock PlayerText_InterpolateLetterSize(playerid, PlayerText:textdraw, Float:start_y, Float:end_y, duration = 1000, ease)
{
	return Animator_Insert(playerid, textdraw, 0.0, start_y, 0.0, end_y, duration, ease, ANIMATOR_LETTER_SIZE);
}

stock PlayerText_InterpolateTextSize(playerid, PlayerText:textdraw, Float:start_x, Float:end_x, duration = 1000, ease)
{
	return Animator_Insert(playerid, textdraw, start_x, 0.0, end_x, 0.0, duration, ease, ANIMATOR_TEXT_SIZE);
}

stock PlayerText_InterpolateColor(playerid, PlayerText:textdraw, color, duration = 1000, ease)
{
	return Animator_Insert(playerid, textdraw, 0.0, 0.0, 0.0, 0.0, duration, ease, ANIMATOR_COLOR, PlayerTextDrawGetColour(playerid, textdraw), color);
}

stock PlayerText_InterpolateBoxColor(playerid, PlayerText:textdraw, color, duration = 1000, ease)
{
	return Animator_Insert(playerid, textdraw, 0.0, 0.0, 0.0, 0.0, duration, ease, ANIMATOR_BOX_COLOR, PlayerTextDrawGetBoxColour(playerid, textdraw), color);
}

stock PlayerText_InterpolateBGColor(playerid, PlayerText:textdraw, color, duration = 1000, ease)
{
	return Animator_Insert(playerid, textdraw, 0.0, 0.0, 0.0, 0.0, duration, ease, ANIMATOR_BACKGROUND_COLOR, PlayerTextDrawGetBackgroundCol(playerid, textdraw), color);
}

stock PlayerText_StopMove(animator_id)
{
	if (animator_id < MAX_ANIMATORS)
	{
		Animator_Destroy(animator_id);
		return 1;
	}
	return 0;
}

public OnGameModeInit()
{
	SetTimer("Animator_Process", ANIMATION_UPDATE_RATE, true);

	#if defined easing_OnGameModeInit
		return easing_OnGameModeInit();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit easing_OnGameModeInit
#if defined easing_OnGameModeInit
	forward easing_OnGameModeInit();
#endif
