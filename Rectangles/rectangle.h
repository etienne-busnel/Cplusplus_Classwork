#include <iostream>

// rectangle has a vertical height and horizontal width
// The class below is a rectangle. It has two private
// data members: height and width.
// TODO: Complete the class declaration and definition.

class rectangle {
  public:
    // TODO: declare a default constructor 
    // sets height and width to the unit rectangle which is a square 1x1 size.
    rectangle();

    // TODO: declare member function add
    // add the supplied value for height to the height of the rectangle and
    // the supplied value for width to the width
    // @param int addHeight, int addWidth
    // @returns void

    void add(int addHeight, int addWidth);

    // TODO: delcare member function set
    // set the height to new_height and width to new_width
    // @param int newHeight, int newWidth
    // @returns void
    void set(int new_height, int new_width);

    // TODO: declare member function draw
    // uses height as the vertical dimension (outer loop) and width as the
    // horizontal dimension (inner loop) to draw the rectangle with '#'
    // characters.
    // @return void
    void draw( );

    // TODO: define an accessor function for width
    int getWidth( );

    // TODO: define an accessor function for height
    int getHeight( );

    // TODO: declare a function that determines if a
    // rectangle is a square
    // @returns bool
    bool isSquare( );

  
  private:
    int height;
    int width;
};

