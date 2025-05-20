/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional members:
 *  1. a string type member variable to store the jobTitle (director, Vice President, ... )
 *  3. Constructor functions: one default one, another taking necessary info. about the administrator: name, SSN, salary, jobTitle
 *  4. redefine print_check() so that the jobTitle is printed on the check. Start with the version from 
 *  SalariedEmployee
 */
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator:public SalariedEmployee
{
  public:
    // ToDo: declare default constructor for Administrator
    Administrator();

    // ToDo: declare constructor for Administrator that takes a name, SSN, salary, jobTitle, bonus
    Administrator(string the_name, string the_SSN, double the_salary, string the_jobTitle, double the_bonus);

    // ToDo: declare Accessor/Mutator functions
    double get_bonus() const;
    void set_bonus(double newBonus);
    string get_job_title() const;
    void set_job_title(string new_job_title);    

    // ToDo: declare virtual functions to override
    
    // call SalariedEmployee::print_check()
    void print_check() const;
    
    // call SalariedEmployee::promptInput(in, out)
    istream& promptInput(istream& in, ostream& out);
    
    // use salary + bonus;
    double get_net_pay() const;

  private: 
    // ToDo: declare jobTitle, bonus member variables
    string jobTitle;
    double bonus;

};

#endif
