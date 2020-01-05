////////////////////////////////////////////////////////////////////////////////
//
// File: Rectangle2D.cpp
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "graphics/Point2D.h"
#include "graphics/Size2D.h"

#include "graphics/Rectangle2D.h"

Rectangle2D::Rectangle2D()
:point(new Point2D(0, 0)),
 size2D(new Size2D(0, 0))
{
}

Rectangle2D::Rectangle2D(int x, int y, int width, int height)
:point(new Point2D(x, y)),
 size2D(new Size2D(width, height))
{
}

Rectangle2D::Rectangle2D(int width, int height)
:point(new Point2D(0, 0)),
 size2D(new Size2D(width, height))
{
}

Rectangle2D::Rectangle2D(const Size2D * size2D)
:point(new Point2D(0, 0)),
 size2D(new Size2D(0, 0))
{
  if(size2D)
  {
    this->size2D->setSize(size2D->getWidth(), size2D->getHeight());
  }
}

Rectangle2D::Rectangle2D(const Point2D * p)
:point(new Point2D(0, 0)),
 size2D(new Size2D(0, 0))
{
  if(p)
  {
    point->setLocation(p->getX(), p->getY());
  }
}

Rectangle2D::Rectangle2D(const Point2D * p, const Size2D * size2D)
:point(new Point2D(0, 0)),
 size2D(new Size2D(0, 0))
{
  if(p)
  {
    point->setLocation(p->getX(), p->getY());
  }

  if(size2D)
  {
    this->size2D->setSize(size2D->getWidth(), size2D->getHeight());
  }
}

Rectangle2D::Rectangle2D(const Rectangle2D * rec)
:point(new Point2D(0, 0)),
 size2D(new Size2D(0, 0))
{
  if(rec)
  {
    this->point->setLocation(rec->getX(), rec->getY());
    this->size2D->setSize(rec->getWidth(), rec->getHeight());
  }
}

Rectangle2D::~Rectangle2D()
{
}

int Rectangle2D::getX() const
{
  return point->getX();
}

int Rectangle2D::getY() const
{
  return point->getY();
}

int Rectangle2D::getWidth() const
{
  return size2D->getWidth();
}

int Rectangle2D::getHeight() const
{
  return size2D->getHeight();
}

const Size2D * Rectangle2D::getSize() const
{
  return size2D.get();
}

const Point2D * Rectangle2D::getLocation() const
{
  return point.get();
}

void Rectangle2D::setLocation(int x, int y)
{
  point->setLocation(x, y);
}

void Rectangle2D::setLocation(const Point2D * p)
{
  if(p)
  {
    point->setLocation(p);
  }
  else
  {
    point->setLocation(0, 0);
  }
}

void Rectangle2D::setSize(int width, int height)
{
  size2D->setSize(width, height);
}

void Rectangle2D::setSize(const Size2D * size2D)
{
  if(size2D)
  {
    this->size2D->setSize(size2D);
  }
  else
  {
    this->size2D->setSize(0, 0);
  }
}

void Rectangle2D::setBounds(int x, int y, int width, int height)
{
  point->setLocation(x, y);
  size2D->setSize(width, height);
}

void Rectangle2D::setBounds(const Rectangle2D * rec)
{
  if(rec)
  {
    point->setLocation(rec->getLocation());
    size2D->setSize(rec->getSize());
  }
  else
  {
    point->setLocation(0, 0);
    size2D->setSize(0, 0);
  }
}
