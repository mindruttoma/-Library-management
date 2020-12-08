#include "LibraryFactory.h"
#include "Library.h"
using namespace std;
Library* LibraryFactory ::createLibrary(){
    tr1::shared_ptr <Library> pLibrary(createLibrary()); // ITEM 13 -> AUTO RELEASE OBJECT BY DESTRUCTOR WHEN IT IS USELESS (MEMORY LEAK)
    return *pLibrary;
}