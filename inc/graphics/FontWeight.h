////////////////////////////////////////////////////////////////////////////////
//
// File: FontWeight.h
//
// Author: Raynard Brown
//
// Copyright (c) 2019 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef FONTWEIGHT_H_
#define FONTWEIGHT_H_

/**
 * The weight of a font in pixels.
 */
struct FontWeight
{
  public:

    enum Value
    {
      ThinWeight,
      ExtraLightWeight,
      LightWeight,
      NormalWeight,
      MediumWeight,
      SemiboldWeight,
      BoldWeight,
      ExtraBoldWeight,
      HeavyWeight,
      DefaultWeight
    };
};
#endif /* FONTWEIGHT_H_ */
