// TODO: Write include guards.

#include <iostream>
using namespace std;

class Rational
{
public:
    /* TODO: declare a default constructor */
    Rational(int numer = 0, int denom = 1);

    /* TODO: declare an input() function to get a user's input to set the
     * object's value.
     */
    

    friend istream& operator >>(istream& ins, Rational& op1);

    /* TODO: declare an output() function to display object's value by printing
     * it to standard output, in the form of numerator/denominator
     */
    friend ostream& operator <<(ostream& outs, const Rational& op1);

    /* TODO: declare the accessor to return the object's numerator */
    int getNum() const;

    /* TODO: declare the accessor to return the object's denominator */
    int getDen() const;

    //sets a new integer and denominator
    void set(int n, int d);

    /* TODO: declare add() to set the object to be the sum of op1 and op2. You
     * should use const parameters that are passed by reference (&).
     */
    friend Rational operator +(const Rational& op1, const Rational& op2);
    
    /* TODO: declare subtract() to set the object to the difference of op1
     * and op2. You should use const parameters that are passed by reference.
     */
    friend Rational operator -(const Rational& op1, const Rational& op2);

    /* TODO: declare multiply() to set the object to the product of op1
     * and op2. You should use const parameters that are passed by reference.
     */
    friend Rational operator *(const Rational& op1, const Rational& op2);


    /* TODO: declare divide() to set the object to the quotient of op1
     * and op2. You should use const parameters that are passed by reference.
     */
    friend Rational operator /(const Rational& op1, const Rational& op2);

private:
    /* TODO: declare data members for rational object. You will need a
     * numerator and a denominator.
     */
    int numer;
    int denom;

    int gcd (int a, int b);
    void simplify();
};
