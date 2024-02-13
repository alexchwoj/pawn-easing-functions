
# pawn-easing-functions
A library that implements easing functions into the Pawn language, and an animation system for textdraws. This idea gained popularity through the "Hyaxe Roleplay" notifications, and I have finally decided to release a public version of this system.

## Implementation

1. Download the [latest version](https://github.com/alexchwoj/pawn-easing-functions/releases/latest).
2. Place the file in your `include` folder.
3. Enter this line in your initial script.
```pawn
#include <pawn-easing-functions>
```
4. Install [YSF](https://github.com/IS4Code/YSF/releases).

## Functions
```pawn
// Position
PlayerText_MoveTo(playerid, PlayerText:textdraw, Float:x, Float:y, duration = 1000, ease);
PlayerText_MoveToX(playerid, PlayerText:textdraw, Float:x, duration = 1000, ease);
PlayerText_MoveToY(playerid, PlayerText:textdraw, Float:y, duration = 1000, ease);

// Size
PlayerText_MoveLetterSize(playerid, PlayerText:textdraw, Float:y, duration = 1000, ease);
PlayerText_MoveTextSize(playerid, PlayerText:textdraw, Float:x, duration = 1000, ease);
PlayerText_MoveSize(playerid, PlayerText:textdraw, Float:x, Float:y, duration = 1000, ease);
PlayerText_InterpolateLetterSize(playerid, PlayerText:textdraw, Float:start_y, Float:end_y, duration = 1000, ease);
PlayerText_InterpolateTextSize(playerid, PlayerText:textdraw, Float:start_x, Float:end_x, duration = 1000, ease);

// Color
PlayerText_InterpolateColor(playerid, PlayerText:textdraw, color, duration = 1000, ease);
PlayerText_InterpolateBoxColor(playerid, PlayerText:textdraw, color, duration = 1000, ease);
PlayerText_InterpolateBGColor(playerid, PlayerText:textdraw, color, duration = 1000, ease);

// General
PlayerText_PlaceOnTop(playerid, PlayerText:textdraw);
PlayerText_StopMove(animator);
```

## Callbacks
```pawn
Animator_OnFinish(playerid, animator, type);
```

## Easing list
```
EASE_IN_SINE
EASE_OUT_SINE
EASE_IN_OUT_SINE
EASE_IN_QUAD
EASE_OUT_QUAD
EASE_IN_OUT_QUAD
EASE_IN_CUBIC
EASE_OUT_CUBIC
EASE_IN_OUT_CUBIC
EASE_IN_QUART
EASE_OUT_QUART
EASE_IN_OUT_QUART
EASE_IN_QUINT
EASE_OUT_QUINT
EASE_IN_OUT_QUINT
EASE_IN_EXPO
EASE_OUT_EXPO
EASE_IN_OUT_EXPO
EASE_IN_CIRC
EASE_OUT_CIRC
EASE_IN_OUT_CIRC
EASE_IN_BACK
EASE_OUT_BACK
EASE_IN_OUT_BACK
EASE_IN_ELASTIC
EASE_OUT_ELASTIC
EASE_IN_OUT_ELASTIC
EASE_IN_BOUNCE
EASE_OUT_BOUNCE
EASE_IN_OUT_BOUNCE
```
You can see what each of these options looks like here: https://easings.net/

## Example
```pawn
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
```

## Update rate
There is a single timer responsible for updating all the animations in order to avoid overwhelming SA-MP's timer mechanism. By default, this runs 30 times per second, which can be interpreted as 30 fps. You may change the fps of the animations by defining `EASING_ANIMATION_FRAMERATE` before including the file.

## Video
https://github.com/alexchwoj/pawn-easing-functions/assets/49602261/87a10706-be3e-4157-ad0e-f0d5558a509c


https://github.com/alexchwoj/pawn-easing-functions/assets/49602261/a10f978e-7b2d-4df5-aa47-1c58efe53503



## Thanks to
* [Markski](https://github.com/markski1) for lending a hand.
