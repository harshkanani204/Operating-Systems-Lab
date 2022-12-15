// Header file for Matrix...
#ifndef _SCALAR_H_
#define _SCALAR_H_

#include <bits/stdc++.h>
using namespace std;

// Class to represent Matrix
class Scalar {
   
   public:
    // Constructor for Scalar
    Scalar(int rows, int columns);

    // Using Default Copy Constructor
    Scalar(const Scalar &m) = default;

    // Using Default Move Constructor
    Scalar(Scalar &&m) = default;    // Scalar &operator=(const Scalar &m) = default;
    // Scalar &operator=(Scalar &&m) = default;

    // Functions to get number of rows or cols
    int getRows() const noexcept;
    int getCols() const noexcept;
    vector<vector<double>> getScalar() const noexcept;

    // Overloaded operators
    // Default overloaded assignment operator
    Scalar &operator=(const Scalar &m) = default;
    Scalar &operator=(Scalar &&m) = default;


    // Operations: Scaler
    Scalar operator+(double x) const noexcept;
    Scalar operator-(double x) const noexcept;
    Scalar operator*(double x) const noexcept;
    Scalar operator/(double x) const;     // Division by Zero Exception
    vector<vector<double>> scalar;

   private:

    int rows, cols;
};

#endif  // _SCALAR_H_