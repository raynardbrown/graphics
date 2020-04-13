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

#include "graphics/private/windows/Win32Graphics.h"

class IDrawable;
class SystemGraphicsPrivate;

class SystemGraphics : public Win32Graphics
{
  public:

    SystemGraphics(IDrawable * drawable);

    SystemGraphics(IDrawable * drawable, HDC hdc);

    virtual ~SystemGraphics();

    virtual void setBackgroundColor(const Color * backgroundColor);

    virtual void setTextColor(const Color * textColor);

  protected:

    SystemGraphics(SystemGraphicsPrivate& d);

    virtual void acquire();

  public:

    virtual void release();
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_SYSTEMGRAPHICS_H_ */
