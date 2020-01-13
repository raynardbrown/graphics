////////////////////////////////////////////////////////////////////////////////
//
// File: Color.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/Color.h"

Color::Color(uint8_t red, uint8_t green, uint8_t blue,
             uint8_t alpha)
{
  this->colorValue = static_cast<uint32_t>(alpha) << 24 |
                     static_cast<uint32_t>(blue)  << 16 |
                     static_cast<uint32_t>(green) << 8 |
                     static_cast<uint32_t>(red)   << 0;
}

Color::~Color()
{
  // nothing to destroy
}

uint8_t Color::getRedValue() const
{
  return (this->colorValue & 0xff);
}

uint8_t Color::getGreenValue() const
{
  return ((this->colorValue >> 8) & 0xff);
}

uint8_t Color::getBlueValue() const
{
  return ((this->colorValue >> 16) & 0xff);
}

uint8_t Color::getAlphaChannel() const
{
  return ((this->colorValue >> 24) & 0xff);
}

uint32_t Color::getColorValue() const
{
  return this->colorValue;
}

void Color::setColorValue(uint32_t newColorValue)
{
  colorValue = newColorValue;
}
