#include <iostream>
#include <string>
using namespace std;
#include "CommissionEmployee.h"


// ToDo: implement the default constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee( ) : Employee( ), sales(0), commission(0)
{
    //deliberately empty
    //cout <<"SalariedEmployee() called\n";
}


// ToDo: implement the constructor, remember to call base class constructor
CommissionEmployee::CommissionEmployee(string name, string SSN, double the_sales, double the_commission) : Employee(name, SSN), sales(the_sales), commission(the_commission)
{
	// deliberately empty
	// cout << "CommissionEmployee(" << name << "," << SSN << "," << sales << "," << commission << ")\n";
}

// ToDo: implement accessor/mutators
void CommissionEmployee::set_sales(double newSales){
  sales = newSales;

}
void CommissionEmployee::set_commission(double newComm){
  commission = newComm;

}
double CommissionEmployee::get_sales() const{
  return sales;

}
double CommissionEmployee::get_commission() const{
    return commission;
}

// ToDo: implement virtual get_net_pay function
// Hint: compensation is commission/100 * sales

double CommissionEmployee::get_net_pay() const
{
    return ((commission/100) * sales);
}


// ToDo: implement the virtual print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void CommissionEmployee::print_check() const
{
    Employee::print_check();
    cout << "Commission Employee." << endl;
    cout << "Gross sales: " << sales << " Commission: " << get_commission() << " Pay: " << get_net_pay();
    cout << endl;
    cout << "_________________________________________________\n";

}

// ToDo: implement the virtual promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream& CommissionEmployee::promptInput(istream& in, ostream& out)
{
    // ToDo: inplement the base class part, follow the model in SalariedEmployee
    Employee::promptInput(in, out);
    out << "Enter sales and commission: ";
	in >> sales >> commission;
	return in;


    // ToDo: read the sales and commission.


}
