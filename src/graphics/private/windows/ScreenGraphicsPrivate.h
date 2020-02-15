////////////////////////////////////////////////////////////////////////////////
//
// File: ScreenGraphicsPrivate.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_SCREENGRAPHICSPRIVATE_H_
#define GRAPHICS_PRIVATE_WINDOWS_SCREENGRAPHICSPRIVATE_H_

#include "graphics/private/windows/Win32GraphicsPrivate.h"

class ScreenGraphicsPrivate : public Win32GraphicsPrivate
{
  public:

    ScreenGraphicsPrivate();

    virtual ~ScreenGraphicsPrivate();
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_SCREENGRAPHICSPRIVATE_H_ */
