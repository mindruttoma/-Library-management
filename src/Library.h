#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Library
{
private:
	vector<Book> books;
	//Item 6: Explicitly disallow the use of compiler generated functions you do not want
    Library(const Library& ); // copy constructor declared private and without implementation
    Library& operator=(const Library& ) ; // assigment operator declared private and without implementation

public:
    
	void getListOfBooks();
	void getBookByAuthorAndTitle(string ,string);
	void getBooksByAuthor(string);
	void addBook(Book);
	void deleteBook(string author, string title);
    void rentBook(string author,string title);
    void returnBook(string author, string title,int numberOfPages);
	Library (Book);//constructor
    Library(vector<Book>); //constructor 
    Library();//default constructor
};
#endif
