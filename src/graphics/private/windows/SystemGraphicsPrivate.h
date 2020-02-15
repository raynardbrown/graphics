////////////////////////////////////////////////////////////////////////////////
//
// File: SystemGraphicsPrivate.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_SYSTEMGRAPHICSPRIVATE_H_
#define GRAPHICS_PRIVATE_WINDOWS_SYSTEMGRAPHICSPRIVATE_H_

#include "graphics/private/windows/Win32GraphicsPrivate.h"

class SystemGraphicsPrivate : public Win32GraphicsPrivate
{
  public:
  
    SystemGraphicsPrivate(IDrawable * drawable);
    
    SystemGraphicsPrivate(IDrawable * drawable, HDC hdc);
    
    virtual ~SystemGraphicsPrivate();

    // The client supplied the HDC. The client is responsible for the HDC.
    bool clientHandle;
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_SYSTEMGRAPHICSPRIVATE_H_ */
