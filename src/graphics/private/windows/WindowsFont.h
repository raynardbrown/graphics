////////////////////////////////////////////////////////////////////////////////
//
// File: WindowsFont.h
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef WINDOWSFONT_H_
#define WINDOWSFONT_H_

#include <memory>
#include <string>

#include "graphics/Font.h"

class FontContext;
class WindowsFontPrivate;

class WindowsFont : public Font
{
  public:

    /**
     * Create a new WindowsFont with the specified typeface, weight, style and
     * size.
     *
     * @param[in] typeface
     *
     * @param[in] fontWeight
     *
     * @param[in] fontStyle
     *
     * @param[in] fontPointSize
     */
    WindowsFont(const std::string& typeface,
                FontWeight::Value fontWeight,
                FontStyle::Value fontStyle,
                std::size_t fontPointSize);

    WindowsFont(const std::string& typeface,
                FontWeight::Value fontWeight,
                std::size_t fontPointSize);

    WindowsFont(const std::string& typeface,
                FontStyle::Value fontStyle,
                std::size_t fontPointSize);

    WindowsFont(const std::string& typeface,
                std::size_t fontPointSize);

    virtual ~WindowsFont();

    virtual std::string getTypeface() const;

    virtual FontWeight::Value getWeight() const;

    virtual FontStyle::Value getStyle() const;

    virtual std::size_t getPointSize() const;

    /**
     * Checks whether this WindowsFont has an italic style.
     *
     * @return true if this WindowsFont has an italic style.
     */
    virtual bool isItalic() const;

    virtual bool isStrikethrough() const;

    virtual bool isUnderlined() const;

    virtual FontContext * getContext() const;

  private:

    std::auto_ptr<WindowsFontPrivate> d;
};
#endif /* WINDOWSFONT_H_ */
