////////////////////////////////////////////////////////////////////////////////
//
// File: Size2D.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_SIZE2D_H_
#define GRAPHICS_SIZE2D_H_

/**
 * <code>Size2D</code> models the size of 2D shapes.
 */
class Size2D
{
  public:

    /**
     * Create a new <code>Size2D</code> with the specified width and height.
     *
     * @param[in] width the width of this <code>Size2D</code>.
     *
     * @param[in] height the height of this <code>Size2D</code>.
     */
    Size2D(int width, int height);

    /**
     * Creates a new <code>Size2D</code> with the width and height of the
     * specified <code>Size2D</code>. If the specified <code>Size2D</code> is
     * <code>nullptr</code> then this <code>Size2D</code> has a width and height
     * equal to 0.
     *
     * @param[in] size2D the new size of this <code>Size2D</code>.
     */
    Size2D(const Size2D * size2D);

    /**
     * Destructor
     */
    ~Size2D();

    /**
     * Return the width of this <code>Size2D</code>.
     *
     * @return the width of this <code>Size2D</code>.
     */
    int getWidth() const;

    /**
     * Return the height of this <code>Size2D</code>.
     *
     * @return the height of this <code>Size2D</code>.
     */
    int getHeight() const;

    /**
     * Sets this <code>Size2D</code> to the specified width and height.
     *
     * @param[in] width the new width of this <code>Size2D</code>.
     *
     * @param[in] height the new height of this <code>Size2D</code>.
     */
    void setSize(int width, int height);

    /**
     * Sets the size of this <code>Size2D</code> to a new size specified by
     * given <code>Size2D</code>. If the specified <code>Size2D</code> is
     * nullptr then the width and height of this <code>Size2D</code> are 0.
     *
     * @param[in] size2D the new size of this <code>Size2D</code>.
     */
    void setSize(const Size2D * size2D);

  private:

    int width;
    int height;
};
#endif /* GRAPHICS_SIZE2D_H_ */
