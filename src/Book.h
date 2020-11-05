#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Book {
private:
	
	static int numberOfBooks;
	int numberOfPages;
	string author;
	string title;
    int numberOfSameBooks;
	
	
    

public: 
    //Item 5: Know what functions C++ silently writes and calls.
    Book(const Book&); //copy constructor
	Book operator=(Book);
	string getTitle();
	string getAuthor();
	int getNumberOfPages();
    int getNumberOfSameBooks();
	void setTitle(string);
	void setAuthor(string);
	void setNumberOfPages(int);
	static int getNumberOfBooks();
	void displayInfo();
    void setNumberOfSameBooks(int);
	Book(void); //default constructor
	Book(string, string, int,int); //constructor with parameters
};

#endif


