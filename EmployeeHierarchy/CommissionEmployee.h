//#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

#ifndef _COMMISSION_H
#define _COMMISSION_H

class CommissionEmployee : public Employee
{
public:
    // ToDo: declare default constructor for CommissionEmployee
    CommissionEmployee();


    // ToDo: declare constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
    CommissionEmployee(string name, string SSN, double sales, double commission);


    // ToDo: declare Accessor/Mutator functions
    void set_sales(double newSales);
    void set_commission(double newComm);
    double get_sales() const;
    double get_commission() const;



    // ToDo: declare vitual functions to override
    void print_check() const override;
    istream& promptInput(istream& in, ostream& out) override;
    double get_net_pay() const override;


private:
    // ToDo: declare a sales, commission percent member
    double sales;
    double commission;

};
#endif // _COMMISSION_H
