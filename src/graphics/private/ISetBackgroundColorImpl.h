////////////////////////////////////////////////////////////////////////////////
//
// File: ISetBackgroundColorImpl.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_PRIVATE_ISETBACKGROUNDCOLORIMPL_H_
#define GRAPHICS_PRIVATE_ISETBACKGROUNDCOLORIMPL_H_

class Color;

class ISetBackgroundColorImpl
{
  protected:

    ISetBackgroundColorImpl()
    {

    }

  public:

    virtual ~ISetBackgroundColorImpl()
    {

    }

    virtual void setBackgroundColor(const Color * backgroundColor) = 0;
};
#endif /* GRAPHICS_PRIVATE_ISETBACKGROUNDCOLORIMPL_H_ */
