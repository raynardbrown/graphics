////////////////////////////////////////////////////////////////////////////////
//
// File: WindowsFontPrivate.h
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_WINDOWSFONTPRIVATE_H_
#define GRAPHICS_PRIVATE_WINDOWS_WINDOWSFONTPRIVATE_H_

#include <string>

#include "graphics/Font.h"

class FontContext;

class WindowsFontPrivate
{
  public:

    WindowsFontPrivate(const std::string& typeface,
                       FontWeight::Value fontWeight,
                       FontStyle::Value fontStyle,
                       std::size_t fontPointSize);

    WindowsFontPrivate(const std::string& typeface,
                       FontWeight::Value fontWeight,
                       std::size_t fontPointSize);

    WindowsFontPrivate(const std::string& typeface,
                       FontStyle::Value fontStyle,
                       std::size_t fontPointSize);

    WindowsFontPrivate(const std::string& typeface,
                       std::size_t fontPointSize);

    ~WindowsFontPrivate();

    FontContext * context;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_WINDOWSFONTPRIVATE_H_ */
