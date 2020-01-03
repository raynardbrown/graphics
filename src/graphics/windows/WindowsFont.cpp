////////////////////////////////////////////////////////////////////////////////
//
// File: WindowsFont.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>

#include "string/extras/CharacterEncoder.h"

#include "graphics/private/windows/FontContext.h"
#include "graphics/private/windows/WindowsFontPrivate.h"

#include "graphics/private/windows/WindowsFont.h"

static int fontWeightEnumToWin32FontWeight(FontWeight::Value fontWeight)
{
  switch(fontWeight)
  {
    case FontWeight::ThinWeight:
    {
      return FW_THIN;
    }

    case FontWeight::ExtraLightWeight:
    {
      return FW_EXTRALIGHT;
    }

    case FontWeight::LightWeight:
    {
      return FW_LIGHT;
    }

    case FontWeight::NormalWeight:
    {
      return FW_NORMAL;
    }

    case FontWeight::MediumWeight:
    {
      return FW_MEDIUM;
    }

    case FontWeight::SemiboldWeight:
    {
      return FW_SEMIBOLD;
    }

    case FontWeight::BoldWeight:
    {
      return FW_BOLD;
    }

    case FontWeight::ExtraBoldWeight:
    {
      return FW_EXTRABOLD;
    }

    case FontWeight::HeavyWeight:
    {
      return FW_HEAVY;
    }

    default:
    {
      // FontWeight::DefaultWeight
      return 0;
    }
  }
}

static FontWeight::Value win32FontWeightToFontWeightEnum(int fontWeight)
{
  switch(fontWeight)
  {
    case FW_THIN:
    {
      return FontWeight::ThinWeight;
    }

    case FW_EXTRALIGHT:
    {
      return FontWeight::ExtraLightWeight;
    }

    case FW_LIGHT:
    {
      return FontWeight::LightWeight;
    }

    case FW_NORMAL:
    {
      return FontWeight::NormalWeight;
    }

    case FW_MEDIUM:
    {
      return FontWeight::MediumWeight;
    }

    case FW_SEMIBOLD:
    {
      return FontWeight::SemiboldWeight;
    }

    case FW_BOLD:
    {
      return FontWeight::BoldWeight;
    }

    case FW_EXTRABOLD:
    {
      return FontWeight::ExtraBoldWeight;
    }

    case FW_HEAVY:
    {
      return FontWeight::HeavyWeight;
    }

    default:
    {
      return FontWeight::DefaultWeight;
    }
  }
}

FontContext::FontContext()
:handle(NULL)
{

}

FontContext::~FontContext()
{
  ::DeleteObject(handle);
}

WindowsFontPrivate::WindowsFontPrivate(const std::string& typeface,
                                       FontWeight::Value fontWeight,
                                       FontStyle::Value fontStyle,
                                       std::size_t fontPointSize)
:context(new FontContext())
{
  HDC informationDC = ::CreateIC(CharacterEncoder::utf8ToUtf16("DISPLAY").c_str(), NULL, NULL, NULL);

  const int pointsInOneInch = 72;
  int fontLogicalHeight = -::MulDiv(fontPointSize, ::GetDeviceCaps(informationDC, LOGPIXELSY), pointsInOneInch);
  const int fontLogicalAverageWidth = 0; // TODO: Let the user specify the width
  const int escapementAngle = 0; // TODO: Let the user specify the angle
  const int orientationAngle = 0; // TODO: Let the user specify the angle

  context->handle  = ::CreateFont(fontLogicalHeight,
                                  fontLogicalAverageWidth,
                                  escapementAngle,
                                  orientationAngle,
                                  fontWeightEnumToWin32FontWeight(fontWeight),
                                  ((fontStyle & FontStyle::ItalicStyle) == FontStyle::ItalicStyle) ? TRUE: FALSE,
                                  ((fontStyle & FontStyle::UnderlineStyle) == FontStyle::UnderlineStyle) ? TRUE: FALSE,
                                  ((fontStyle & FontStyle::StrikethroughStyle) == FontStyle::StrikethroughStyle) ? TRUE: FALSE,
                                  ANSI_CHARSET, // TODO: Clients need to ensure that this character set matches the typeface
                                  OUT_DEFAULT_PRECIS,
                                  CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, // TODO: Allow the user to control anti-aliasing
                                  DEFAULT_PITCH | FF_SWISS,
                                  CharacterEncoder::utf8ToUtf16(typeface).c_str()); // TODO: This has a max length of 32 characters including the null terminator

  ::DeleteDC(informationDC);
}

WindowsFontPrivate::WindowsFontPrivate(const std::string& typeface,
                                       FontWeight::Value fontWeight,
                                       std::size_t fontPointSize)
