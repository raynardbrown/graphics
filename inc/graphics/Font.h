////////////////////////////////////////////////////////////////////////////////
//
// File: Font.h
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_FONT_H_
#define GRAPHICS_FONT_H_

#include <string>

#include "graphics/FontWeight.h"
#include "graphics/FontStyle.h"

class FontContext;

/**
 * A collection of symbols (glyphs) from a character set that can be drawn on
 * a screen.
 */
class Font
{
  protected:

    Font();

  public:

    virtual ~Font();

    virtual std::string getTypeface() const = 0;

    virtual FontWeight::Value getWeight() const = 0;

    virtual FontStyle::Value getStyle() const = 0;

    virtual std::size_t getPointSize() const = 0;

    /**
     * Checks whether this Font has an italic style.
     *
     * @return true if this Font has an italic style.
     */
    virtual bool isItalic() const = 0;

    virtual bool isStrikethrough() const = 0;

    virtual bool isUnderlined() const = 0;

    virtual FontContext * getContext() const = 0;
};
#endif /* GRAPHICS_FONT_H_ */
