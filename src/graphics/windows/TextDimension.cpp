////////////////////////////////////////////////////////////////////////////////
//
// File: TextDimension.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>

#include "string/extras/CharacterEncoder.h"

#include "graphics/Font.h"
#include "graphics/Size2D.h"

#include "graphics/private/windows/FontContext.h"

#include "graphics/TextDimension.h"

TextDimension::TextDimension()
{
}

TextDimension::~TextDimension()
{
}

/* static */ std::auto_ptr<Size2D> TextDimension::getTextSize(const Font * font,
                                                              const std::string& text)
{
  // get a device context for the entire screen
  HDC screenDc = ::GetDC(NULL);

  HFONT clientFont = font->getContext()->handle;

  // replace the font in the screen dc with the client specified font
  HGDIOBJ hGdiObj = ::SelectObject(screenDc, reinterpret_cast<HGDIOBJ>(clientFont));

  // save a copy of the screen dc font so that we can restore the font
  HFONT originalFont = reinterpret_cast<HFONT>(hGdiObj);

  SIZE textDimension;
  std::wstring tempString(CharacterEncoder::utf8ToUtf16(text));

  BOOL returnValue = ::GetTextExtentPoint32W(screenDc,
                                             tempString.c_str(),
                                             tempString.length(),
                                             &textDimension);

  // restore the screen dc font
  ::SelectObject(screenDc, originalFont);

  // release the screen dc allowing another application to use it
  ::ReleaseDC(NULL, screenDc);

  if(returnValue)
  {
    return std::auto_ptr<Size2D>(new Size2D(textDimension.cx,
                                            textDimension.cy));
  }
  else
  {
    return std::auto_ptr<Size2D>(NULL);
  }
}
