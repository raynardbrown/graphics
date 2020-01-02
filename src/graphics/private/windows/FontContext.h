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

#ifndef FONTCONTEXT_H_
#define FONTCONTEXT_H_

#include <windows.h>

class FontContext
{
  public:

    FontContext();
    ~FontContext();

    HFONT handle;
};
#endif /* FONTCONTEXT_H_ */
