////////////////////////////////////////////////////////////////////////////////
//
// File: Win32GraphicsImpl.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSIMPL_H_
#define GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSIMPL_H_

#include "graphics/private/IGraphicsImpl.h"

class Color;

class Win32Graphics;

class Win32GraphicsImpl : public IGraphicsImpl
{
  public:

    Win32GraphicsImpl(Win32Graphics * win32Graphics);

    virtual ~Win32GraphicsImpl();

    virtual void setBackgroundColor(const Color * backgroundColor);

  private:

    Win32Graphics * win32Graphics;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSIMPL_H_ */
