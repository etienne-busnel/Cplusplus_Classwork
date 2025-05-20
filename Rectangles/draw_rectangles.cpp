#include <iostream>

// TODO: include the rectangle class header file
#include "rectangle.h"

int main() 
{
    using std::cout;
    using std::endl;
    // Declare 2 rectangles
    rectangle r1, r2;

    // Draw the unit rectangle
    cout << "unit rectangle" << endl;
    r1.draw();

    // Set, print dimensions and draw
    r1.set(4, 3);
    cout << "r1 is " << r1.getHeight() << " x " << r1.getWidth() << endl;
    r1.draw();

    // Assign, increment, print dimensions and draw
    r2 = r1;
    r2.add(3, 4);
    cout << "r2 is " << r2.getHeight() << " x " << r2.getWidth() << endl;
    r2.draw();

    if (r2.isSquare())
        cout << "r2 is a square" << endl;
    else
        cout << "r2 is not a square" << endl;
    return 0;
}


