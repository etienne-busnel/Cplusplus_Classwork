// Include your header file.
#include <iostream>
#include "Rational.h"
#include <string>
using namespace std;

// Implement the functions defined in Rational.h
//
// Not that for your default constructor, set the numerator to 0 and the
// denominator to 1
//
Rational::Rational(int numer, int denom) {

}

void Rational::set(int n, int d) {
    numer = n;
    denom = d;
}

istream& operator >>(istream& ins, Rational& op1)
{
    std::string intake;
    int slash_pos;

    ins >> intake;

    slash_pos = intake.find("/");

    op1.numer = stoi(intake.substr(0,slash_pos));
    op1.denom = stoi(intake.substr(slash_pos+1));
    
    return ins;
}


ostream& operator <<(ostream& outs, const Rational& op1)
{
    outs << "result = " << op1.numer << "/" << op1.denom;
    return outs;
}

int Rational::getNum() const {
    return numer;
}

int Rational::getDen() const {
    return denom;
}


/* TODO: declare add() to set the object to be the sum of op1 and op2. You
     * should use const parameters that are passed by reference (&).
     */
Rational operator +(const Rational& op1, const Rational& op2)
{
    Rational temp;
    temp.numer = (op1.getNum()*op2.getDen() + op2.getNum()*op1.getDen());
    temp.denom = (op1.getDen() * op2.getDen());
    temp.simplify();
    return temp;
}

    /* TODO: declare subtract() to set the object to the difference of op1
     * and op2. You should use const parameters that are passed by reference.
     */
Rational operator -(const Rational& op1, const Rational& op2)
{
    Rational temp;
    temp.numer = (op1.getNum()*op2.getDen() - op2.getNum()*op1.getDen());
    temp.denom = (op1.getDen() * op2.getDen());
    temp.simplify();
    return temp;
}

    /* TODO: declare multiply() to set the object to the product of op1
     * and op2. You should use const parameters that are passed by reference.
     */
Rational operator *(const Rational& op1, const Rational& op2)
{
    Rational temp;
    temp.numer = op1.getNum()*op2.getNum();
    temp.denom = op1.getDen()*op2.getDen();
    temp.simplify();
    return temp;
}

    /* TODO: declare divide() to set the object to the quotient of op1
     * and op2. You should use const parameters that are passed by reference.
     */
Rational operator /(const Rational& op1, const Rational& op2)
{
    Rational temp;
    temp.numer = op1.getNum()*op2.getDen();
    temp.denom = op1.getDen()*op2.getNum();
    temp.simplify();
    return temp;
}

// Function to find greatest common divisor between two integers
int Rational::gcd (int a, int b)
{
    while (a != 0 && b != 0)
    {
        a = a % b;
        if (a != 0)
            b = b % a;
    }
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return 1;
}

void Rational::simplify() {
    int divisor = gcd(numer, denom);
    
    numer = numer / divisor;
    denom = denom / divisor;

}
