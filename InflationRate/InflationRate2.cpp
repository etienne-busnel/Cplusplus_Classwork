#include <iostream>

/*
 * collectInflationRateValues - promots user to enter an old and new cpi,
 * then return the inflation rate between the two. They have the option to
 * calculate more inflation rates or stop.
 * @param inflationRates[]: array that will store all the inflation rates
 * @param nbrInList: counts how many inflation rates are stored in the array
 */
void collectInflationRateValues(double inflationRates[], int &nbrInList);

/*
 * Sums the values in the passed array and finds the average of them.
 * @param inflationRates: array of inflation rates
 * @param nbrInList: size of the array
 */
double calcAverageRate(double inflationRates[], int nbrInList);

/*
 * calcInflationRate - calculates the inflation rate given the old and new
 * consumer price index (both must be greater than 0)
 *
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double calcInflationRate(double old_cpi, double new_cpi);

/*
 * isInvalidCPI - checks that the given CPI value is greater than 0. Returns
 * true if the value is invalid, false if it is valid.
 *
 * @param cpi_value: the value of the CPI
 * @returns: false if the value is okay or false if value is valid
 */
bool isInvalidCPI(double cpi_value);

const int MAXSIZE = 20;

int main()
{
    using namespace std;

    // TODO: Declare an array that can hold upto MAXSIZE double values to store
    // the calculated inflation rates.
    double rates_array[MAXSIZE];

    // TODO: Declare a variable to store the number of inflation rate stored
    int num_rates = 0;


    // TODO: Call the collectInflationRateValues() function to populate
    //       the array with inflation rates.

    collectInflationRateValues(rates_array, num_rates);

    // TODO: Call the calcAverageRate() function to get the average rate
    // of inflation.

    double avg_rate = calcAverageRate(rates_array, num_rates);

    // TODO: Print the average rate: "Average rate is "
    
    cout << "Average rate is " << avg_rate << endl;

    return 0;
}

// Function that fills the array with inflationRate values. It asks a user
// to enter two consumer price index values for as many values the user
// requests.
//   - The function also sets nbrInList to the number of inflation rates added
//     to the array.
//   - Make sure that the number of items entered does not go beyond the size
//     of the array.
//   - Check that CPI values are valid and do not add anything to the array
//     if they are invalid.
void collectInflationRateValues(double inflationRates[], int &nbrInList)
{
    using namespace std;
    double old_cpi, new_cpi, rate;

    while (true) {

    // TODO: write the code inside the loop to collect CPI values,
    // calculate the inflation rate, and store the calculated rate in the
    // inflationRates[] array.
    // HINT: You can use the code from the main() function in Part 1 of this
    // assignment to collect CPI values and calculate the inflation rate
    // from them.
	
	cout << "Enter the old and new consumer price indices: ";
	cin >> old_cpi >> new_cpi;
	
	if (isInvalidCPI(old_cpi) || isInvalidCPI(new_cpi)) {
	    cout << "One or both CPI values is invalid." << endl;
	}
	else {
	    rate = calcInflationRate(old_cpi, new_cpi);
	    cout << "Inflation rate is " << rate << endl;

	    inflationRates[nbrInList] = rate;
	    nbrInList++;
	
	    if(nbrInList == MAXSIZE){
	        break;
	    }

	    char continue_input;

	    cout << "Try again? (y or n): ";
            cin >> continue_input;
            if (continue_input != 'Y' && continue_input != 'y') {
                break;
            }
	}
    }

}


// double calcInflationRate(double old_cpi, double new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double calcInflationRate(double old_cpi, double new_cpi)
{
    // Check for valid CPI values in both parameters. Return 0 if the values
    // are not correct.
    if (isInvalidCPI(old_cpi) || isInvalidCPI(new_cpi)) {
        return 0;
    }

    double rate = (new_cpi - old_cpi) / old_cpi * 100;
    return rate;
}

//calculates the average inflation rate of the passed array
double calcAverageRate(double inflationRates[], int nbrInList)
{
    double sum = 0;

    for (int i = 0; i < nbrInList; i++) {
        sum = sum + inflationRates[i];
    }
	
    double total = sum / nbrInList;

    return total;
}

//returns true if passsed value is >0, false otherwise 
bool isInvalidCPI(double cpi_value)
{
    if (cpi_value > 0)
        return false;
    else
        return true;

}
