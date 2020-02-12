////////////////////////////////////////////////////////////////////////////////
//
// File: ScreenGraphics.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_SCREENGRAPHICS_H_
#define GRAPHICS_PRIVATE_WINDOWS_SCREENGRAPHICS_H_

#include "graphics/private/windows/Win32Graphics.h"

class ScreenGraphicsPrivate;

class ScreenGraphics : public Win32Graphics
{
  public:

    ScreenGraphics();

    virtual ~ScreenGraphics();

  protected:

    ScreenGraphics(ScreenGraphicsPrivate& d);
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_SCREENGRAPHICS_H_ */
