#pragma once

#include "effect/effectwindow.h"

namespace KWin
{

inline bool isMenu(const EffectWindow *w)
{
    return w->isMenu() || w->isDropdownMenu() || w->isPopupMenu() || w->isPopupWindow();
}

}
