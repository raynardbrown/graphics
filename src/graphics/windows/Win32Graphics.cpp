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
#include "graphics/private/windows/Win32GraphicsImpl.h"

#include "graphics/private/windows/Win32Graphics.h"

Win32GraphicsPrivate::Win32GraphicsPrivate(IDrawable * drawable)
:drawable(drawable),
 hdc(nullptr),
 memoryDC(nullptr),
 compatibleBitmap(nullptr),
 oldBitmap(nullptr),
 doubleBufferingEnabled(true),
 graphicsImpl(nullptr)
{

}

Win32GraphicsPrivate::~Win32GraphicsPrivate()
{

}

Win32Graphics::Win32Graphics(IDrawable * drawable)
:dRoot(new Win32GraphicsPrivate(drawable))
{
  dRoot->graphicsImpl = new Win32GraphicsImpl(this);
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
  dRoot->graphicsImpl->setBackgroundColor(backgroundColor);
}

void Win32Graphics::setTextColor(const Color * textColor)
{
  HDC hdc;

  if(dRoot->doubleBufferingEnabled)
  {
    // TODO: make sure the memory has been initialized
    hdc = dRoot->memoryDC;
  }
  else
  {
    hdc = dRoot->hdc;
  }

  ::SetTextColor(hdc, textColor->getColorValue());
}

void Win32Graphics::initialize()
{
  acquire();

  postAcquire();
}

void Win32Graphics::acquire()
{
  HWND localHwnd = nullptr;

  if(dRoot->drawable->getDrawableSurface()->getDrawableSurfaceContext()->hwnd == nullptr)
  {
    // draw on the whole screen
    dRoot->hdc = ::GetDC(nullptr);

    localHwnd = nullptr;
  }
  else
  {
    // draw on just the drawable surface
    dRoot->hdc = ::GetDC(dRoot->drawable->getDrawableSurface()->getDrawableSurfaceContext()->hwnd);

    localHwnd = dRoot->drawable->getDrawableSurface()->getDrawableSurfaceContext()->hwnd;
  }

  if(dRoot->hdc == nullptr)
  {
    // TOD: handle null
  }

  if(dRoot->doubleBufferingEnabled)
  {
    dRoot->memoryDC = ::CreateCompatibleDC(dRoot->hdc);

    if(dRoot->memoryDC == nullptr)
    {
      ::ReleaseDC(localHwnd, dRoot->hdc);

      // TODO: handle create compatiable dc failure
    }

    dRoot->compatibleBitmap = ::CreateCompatibleBitmap(dRoot->hdc,
                                                       dRoot->drawable->getDrawableSurface()->getWidth(),
                                                       dRoot->drawable->getDrawableSurface()->getHeight());

    if(dRoot->compatibleBitmap == nullptr)
    {
      ::DeleteDC(dRoot->memoryDC);
      ::ReleaseDC(localHwnd, dRoot->hdc);

      // TODO: handle CreateCompatibleBitmap fail
    }

    dRoot->oldBitmap = static_cast<HBITMAP>(::SelectObject(dRoot->memoryDC, dRoot->compatibleBitmap));
  }
}

void Win32Graphics::postAcquire()
{

}

void Win32Graphics::release()
{
  if(dRoot->doubleBufferingEnabled)
  {
    ::SelectObject(dRoot->memoryDC, dRoot->oldBitmap);
    ::DeleteObject(dRoot->compatibleBitmap);
    ::DeleteDC(dRoot->memoryDC);
  }

  ::ReleaseDC(dRoot->drawable->getDrawableSurface()->getDrawableSurfaceContext()->hwnd, dRoot->hdc);
}
