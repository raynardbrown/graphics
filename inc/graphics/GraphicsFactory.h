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

#include <memory>

class Graphics;

class GraphicsFactory
{
  private:

    GraphicsFactory()
    {

    }

  public:

    ~GraphicsFactory()
    {

    }

    static std::auto_ptr<Graphics> getScreenGraphics();
};
#endif /* GRAPHICS_GRAPHICSFACTORY_H_ */
