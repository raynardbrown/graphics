////////////////////////////////////////////////////////////////////////////////
//
// File: Color.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_COLOR_H_
#define GRAPHICS_COLOR_H_

#include <cstdint>

class Color
{
  public:

    /**
     * Create a new color with the specified red, green, and blue values.
     *
     * @param[in] red the red value in the range 0 - 255.
     * @param[in] green the green value in the range 0 - 255.
     * @param[in] blue the blue value in the range 0 - 255.
     * @param[in] alpha the alpha channel
     */
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

    /**
     * destructor
     */
    ~Color();

    /**
     * Return the red value of this Color.
     * @return the red value
     */
    uint8_t getRedValue() const;

    /**
     * Return the green value of this Color.
     * @return the green value
     */
    uint8_t getGreenValue() const;

    /**
     * Return the blue value of this Color.
     * @return the blue value
     */
    uint8_t getBlueValue() const;

    uint8_t getAlphaChannel() const;

    uint32_t getColorValue() const;

    void setColorValue(uint32_t newColorValue);

  private:

    uint32_t colorValue;
};
#endif /* GRAPHICS_COLOR_H_ */
