////////////////////////////////////////////////////////////////////////////////
//
// File: GraphicsFactory.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_GRAPHICSFACTORY_H_
#define GRAPHICS_GRAPHICSFACTORY_H_

#include <boost/shared_ptr.hpp>

class Graphics;
class IDrawable;

class GraphicsFactory
{
  private:

    GraphicsFactory();

  public:

    ~GraphicsFactory();

    static boost::shared_ptr<Graphics> getScreenGraphics();

    static boost::shared_ptr<Graphics> getGraphics(IDrawable * drawable);
};
#endif /* GRAPHICS_GRAPHICSFACTORY_H_ */
