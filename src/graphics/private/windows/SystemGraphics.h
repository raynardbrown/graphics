////////////////////////////////////////////////////////////////////////////////
//
// File: SystemGraphics.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_SYSTEMGRAPHICS_H_
#define GRAPHICS_PRIVATE_WINDOWS_SYSTEMGRAPHICS_H_

#include <windows.h>

#include "graphics/Graphics.h"

class IDrawable;

class SystemGraphics : public Graphics
{
  public:

    SystemGraphics(IDrawable * drawable);

    SystemGraphics(IDrawable * drawable, HDC hdc);

    virtual ~SystemGraphics();
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_SYSTEMGRAPHICS_H_ */
