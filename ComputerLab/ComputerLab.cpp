/* Include Header Comment Here
 */

#include <iostream>

using namespace std;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(int * labs[], int labsizes[]);

/* 
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(int * labs[]);


/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(int * labs[], int labsizes[]);


// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(int * labs[], int labsizes[]);


// ======================
// logout:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logout(int * labs[], int labsizes[]);


// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(int * labs[], int labsizes[]);


// ======================
//     main function
// ======================
int main()
{
    int * labs[NUMLABS];     // store the pointers to the dynamic array for each lab
    int labsizes[NUMLABS];    // Number of computers in each lab
    int choice = -1;
    
    cout << "Welcome to the LabMonitorProgram!\n";

    // Prompt the user to enter labsizes 
    cout << "Please enter the number of computer stations in each lab:\n"; 
    for (int i = 0; i < NUMLABS; i++)
    {
        do
        {
            cout << "How many computers in Lab " << i+1 << "? ";
            cin >> labsizes[i]; 
        } while (labsizes[i] < 0);
    }

    // Create ragged array structure
    createArrays(labs, labsizes);

    // Main Menu
   
    while (choice != 0)
    {
        cout << endl;
        cout << "MAIN MENU" << endl;
        cout << "0) Quit" << endl;
        cout << "1) Simulate login" << endl;
        cout << "2) Simulate logout" << endl;
        cout << "3) Search" << endl;
        cin >> choice;
        if (choice == 1)
        {
            login(labs, labsizes);
            showLabs(labs, labsizes);
        }
        else if (choice == 2)
        {
            logout(labs, labsizes);
            showLabs(labs, labsizes);
        }
        else if (choice == 3)
        {
            search(labs, labsizes);
        }
    }
    freeArrays(labs);        // Free memory before exiting
    
    cout << "Bye!\n";
    
    return 0;
}

// creates the multidimensional lab array
void createArrays(int * labs[], int labsizes[])
{
  // Implement the Code!
  //Hint: for each of the 4 labs, dynamically allocate an int array of size given by the number of computers in the lab. 
    for (int i=0; i < NUMLABS; i++) {
        labs[i] = new int[labsizes[i]];
    }    

    return;
}

// frees memory allocated to lab arrays
void freeArrays(int * labs[])
{
    for (int i=0; i < NUMLABS; i++) {
        delete[] labs[i];
    }
    
    return;
}

/* showLabs:
   Displays the status of all labs (who is logged into which computer).
   Precondition: labs[] is a multidimensional array of labs with computers
                 labsizes[i] contains the size of the array in labs[i]
 */
void showLabs(int * labs[], int labsizes[])
{

    int i;
    int j;

    cout << "LAB STATUS" << endl;
    cout << "Lab #     Computer Stations" << endl;
    for (i = 0; i < NUMLABS; i++)
    {
        cout << i+1 << "         ";
        for (j = 0; j < labsizes[i]; j++)
        {
            cout << (j+1) << ": ";
            if (labs[i][j] == 0)
            {
                cout << "empty ";
            }
            else
            {
                cout << labs[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return;
}

// lets user enter a login id and specify what lab/station to login the user to
void login(int * labs[], int labsizes[])
{
    // variable declaration
    int login_id;
    int lab_num;
    int stn_num;
    
    // get login information from user
    cout << "Enter the 5 digit ID number of the user logging in: \n";
    cin >> login_id;
    cout << "Enter the lab number the user is logging in from (1-" << NUMLABS << "): \n";
    cin >> lab_num;
    cout << "Enter computer station number the user is logging in to (1-" << labsizes[lab_num-1] << "): \n";
    cin  >> stn_num;

    // set that station to the user's ID number
    labs[lab_num-1][stn_num-1] = login_id;

    return;
}

// prompts the user to enter an id and clears it from the lab array if found
void logout(int * labs[], int labsizes[])
{
    // variable declaration
    int logout_id;
    bool id_found = false;

    // take in the user's id number
    cout << "Enter the 5 digit ID number of the user logging out: \n";
    cin >> logout_id;

    // search for id in labs array
    for (int i=0; i < NUMLABS; i++) {
        for (int j=0; j < labsizes[i]; j++) {
	    if (labs[i][j] == logout_id) {
	        // if found, set that computer to empty
	        labs[i][j] = 0;
		id_found = true;
		cout << "Logout user " << logout_id << " in Lab " << i+1 << " at computer " << j+1 << endl;
		break;
	    }
	}
    }

    if (id_found == false) {
        cout << "User not logged in.\n";
    }

    return;
}

// searches for an id in the lab array and if found, returns the location
void search(int * labs[], int labsizes[])
{
    // variables
    int search_id;
    bool id_found = false;
    
    // get the id
    cout << "Enter the 5 digit ID number of the user to search for: \n";
    cin >> search_id;

    // search for id in labs array
    for (int i=0; i < NUMLABS; i++) {
        for (int j=0; j < labsizes[i]; j++) {
            if (labs[i][j] == search_id) {
                // if found, set that computer to empty
                labs[i][j] = 0;
                id_found = true;
                cout << "User " << search_id << " logged in Lab " << i+1 << " at computer " << j+1 << endl;
                break;
            }
        }
    }
    
    if (id_found == false) {
        cout << "User not logged in.\n";
    }

    return;
}
