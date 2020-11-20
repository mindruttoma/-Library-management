#include "Book.h"
using namespace std;

//copy constructor
Book::Book(const Book& b){
    title=b.title;
    author=b.author;
    numberOfPages=b.numberOfPages;
    numberOfSameBooks=b.numberOfSameBooks;
}
//assigment operator
Book Book::operator=(Book b) 
{   if(this==&b) return *this; //item 11 self assigment
    title=b.getTitle();
    author=b.getAuthor();
    numberOfSameBooks=b.getNumberOfSameBooks();
    numberOfPages=b.getNumberOfPages();
    return *this;
}



//default constructor
//Item 4: Make sure that objects are initialized before they’re used.
Book::Book() :
    title(""),
    author(""),
    numberOfPages(0),
    numberOfSameBooks(0)
{
    numberOfBooks++;
};
//constructor with parameters
//Item 4: Make sure that objects are initialized before they’re used.
Book::Book(string title, string author, int numberOfPages,int numberOfSameBooks) :
    title(title),
    author(author),
    numberOfPages(numberOfPages),
    numberOfSameBooks(numberOfSameBooks)
{
    numberOfBooks++;
};


int Book::numberOfBooks = 0;
string Book::getAuthor() {
    return this->author;
}
string Book::getTitle() {
    return this->title;
}
int Book::getNumberOfPages() {
    return this->numberOfPages;
}
int Book::getNumberOfBooks() {
    return numberOfBooks;
}
int Book::getNumberOfSameBooks() {
    return numberOfSameBooks;
}
void Book::displayInfo() {
    cout << "Title :" << this->title << " Autor: " << this->author << " Number of pages: " << this->numberOfPages<< " Number of copies : "<< this->getNumberOfSameBooks()<<endl;
}
void Book::setAuthor(string author) {
    this->author = author;
}
void Book::setTitle(string title) {
    this->title = title;
}
void Book::setNumberOfPages(int numberOfPages){
    this->numberOfPages = numberOfPages;
}

void Book::setNumberOfSameBooks(int numberOfSameBooks)
{
    this->numberOfSameBooks=numberOfSameBooks;
}
