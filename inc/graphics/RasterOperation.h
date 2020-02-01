////////////////////////////////////////////////////////////////////////////////
//
// File: RasterOperation.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_RASTEROPERATION_H_
#define GRAPHICS_RASTEROPERATION_H_

struct RasterOperation
{
  public:

    enum Value
    {
      SourceCopyRasterOperation /**< Copy the source rectangle directly into the destination rectangle. */
    };
};
#endif /* GRAPHICS_RASTEROPERATION_H_ */
