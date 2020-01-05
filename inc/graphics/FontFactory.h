////////////////////////////////////////////////////////////////////////////////
//
// File: FontFactory.h
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_FONTFACTORY_H_
#define GRAPHICS_FONTFACTORY_H_

#include <memory>

#include <boost/shared_ptr.hpp>

#include "graphics/FontStyle.h"
#include "graphics/FontWeight.h"

class Font;
class FontFactoryPrivate;

class FontFactory
{
  public:

    FontFactory();

    ~FontFactory();

    static std::auto_ptr<Font> createFont(const std::string& typeface,
                                          FontWeight::Value fontWeight,
                                          FontStyle::Value fontStyle,
                                          std::size_t fontPointSize);

    static std::auto_ptr<Font> createFont(const std::string& typeface,
                                          FontWeight::Value fontWeight,
                                          std::size_t fontPointSize);

    static std::auto_ptr<Font> createFont(const std::string& typeface,
                                          FontStyle::Value fontStyle,
                                          std::size_t fontPointSize);

    static std::auto_ptr<Font> createFont(const std::string& typeface,
                                          std::size_t fontPointSize);

    boost::shared_ptr<Font> createSharedFont(const std::string& typeface,
                                             FontWeight::Value fontWeight,
                                             FontStyle::Value fontStyle,
                                             std::size_t fontPointSize);

    boost::shared_ptr<Font> createSharedFont(const std::string& typeface,
                                             FontWeight::Value fontWeight,
                                             std::size_t fontPointSize);

    boost::shared_ptr<Font> createSharedFont(const std::string& typeface,
                                             FontStyle::Value fontStyle,
                                             std::size_t fontPointSize);

    boost::shared_ptr<Font> createSharedFont(const std::string& typeface,
                                             std::size_t fontPointSize);

  private:

    std::auto_ptr<FontFactoryPrivate> d;
};
#endif /* GRAPHICS_FONTFACTORY_H_ */
