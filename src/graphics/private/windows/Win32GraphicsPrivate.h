////////////////////////////////////////////////////////////////////////////////
//
// File: Win32GraphicsPrivate.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSPRIVATE_H_
#define GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSPRIVATE_H_

#include <windows.h>

class IDrawable;

class Win32GraphicsPrivate
{
  public:

    Win32GraphicsPrivate(IDrawable * drawable);
    Win32GraphicsPrivate(IDrawable * drawable, HDC hdc);

    ~Win32GraphicsPrivate();

    void initialize();
    void destroy();
    void setDoubleBufferingEnabled(bool flag);

    IDrawable * drawable;
    HDC hdc;
    HDC memoryDC;
    HBITMAP compatibleBitmap;
    HBITMAP oldBitmap;
    bool doubleBufferingEnabled;

    PAINTSTRUCT ps;

    // The client supplied the HDC. The client is responsible for the HDC.
    bool clientHandle;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICSPRIVATE_H_ */
