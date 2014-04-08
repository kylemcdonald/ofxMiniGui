#pragma once

/*
 ideas:
 - show value in tooltip instead of replacing text
 - show large text of currently selected item 
 principles:
 - take up as little space as necessary.
 - code is generalized exactly when it would otherwise be duplicated.
 - you can't define where something is. layout is automatic.
 - therefore nothing knows where it is until is drawn. drawable = clickable.
 - all controls are rectangular.
 - all control are exactly getWidth() x getHeight(), with nothing outside.
 - all drawing happens on the pixel grid.
 - inherited values init in constructor, non-inherited in initializer lists.
*/

#include "Gui.h"
#include "Slider.h"