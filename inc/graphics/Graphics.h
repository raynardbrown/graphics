////////////////////////////////////////////////////////////////////////////////
//
// File: Graphics.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_GRAPHICS_H_
#define GRAPHICS_GRAPHICS_H_

class Color;

class Graphics
{
  protected:

    Graphics()
    {

    }

  public:

    virtual ~Graphics()
    {

    }

    virtual void setBackgroundColor(const Color * backgroundColor) = 0;

    /**
     * Set the color that this Graphics will use to draw text.
     *
     * @param[in] textColor the new color that this Graphics will use to draw
     * text.
     */
    virtual void setTextColor(const Color * textColor) = 0;
};
#endif /* GRAPHICS_GRAPHICS_H_ */
