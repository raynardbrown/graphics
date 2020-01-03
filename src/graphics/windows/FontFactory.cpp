////////////////////////////////////////////////////////////////////////////////
//
// File: FontFactory.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include <vector>

#include "graphics/private/windows/WindowsFont.h"

#include "graphics/FontFactory.h"

class FontFactoryPrivate
{
  public:

    FontFactoryPrivate()
    {

    }

    ~FontFactoryPrivate()
    {
      sharedFonts.clear();
    }

    std::vector<boost::shared_ptr<Font> > sharedFonts;
};

FontFactory::FontFactory()
:d(new FontFactoryPrivate())
{
}

FontFactory::~FontFactory()
{
}

/* static */ std::auto_ptr<Font> FontFactory::createFont(const std::string& typeface,
                                                         FontWeight::Value fontWeight,
                                                         FontStyle::Value fontStyle,
                                                         std::size_t fontPointSize)
{
  return std::auto_ptr<Font>(new WindowsFont(typeface, fontWeight, fontStyle, fontPointSize));
}

/* static */ std::auto_ptr<Font> FontFactory::createFont(const std::string& typeface,
                                                         FontWeight::Value fontWeight,
                                                         std::size_t fontPointSize)
{
  return std::auto_ptr<Font>(new WindowsFont(typeface, fontWeight, fontPointSize));
}

/* static */ std::auto_ptr<Font> FontFactory::createFont(const std::string& typeface,
                                                         FontStyle::Value fontStyle,
                                                         std::size_t fontPointSize)
{
  return std::auto_ptr<Font>(new WindowsFont(typeface, fontStyle, fontPointSize));
}

/* static */ std::auto_ptr<Font> FontFactory::createFont(const std::string& typeface,
                                                         std::size_t fontPointSize)
{
  return std::auto_ptr<Font>(new WindowsFont(typeface, fontPointSize));
}

boost::shared_ptr<Font> FontFactory::createSharedFont(const std::string& typeface,
                                                      FontWeight::Value fontWeight,
                                                      FontStyle::Value fontStyle,
                                                      std::size_t fontPointSize)
{
  for(std::size_t i = 0; i < d->sharedFonts.size(); ++i)
  {
    boost::shared_ptr<Font> font = d->sharedFonts.at(i);

    if(font->getTypeface() == typeface &&
       font->getWeight() == fontWeight &&
       font->getStyle() == fontStyle &&
       font->getPointSize() == fontPointSize)
    {
      // return an existing font
      return font;
    }
  }

  // Font not found we need to create one, and add it to our collection for reuse
  std::auto_ptr<Font> font(FontFactory::createFont(typeface, fontWeight, fontStyle, fontPointSize));

  boost::shared_ptr<Font> sharedFont(font);

  d->sharedFonts.push_back(sharedFont);

  return sharedFont;
}

boost::shared_ptr<Font> FontFactory::createSharedFont(const std::string& typeface,
                                                      FontWeight::Value fontWeight,
                                                      std::size_t fontPointSize)
{
  for(std::size_t i = 0; i < d->sharedFonts.size(); ++i)
  {
    boost::shared_ptr<Font> font = d->sharedFonts.at(i);

    if(font->getTypeface() == typeface &&
       font->getWeight() == fontWeight &&
       font->getStyle() == FontStyle::DefaultStyle &&
       font->getPointSize() == fontPointSize)
    {
      // return an existing font
      return font;
    }
  }

  std::auto_ptr<Font> font(FontFactory::createFont(typeface, fontWeight, fontPointSize));

  boost::shared_ptr<Font> sharedFont(font);

  d->sharedFonts.push_back(sharedFont);

  return sharedFont;
}

boost::shared_ptr<Font> FontFactory::createSharedFont(const std::string& typeface,
                                                      FontStyle::Value fontStyle,
                                                      std::size_t fontPointSize)
{
  for(std::size_t i = 0; i < d->sharedFonts.size(); ++i)
  {
    boost::shared_ptr<Font> font = d->sharedFonts.at(i);

    if(font->getTypeface() == typeface &&
       font->getWeight() == FontWeight::DefaultWeight &&
       font->getStyle() == fontStyle &&
       font->getPointSize() == fontPointSize)
    {
      // return an existing font
      return font;
    }
  }

  std::auto_ptr<Font> font(FontFactory::createFont(typeface, fontStyle, fontPointSize));

  boost::shared_ptr<Font> sharedFont(font);

  d->sharedFonts.push_back(sharedFont);

  return sharedFont;
}

boost::shared_ptr<Font> FontFactory::createSharedFont(const std::string& typeface,
                                                      std::size_t fontPointSize)
{
  for(std::size_t i = 0; i < d->sharedFonts.size(); ++i)
  {
    boost::shared_ptr<Font> font = d->sharedFonts.at(i);

    if(font->getTypeface() == typeface &&
        font->getWeight() == FontWeight::DefaultWeight &&
        font->getStyle() == FontStyle::DefaultStyle &&
        font->getPointSize() == fontPointSize)
    {
      // return an existing font
      return font;
    }
  }

  std::auto_ptr<Font> font(FontFactory::createFont(typeface, fontPointSize));

  boost::shared_ptr<Font> sharedFont(font);

  d->sharedFonts.push_back(sharedFont);

  return sharedFont;
}
