////////////////////////////////////////////////////////////////////////////////
//
// File: Win32Graphics.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/IDrawable.h"

#include "graphics/Color.h"
#include "graphics/IDrawableSurface.h"
#include "graphics/private/windows/Win32GraphicsPrivate.h"
#include "graphics/private/windows/DrawableSurfaceContext.h"

#include "graphics/private/windows/Win32Graphics.h"

Win32GraphicsPrivate::Win32GraphicsPrivate(IDrawable * drawable)
:drawable(drawable),
 hdc(nullptr),
 memoryDC(nullptr),
 compatibleBitmap(nullptr),
 oldBitmap(nullptr),
 doubleBufferingEnabled(true)
{

}

void Win32Graphics::initialize()
{
  acquire();

  postAcquire();
}
