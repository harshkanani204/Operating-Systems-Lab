// Header file for Matrix...
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <bits/stdc++.h>
using namespace std;

// Class to represent Matrix
class Matrix {
   
   public:
    // Constructor for Matrix
    Matrix(int rows, int columns);

    // Using Default Copy Constructor
    Matrix(const Matrix &m) = default;

    // Using Default Move Constructor
    Matrix(Matrix &&m) = default;

    // Functions to get number of rows or cols
    int getRows() const noexcept;
    int getCols() const noexcept;
    vector<vector<double>> getMatrix() const noexcept;

    // Overloaded operators
    // Default overloaded assignment operator
    Matrix &operator=(const Matrix &m) = default;
    Matrix &operator=(Matrix &&m) = default;

    // Operations: Matrix
    Matrix operator+(const Matrix &m) const;    // Both should have same Dimensions
    Matrix operator-(const Matrix &m) const;    // Both should have same Dimensions
    Matrix operator*(const Matrix &m) const;    // Cols of First Matrix = Rows of Second Matrix

    vector<vector<double>> matrix;
    // Function to get transpose of the matrix
    Matrix transpose() const noexcept;

    // Function to get the determinant of the matrix
    double deter() const;     // Should be square Matrix i.e. rows=cols
   
   private:

    int rows, cols;

    // Submatrix Function
    vector<vector<double>> getRemainingSubmatrix(const vector<vector<double>> &m, int r, int c) const;

    // Determinant Funtion
    double determinant(const vector<vector<double>> &m, int n) const;
};


#endif  // _MATRIX_H_