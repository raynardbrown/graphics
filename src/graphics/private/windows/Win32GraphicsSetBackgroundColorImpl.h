////////////////////////////////////////////////////////////////////////////////
//
// File: Win32GraphicsSetBackgroundColorImpl.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSBACKGROUNDCOLORIMPL_H_
#define GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSBACKGROUNDCOLORIMPL_H_

#include "graphics/private/ISetBackgroundColorImpl.h"

class Color;

class Win32Graphics;

class Win32GraphicsSetBackgroundColorImpl : public ISetBackgroundColorImpl
{
  public:

    Win32GraphicsSetBackgroundColorImpl(Win32Graphics * win32Graphics);

    virtual ~Win32GraphicsSetBackgroundColorImpl();

    virtual void setBackgroundColor(const Color * backgroundColor);

  private:

    Win32Graphics * win32Graphics;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSBACKGROUNDCOLORIMPL_H_ */
