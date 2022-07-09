#ifndef fraction_h
#define fraction_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;

namespace cs_fraction {

class Fraction
{
    
public:
    Fraction(int inNum = 0, int inDenom = 1);
    void Simplify();
    void sqrt(); //Use Inheritance
        friend ostream& operator<<(ostream& out,const Fraction& right);
        friend istream& operator>>(istream& in, Fraction& right);
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);
    Fraction operator+=(const Fraction& right);
    Fraction operator-=(const Fraction& right);
    Fraction operator*=(const Fraction& right);
    Fraction operator/=(const Fraction& right);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
    
    
    
private:
    int num;
    int denom;
    bool isRoot;
    
};
}
#endif /* cs_fraction_h */
