////////////////////////////////////////////////////////////////////////////////
//
// File: Point2D.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_POINT_H_
#define GRAPHICS_POINT_H_

/**
 * Point in a two-dimensional coordinate system.
 */
class Point2D
{
  public:

    /**
     * Create a new <code>Point2D</code> with the x and y coordinates set to 0.
     */
    Point2D();

    /**
     * Create a new <code>Point2D</code> with the specified coordinates.
     *
     * @param[in] x the x coordinate of this <code>Point2D</code>.
     *
     * @param[in] y the y coordinate of this <code>Point2D</code>.
     */
    Point2D(int x, int y);

    /**
     * Create a new <code>Point2D</code> by copying the coordinates from the
     * specified point. If the specified <code>Point2D</code> is
     * <code>nullptr</code> then this <code>Point2D</code> will have its x and y
     * coordinates set to 0.
     *
     * @param[in] p the <code>Point2D</code> that this <code>Point</code> will
     * copy from.
     */
    Point2D(const Point2D * p);

    /**
     * Destructor
     */
    ~Point2D();

    /**
     * Returns the x coordinate of this <code>Point2D</code>.
     *
     * @return the x coordinate of this <code>Point2D</code>.
     */
    int getX() const;

    /**
     * Returns the y coordinate of this <code>Point2D</code>.
     *
     * @return the y coordinate of this <code>Point2D</code>.
     */
    int getY() const;

    /**
     * Changes the location of this <code>Point2D</code> to the specified
     * location.
     *
     * @param[in] x the new x coordinate of this <code>Point2D</code>.
     *
     * @param[in] y the new y coordinate of this <code>Point2D</code>.
     */
    void setLocation(int x, int y);

    /**
     * Changes the location of this <code>Point2D</code> to the specified
     * location. If the specified <code>Point2D</code> is <code>nullptr</code>
     * then this <code>Point2D</code> will have its x and y coordinates set to
     * 0.
     *
     * @param[in] p the new location of this <code>Point2D</code>.
     */
    void setLocation(const Point2D * p);

  private:

    int x;
    int y;
};
#endif /* GRAPHICS_POINT_H_ */
