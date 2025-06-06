#include <iostream>
#include <fstream>


// readMagicSquareValues() - reads the contents of the supplied file object
// which are assumed to be a nXn array of numbers. The function returns a
// MagicSquare struct with the contents of the file loaded into the
// magicSquare.square member variable and the magicSquare.order variable set to
// the dimension of the array that has been read.
// Parameters:
//   ifstream inFile - the file object to read from
//   int order - the dimension of the magic square array to be read
// Returns:
//   a MagicSquare struct
struct MagicSquare readMagicSquareValues(std::ifstream& inFile, int order);

// validateMagicSquare() - validates the supplied MagicSquare struct to confirm
// that is satisfies the properties of a Magic Square.
// Parameters:
//   struct MagicSquare magicSquare - the magic square values to be validated
// Returns:
//   true if the magic square is correct; false otherwise
bool validateMagicSquare(struct MagicSquare &magicSquare);

// MagicSquare structure to store a 2-dimensional array and its dimension
struct MagicSquare {
    int **square;
    int order;
};


int main()
{
    using namespace std;

    string fileName;
    int order;
    ifstream in;

    cout << "Enter the name of the file that contains your magic square: ";
    cin >> fileName;
    cout << "Enter the dimension of your magic square: ";
    cin >> order;

    // TODO: Open the file containing the magic square values.
    ifstream inFile(fileName);

    // TODO: Call your readMagicSquareValues() function saving the returned
    // MagicSquare struct into a variable.
    MagicSquare array;
    array = readMagicSquareValues(inFile, order);

    // TODO: Close the file you opened.
    inFile.close();

    // TODO: Call your validateMagicSquare() function to determine if the 
    // given magic square is correct or not. If it is correct, print a 
    // message to the screen: "Your magic square is perfect!\n". If it is
    // not correct, print "Your magic square is not very magical, is it?\n".
    if (validateMagicSquare(array) == true) {
        cout << "Your magic square is perfect!\n";
    }
    else {
        cout << "Your magic square is not very magical, is it?\n";
    }

    // TODO: Free the memory allocated to myMagicSquare.square.
    //for (int i = 0; i < 3; i++) {
    //    delete[] array[i];
    //}
    //delete[] array;

    return 0;
}


/*
 * Validates the supplied MagicSquare struct
to confirm that it satisfies the properties of a Magic Square. Your function must check the sums of
the rows at a minimum.
*/
bool validateMagicSquare(struct MagicSquare &magicSquare) {

    // TODO: initialize a flag to indicate whether or not the given
    // magic square is valid or not.
    bool isMagic = true;

    // TODO: Write the code to check that the sums of the rows and columns of
    // the magic square are all the same.  Remember that you are working with a
    // 2-dimensional array, which suggests that two for loops will be used.

    // TODO: Write a pair (inner and outer) of for loops to check that all the
    // rows add up to the same value.
    int oldSum = 0;
    int newSum = 0;

    for (int i=0; i < magicSquare.order; i++) {
        for (int j=0; j < magicSquare.order; j++) {
            newSum += magicSquare.square[i][j];
        }
        if ((i != 0) & (oldSum != newSum)) {
            isMagic = false;
            return isMagic;
        }
        oldSum = newSum;
        newSum = 0;

    }

    // TODO: Bonus Part +5 points. Write a pair (inner and outer) of for loops
    // to check that all the columns add up to the same value.
    oldSum = 0;
    newSum = 0;

    for (int i=0; i < magicSquare.order; i++) {
        for (int j=0; j < magicSquare.order; j++) {
            newSum += magicSquare.square[j][i];
        }
        if ((i != 0) & (oldSum != newSum)) {
            isMagic = false;
            return isMagic;
        }
        oldSum = newSum;
        newSum = 0;

    }

    return isMagic;
}

/* Reads the contents of the supplied file
object which are assumed to be a n × n array of numbers. The function returns a MagicSquare
struct with the contents of the file loaded into the magicSquare.square member variable, and the
magicSquare.order variable should be set to the dimensions of the array that has been read
*/
struct MagicSquare readMagicSquareValues(std::ifstream& inFile, int order)
{
    int **magicSquareArray; // Pointer to a two-dimensional array.
    int currentValue;

    // TODO: allocate memory for the rows of the two-dimensional array.
    // See slide #51 03 - Pointers and Dynamic Arrays
    magicSquareArray = new int*[order];

    for (int i = 0; i < order; i++) {
        
        // TODO: allocate memory for the columns in this row of the array.
	magicSquareArray[i] = new int[order];

	// See slide #51 03 - Pointers and Dynamic Arrays


	for (int j = 0; j < order; j++) {
            // TODO: read the values in this row of the array. You can read
            // and store a value into the currentValue variable and then place
            // that value into your magicSquareArray array.
           
            inFile >> currentValue;
	    magicSquareArray[i][j] = currentValue;
        }
    }

    // TODO: Declare a MagicSquare struct variable and set its member elements
    // to the magicSquareArray and the order.
    MagicSquare array;
    array.square = magicSquareArray;
    array.order = order;

    // TODO: Return the MagicSquare struct you created in this function.
    return array;

}

