#include <iostream>

/*
 * calcInflationRate - calculates the inflation rate given the old and new
 * consumer price index (both must be greater than 0)
 *
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double calcInflationRate(double old_cpi, double new_cpi);
bool isInvalidCPI(double cpi_value);

/*
 * isInvalidCPI - checks that the given CPI value is greater than 0. Returns
 * true if the value is invalid, false if it is valid.
 *
 * @param cpi_value: the value of the CPI
 * @returns: false if the value is okay or false if value is valid
 */

int main()
{
    using namespace std;

    // Declare two double variables for the old consumer price index (cpi)
    // and the new cpi.
    double old_cpi, new_cpi;


    // Read in two double values for the cpi and store them
    // in the variables
    cout << "Enter the old and new consumer price indices: ";
    cin >> old_cpi >> new_cpi;

    // TODO: check both values as entered. Print an error message if either
    // value is not valid and exit the program.
    
    if ((isInvalidCPI(old_cpi) == 0) || (isInvalidCPI(new_cpi) == 0)) {
	cout << "One or both CPI values is invalid, exiting.";
	return 0;
    }    
    
    // Call the function calcInflationRate with the two cpis
    double rate = calcInflationRate(old_cpi, new_cpi);


    // Print the results
    cout << "Inflation rate is " << rate << "\n"; 

    return 0;
}


// double calcInflationRate(double old_cpi, double new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double calcInflationRate(double old_cpi, double new_cpi)
{
    // TODO: Rewrite the code in this function to check for valid CPI values
    // in both parameters. Return 0 if the values are not correct; otherwise,
    if ((isInvalidCPI(old_cpi) == 0) || (isInvalidCPI(new_cpi) == 0)) {
    	return 0;
    } 	
   
    double rate = (new_cpi - old_cpi) / old_cpi * 100;
    return rate;
}

//returns 1 if CPI is positive, 0 if negative 
bool isInvalidCPI(double cpi_value)
{
    if (cpi_value <= 0) {
        return 0;
    }

    return 1;
}


// TODO: write the definition of the isInvalidCPI function.
