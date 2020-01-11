////////////////////////////////////////////////////////////////////////////////
//
// File: FontContext.h
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_FONTCONTEXT_H_
#define GRAPHICS_PRIVATE_WINDOWS_FONTCONTEXT_H_

#include <windows.h>

class FontContext
{
  public:

    FontContext();
    ~FontContext();

    HFONT handle;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_FONTCONTEXT_H_ */
