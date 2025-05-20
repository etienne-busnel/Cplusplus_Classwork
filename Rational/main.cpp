#include <iostream>
#include <string>
#include <stdlib.h>
// Include your header file
#include "Rational.h"
using namespace std;

int main()
{
    char oper;

    // TODO: declare two Rational objects that will store a result and operand.
    Rational r1, r2;

    std::cout << "Enter op1 (in the format of p/q): ";
    // TODO: Use your input function to read the first operand into result.
    cin >> r1;

    //Test Rational class member function 
    do {
        std::cout << "\nEnter operator [+, -, /, *, =, c(lear), a(ccessors), q(uit)]: ";
        // TODO: Read the operator into oper
        std::cin >> oper;

        // TODO: Change the commented out pseodocode on the line below to
        // test oper for binary operators:
        if (oper == '+' || oper == '-' || oper == '*' || oper == '/') 
        {
            std::cout << "\nEnter op2 (in the format of p/q): ";
            // TODO: Use your input function to read the operand into operand
	    cin >> r2;

        }

        // TODO: Implement a switch or multiway if statement with one case
        // for each option above where
        //  '+','*','/','-' calculates result.oper(result, operand)
        //  '=' outputs the current result,
        //  'c' to clear the current result,
        //  'a' to test accessors,
        //  'q' to quit.
        // In the case where a user selects 'c' to clear the results, you
        // should start over from the beginning. In that situation you will
        // prompt the user to enter op1 and then use the input() function again
        // to read the first operand into result. The code will then resume
        // within the loop.
	switch(oper)    
	    {
		case '+':
		r1 = r1 + r2;
		break;

		case '-':
		r1 = r1 - r2;
                break;

                case '*':
		r1 = r1*r2;
                break;

		case '/':
                r1 = r1/r2;
                break;

		case '=':
                cout << r1;
                break;

		case 'c':
                std::cout << "\nEnter op1 (in the format of p/q): ";
                // TODO: Use your input function to read the first operand into result.
                cin >> r1;
                break;

		case 'a':
		std::cout << "result's numerator is: " << r1.getNum() << "\n";
	        std::cout << "result's denominator is: " << r1.getDen() << "\n";	
                break;

		default:
		;
	    }


    } while (oper != 'q');
  
    return 0;
}
