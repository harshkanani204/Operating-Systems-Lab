// CPP File For Exceptions

// First list all the exceptions in header file and then write msg here
/*
 --while taking inputs
    -file not found
    -if no arguments are there
    -arguements are incomplete
    -invalid arguements
        -arguements other than a,s,d,m,A,S,D,M
        -invalid dimentions
        -invalid operations
        -
 -- during the execution 
    -if dividing by zero
    -trying to access index which are out of boundaries
    -calculating determinant of nonsquare matrix
    -if dimension of matrices which are being adeed are not equal
*/
#include "../include/exceptions.h"

//if input file is not found  
const char* FileNotFound::what() const noexcept{
    return "File not found...Is there such file???";
}


//no arguements are there
const char* NoArguements::what() const noexcept{
    return "No Arguements received, require some arguements...";
}


//arguements are incomplete 
const char* IncompleteArguements::what() const noexcept{
    return "Incomplete Arguement!!! More arguements are needed";
}


//invalid arguements
const char* InvalidArguement::what() const noexcept{
    return "Arguement is not Valid...Check the arguement again";
}

//if input format of matrices is not in conventional form in the input file
const char* InvalidInput::what() const noexcept{
    return "Input is not in the conventional form";
}

//invalid dimentions in the input file
const char* InvalidDimentionInput::what() const noexcept{
    return "Matrix Dimentions are incorrect!!! Check if number of rows/column are negative  ";
}


//invalid operations such as scalar operations to matxices
const char* InvalidOperation::what() const noexcept{
    return "Invalid operations!!! check if operation arguement is correct or not...";
}


//if dividing by zero
const char* DividingByZeroException::what() const noexcept{
    return "Oops...you are dividing by zero somewhere";
}


////accesing out of bound indexes
const char* OutOfBounds::what() const noexcept{
    return "Index are going out of bounds";
}


//determinant exeption...for non square matrix 
const char* DeterminantExeption::what() const noexcept{
    return "That Matrix is not square matrix...cant give its determinant";
}

//dimention operation exeption
const char* DimentionOperationException::what() const noexcept{
    return "oops cant add/sub...Check if dimentions of both the matrixes are same";
}