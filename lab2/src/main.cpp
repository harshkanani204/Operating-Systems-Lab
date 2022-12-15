#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include "../include/Matrix.h"
#include "../include/Scalar.h"
#include "../include/logger.h"
using namespace std;

int CLO = 0;

void printMat_out(Matrix &m, ostringstream &log)
{
    const vector<vector<double>> arr = m.getMatrix();
    if (CLO)
    {
        cout << arr.size() << " " << arr[0].size() << '\n';
    }

    for (vector<double> row : arr)
    {
        if(CLO)
        {
            cout << "| ";
        }
        log << "| ";
        for (double ele : row)
        {
            if (CLO)
            {
                cout << ele << ",";
            }
            log << ele << ",";
        }
        if (CLO)
        {
            cout << "|\n";
        }
        log << "|\n";
    }
}

void printMat(Matrix &m, ostringstream &log)
{
    const vector<vector<double>> arr = m.getMatrix();

    for (vector<double> row : arr)
    {
        log << "| ";
        for (double ele : row)
        {
            
            log << ele << ",";
        }
        log << "|\n";
    }
}

void printScalar_out(Scalar &m, ostringstream &log)
{
    const vector<vector<double>> arr = m.getScalar();
    if (CLO)
    {
        cout << arr.size() << " " << arr[0].size() << '\n';
    }

    for (vector<double> row : arr)
    {
        if(CLO)
        {
            cout << "| ";
        }
        log << "| ";
        for (double ele : row)
        {
            if (CLO)
            {
                cout << ele << ",";
            }
            log << ele << ",";
        }
        if (CLO)
        {
            cout << "|\n";
        }
        log << "|\n";
    }
}

void printScalar(Scalar &m, ostringstream &log)
{
    const vector<vector<double>> arr = m.getScalar();

    for (vector<double> row : arr)
    {
        log << "| ";
        for (double ele : row)
        {
            
            log << ele << ",";
        }
        log << "|\n";
    }
}

vector<vector<double>> ReadMatrix(int n, int m, ostringstream &log)
{
    vector<vector<double>> temp(n);

    string line;
    for (int i = 0; i < n; i++)
    {

        string tempString = "";
        vector<double> tempList;
        getline(cin, line);

        for (int j = 0; j < (int)line.size(); j++)
        {

            if (line[j] == ',')
            {

                tempList.push_back(stoi(tempString));
                tempString = "";
            }
            else
            {
                tempString.push_back(line[j]);
            }
        }

        temp[i] = tempList;
    }

    return temp;
}

void ReadFile(vector<vector<vector<double>>> &mat, int &cnt, vector<double> &input_scalar, int &scalar_cnt, ostringstream &log)
{


    string line;
    while (getline(cin, line))
    {
        if (line.size() == 0 or line[0] == '#')
            continue;
        else if (line.find(' ') == string::npos and line.find(',') == string::npos)
        {
            input_scalar.push_back(stoi(line));
            scalar_cnt++;
        }
        else if (line.find(',') == string::npos)
        {

            int len;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == ' ')
                {
                    len = i;
                    break;
                }
            }

            int n = stoi(line.substr(0, len));
            int m = stoi(line.substr(len));
            // cout<<n<<" "<<m<<'\n';
            vector<vector<double>> temp = ReadMatrix(n, m, log);
            // printMat(temp);

            mat.push_back(temp);
            cnt++;
        }
    }
}
Scalar ScalarOps(string &s, Scalar &mat1, Scalar &mat2, double input_scalar, ostringstream &log)
{

    if (s == "-a")
    {
        Scalar mat = mat2 + input_scalar;
        if (CLO)
        {
            cout << "Matrix after scalar addition\n";
        }
        log << "Matrix after scalar addition\n";
        printScalar_out(mat, log);
        return mat;
    }
    else if (s == "-s")
    {
        Scalar mat = mat2 - input_scalar;
        if (CLO)
        {
            cout << "Matrix after scalar subtraction\n";
        }
        log << "Matrix after scalar subtraction\n";
        printScalar_out(mat, log);
        return mat;
    }
    else if (s == "-m")
    {
        Scalar mat = mat2 * input_scalar;
        if (CLO)
        {
            cout << "Matrix after scalar multiplication\n";
        }
        log << "Matrix after scalar multiplication\n";
        printScalar_out(mat, log);
        return mat;
    }
    else if (s == "-d")
    {
        Scalar mat = mat2/input_scalar;
        if (CLO)
        {
            cout << "Matrix after scalar division\n";
        }
        log << "Matrix after scalar division\n";
        printScalar_out(mat, log);
        return mat;
    }
    else
    {
        if (CLO)
        {
            cout << "Error\n";
        }
        log << "Error\n";
    }
    Scalar A = Scalar(0,0);
    return A;
}
Matrix MatrixOps(string &s, Matrix &mat1, Matrix &mat2, double input_scalar, ostringstream &log)
{

    if (s == "-A")
    {
        Matrix mat = mat1 + mat2;
        if (CLO)
        {
            cout << "Matrix after Addition-\n";
        }
        log << "Matrix after Addition-\n";
        printMat_out(mat, log);
        return mat;
    }
    else if (s == "-S")
    {
        Matrix mat = mat1 - mat2;
        if (CLO)
        {
            cout << "Matrix after Subtraction-\n";
        }
        log << "Matrix after Subtraction-\n";
        printMat_out(mat, log);
        return mat;
    }
    else if (s == "-M")
    {
        Matrix mat = mat1 * mat2;
        if (CLO)
        {
            cout << "Matrix after Multiplication-\n";
        }
        log << "Matrix after Multiplication-\n";
        printMat_out(mat, log);
        return mat;
    }
    else if (s == "-T")
    {
        Matrix mat = mat1.transpose();
        if (CLO)
        {
            cout << "Matrix after Transpose\n";
        }
        log << "Matrix after Transpose\n";
        printMat_out(mat, log);
        return mat;
    }
   
    else
    {
        if (CLO)
        {
            cout << "Error\n";
        }
        log << "Error\n";
    }
    Matrix A = Matrix(0,0);
    return A;
}

