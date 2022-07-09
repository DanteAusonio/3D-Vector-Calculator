#include <iostream>
#include "Fraction.h"
#include "Vector.h"
using namespace std;
namespace cs_Vector {

/*                               //          \\
                                //Constructors\\
                               //              \\
*/

//Default Constructor
Vector::Vector() {
    i = 1;
    j = 1;
    k = 1;
    is3D = true;
}




//2D Constructor
Vector::Vector(value_type x, value_type y) {
    
    i = x;
    j = y;
    is3D = false;
}




//3D Constructor
Vector::Vector(value_type x, value_type y, value_type z) {
    
    i = x;
    j = y;
    k = z;
    is3D = true;
}





//Copy Constructor
Vector::Vector(const Vector& right) {
    
    if (right.is3D == false) {
        i = right.i;
        j = right.j;
        is3D = false;
    } else if (right.is3D == true) {
        i = right.i;
        j = right.j;
        k = right.k;
        is3D = true;
    }
}




/*                              //                \\
                               //Operator Overloads\\
                              //                    \\
*/


//Assignment Operator Overload
Vector Vector::operator=(const Vector &right) {
    
    if (right.is3D == false) {
        i = right.i;
        j = right.j;
        is3D = false;
    } else if (right.is3D == true) {
        i = right.i;
        j = right.j;
        k = right.k;
        is3D = true;
    }
    return *this;
}






//Insertion Operator Overload
ostream& operator<<(ostream& out, const Vector& right) {
    
    if (right.is3D == false) {
        out << "<" << right.i << ", " << right.j << "> ";
        return out;
    } else {
        out << "<" << right.i << ", " << right.j << ", " << right.k << "> ";
        return out;
    }
}






//Extraction Operator Overload
istream& operator>>(istream& in, Vector& right) {
    
  
    char temp;
    in >> temp;
    if (temp == '<') {
        in >> right.i;
        in >> temp;
        if (temp == ',') {
            in >> right.j;
            in >> temp;
            if (temp == '>') {
                right.k = 0;
                right.is3D = false;
                return in;
            } else if (temp == ',') {
                in >> right.k;
                right.is3D = true;
                in >> temp;
            }
        }
    }
    return in;
}



bool operator==(const Vector& left, const Vector& right){
    
    if ((left.i == right.i) && (left.j == right.j) && (left.k == right.k)) {
        return true;
    } else {
        return false;
    }
    
    
    
}





/*                          //                       \\
                           // Mathematical Operations \\
                          //                           \\
*/








//Scalar Multiple Operator Overload
Vector operator*(const Vector::value_type& multiplier, const Vector& right) {
    Vector result;
    
    result.i = right.i * multiplier;
    result.j = right.j * multiplier;
    if (right.is3D == true) {
        result.k = right.k * multiplier;
    }
    
    return result;
}







//Scalar Division overload
Vector operator/(const Vector& left, const Vector::value_type& multiplier) {
    Vector result;
    
    result.i = left.i / multiplier;
    result.j = left.j / multiplier;
    if (left.is3D == true) {
        result.k = left.k / multiplier;
    }
    

    return result;
}







//Vector Division Overload
Vector operator/(const Vector& left, const Vector& right) {
    Vector result;
    
    result.i = left.i / right.i;
    result.j = left.j / right.j;
    if (left.is3D == true) {
        result.k = left.k / right.k;
    };
    
    return result;
}







//Dot Product Operator Overload
Vector::value_type operator*(const Vector& multiplier, const Vector& right) {
    
    Vector result;
    Vector::value_type returnResult;
    
    result.i = right.i * multiplier.i;
    result.j = right.j * multiplier.j;
    result.k = right.k * multiplier.k;
    returnResult = result.i + result.j + result.k;
    
    return returnResult;
}




//Vector Addition
Vector operator+(const Vector& left, const Vector& right) {
    
    Vector result(left.i + right.i, left.j + right.j, left.k + right.k);
    return result;
}





//Vector Subtraction
Vector operator-(const Vector& left, const Vector& right) {
    
    Vector result(left.i - right.i, left.j - right.j, left.k - right.k);
    return result;
}









//Find Vector Magnitude

Vector::value_type Vector::Magnitude() {
    
    value_type x;
    value_type y;
    value_type z;
    value_type result;
    
    x = i * i;
    y = j * j;
    z = k * k;
    result = x + y + z;
    result.sqrt();
    
    return result;
}







//Unit Vector

Vector Vector::u() {
    
    Vector u(i, j, k);
    value_type uMag = this->Magnitude();
    u = u / uMag;
    
    
    return u;
}







//Cross Product
Vector Vector::x(Vector inVec) {
    Vector Result;
    
    Result.i = ((j * inVec.k) - (k * inVec.j));
    Result.j = -1*((i * inVec.k) - (k * inVec.i));
    Result.k = ((i * inVec.j) - (j * inVec.i));
    
    return Result;
}










/*                            //                \\
                             // Vector Qualities \\
                            //                    \\
*/



//Check Coliniarity
bool Vector::isColinearWith(Vector b)const {
    
    //int ConditionOfColinearity;
    Vector::value_type n;
    Vector a = *this;
    
        if (a.i != 0){
            n = b.i/a.i;
        } else if (a.i == 0) {
            n = b.j/a.j;
        } else if (a.i == 0 && a.j == 0) {
            n = b.k/a.k;
        }
        
        a = n * a;
        if (a == b) {
            return true;
        } else {
            return false;
        }
    }
    
    


//Check 2 Vectors are Orthogonal
bool Vector::isOrthogonalTo(Vector b)const {
    
    Vector a = *this;
    value_type x = a * b;
    
    if (x == 0) {
        return true;
    } else {
        return false;
    }
    
}







}





