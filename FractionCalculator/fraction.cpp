//
//  fraction.cpp
//
//  Created by Rebecca Henry on 2021-10-17.
//

#include "fraction.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// Fraction Exception initialization
FractionException::FractionException(const string& message): message(message){}
string& FractionException::what(){return message;}

// Fraction initialization
Fraction::Fraction(void):num(0), denom(1){}
Fraction::Fraction(const int num):num(num), denom(1){}
Fraction::Fraction(const int num, const int denom):num(num), denom(denom){
    if (denom == 0){throw FractionException("FractionException: denominator can't be 0.");}
    this->normalise();
}

// accessors for numerator and denominator of object
int Fraction::numerator() const{return num;}
int Fraction::denominator() const{return denom;}

// normalise the fraction object by using gcd and adjusting negativity
void Fraction::normalise(){
    bool neg = false;
    if (num<0 xor denom<0){neg = true;}
    else if (num<0 and denom<0){
        num = num * (-1);
        denom = denom * (-1);}
    if (denom<0){denom = denom*(-1);}
    int lowest = gcd(num,denom);
    num = num/lowest;
    denom = denom/lowest;
    if (neg == true){num = num*(-1);}
}

// negate the fraction object
Fraction& Fraction::operator-(){
    num = (-1)*num;
    return *this;
}

// Pre-increment the fraction object by 1/1
Fraction& Fraction::operator++() {
    num = num+denom;
    this->normalise();
    return *this;
}

// Post-increment the fraction object
// int i is unused
Fraction Fraction::operator++(int i) {
    Fraction clone(num, denom);
    num = num+denom;
    this->normalise();
    return clone;
}

// add a fraction to the fraction object and re assign it
Fraction& Fraction::operator+=(const Fraction& frac) {
    num = (num * frac.denom)+(denom*frac.num);
    denom = denom*frac.denom;
    this->normalise();
    return *this;
}

// add an int to the fraction object and reassign it
Fraction& Fraction::operator+=(int i) {
    int lcm = abs(denom * 1)/ gcd(denom, 1);
    num = (denom/lcm)*num + (1/lcm)*i;
    denom = lcm;
    this->normalise();
    return *this;
}

// use recursion to find greatest common denominator
int gcd(int n,int m){
    if (n<0){n=n*-1;} // make sure there's no negative values
    if (m<0){m=m*-1;}
    if (m<=n && n%m==0) {return m;} //return the gcd
    else if (n<m) {return gcd(m,n);}
    else {return gcd(m,n%m);}
}

// less than comparison between 2 fractions
// returns true or false
bool operator<(Fraction& frac1, Fraction& frac2){
    bool lessThan = false;
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    if ( ((lcm/frac1.denominator())*frac1.numerator()) <     ((lcm/frac2.denominator())*frac2.numerator()) )
    {lessThan = true;}
    return lessThan;
}

// less than comparison between and int and a fraction
// returns true or false
bool operator<(int i, Fraction& frac2){
    bool lessThan = false;
    int lcm = abs(1 * frac2.denominator())/ gcd(1, frac2.denominator());
    if ((lcm/1)*i < ((lcm/frac2.denominator())*frac2.numerator()))
    {lessThan = true;}
    return lessThan;
}

// less than comparison between a fraction and an int
// returns true or false
bool operator<(Fraction& frac1, int i){
    bool lessThan = false;
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    if (((lcm/frac1.denominator())*i)<((lcm/1)*i))
    {lessThan = true;}
    return lessThan;
}

// greater than comparison between 2 fractions
// returns true or false
bool operator>(Fraction& frac1, Fraction& frac2){
    bool gThan = false;
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    if ( ( (lcm/frac1.denominator()) * frac1.numerator()) > ((lcm/frac2.denominator())*frac2.numerator()) )
    {gThan = true;}
    return gThan;
}

// greater than comparison between an int and a fraction
// returns true or false
bool operator>(int i, Fraction& frac2){
    bool gThan = false;
    int lcm = abs(1 * frac2.denominator())/ gcd(1, frac2.denominator());
    if ( ((lcm/1)*i) > ( (lcm/frac2.denominator()) *frac2.numerator()) )
    {gThan = true;}
    return gThan;
}

