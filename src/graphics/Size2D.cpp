////////////////////////////////////////////////////////////////////////////////
//
// File: Size2D.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/Size2D.h"

Size2D::Size2D(int width, int height)
:width(width),
 height(height)
{
}

Size2D::Size2D(const Size2D * size2D)
:width(0),
 height(0)
{
  if(size2D)
  {
    width = size2D->getWidth();
    height = size2D->getHeight();
  }
}

Size2D::~Size2D()
{
}

int Size2D::getWidth() const
{
  return this->width;
}

int Size2D::getHeight() const
{
  return this->height;
}

void Size2D::setSize(int width, int height)
{
  this->width = width;
  this->height = height;
}

void Size2D::setSize(const Size2D * size2D)
{
  if(size2D)
  {
    this->width = size2D->getWidth();
    this->height = size2D->getHeight();
  }
  else
  {
    this->width = 0;
    this->height = 0;
  }
}
