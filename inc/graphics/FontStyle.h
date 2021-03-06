////////////////////////////////////////////////////////////////////////////////
//
// File: FontStyle.h
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_FONTSTYLE_H_
#define GRAPHICS_FONTSTYLE_H_

struct FontStyle
{
  public:

    /**
     * The font style flags
     */
    enum Value
    {
      DefaultStyle = 0,
      ItalicStyle = 1,
      StrikethroughStyle = 2,

      /**
       * This Font is drawn with a line under the font if this flag is specified
       */
      UnderlineStyle = 4
    };
};

FontStyle::Value operator|(FontStyle::Value a, FontStyle::Value b);
FontStyle::Value& operator|=(FontStyle::Value& a, FontStyle::Value b);
FontStyle::Value operator&(FontStyle::Value a, FontStyle::Value b);
#endif /* GRAPHICS_FONTSTYLE_H_ */