// greater than comparison between a fraction and an int
// returns true or false
bool operator>(Fraction& frac1, int i){
    bool gThan = false;
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    if ( ((lcm/frac1.denominator())*frac1.numerator()) > ((lcm/1)*i))
    {gThan = true;}
    return gThan;
}

// less than equals to comparison between 2 fractions
// returns true or false
bool operator<=(Fraction& frac1, Fraction& frac2){
    bool lThanE = false;
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    if (((lcm/frac1.denominator())*frac1.numerator())<=(lcm/frac2.denominator())*frac2.numerator())
    {lThanE = true;}
    return lThanE;
}

// less than equals to comparison between an int and a fraction
// returns true or false
bool operator<=(int i, Fraction& frac2){
    bool lThanE = false;
    int lcm = abs(1 * frac2.denominator())/ gcd(1, frac2.denominator());
    if (((lcm/1)*i)<=((lcm/frac2.denominator())*frac2.numerator()))
    {lThanE = true;}
    return lThanE;
}

// less than equals to comparison between a fraction and an int
// returns true or false
bool operator<=(Fraction& frac1, int i){
    bool lThanE = false;
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    if (((lcm/frac1.denominator())*frac1.numerator())<=((lcm/1)*i))
    {lThanE = true;}
    return lThanE;
}

// greater than equals to comparison between 2 fractions
// returns true or false
bool operator>=(Fraction& frac1, Fraction& frac2){
    bool gThanE = false;
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    if (((lcm/frac1.denominator())*frac1.numerator())>=((lcm/frac2.denominator())*frac2.numerator()))
    {gThanE = true;}
    return gThanE;
}

// greater than equals to comparison between an int and a fraction
// returns true or false
bool operator>=(int i, Fraction& frac2){
    bool gThanE = false;
    int lcm = abs(1* frac2.denominator())/ gcd(1, frac2.denominator());
    if (((lcm/1)*i)>= ((lcm/frac2.denominator())*frac2.numerator()))
    {gThanE = true;}
    return gThanE;
}

// greater than equals to comparison between a fraction and an int
// returns true or false
bool operator>=(Fraction& frac1, int i){
    bool gThanE = false;
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    if (((lcm/frac1.denominator())*frac1.numerator())>=((lcm/1)*i))
    {gThanE = true;}
    return gThanE;
}

// equals to comparison between 2 fractions
// returns true or false
bool operator==(Fraction& frac1, Fraction& frac2){
    bool equ = false;
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    if (((lcm/frac1.denominator())*frac1.numerator())==((lcm/frac2.denominator())*frac2.numerator())){equ = true;}
    return equ;
}

// equals to comparison between an int and a fraction
// returns true or false
bool operator==(int i, Fraction& frac2){
    bool equ = false;
    int lcm = abs(1 * frac2.denominator())/ gcd(1, frac2.denominator());
    if (((lcm/1)*i)==((lcm/frac2.denominator())*frac2.numerator()))
    {equ = true;}
    return equ;
}

// equals to comparison between a fraction and an int
// returns true or false
bool operator==(Fraction& frac1, int i){
    bool equ = false;
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    if (((lcm/frac1.denominator())*frac1.numerator())==((lcm/1)*i))
    {equ = true;}
    return equ;
}

// not equals to comparison between 2 fractions
// returns true or false
bool operator!=(Fraction& frac1, Fraction& frac2){
    bool nequ = false;
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    if (((lcm/frac1.denominator())*frac1.numerator())!=((lcm/frac2.denominator())*frac2.numerator())) {nequ = true;}
    return nequ;
}

// not equals to comparison between an int and a fraction
// returns true or false
bool operator!=(int i, Fraction& frac2){
    bool nequ = false;
    int lcm = abs(1 * frac2.denominator())/ gcd(1, frac2.denominator());
    if (((lcm/1)*i)!=((lcm/frac2.denominator())*frac2.numerator())){
        nequ = true;
    }
    return nequ;
}

