////////////////////////////////////////////////////////////////////////////////
//
// File: GraphicsFactory.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/private/windows/ScreenGraphics.h"
#include "graphics/private/windows/Win32Graphics.h"
#include "graphics/private/windows/GraphicsDeleter.h"

#include "graphics/GraphicsFactory.h"

GraphicsFactory::GraphicsFactory()
{

}

GraphicsFactory::~GraphicsFactory()
{

}

/* static */ boost::shared_ptr<Graphics> GraphicsFactory::getScreenGraphics()
{
  return boost::shared_ptr<Graphics>(new ScreenGraphics(), GraphicsDeleter());
}

/* static */ boost::shared_ptr<Graphics> GraphicsFactory::getGraphics(IDrawable * drawable)
{
  return boost::shared_ptr<Graphics>(new Win32Graphics(drawable), GraphicsDeleter());
}
