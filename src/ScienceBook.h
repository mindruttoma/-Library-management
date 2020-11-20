#ifndef SCIENCE_BOOK
#define SCIENCE_BOOK


#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class ScienceBook : public ScienceBook   // derived class
{
    public:
        string getDomain();
        ScienceBook (const ScienceBook&);
        ScienceBook operator = (ScienceBook);
    
    private:
        string domain;
    

};
#endif