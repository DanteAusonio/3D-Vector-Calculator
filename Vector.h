//
//  Vector.hpp
//  3D Vector Calculator
//
//  Created by Dante Ausonio on 4/22/22.
//

#ifndef Vector_h
#define Vector_h
#include <stdio.h>
#include <iostream>
#include "fraction.h"
using namespace std;
using namespace cs_fraction;

namespace cs_Vector {



class Vector {
public:
    typedef std::size_t size_type;
    typedef Fraction value_type;
    
    

//Class Operations
    Vector();
    Vector(value_type x, value_type y);
    Vector(value_type x, value_type y, value_type z);
    Vector(const Vector& right);
    
    
//Operator Overloads
    friend std::ostream& operator<<(ostream& out, const Vector& right);
    friend std::istream& operator>>(istream& in, Vector& right);
    Vector operator=(const Vector& right);
    //scalar multiple
    friend Vector operator*(const value_type& multiplier, const Vector& right);
    //Dot Product (return obj of type T)
    friend value_type operator*(const Vector& multiplier, const Vector& right);
    friend Vector operator/(const Vector& right, const value_type& multiplier);
    friend Vector operator/(const Vector& left, const Vector& right);
    friend Vector operator+(const Vector& left, const Vector& right);
    friend Vector operator-(const Vector& left, const Vector& right);
    friend bool operator==(const Vector& left, const Vector& right);

    
   
    
//Mathematical Operations
    value_type Magnitude();
    Vector u();
    Vector x(Vector B);
    
//Vector Qualities
    bool isColinearWith(Vector b)const;
    bool isOrthogonalTo(Vector b)const;
    
 
    
private:
    value_type i, j, k;
    bool is3D;
    
};
}
#endif /* Vector_hpp */

