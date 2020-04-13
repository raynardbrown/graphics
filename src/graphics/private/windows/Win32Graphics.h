////////////////////////////////////////////////////////////////////////////////
//
// File: Win32Graphics.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICS_H_
#define GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICS_H_

#include <memory>
#include <windows.h>

#include "graphics/Graphics.h"

class IDrawable;
class Win32GraphicsPrivate;

class Win32Graphics : public Graphics
{
  public:

    Win32Graphics(IDrawable * drawable);

    Win32Graphics(IDrawable * drawable, HDC hdc);

    virtual ~Win32Graphics();

    virtual void setBackgroundColor(const Color * backgroundColor);

    /**
     * Set the color that this Graphics will use to draw text.
     *
     * @param[in] textColor the new color that this Graphics will use to draw
     * text.
     */
    virtual void setTextColor(const Color * textColor);

    void initialize();

  protected:

    Win32Graphics(Win32GraphicsPrivate &d);

    virtual void acquire();

    virtual void postAcquire();

  public:

    virtual void release();

  protected:

    std::auto_ptr<Win32GraphicsPrivate> dRoot;

  private:

    friend class Win32GraphicsImpl;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICS_H_ */
