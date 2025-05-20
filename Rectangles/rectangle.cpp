#include <iostream>

// TODO: Remember to include the header file for the rectangle class.
#include "rectangle.h"

// TODO: implement a default constructor 
// sets height and width to the unit rectangle which is
// a square 1x1 size.
rectangle::rectangle() {
        height = 1;
        width = 1;
    }


// TODO: Implement add member function
// @param int addHeight, int addWidth
// to addHeight to height and add addWidth to width
void rectangle::add(int addHeight, int addWidth)
{
    height += addHeight;
    width += addWidth;

    return;
}

// TODO: implement member function void set that assigns
// new_height to height and new_width to width
// @param int new_height, int new_width
void rectangle::set(int newHeight, int newWidth)
{
    height = newHeight;
    width = newWidth;

    return;
}

// TODO: declare member function void draw that uses
// uses the height in an outer loop and the width in an
// inner loop to draw the rectangle with '#' characters.
void rectangle::draw()
{
    for (int i=0; i<width; i++) {
        for (int j=0; j<height; j++) {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return; 
}

// TODO: Also define functions for getWidth and getHeight

// TODO: and a function that indicates if the rectangle is square or not

    int rectangle::getWidth( ) {
        return width;
    }

    int rectangle::getHeight( ) {
        return height;
    }

    bool rectangle::isSquare( ) {
        if (getWidth() == getHeight()) {
            return true;
        }
        else {
            return false;
        }
    }
