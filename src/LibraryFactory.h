#ifndef LIBRARY_FACTORY
#include <iostream>
using namespace std;

#def LIBRARY_FACTORY

class LibraryFactory {
    private:
        Library *library;
    public:
        Library* createLibrary();
        LibraryFactory(const LibraryFactory&)=delete; // ITEM 14 -> DISABLE COPYING RAII OBJECT
        LibraryFactory& operator=(const LibraryFactory&)=delete; // ITEM 14 -> DISABLE COPYING RAII OBJECT
}

#endif