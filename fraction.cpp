/*
 2 Data Members:
 Num acts as the numerator of the fraction.
 Denom acts as the denominator of the fraction.
 
 
 Fraction objects will always be stored in lowest terms.
 Fraction objects will be stored in improper form and printed as such.
 The Denominator will never be negative. Any negatives will be stored in the numerator
 
*/

#include "fraction.h"
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;



namespace cs_fraction {


Fraction::Fraction(int inNum, int inDenom)
{
    assert(inDenom != 0);
    num = inNum;
    denom = inDenom;
    isRoot = false;
    Simplify();
}






void Fraction::Simplify()
{
    if (denom < 0){
        denom *= -1;
        num *= -1;
    }
    
    for (int i = denom; i > 1; i--){
        if (num % i == 0 && denom % i == 0){
            num /= i;
            denom /= i;
        }
    }
    
    if (num == 0){
        denom = 1;
    }
}







void Fraction::sqrt(){
    
    isRoot = true;
}





/*
 This function takes an input stream and converts it into a fraction object by abstracting its numerator and denominator based weather its a mixed fraction or not using the extraction operator. in represents the input streeam, and right is the fraction object.
 */
istream& operator>>(istream& in, Fraction& right)
{
    int temp;
    in >> temp;
   
    if (in.peek() == '/'){
        right.num = temp;
        in.ignore();
        in >> temp;
        right.denom = temp;
    } else {
        right.num = temp;
        right.denom = 1;
    }
    right.Simplify();
    return in;
}






/*
 This function allows you to convert a fraction object into an output stream using the insertion operator. out is a stream that displays a fraction in mixed, proper or improper form. Right is the fraction object whose numerator and denominator are being displayed.
 */
ostream& operator<<(ostream& out, const Fraction& right)
{
    if (right.denom == 1){
        out << right.num;
    } else if (right.isRoot == true){
        out << "sqrt(" << right.num << "/" << right.denom << ")";
    } else {
        out << right.num << "/" << right.denom;
    }
    return out;
}






bool operator<(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l < r){
        return true;
    }
    if (l > r){
        return false;
    }
    return l < r;
}






bool operator<=(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l <= r){
        return true;
    }
    if (l >= r){
        return false;
    }
    return l < r;
}






bool operator>(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l > r){
        return true;
    }
    if (l < r){
        return false;
    }
    return l > r;
}






bool operator>=(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l >= r){
        return true;
    }
    if (l <= r){
        return false;
    }
    return l >= r;
}






bool operator!=(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l != r){
        return true;
    }
    if (l == r){
        return false;
    }
    return l != r;
}






bool operator==(const Fraction& left, const Fraction& right)
{
    int l = left.num * right.denom;
    int r = right.num * left.denom;
    
    if (l == r){
        return true;
    }
    if (l != r){
        return false;
    }
    return l == r;
}






Fraction operator+(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = (left.num * right.denom) + (right.num * left.denom);
    result.denom = (left.denom * right.denom);
    result.Simplify();
    return result;
}






Fraction operator-(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = (left.num * right.denom) - (right.num * left.denom);
    result.denom = (left.denom * right.denom);
    result.Simplify();
    return result;
}






Fraction operator*(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = left.num * right.num;
    result.denom = left.denom * right.denom;
    result.Simplify();
    return result;
}






Fraction operator/(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.num = left.num * right.denom;
    result.denom = left.denom * right.num;
    result.Simplify();
    return result;
}






Fraction Fraction::operator+=(const Fraction& right)
{
    *this = *this + right;
    return *this;
}






Fraction Fraction::operator-=(const Fraction& right)
{
    *this = *this - right;
    return *this;
}






Fraction Fraction::operator*=(const Fraction& right)
{
    *this = *this * right;
    return *this;
}






Fraction Fraction::operator/=(const Fraction& right)
{
    *this = *this / right;
    return *this;
}






Fraction Fraction::operator++()
{
    num += denom;
    return *this;
}






Fraction Fraction::operator++(int)
{
    Fraction temp(num, denom);
    num += denom;
    return temp;
}






Fraction Fraction::operator--()
{
    num -= denom;
    return *this;
}






Fraction Fraction::operator--(int)
{
    Fraction temp(num, denom);
    num -= denom;
    return temp;
}
}
