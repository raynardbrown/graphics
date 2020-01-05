////////////////////////////////////////////////////////////////////////////////
//
// File: Rectangle2D.h
//
// Author: Raynard Brown
//
// Copyright (c) 2020 Raynard Brown
//
// All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_RECTANGLE2D_H_
#define GRAPHICS_RECTANGLE2D_H_

#include <memory>

class Point2D;
class Size2D;

/**
 * A two-dimensional rectangle shape.
 */
class Rectangle2D
{
  public:

    /**
     * Create a new <code>Rectangle2D</code> with the coordinates and the size
     * equal to 0.
     */
    Rectangle2D();

    /**
     * Create a new <code>Rectangle2D</code> with the specified coordinates and
     * size.
     *
     * @param[in] x the x coordinate of this <code>Rectangle2D</code>.
     *
     * @param[in] y the y coordinate of this <code>Rectangle2D</code>.
     *
     * @param[in] width the width of this <code>Rectangle2D</code>.
     *
     * @param[in] height the height of this <code>Rectangle2D</code>.
     */
    Rectangle2D(int x, int y, int width, int height);

    /**
     * Create a new <code>Rectangle2D</code> with the specified width, height,
     * and size equal to 0.
     *
     * @param[in] width the width of this <code>Rectangle2D</code>.
     *
     * @param[in] height the height of this <code>Rectangle2D</code>.
     */
    Rectangle2D(int width, int height);

    /**
     * Create a new <code>Rectangle2D</code> with the specified size, and with
     * the x and y coordinates equal to 0. If the specified <code>Size2D</code>
     * is <code>nullptr</code> then this <code>Rectangle2D</code> has a width
     * and height that is equal to 0.
     *
     * @param[in] size2D the size of this <code>Rectangle2D</code>.
     */
    Rectangle2D(const Size2D * size2D);

    /**
     * Create a new <code>Rectangle2D</code> with the specified location, and
     * size equal to 0. If the specified <code>Point2D</code> is
     * <code>nullptr</code> then this <code>Rectangle2D</code> has a x and y
     * coordinate that is equal to 0.
     *
     * @param[in] p the location of this <code>Rectangle2D</code>.
     */
    Rectangle2D(const Point2D * p);

    /**
     * Create a new <code>Rectangle2D</code> with the specified location and
     * size. If the specified <code>Point2D</code> is <code>nullptr</code> then
     * this <code>Rectangle2D</code> has a x and y coordinate that is equal to
     * 0. If the specified <code>Size2D</code> is <code>nullptr</code> then this
     * <code>Rectangle2D</code> has a width and height that is equal to 0.
     *
     * @param[in] p the location of this <code>Rectangle2D</code>.
     *
     * @param[in] size2D the size of this <code>Rectangle2D</code>.
     */
    Rectangle2D(const Point2D * p, const Size2D * size2D);

    /**
     * Create a new <code>Rectangle2D</code> that is a copy of the specified
     * <code>Rectangle2D</code>. If the specified <code>Rectangle2D</code> is
     * <code>nullptr</code> then this call is equivalent to
     * {@link Rectangle2D#Rectangle2D() <code>Rectangle2D()</code>}.
     *
     * @param[in] rec the <code>Rectangle2D</code> that this
     * <code>Rectangle2D</code> will copy.
     */
    Rectangle2D(const Rectangle2D * rec);

    /**
     * Destructor
     */
    ~Rectangle2D();

    /**
     * Returns the x coordinate of this <code>Rectangle2D</code>.
     *
     * @return the x coordinate of this <code>Rectangle2D</code>.
     */
    int getX() const;

    /**
     * Returns the y coordinate of this <code>Rectangle2D</code>.
     *
     * @return the y coordinate of this <code>Rectangle2D</code>.
     */
    int getY() const;

    /**
     * Returns the width of this <code>Rectangle2D</code>.
     *
     * @return the width of this <code>Rectangle2D</code>.
     */
    int getWidth() const;

    /**
     * Returns the height of this <code>Rectangle2D</code>.
     *
     * @return the height of this <code>Rectangle2D</code>.
     */
    int getHeight() const;

    /**
     * Returns the size of this <code>Rectangle2D</code>.
     *
     * @return the size of this <code>Rectangle2D</code>.
     */
    const Size2D * getSize() const;

    /**
     * Returns the location of this <code>Rectangle2D</code>.
     *
     * @return the location of this <code>Rectangle2D</code>.
     */
    const Point2D * getLocation() const;

    /**
     * Changes the location of this <code>Rectangle2D</code> to the specified
     * location.
     *
     * @param[in] x the new x coordinate of this <code>Rectangle2D</code>.
     *
     * @param[in] y the new y coordinate of this <code>Rectangle2D</code>.
     */
    void setLocation(int x, int y);

    /**
     * Changes the location of this <code>Rectangle2D</code> to the specified
     * location. If the specified <code>Point2D</code> is <code>nullptr</code>
     * then this <code>Rectangle2D</code> has x and y coordinates that are equal
     * to 0.
     *
     * @param[in] p the new location of this <code>Rectangle2D</code>.
     */
    void setLocation(const Point2D * p);

    /**
     * Changes the size of this <code>Rectangle2D</code> to the specified size.
     *
     * @param[in] width the new width of this <code>Rectangle2D</code>.
     *
     * @param[in] height the new height of this <code>Rectangle2D</code>.
     */
    void setSize(int width, int height);

    /**
     * Changes the size of this <code>Rectangle2D</code> to the specified size.
     * If the specified <code>Size2D</code> is <code>nullptr</code> then this
     * <code>Rectangle2D</code> has a width and height that is equal to 0.
     *
     * @param[in] size2D the new size of this <code>Rectangle2D</code>.
     */
    void setSize(const Size2D * size2D);

    /**
     * Changes the bounding area of this <code>Rectangle2D</code> to the
     * specified bounds. If the specified <code>Rectangle2D</code> is
     * <code>nullptr</code> then this <code>Rectangle2D</code> has x and y
     * coordinates that are equal to 0 and a width and height that are equal to
     * 0.
     *
     * @param[in] rec the new boundary that will enclose this
     * <code>Rectangle2D</code>.
     */
    void setBounds(const Rectangle2D * rec);

    /**
     * Changes the  bounding area of this <code>Rectangle2D</code> to
     * the specified bounds.
     *
     * @param[in] x the new x coordinate of this <code>Rectangle2D</code>.
     *
     * @param[in] y the new y coordinate of this <code>Rectangle2D</code>.
     *
     * @param[in] width the new width of this <code>Rectangle2D</code>.
     *
     * @param[in] height the new height of this <code>Rectangle2D</code>.
     */
    void setBounds(int x, int y, int width, int height);

  private:

    std::auto_ptr<Point2D> point;
    std::auto_ptr<Size2D> size2D;
};
#endif /* GRAPHICS_RECTANGLE2D_H_ */
