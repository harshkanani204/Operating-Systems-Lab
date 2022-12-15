// CPP File for Matrix
#include "../include/Scalar.h"
#include "../include/exceptions.h"
#include "../include/logger.h"
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

// Constructor
Scalar::Scalar(int rows, int cols) 
    : rows{rows}, cols{cols} {
    if (rows <= 0 || cols <= 0) 
    {
        InvalidDimentionInput A;
        Log::ThrowError(A.what());
    }

    scalar.assign(rows, vector<double>(cols, 0));
}

int Scalar::getRows() const noexcept {
    return this->rows;
}

int Scalar::getCols() const noexcept {
    return this->cols;
}

vector<vector<double>> Scalar::getScalar() const noexcept {
    return this->scalar;
}

// Operations: Scaler
Scalar Scalar::operator+(double x) const noexcept 
{
    Scalar result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.scalar[i][j] = this->scalar[i][j] + x;
        }
    }

    return result;
}

Scalar Scalar::operator-(double x) const noexcept 
{
    Scalar result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.scalar[i][j] = this->scalar[i][j] - x;
        }
    }

    return result;
}

Scalar Scalar::operator*(double x) const noexcept 
{
    Scalar result(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.scalar[i][j] = this->scalar[i][j] * x;
        }
    }

    return result;
}

Scalar Scalar::operator/(double x) const 
{
    if (x == 0) 
    {
        DividingByZeroException A;
        Log::ThrowError(A.what());
    }

    Scalar result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.scalar[i][j] = this->scalar[i][j] / x;
        }
    }

    return result;
}

