////////////////////////////////////////////////////////////////////////////////
//
// File: SystemGraphics.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/Color.h"
#include "graphics/IDrawable.h"

#include "graphics/IDrawableSurface.h"
#include "graphics/private/windows/Win32GraphicsPrivate.h"
#include "graphics/private/windows/DrawableSurfaceContext.h"
#include "graphics/private/windows/SystemGraphicsPrivate.h"
#include "graphics/private/ISetBackgroundColorImpl.h"

#include "graphics/private/windows/SystemGraphics.h"

SystemGraphicsPrivate::SystemGraphicsPrivate(IDrawable * drawable)
:Win32GraphicsPrivate(drawable),
 clientHandle(false)
{

}

SystemGraphicsPrivate::SystemGraphicsPrivate(IDrawable * drawable, HDC hdc)
:Win32GraphicsPrivate(drawable),
 clientHandle(true)
{
  this->hdc = hdc;
}

SystemGraphicsPrivate::~SystemGraphicsPrivate()
{
}

SystemGraphics::SystemGraphics(IDrawable * drawable)
:Win32Graphics(*new SystemGraphicsPrivate(drawable))
{

}

SystemGraphics::SystemGraphics(IDrawable * drawable, HDC hdc)
:Win32Graphics(*new SystemGraphicsPrivate(drawable, hdc))
{

}

SystemGraphics::~SystemGraphics()
{
}


void SystemGraphics::setBackgroundColor(const Color * backgroundColor)
{
  SystemGraphicsPrivate * d = static_cast<SystemGraphicsPrivate *>(dRoot.get());

  if(d->clientHandle)
  {
    // When we use the client supplied HDC handle, which is from
    // WM_CTLCOLORSTATIC, we draw directly into the HDC.
    ::SetBkColor(d->hdc, backgroundColor->getColorValue());
  }
  else
  {
    d->setBackgroundColorImpl->setBackgroundColor(backgroundColor);
  }
}

void SystemGraphics::acquire()
{
  SystemGraphicsPrivate * d = static_cast<SystemGraphicsPrivate *>(dRoot.get());

  if(!d->clientHandle)
  {
    d->hdc = ::BeginPaint(d->drawable->getDrawableSurface()->getDrawableSurfaceContext()->hwnd, &d->ps);

    if(d->hdc == nullptr)
    {
      // TODO: handle nullptr
    }

    d->memoryDC = ::CreateCompatibleDC(d->hdc);

    if(d->memoryDC == nullptr)
    {
      // TODO: handle nullptr
    }

    d->compatibleBitmap = ::CreateCompatibleBitmap(d->hdc,
                                                   d->drawable->getDrawableSurface()->getWidth(),
                                                   d->drawable->getDrawableSurface()->getHeight());

    if(d->compatibleBitmap == nullptr)
    {
      // TODO: handle nullptr
    }

    d->oldBitmap = static_cast<HBITMAP>(::SelectObject(d->memoryDC, d->compatibleBitmap));
  }
}

void SystemGraphics::release()
{
  SystemGraphicsPrivate * d = static_cast<SystemGraphicsPrivate *>(dRoot.get());

  if(!d->clientHandle)
  {
    ::EndPaint(d->drawable->getDrawableSurface()->getDrawableSurfaceContext()->hwnd, &d->ps);
    ::SelectObject(d->memoryDC, d->oldBitmap);
    ::DeleteObject(d->compatibleBitmap);
    ::DeleteDC(d->memoryDC);
  }
}
