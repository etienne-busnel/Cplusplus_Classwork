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
    fillArray(numArray, numElements);

    // 2. TODO: Call the printArray function.
    printArray(numArray, numElements);

    // 3. TODO: Call the isSorted function. If the array is sorted, print
    // "Array is sorted\n" otherwise print "Array is not sorted\n"
    if(isSorted(numArray, numElements) == true)
        cout << "Array is sorted\n";
    else
        cout << "Array is not sorted\n";

    // 4. TODO: Read a value from the user. Use this prompt: "Enter a value
    // to insert: "
    cout << "Enter a value to insert: ";
    int insert_val;
    cin >> insert_val;
    // Call the insertValue function to insert the value obtained from the
    // user.
    insertValue(numArray, numElements, insert_val);
    // 5. TODO: Call printArray
    printArray(numArray, numElements);

    // 6. TODO: Read a value from a user and then call the deleteFromArray
    // function to delete the value from the array if it is there. Use this
    // prompt: "Enter a value to delete: "

    int del_value;
    cout << "Enter a value to delete: ";

    cin >> del_value;
    deleteFromArray(array[], numElements, insertValue);

    // 7. TODO: Call printArray

    // 8. TODO: Call the sortArray function.

    // 9. TODO:
    //     Call printArray
    //        If the array is sorted, print "Array is sorted\n"
    //        otherwise print "Array is not sorted\n"

    // 10. TODO: Call the reverseArray function

    // 11. TODO: Print the prompt "Reversing the Array is:\n"
    // and then call the printArray function.

    return 0;

}

//TODO: Implement all functions as required by the instructions.

//Performs bubble sort on an array
void sortArray(int array[], int size) {
    for (int i=0; i < size; i++) {
        bool swapped_vals = false;
        for (int j=0; j < (size-i-1); j++) {
            if (array[j] > array[j+1]){
                swapped_vals = true;
                swap(array[j],array[j+1]);
            }
        }
        if (!swapped_vals)
                break;
    }
}

/*Fills an int array with values entered by a user. Stops
reading input when the user inputs -1 or it reaches CAPACITY. Use this prompt: "Enter
non-negative integers. End with -1: "
• parameter: int array[] is an array of integers after leaving this function
• parameter: int &numElements is the number of Elements in the array when done
• returns: void */
void fillArray(int array[], int &numElements) {
    cout << "Enter non-negative integers. End with -1: " << endl;
    bool proceed = true;

    while (proceed == true) {
        cin >> array[numElements];
        if (array[numElements] == -1) {
            proceed = false;
        }
        else {
            numElements++;
        }
    }
}

void printArray(int array[], int numElements) {
    for (int i=0; i < numElements; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool isSorted(int array[], int numElements) {
    bool sorted = true;
    for (int i=0; i < numElements-1; i++) {
        if(array[i] > array[i+1]) {
            sorted = false;
            break;
        }
    }

    return sorted;
}

void insertValue(int array[], int &numElements, int insertValue) {
    if (isSorted(array, numElements) == true) {
        int position = getInsertPosition(array, numElements, insertValue);
        for (int i = numElements; i >= position; i--) {
            array[i] = array[i-1];
        }
        array[position] = insertValue;
        numElements++;
    }

    else {
        array[numElements] = insertValue;
        numElements++;
    }
}

int getInsertPosition(int array[], int numElements, int insertValue) {
    int position;
    for (int i=0; i < numElements; i++) {
        if (array[i] > insertValue) {
            position = i;
            break;
        }
    }

    return position;
}

/*
void deleteFromArray(int array[], int &numElements, int deleteValue) {
    if () {
    }
    else {
        if (isSorted(array, numElements) {

        }
        else {

        }
    }
}
*/

int findInArray(int array[], int numElements, int findValue) {
    int indexOfValue = -1;
    for (int i=0; i < numElements; i++) {
        if(array[i] == findValue) {
            indexOfValue = i;
            break;
        }
    }

    return indexOfValue;

