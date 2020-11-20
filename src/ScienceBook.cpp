#include "ScienceBook.h"

ScienceBook::ScienceBook(const ScienceBook& b): // copy constructor
    Book(b) ; // invoke copy constructor from base class // item 12
    domain(b.domain);
{
;
}
ScieneBook ScienceBook::operator=(ScienceBook b)
{
    Book::operator=b; // invoke assigment operator from base class // item 12
    domain=b.domain;
    return *this; // return this reference -> item 10
}