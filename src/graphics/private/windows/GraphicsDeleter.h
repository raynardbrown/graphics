////////////////////////////////////////////////////////////////////////////////
//
// File: GraphicsDeleter.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_WINDOWS_GRAPHICSDELETER_H_
#define GRAPHICS_PRIVATE_WINDOWS_GRAPHICSDELETER_H_

struct GraphicsDeleter
{
    template<typename T>
    void operator()(T * graphics) const
    {
      graphics->release();

      delete graphics;
    }
};
#endif /* GRAPHICS_PRIVATE_WINDOWS_GRAPHICSDELETER_H_ */
