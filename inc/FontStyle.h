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

#ifndef FONTSTYLE_H_
#define FONTSTYLE_H_

struct FontStyle
{
  public:

    /**
     * The font style flags
     */
    enum FontStyle
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
#endif /* FONTSTYLE_H_ */