// not equals to comparison between a fraction and an int
// returns true or false
bool operator!=(Fraction& frac1, int i){
    bool nequ = false;
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    if (((lcm/frac1.denominator())*frac1.numerator())==((lcm/1)*i)){
        nequ = true;
    }
    return nequ;
}

// adds an int and a fraction
// returns a fraction
Fraction operator+(int i, const Fraction& frac1){
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    int num = (lcm/1)*i + (lcm/frac1.denominator())*frac1.numerator();
    int denom = lcm;
    Fraction frac(num,denom);
    frac.normalise();
    return frac;
}

// adds a fraction and an int
// returns a fraction
Fraction operator+(const Fraction frac1, int i){
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    int num = (lcm/frac1.denominator())*frac1.numerator() + (lcm/1)*i;
    int denom = lcm;
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// adds 2 fractions
// returns a fraction
Fraction operator+(const Fraction& frac1,const Fraction& frac2){
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    int num = (lcm/frac1.denominator())*frac1.numerator() + (lcm/frac2.denominator())*frac2.numerator();
    int denom = lcm;
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// subtracts a fraction from an int
// returns a fraction
Fraction operator-(int i, Fraction& frac1){
    int lcm = abs(1 * frac1.denominator())/ gcd(1, frac1.denominator());
    int num = (lcm/1)*i - (lcm/frac1.denominator())*frac1.numerator();
    int denom = lcm;
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// subtracts an int from a fraction
// returns a fraction
Fraction operator-(Fraction& frac1, int i){
    int lcm = abs(frac1.denominator() * 1)/ gcd(frac1.denominator(), 1);
    int num = (lcm/frac1.denominator())*frac1.numerator() - (lcm)*i;
    int denom = lcm;
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// subtracts a fraction from a fraction
// returns a fraction
Fraction operator-(Fraction& frac1, Fraction& frac2){
    int lcm = abs(frac1.denominator() * frac2.denominator())/ gcd(frac1.denominator(), frac2.denominator());
    int num = (lcm/frac1.denominator())*frac1.numerator() - (lcm/frac2.denominator())*frac2.numerator();
    int denom = lcm;
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// multiplies an int and a fraction
// returns a fraction
Fraction operator*(int i, Fraction& frac1){
    int num = i*frac1.numerator();
    int denom = i*frac1.denominator();
    Fraction frac(num,denom);
    frac.normalise();
    return frac;
}

// multiplies a fraction and an int
// returns a fraction
Fraction operator*(Fraction& frac1, int i){
    int num = i*frac1.numerator();
    int denom = i*frac1.denominator();
    Fraction frac(num,denom);
    frac.normalise();
    return frac;
}

// multiplies two fractions
// returns a fraction
Fraction operator*(Fraction& frac1, Fraction& frac2){
    int num = frac1.numerator()*frac2.numerator();
    int denom = frac1.denominator()*frac2.denominator();
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// divides an int by a fraction
// returns a fraction
Fraction operator/(int i, Fraction& frac1){
    int num = i*frac1.denominator();
    int denom = 1*frac1.numerator();
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// divides a fraction by an int
// returns a fraction
Fraction operator/(Fraction& frac1, int i){
    int num = 1*frac1.numerator();
    int denom = i*frac1.denominator();
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// divides a fraction by a fraction
// returns a fraction
Fraction operator/(Fraction& frac1, Fraction& frac2){
    int num = frac1.numerator()*frac2.denominator();
    int denom = frac1.denominator()*frac2.numerator();
    Fraction frac(num, denom);
    frac.normalise();
    return frac;
}

// shapes output
// returns an ostream
ostream& operator<<(ostream& os, Fraction& frac){
   os << frac.numerator() << '/' << frac.denominator();
   return os;
}

// shapes input
// returns an istream
istream& operator>>(istream& is, Fraction& frac){
    int num;
    int denom;
    char next;
    is >> num;
    is >> next;
    if (next == '/'){is >> denom;}
    else {denom = 1;}
    if (denom == 0){throw FractionException("FractionException: denominator can't be 0.");}
    frac = Fraction(num, denom);
    return is;
 }
