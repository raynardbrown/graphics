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

    virtual void create();

    virtual void postCreate();

  private:

    std::auto_ptr<Win32GraphicsPrivate> d;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_WIN32GRAPHICS_H_ */