:context(new FontContext())
{
  HDC informationDC = ::CreateIC(CharacterEncoder::utf8ToUtf16("DISPLAY").c_str(), NULL, NULL, NULL);

  const int pointsInOneInch = 72;
  int fontLogicalHeight = -::MulDiv(fontPointSize, ::GetDeviceCaps(informationDC, LOGPIXELSY), pointsInOneInch);
  const int fontLogicalAverageWidth = 0; // TODO: Let the user specify the width
  const int escapementAngle = 0; // TODO: Let the user specify the angle
  const int orientationAngle = 0; // TODO: Let the user specify the angle

  context->handle  = ::CreateFont(fontLogicalHeight,
                                  fontLogicalAverageWidth,
                                  escapementAngle,
                                  orientationAngle,
                                  fontWeightEnumToWin32FontWeight(fontWeight),
                                  FALSE,
                                  FALSE,
                                  FALSE,
                                  ANSI_CHARSET, // TODO: Clients need to ensure that this character set matches the typeface
                                  OUT_DEFAULT_PRECIS,
                                  CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, // TODO: Allow the user to control anti-aliasing
                                  DEFAULT_PITCH | FF_SWISS,
                                  CharacterEncoder::utf8ToUtf16(typeface).c_str()); // TODO: This has a max length of 32 characters including the null terminator

  ::DeleteDC(informationDC);
}

WindowsFontPrivate::WindowsFontPrivate(const std::string& typeface,
                                       FontStyle::Value fontStyle,
                                       std::size_t fontPointSize)
:context(new FontContext())
{
  HDC informationDC = ::CreateIC(CharacterEncoder::utf8ToUtf16("DISPLAY").c_str(), NULL, NULL, NULL);

  const int pointsInOneInch = 72;
  int fontLogicalHeight = -::MulDiv(fontPointSize, ::GetDeviceCaps(informationDC, LOGPIXELSY), pointsInOneInch);
  const int fontLogicalAverageWidth = 0; // TODO: Let the user specify the width
  const int escapementAngle = 0; // TODO: Let the user specify the angle
  const int orientationAngle = 0; // TODO: Let the user specify the angle

  context->handle  = ::CreateFont(fontLogicalHeight,
                                  fontLogicalAverageWidth,
                                  escapementAngle,
                                  orientationAngle,
                                  fontWeightEnumToWin32FontWeight(FontWeight::DefaultWeight),
                                  ((fontStyle & FontStyle::ItalicStyle) == FontStyle::ItalicStyle) ? TRUE: FALSE,
                                  ((fontStyle & FontStyle::UnderlineStyle) == FontStyle::UnderlineStyle) ? TRUE: FALSE,
                                  ((fontStyle & FontStyle::StrikethroughStyle) == FontStyle::StrikethroughStyle) ? TRUE: FALSE,
                                  ANSI_CHARSET, // TODO: Clients need to ensure that this character set matches the typeface
                                  OUT_DEFAULT_PRECIS,
                                  CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, // TODO: Allow the user to control anti-aliasing
                                  DEFAULT_PITCH | FF_SWISS,
                                  CharacterEncoder::utf8ToUtf16(typeface).c_str()); // TODO: This has a max length of 32 characters including the null terminator

  ::DeleteDC(informationDC);
}

WindowsFontPrivate::WindowsFontPrivate(const std::string& typeface,
                                       std::size_t fontPointSize)
:context(new FontContext())
{
  HDC informationDC = ::CreateIC(CharacterEncoder::utf8ToUtf16("DISPLAY").c_str(), NULL, NULL, NULL);

  const int pointsInOneInch = 72;
  int fontLogicalHeight = -::MulDiv(fontPointSize, ::GetDeviceCaps(informationDC, LOGPIXELSY), pointsInOneInch);
  const int fontLogicalAverageWidth = 0; // TODO: Let the user specify the width
  const int escapementAngle = 0; // TODO: Let the user specify the angle
  const int orientationAngle = 0; // TODO: Let the user specify the angle

  context->handle  = ::CreateFont(fontLogicalHeight,
                                  fontLogicalAverageWidth,
                                  escapementAngle,
                                  orientationAngle,
                                  fontWeightEnumToWin32FontWeight(FontWeight::DefaultWeight),
                                  FALSE,
                                  FALSE,
                                  FALSE,
                                  ANSI_CHARSET, // TODO: Clients need to ensure that this character set matches the typeface
                                  OUT_DEFAULT_PRECIS,
                                  CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, // TODO: Allow the user to control anti-aliasing
                                  DEFAULT_PITCH | FF_SWISS,
                                  CharacterEncoder::utf8ToUtf16(typeface).c_str()); // TODO: This has a max length of 32 characters including the null terminator

  ::DeleteDC(informationDC);
}

