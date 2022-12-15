// CPP File for Matrix
#include "../include/Matrix.h"
#include "../include/exceptions.h"
#include "../include/logger.h"
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

// Constructor
Matrix::Matrix(int rows, int cols) 
    : rows{rows}, cols{cols} {
    if (rows <= 0 || cols <= 0) 
    {
        InvalidDimentionInput A;
        Log::ThrowError(A.what());
    }

    matrix.assign(rows, vector<double>(cols, 0));
}


int Matrix::getRows() const noexcept {
    return this->rows;
}

int Matrix::getCols() const noexcept {
    return this->cols;
}

vector<vector<double>> Matrix::getMatrix() const noexcept {
    return this->matrix;
}

// Operations: Matrix
Matrix Matrix::operator+(const Matrix &m) const 
{
    if (this->rows != m.rows || this->cols != m.cols) 
    {
        DimentionOperationException A;
        Log::ThrowError(A.what());
    }

    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.matrix[i][j] = m.matrix[i][j] + this->matrix[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix &m) const 
{
    if (this->rows != m.rows || this->cols != m.cols) 
    {
        DimentionOperationException A;
        Log::ThrowError(A.what());
    }

    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix &m) const 
{
    if (this->cols != m.rows) 
    {
        DimentionOperationException A;
        Log::ThrowError(A.what());
    }

    Matrix result(this->rows, m.cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < m.cols; j++) 
        {
            for (int k = 0; k < this->cols; k++) 
            {
                result.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::transpose() const noexcept 
{
    Matrix result(this->cols, this->rows);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.matrix[j][i] = this->matrix[i][j];
        }
    }

    return result;
}

vector<vector<double>> Matrix::getRemainingSubmatrix(const vector<vector<double>> &m, int r, int c) const 
{
    int currR = m.size();
    int currC = m[0].size();

    if (currR <= 1 || currC <= 1) 
    {
        InvalidDimentionInput A;
        Log::ThrowError(A.what());
    }


    if (r < 0 || r >= currR || c < 0 || c >= currC) 
    {
        OutOfBounds A;
        Log::ThrowError(A.what());
    }

    vector<vector<double>> result(currR - 1, vector<double>(currC - 1, 0));
    int newR = 0; 
    int newC = 0;

    for (int i = 0; i < currR; i++) 
    {
        // Exclude i-th row
        if(i == r)
        {
            continue;
        }

        for(int j = 0; j < currC; j++) 
        {
            // Exclude j-th col
            if(j == c)
            {
                continue;  
            }
            result[newR][newC] = m[i][j];
            newC++;
        }
        newR++;
        newC = 0;
    }
    return result;
}

double Matrix::determinant(const vector<vector<double>> &m, int n) const 
{
    // Determinant of 1x1 matrix is the value itself
    if(n == 1) 
    {
        return m[0][0];
    }

    // result = final answer, i = row along which determinant is evaluated
    double result = 0;
    int sign = 1;
    int i = 0;
    for (int j = 0; j < n; j++) 
    {
        result += (sign * m[i][j] * determinant(getRemainingSubmatrix(m, i, j), n - 1));
        sign = -sign;
    }

    return result;
}

double Matrix::deter() const 
{
    if (this->rows != this->cols) 
    {
        DeterminantExeption A;
        Log::ThrowError(A.what());
    }

    return determinant(this->matrix, this->rows);
}