bool is_lower(char c)
{
    return 97 <= c && c <= 122;
}

int main(int argc, char const *argv[])
{

    ostringstream log;

    vector<vector<vector<double>>> input_matrix;
    vector<double> input_scalar;
    int cnt = 0, scalar_cnt = 0;
    
    ReadFile(input_matrix, cnt, input_scalar, scalar_cnt, log);

    vector<vector<double>> temp_matrix = input_matrix[0];
    int temp_scalar , mat_rows = 1 ,scalar_idx = 0;
    bool scalar_present = false;
    for (int i = 1; i < argc; i++)
    {
        string s = argv[i];
        if (s == "DO")
        {
            CLO = 1;
            continue;
        }

        if (s == "-X")
        {
            Matrix A(temp_matrix.size(),temp_matrix[0].size());
            A.matrix = temp_matrix;
            printMat(A, log);
            double det = A.deter();
            if (mat_rows < cnt - 1)
                temp_matrix = input_matrix[mat_rows];
            mat_rows++;
            temp_scalar = det;
            scalar_present = true;
            log << "Determinant of Matrix\n";
            log << det << '\n';
            if (CLO)
            {
                cout << "# Determinant of Matrix\n"<< det << '\n'; 
            }
        }
        else if (is_lower(s[1]))
        {
            int scalar_to_use;
            if (scalar_present)
            {
                scalar_to_use = temp_scalar;
                scalar_present = false;
            }
            else
            {
                scalar_to_use = input_scalar[scalar_idx];
                scalar_idx++;
            }
            vector<vector<double>> temp_arr = temp_matrix;
            log << "input_scalar\n";
            log << scalar_to_use << '\n';

            log << "Matrix\n";
            Scalar A(temp_matrix.size(),temp_matrix[0].size());
            A.scalar = temp_matrix;
            printScalar(A, log);
            Scalar B(temp_arr.size(),temp_arr[0].size());
            B.scalar = temp_arr;
            A = ScalarOps(s, B, A, scalar_to_use, log);
            temp_matrix = A.scalar;
        }
        else if (s == "-T")
        {
            vector<vector<double>> temp_arr = temp_matrix;
            log << "Transpose operation\n";
            log << "Matrix\n";
            Matrix A(temp_matrix.size(),temp_matrix[0].size());
            A.matrix = temp_matrix;
            printMat(A, log);
            Matrix B(temp_arr.size(),temp_arr[0].size());
            B.matrix = temp_arr;
            printMat(A, log);
            A = MatrixOps(s, A, B, -1, log);
            temp_matrix = A.matrix;
        }
        else
        {
            log << "Matrix operation\n";
            log << "Matrix1\n";
            Matrix A(temp_matrix.size(),temp_matrix[0].size());
            A.matrix = temp_matrix;
            printMat(A, log);
            Matrix B(input_matrix[mat_rows].size(),input_matrix[mat_rows][0].size());
            B.matrix = input_matrix[mat_rows];
            printMat(A, log);
            log << "Matrix2\n";
            printMat(B, log);
            A = MatrixOps(s, A, B, -1, log);
            temp_matrix = A.matrix;
            mat_rows++;
        }
    }

    // Log::open();
    Log::msg(log);

    return 0;
}