WindowsFontPrivate::~WindowsFontPrivate()
{
  delete context;
  context = NULL;
}

WindowsFont::WindowsFont(const std::string& typeface,
                         FontWeight::Value fontWeight,
                         FontStyle::Value fontStyle,
                         std::size_t fontPointSize)
:Font(),
 d(new WindowsFontPrivate(typeface, fontWeight, fontStyle, fontPointSize))
{

}

WindowsFont::WindowsFont(const std::string& typeface,
                         FontWeight::Value fontWeight,
                         std::size_t fontPointSize)
:Font(),
 d(new WindowsFontPrivate(typeface, fontWeight, fontPointSize))
{

}

WindowsFont::WindowsFont(const std::string& typeface,
                         FontStyle::Value fontStyle,
                         std::size_t fontPointSize)
:Font(),
 d(new WindowsFontPrivate(typeface, fontStyle, fontPointSize))
{

}

WindowsFont::WindowsFont(const std::string& typeface,
                         std::size_t fontPointSize)
:Font(),
 d(new WindowsFontPrivate(typeface, fontPointSize))
{

}

WindowsFont::~WindowsFont()
{

}

std::string WindowsFont::getTypeface() const
{
  if(d->context->handle)
  {
    LOGFONT logFont;
    ::GetObject(d->context->handle, sizeof(LOGFONT), &logFont); // TODO: Check for failure

    return CharacterEncoder::utf16ToUtf8(logFont.lfFaceName);
  }

  return "";
}

FontWeight::Value WindowsFont::getWeight() const
{
  if(d->context->handle)
  {
    LOGFONT logFont;
    ::GetObject(d->context->handle, sizeof(LOGFONT), &logFont); // TODO: Check for failure

    return win32FontWeightToFontWeightEnum(logFont.lfWeight);
  }

  return FontWeight::DefaultWeight;
}

FontStyle::Value WindowsFont::getStyle() const
{
  FontStyle::Value style = FontStyle::DefaultStyle;

  if(d->context->handle)
  {
    LOGFONT logFont;
    ::GetObject(d->context->handle, sizeof(LOGFONT), &logFont); // TODO: Check for failure

    if(logFont.lfItalic)
    {
      style |= FontStyle::ItalicStyle;
    }

    if(logFont.lfStrikeOut)
    {
      style |= FontStyle::StrikethroughStyle;
    }

    if(logFont.lfUnderline)
    {
      style |= FontStyle::UnderlineStyle;
    }
  }

  return style;
}

std::size_t WindowsFont::getPointSize() const
{
  // Formula for point size to logical font height
  // lfHeight = -MulDiv(PointSize, GetDeviceCaps(hDC, LOGPIXELSY), 72);

  // Formula for logical font height to point size
  // PointSize = -MulDiv(lfHeight, 72, GetDeviceCaps(hDC, LOGPIXELSY));

  if(d->context->handle)
  {
    LOGFONT logFont;
    ::GetObject(d->context->handle, sizeof(LOGFONT), &logFont); // TODO: Check for failure

    HDC informationDC = ::CreateIC(CharacterEncoder::utf8ToUtf16("DISPLAY").c_str(), NULL, NULL, NULL);

    const int pointsInOneInch = 72;
    std::size_t fontPointSize = -::MulDiv(logFont.lfHeight, pointsInOneInch, ::GetDeviceCaps(informationDC, LOGPIXELSY));

    ::DeleteDC(informationDC);

    return fontPointSize;
  }

  return 12; // TODO: Going with 12 point size as the default for now
}

bool WindowsFont::isItalic() const
{
  if(d->context->handle)
  {
    LOGFONT logFont;
    ::GetObject(d->context->handle, sizeof(LOGFONT), &logFont); // TODO: Check for failure

    return logFont.lfItalic ? true: false;
  }

  return false;
}

bool WindowsFont::isStrikethrough() const
{
  if(d->context->handle)
  {
    LOGFONT logFont;
    ::GetObject(d->context->handle, sizeof(LOGFONT), &logFont); // TODO: Check for failure

    return logFont.lfStrikeOut ? true: false;
  }

  return false;
}

bool WindowsFont::isUnderlined() const
{
  if(d->context->handle)
  {
    LOGFONT logFont;
    ::GetObject(d->context->handle, sizeof(LOGFONT), &logFont); // TODO: Check for failure

    return logFont.lfUnderline ? true: false;
  }

  return false;
}

FontContext * WindowsFont::getContext() const
{
  return d->context;
}
