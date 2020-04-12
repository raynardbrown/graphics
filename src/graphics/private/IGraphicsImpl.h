////////////////////////////////////////////////////////////////////////////////
//
// File: IGraphicsImpl.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_IGRAPHICSIMPL_H_
#define GRAPHICS_PRIVATE_IGRAPHICSIMPL_H_

class Color;

class IGraphicsImpl
{
  protected:

    IGraphicsImpl()
    {

    }

  public:

    virtual ~IGraphicsImpl()
    {

    }

    virtual void setBackgroundColor(const Color * backgroundColor) = 0;
};
#endif /* GRAPHICS_PRIVATE_IGRAPHICSIMPL_H_ */
