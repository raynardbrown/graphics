////////////////////////////////////////////////////////////////////////////////
//
// File: Point2D.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/Point2D.h"

Point2D::Point2D()
:x(0),
 y(0)
{
}

Point2D::Point2D(int x, int y)
:x(x),
 y(y)
{
}

Point2D::Point2D(const Point2D * point)
{
  if(point)
  {
    this->x = point->getX();
    this->y = point->getY();
  }
  else
  {
    this->x = 0;
    this->y = 0;
  }
}

Point2D::~Point2D()
{
}

int Point2D::getX() const
{
  return this->x;
}

int Point2D::getY() const
{
  return this->y;
}

void Point2D::setLocation(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Point2D::setLocation(const Point2D * point)
{
  if(point)
  {
    this->x = point->getX();
    this->y = point->getY();
  }
  else
  {
    this->x = 0;
    this->y = 0;
  }
}
