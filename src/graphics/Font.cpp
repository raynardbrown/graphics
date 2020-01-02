////////////////////////////////////////////////////////////////////////////////
//
// File: Font.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/Font.h"

FontStyle::Value operator|(FontStyle::Value a, FontStyle::Value b)
{
  return static_cast<FontStyle::Value>(static_cast<int>(a) | static_cast<int>(b));
}

FontStyle::Value operator&(FontStyle::Value a, FontStyle::Value b)
{
  return static_cast<FontStyle::Value>(static_cast<int>(a) & static_cast<int>(b));
}

FontStyle::Value& operator|=(FontStyle::Value& a, FontStyle::Value b)
{
  a = static_cast<FontStyle::Value>(static_cast<int>(a) | static_cast<int>(b));
  return a;
}

Font::Font()
{
}

Font::~Font()
{
}
