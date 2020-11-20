#ifndef SCIENCE_BOOK
#def SCIENCE_BOOK

class ScienceBook : public ScienceBook   // derived class
{
    public:
        string getDomain();
        ScienceBook (const ScienceBook&);
        ScienceBook operator = (ScienceBook);
    
    private:
        string domain;
    

}