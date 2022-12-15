#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

#ifndef __LOG_H__
#define __LOG_H__

namespace Log
{
    void msg(ostringstream &ss)
    {
        ofstream file;
        const string log = "Console.log";
        file.open(log.c_str(), ios::out | ios::app);

        file << ss.str() << "\n";
        file.close();
    }

    void ThrowError(const char* e)
    {
        ofstream file;
        const string log = "Console.log";
        file.open(log.c_str(), ios::out | ios::app);

        ostringstream ss;
        ss << "[ERROR] : " << e << "\n";
        file << ss.str() << "\n";
        file.close();
    }
}

#endif