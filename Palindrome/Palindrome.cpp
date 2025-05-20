/* 
 * pallindrome: checks a string to see if it is a pallindrome.
 *  
 *  Examples:
 * 
 *  Able was I 'ere I saw Elba.
 *  Madam, I'm Adam.
 *  A man, a plan, a canal, Panama.
 *  Racecar
 * 
 *  First, create a clean version of the string. 
 *  	- convert all characters to lower case.
 *  	- remove all punctuation.
 * 
 *  Second, create a reverse version of the string.
 *   - use reverse and swap from our lab assignment
 *   so first make a copy of the string and pass in
 *   the copy to reverse.
 *   
 *  Third
 *  	- compare the two strings 
 *  		if they are the same, palindrome.
 *  		else, not palindrome.
 */ 
#include <iostream>
#include <string>
#include <vector>

// ToDo: Add include files.
using namespace std;


string removePunct(string str);
// Function: removePunct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

string convertToLower(string str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

string reverse(string str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

    // ToDo: Declare two vectors of strings to save the input strings:
    // palindromes, not_palindromes.
    vector <string> palindromes;
    vector <string> not_palindromes;

    // ToDo: Implement a loop to read in the palindrome strings using getline
    // until the user quits. The user will enter the word "quit" to exit the
    // loop. Prompt the user with "Enter your palindrome or type quit:"
    
    // ToDo: In the loop, call the isPalindrome function on the input string
    // and store it in the palindromes vector if true and the notPalindromes
    // vector if false.
    
    //declare variables
    bool quit = false;
    string line;
   
    //prompt user to enter lines until quit is entered
    while (quit == false) {
        cout << "Enter your palindrome or type quit:\n";
	getline(cin, line);
	if (line == "quit") {
	    quit = true;
	    break;
	}
        
	//call isPalindrome, and if string is a palindrome add to respective vector
	if (isPalindrome(line) == 1) {
	    palindromes.push_back(line);
	}
	else {
	    not_palindromes.push_back(line);
	}    
    }   

    // ToDo: After exiting the loop, print the list of palindromes under a
    // Palindrome heading and the list that are not palindromes under a Not
    // Palindrome heading.  The display function should print a tab character
    // before printing
    
    cout << "Palindromes:\n";
    display(palindromes);

    cout << "NOT Palindromes:\n";
    display(not_palindromes);

    return 0;
}

//checks if a string is a palindrome
bool isPalindrome(string str) {
    string str_copy = str;
    string str_copy_rev;

    str_copy = removePunct(str_copy);
    str_copy = convertToLower(str_copy);
    str_copy_rev = reverse(str_copy);
    
    if (str_copy == str_copy_rev) {
	return 1;
    }
    else {
        return 0;
    }
}

//removes all punctuation from the string
string removePunct(string str) {
    bool is_punct = true;
    int punct_pos;
    while (is_punct == true) {
        punct_pos = str.find_first_of(".,/?! []{}'\"", 0);
	if(punct_pos == -1) {
	    is_punct = false;
	    break;
	}
	else {
	    str.erase(punct_pos, 1);
	}
    }
    return str;
}

//make all upper case letter in a string lowercase
string convertToLower(string str) {
    for (int i=0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }

    return str;
}

//returns a reversed copy of the string
string reverse(string str) {
    string str_rev = str;
    for (int i=0; i < str.length(); i++) {
        str_rev[i] = str[str.length()-i-1];
    } 

    return str_rev;
}

//displays the entries of a vector which each indented on a new line
void display(vector<string> vstrings) {
    for (int i=0; i < vstrings.size(); i++) {
        cout << "\t" << vstrings[i] << endl;
    }
}
