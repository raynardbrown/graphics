////////////////////////////////////////////////////////////////////////////////
//
// File: TextDimension.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_TEXTDIMENSION_H_
#define GRAPHICS_TEXTDIMENSION_H_

#include <memory>
#include <string>

class Font;
class Size2D;

class TextDimension
{
  public:

    TextDimension();

    ~TextDimension();

    static std::auto_ptr<Size2D> getTextSize(const Font * font,
                                             const std::string& text);
};
#endif /* GRAPHICS_TEXTDIMENSION_H_ */
