#include "ScienceBook.h"
#include "Book.h"
using namespace std;

ScienceBook::ScienceBook(const ScienceBook& b): // copy constructor
    Book(b) , // invoke copy constructor from base class // item 12
    domain(b.domain)
{
;
};
ScienceBook ScienceBook::operator=(ScienceBook b)
{    
    if(this==&b) return *this; // item 11 self-assigment
    Book::operator=(b); // invoke assigment operator from base class // item 12
    domain=b.domain;
    return *this; // return this reference -> item 10
}