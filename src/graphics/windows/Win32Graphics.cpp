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
 doubleBufferingEnabled(true),
 clientHandle(false)
{
}

Win32GraphicsPrivate::Win32GraphicsPrivate(IDrawable * drawable,
                                           HDC hdc)
:drawable(drawable),
 hdc(hdc),
 memoryDC(nullptr),
 compatibleBitmap(nullptr),
 oldBitmap(nullptr),
 doubleBufferingEnabled(false), // don't use the memory dc the client is supply an HDC
 clientHandle(true)
{
}

void Win32Graphics::initialize()
{
  create();

  postCreate();
}
