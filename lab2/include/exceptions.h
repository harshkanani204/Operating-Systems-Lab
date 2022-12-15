// Header File for Exceptions

// First List all the exceptions
/*
 --while taking inputs
    -file not found
    -if no arguments are there
    -arguements are incomplete
    -invalid arguements
        -arguements other than a,s,d,m,A,S,D,M
        -invalid dimentions
        -invalid operations
        -invalid input
 -- during the execution 
    -if dividing by zero
    -trying to access index which are out of boundaries
    -calculating determinant of nonsquare matrix
    -if dimension of matrices which are being adeed are not equal
*/
#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <exception>


//file not found
class  FileNotFound : public std :: exception
{
public:
     FileNotFound() noexcept = default;
    virtual ~ FileNotFound() noexcept = default;
    virtual const char* what() const noexcept override;
};

//no arguements are there
class  NoArguements : public std :: exception
{
public:
     NoArguements() noexcept = default;
    virtual ~ NoArguements() noexcept = default;
    virtual const char* what() const noexcept override;
};

//arguements are incomplete
class  IncompleteArguements : public std :: exception
{
public:
     IncompleteArguements() noexcept = default;
    virtual ~ IncompleteArguements() noexcept = default;
    virtual const char* what() const noexcept override;
};
//invalid arguements
class  InvalidArguement : public std :: exception
{
public:
     InvalidArguement() noexcept = default;
    virtual ~ InvalidArguement() noexcept = default;
    virtual const char* what() const noexcept override;
};

// if input format of matrices is not in conventional form in the input file
class  InvalidInput : public std :: exception
{
public:
     InvalidInput() noexcept = default;
    virtual ~ InvalidInput() noexcept = default;
    virtual const char* what() const noexcept override;
};
//invalid dimentions
class  InvalidDimentionInput : public std :: exception
{
public:
     InvalidDimentionInput() noexcept = default;
    virtual ~ InvalidDimentionInput() noexcept = default;
    virtual const char* what() const noexcept override;
};
//invalid operations such as scalar operations to matxices
class  InvalidOperation : public std :: exception
{
public:
     InvalidOperation() noexcept = default;
    virtual ~ InvalidOperation() noexcept = default;
    virtual const char* what() const noexcept override;
};
//if dividing by zero
class  DividingByZeroException : public std :: exception
{
public:
     DividingByZeroException() noexcept = default;
    virtual ~ DividingByZeroException() noexcept = default;
    virtual const char* what() const noexcept override;
};
//accesing out of bound indexes
class  OutOfBounds : public std :: exception
{
public:
     OutOfBounds() noexcept = default;
    virtual ~ OutOfBounds() noexcept = default;
    virtual const char* what() const noexcept override;
};
//determinant exeption 
class  DeterminantExeption : public std :: exception
{
public:
     DeterminantExeption() noexcept = default;
    virtual ~ DeterminantExeption() noexcept = default;
    virtual const char* what() const noexcept override;
};
//dimention operation exeption
class  DimentionOperationException : public std :: exception
{
public:
     DimentionOperationException() noexcept = default;
    virtual ~ DimentionOperationException() noexcept = default;
    virtual const char* what() const noexcept override;
};


#endif  // _EXCEPTIONS_H_