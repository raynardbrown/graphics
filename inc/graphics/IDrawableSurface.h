////////////////////////////////////////////////////////////////////////////////
//
// File: IDrawableSurface.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_IDRAWABLESURFACE_H_
#define GRAPHICS_IDRAWABLESURFACE_H_

struct DrawableSurfaceContext;

class IDrawableSurface
{
  protected:

    IDrawableSurface()
    {

    }

  public:

    virtual ~IDrawableSurface()
    {

    }

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    virtual DrawableSurfaceContext * getDrawableSurfaceContext() const = 0;
};
#endif /* GRAPHICS_IDRAWABLESURFACE_H_ */
