#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
using namespace std;

#ifndef __LOG_H__
#define __LOG_H__

namespace Log
{
    void msg(ostringstream &ss);
    void ThrowError(const char* msg);
}

#endif