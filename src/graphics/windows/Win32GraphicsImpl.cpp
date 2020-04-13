////////////////////////////////////////////////////////////////////////////////
//
// File: Win32GraphicsImpl.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>

#include "graphics/Color.h"
#include "graphics/IDrawable.h"
#include "graphics/IDrawableSurface.h"

#include "graphics/private/windows/Win32Graphics.h"
#include "graphics/private/windows/Win32GraphicsPrivate.h"

#include "graphics/private/windows/Win32GraphicsImpl.h"

Win32GraphicsImpl::Win32GraphicsImpl(Win32Graphics * win32Graphics)
:IGraphicsImpl(),
 win32Graphics(win32Graphics)
{

}

Win32GraphicsImpl::~Win32GraphicsImpl()
{

}

void Win32GraphicsImpl::setBackgroundColor(const Color * backgroundColor)
{
  HDC hdc;

  if(win32Graphics->dRoot->doubleBufferingEnabled)
  {
    // TODO: make sure the memory has been initialized
    hdc = win32Graphics->dRoot->memoryDC;
  }
  else
  {
    hdc = win32Graphics->dRoot->hdc;
  }

  // TODO: Remember the default color of a bitmap is black.
  //       Put in an API to let the user decide the color of the bitmap.

  // TODO: For now do this. If not the entire background will be black when you
  //       draw
  RECT rc;

  rc.left = 0;
  rc.top = 0;
  rc.right = win32Graphics->dRoot->drawable->getDrawableSurface()->getWidth();
  rc.bottom = win32Graphics->dRoot->drawable->getDrawableSurface()->getHeight();

  HBRUSH brush = ::CreateSolidBrush(backgroundColor->getColorValue());

  ::FillRect(hdc, &rc, brush);

  ::DeleteObject(brush);
}

void Win32GraphicsImpl::setTextColor(const Color * textColor)
{
  HDC hdc;

  if(win32Graphics->dRoot->doubleBufferingEnabled)
  {
    // TODO: make sure the memory has been initialized
    hdc = win32Graphics->dRoot->memoryDC;
  }
  else
  {
    hdc = win32Graphics->dRoot->hdc;
  }

  ::SetTextColor(hdc, textColor->getColorValue());
}
