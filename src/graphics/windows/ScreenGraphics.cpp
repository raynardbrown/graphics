////////////////////////////////////////////////////////////////////////////////
//
// File: ScreenGraphics.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/private/windows/Win32GraphicsPrivate.h"
#include "graphics/private/windows/ScreenGraphicsPrivate.h"

#include "graphics/private/windows/ScreenGraphics.h"

ScreenGraphicsPrivate::ScreenGraphicsPrivate()
:Win32GraphicsPrivate(nullptr)
{
  // TODO: Use the EnumDisplayMonitors function in order to determine the size
  //       of the display so a proper drawable can be created. Until then, this
  //       class cannot be used since the drawable is nullptr
}

ScreenGraphicsPrivate::~ScreenGraphicsPrivate()
{

}

ScreenGraphics::ScreenGraphics()
:Win32Graphics(*new ScreenGraphicsPrivate())
{

}

ScreenGraphics::ScreenGraphics(ScreenGraphicsPrivate& d)
:Win32Graphics(d)
{

}

ScreenGraphics::~ScreenGraphics()
{

}
