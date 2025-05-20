/* Implement Administrator class */
#include "Administrator.h"
#include <string>
#include <iostream>
using namespace std;

// ToDo: implement the default constructor, remember to call base class
// constructor
Administrator::Administrator() : SalariedEmployee(), bonus(0), jobTitle("")
{
	//deliberately empty
}

// ToDo: implement the constructor, remember to call base class constructor
Administrator::Administrator(string the_name, string the_SSN, double the_salary,
                             string the_jobTitle, double the_bonus)
: SalariedEmployee(the_name, the_SSN, the_salary), jobTitle(the_jobTitle), bonus(the_bonus)
{
    // deliberately empty
    // cout << "Adminstrator(" << name << "," << SSN << "," << salary << "," <<
    // title << ")\n";
}

// ToDo: implement accessor/mutators
void Administrator::set_bonus(double newBonus)
{
    bonus = newBonus;
}

double Administrator::get_bonus() const
{
    return bonus;
}

void Administrator::set_job_title(string newJobTitle)
{
    jobTitle = newJobTitle;
}

string Administrator::get_job_title() const
{
    return jobTitle;
}

// ToDo: implement virtual functions

// ToDo: implement virtual get_net_pay function
// Hint: compensation is salary + bonus
double Administrator::get_net_pay() const
{
    return (SalariedEmployee::get_salary() + get_bonus());
}

// ToDo: implement the print_check() function. Follow the model in
// SalariedEmployee Hint: Use the base class print_check()
void Administrator::print_check() const {
    SalariedEmployee::print_check();
    cout << "Administrator Title:" << get_job_title() << endl;
    cout << "Bonus: " << get_bonus() << " Pay: " << get_net_pay() << endl << endl;
    cout << "_________________________________________________\n";
}

// ToDo: implement the promptInput() function. Follow the model in
// SalariedEmployee Hint: Use the base class promptInput()
istream& Administrator::promptInput(istream& in, ostream& out) {
    // ToDo: inplement the base class part, follow the model in SalariedEmployee
    SalariedEmployee::promptInput(in, out);
    out << "Enter bonus and title: ";
    
    // ToDo: read the bonus. Use ignorespace() to skip newline.
    string str;
    double dbl;
        in >> dbl;
    set_bonus(dbl);
    ignorespace(in);

    // ToDo: read the rest of the line for the title
    getline(in, str);
    set_job_title(str);
    return in;
}



