#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include "Vector.h"
#include "fraction.h"
using namespace std;
using namespace cs_fraction;
using namespace cs_Vector;



void compoundProduct(const Vector& A, const Vector& B, Vector& C);
void get_Vector(Vector& inVec);
void check_Orthognality(const Vector& A, const Vector& B);
void check_colinearity(const Vector& A, const Vector& B);
  

int main()
{
    Vector A;
    Vector B;
    Fraction f1(2, 3);
    
    cout << "input A: ";
    cin >> A;
    cout << "input B: ";
    cin >> B;
    cout << "Vector A: " << A << " Vector B: " << B << endl;
    
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    
    cout << "2A = " << 2 * A << endl;
    cout << "(2/3)B = " << f1 * B << endl;
    cout << "Dot Product of A & B, or A (dot) B, or A * B = " << A * B << endl;
    cout << "Cross Product of A & B, or A (cross) B, or A x B = " << A.x(B) << endl;
    cout << "B x A = " << B.x(A) << endl;
    cout << "Magnitude of A is: " << A.Magnitude() << endl;
    cout << "Unit Vector of B is: " << B.u() << endl;
    check_colinearity(A, B);
    check_Orthognality(A, B);
    cout << "The Scalar Tribble Product of A, B, and the unit Vector of A is: ";
    Vector C = A.u();
    compoundProduct(A, B, C);
    cout << endl;
}



//Scalar Tripple Product
void compoundProduct(const Vector& A, const Vector& B, Vector& C) {
    
    Fraction x = A * (C.x(B));
    cout << x << endl;
}






void check_Orthognality(const Vector& A, const Vector& B) {
    
    if (A.isOrthogonalTo(B)){
        cout << "A and B ARE orthognal!" << endl;
    } else {
        cout << "A and B are NOT orthogonal" << endl;
    }
}






void check_colinearity(const Vector& A, const Vector& B) {
    
    if (A.isColinearWith(B)){
        cout << "A and B ARE colinear!" << endl;
    } else {
        cout << "A and B are NOT colinear" << endl;
    }
}






