
# pawn-easing-functions
A library that compiles easing functions ported to Pawn, and it also includes an animation system for textdraws. This experimental idea gained fame through the "Hyaxe Roleplay" notifications, and I have finally decided to release a public version of this system.

## Implementation

1. Download the latest version in [releases](https://github.com/alexchwoj/pawn-easing-functions/releases)
2. Enter this line in your initial script
```pawn
#include <pawn-easing-functions>
```
4. Install [YSF](https://github.com/IS4Code/YSF/releases)

## Functions
```pawn
PlayerText_MoveTo(playerid, PlayerText:textdraw, Float:x, Float:y, duration = 1000, ease);
PlayerText_MoveToX(playerid, PlayerText:textdraw, Float:x, duration = 1000, ease);
PlayerText_MoveToY(playerid, PlayerText:textdraw, Float:y, duration = 1000, ease);
PlayerText_MoveLetterSize(playerid, PlayerText:textdraw, Float:y, duration = 1000, ease);
PlayerText_MoveTextSize(playerid, PlayerText:textdraw, Float:x, duration = 1000, ease);
PlayerText_MoveSize(playerid, PlayerText:textdraw, Float:x, Float:y, duration = 1000, ease);
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
You can see what each of these features looks like here: https://easings.net/

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
Internally there is a single timer that is responsible for updating all the animations so as not to saturate the timer server. This system may work poorly for users who have a very bad internet or a lot of packet loss, in any case you can globally change the refresh rate by overwriting the definition "ANIMATORS_UPDATE_RATE" which by default is set to 16 milliseconds.

## Video
https://github.com/alexchwoj/pawn-easing-functions/assets/49602261/87a10706-be3e-4157-ad0e-f0d5558a509c

## Thanks to
* [Markski](https://github.com/markski1) for lend a hand

