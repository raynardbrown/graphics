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
#include "graphics/private/ISetBackgroundColorImpl.h"
#include "graphics/private/windows/Win32GraphicsSetBackgroundColorImpl.h"

#include "graphics/private/windows/Win32Graphics.h"

Win32GraphicsPrivate::Win32GraphicsPrivate(IDrawable * drawable)
:drawable(drawable),
 hdc(nullptr),
 memoryDC(nullptr),
 compatibleBitmap(nullptr),
 oldBitmap(nullptr),
 doubleBufferingEnabled(true),
 setBackgroundColorImpl(nullptr)
{

}

Win32GraphicsPrivate::~Win32GraphicsPrivate()
{

}

Win32Graphics::Win32Graphics(IDrawable * drawable)
:dRoot(new Win32GraphicsPrivate(drawable))
{
  dRoot->setBackgroundColorImpl = new Win32GraphicsSetBackgroundColorImpl(this);
}

Win32Graphics::Win32Graphics(Win32GraphicsPrivate &dRoot)
:dRoot(&dRoot)
{

}

Win32Graphics::~Win32Graphics()
{

}

void Win32Graphics::setBackgroundColor(const Color * backgroundColor)
{
  dRoot->setBackgroundColorImpl->setBackgroundColor(backgroundColor);
}

void Win32Graphics::initialize()
{
  acquire();

  postAcquire();
}
