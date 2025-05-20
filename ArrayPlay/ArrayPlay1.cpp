#include <iostream>

const int CAPACITY = 20;

using namespace std;

//declare functions
void sortArray(int array[], int size);
void fillArray(int array[], int &numElements);
void printArray(int array[], int numElements);
bool isSorted(int array[], int numElements);
void insertValue(int array[], int &numElements, int insertValue);
int getInsertPosition(int array[], int numElements, int insertValue);
//void deleteFromArray(int array[], int &numElements, int deleteValue);
int findInArray(int array[], int numElements, int findValue);

int main(void)
{
    int numArray[CAPACITY];     // an int array with a given CAPACITY
    // numArray can be partially filled, (so use numElements below
    // to indicate the number of elements in the array)

    int numElements = 0;     // the array is initially empty,
                             // i.e., contains 0 elements
    // The numElements variable will store the actual number of elements
    // stored as the program runs.

    // 1. TODO: Call the fillArray function to collect a number of values
    // from a user.
