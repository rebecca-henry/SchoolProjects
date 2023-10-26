//
//  fraction.h
//
//  Created by Rebecca Henry on 2021-10-17.
//

#ifndef fraction_h
#define fraction_h

#endif /* fraction_h */

#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

// Fraction Exception class
class FractionException{
public:
    FractionException(const string& message); //returns the error message
    string& what();
private:
    string message;
};

//Fraction class
class Fraction{
public:
    Fraction(); // making cases for no parameters, 1 parameter, and 2 parameters
    Fraction(int);
    Fraction(int, int);
    void normalise(); // normalises the fraction
    int numerator() const; // accesses the numerator
    int denominator() const; //accesses the denominator
    
    Fraction& operator-();   // negation
    Fraction& operator++();         // Pre-increment
    Fraction operator++(int i);    // Post-increment
    Fraction& operator+=(const Fraction& frac); // add and assign a fraction
    Fraction& operator+=(int i); // add and assign an int
private:
    int num;    //numerator int
    int denom; //denominator int
};

// finds gcd of 2 integers
int gcd(int n, int m);

// addition overloading
Fraction operator+(const Fraction& frac1, const Fraction& frac2);
Fraction operator+(int i, const Fraction& frac1);
Fraction operator+(const Fraction frac1, int i);

// subtraction overloading
Fraction operator-(Fraction& frac1, Fraction& frac2);
Fraction operator-(Fraction& frac1, int i);
Fraction operator-(int i, Fraction& frac2);

// multiplication overloading
Fraction operator*(Fraction& frac1, Fraction& frac2);
Fraction operator*(int i, Fraction& frac2);
Fraction operator*(Fraction& frac1, int i);

// division overloading
Fraction operator/(Fraction& frac1, Fraction& frac2);
Fraction operator/(int i, Fraction& frac2);
Fraction operator/(Fraction& frac1, int i);

// less than overloading
bool operator<(Fraction& frac1, Fraction& frac2);
bool operator<(int i, Fraction& frac2);
bool operator<(Fraction& frac1, int i);

// greater than overloading
bool operator>(Fraction& frac1, Fraction& frac2);
bool operator>(int i, Fraction& frac2);
bool operator>(Fraction& frac1, int i);

// less than or equals to overloading
bool operator<=(Fraction& frac1, Fraction& frac2);
bool operator<=(int i, Fraction& frac2);
bool operator<=(Fraction& frac1, int i);

// greater than or equals to overloading
bool operator>=(Fraction& frac1, Fraction& frac2);
bool operator>=(int i, Fraction& frac2);
bool operator>=(Fraction& frac1, int i);

// equals to overloading
bool operator==(Fraction& frac1, Fraction& frac2);
bool operator==(int i, Fraction& frac2);
bool operator==(Fraction& frac1, int i);

// not equal to overloading
bool operator!=(Fraction& frac1, Fraction& frac2);
bool operator!=(int i, Fraction& frac2);
bool operator!=(Fraction& frac1, int i);

// input and output overloading
ostream& operator<<(ostream& os, Fraction& frac);
istream& operator>>(istream& is, Fraction& frac);
