////////////////////////////////////////////////////////////////////////////////
//
// File: IDrawable.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_IDRAWABLE_H_
#define GRAPHICS_IDRAWABLE_H_

class IDrawableSurface;

class IDrawable
{
  protected:

    IDrawable()
    {

    }

  public:

    virtual ~IDrawable()
    {

    }

    virtual IDrawableSurface * getDrawableSurface() const = 0;
};
#endif /* GRAPHICS_IDRAWABLE_H_ */
