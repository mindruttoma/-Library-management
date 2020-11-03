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
	Book(void);
	Book(string, string, int,int);
};

Book Book::operator=(Book b)
{
    title=b.getTitle();
    author=b.getAuthor();
    numberOfSameBooks=b.getNumberOfSameBooks();
    numberOfPages=b.getNumberOfPages();
    return *this;
}


Book::Book() :
    title(""),
    author(""),
    numberOfPages(0),
    numberOfSameBooks(0)
{
    numberOfBooks++;
};

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
class Library
{
private:
	vector<Book> books;
    Library(const Library& lib) = delete; // copy constructor deleted
    Library& operator=(const Library& lib) = delete ; // = operator deleted
public:
    
	void getListOfBooks();
	void getBookByAuthorAndTitle(string ,string);
	void getBooksByAuthor(string);
	void addBook(Book);
	void deleteBook(string author, string title);
    void rentBook(string author,string title);
    void returnBook(string author, string title,int numberOfPages);
	Library (Book);
    Library(vector<Book>);
    Library();
};


void Library::returnBook(string author , string title , int numberOfPages)
{
    for(int i=0; i<this->books.size(); i++)
        if((this->books[i].getAuthor() == author) && (this->books[i].getTitle()==title)){
            this->books[i].setNumberOfSameBooks(this->books[i].getNumberOfSameBooks()+1);
            return;
        }
    Book book(title,author,numberOfPages,1);
    this->addBook(book);
    return;
}

Library::Library()
{
    books={};
}
Library::Library(Book book)
{
    books.push_back(book);
}
Library::Library(vector<Book>books)
{
    this->books=books;
}
void Library::getBookByAuthorAndTitle(string author , string title)
{
    for(int i=0;i<books.size();i++)
    {
        if((books[i].getAuthor()==author) && (books[i].getTitle()==title))
        {
            books[i].displayInfo();
        }
    }
}
void Library::getListOfBooks()
{
    for(int i=0;i<books.size();i++)
    {
        books[i].displayInfo();
    }
}


void Library::addBook(Book b){
    for(int i=0;i<this->books.size();i++)
    {
        if(this->books[i].getTitle()==b.getTitle() &&  this->books[i].getAuthor() == b.getAuthor() )
        {
            int val1 = this->books[i].getNumberOfSameBooks();
            int val2 = b.getNumberOfSameBooks();
            this->books[i].setNumberOfSameBooks(val1+val2);
            return;
        }
    }
    this->books.push_back(b);
}

void Library::deleteBook(string author,string title)
{
    for (int i=0;i<this->books.size();i++)
    {
        if(this->books[i].getTitle() == title && this->books[i].getAuthor() == author )
        {
            this->books.erase(this->books.begin()+i);
            break ;
        }
    }
}

void Library::rentBook(string author,string title)
{
    for (int i=0;i<this->books.size();i++)
    {
        if(this->books[i].getTitle() == title && this->books[i].getAuthor() == author && this->books[i].getNumberOfSameBooks()!=0)
        {

            int val1 = this->books[i].getNumberOfSameBooks();
            this->books[i].setNumberOfSameBooks(val1-1);
            return;
        }
    }
    cout<<"Sorry, we haven't available this book!"<<endl;
}

void Library::getBooksByAuthor(string author)
{ for (int i=0;i<this->books.size();i++)
   {
       if(this->books[i].getAuthor()==author){
           books[i].displayInfo();
       }
   }
}


int main()
{
    Book b1;
    Library l;
    string title1;
    string author1;
    int numberOfPages1;
    int numberOfSameBooks1;
    int choise;
    while(1){
       
       cout<<"1.Add a book \n";
       cout<<"2.Delete a book\n";
       cout<<"3.Check a book\n";
       cout<<"4.Rent a book\n";
       cout<<"5.Display books by author\n";
       cout<<"6.Display all information for books\n";
       cout<<"7.Return book\n";
       cout<<"8.Quit\n";
       cin>>choise;
       switch(choise){
       	case 1: 
               cout<<"Enter title\n";
               cin>>title1;
               b1.setTitle(title1);
               cout<<"Enter author\n";
               cin>>author1;
               b1.setAuthor(author1);
               cout<<"Enter a number of pages\n";
               cin>>numberOfPages1;
               b1.setNumberOfPages(numberOfPages1);
               cout<<"Enter a number of same books\n";
               cin>>numberOfSameBooks1;
               b1.setNumberOfSameBooks(numberOfSameBooks1);
               l.addBook(b1);
               l.getListOfBooks();
               break;
 
      	case 2:
               cout<<"Enter title\n";
               cin>>title1;
               cout<<"Enter author\n";
               cin>>author1;
               l.deleteBook(author1,title1);
               l.getListOfBooks();
               break;
        
     	case 3:
               cout<<"Enter title\n";
               cin>>title1;
               cout<<"Enter author\n";
               cin>>author1;
               l.getBookByAuthorAndTitle(author1 ,title1);
               break;

       	case 4: 
               cout<<"Enter title\n";
               cin>>title1;
               cout<<"Enter author\n";
               cin>>author1;
               l.rentBook( author1, title1);
               break;
      
       	case 5: 
               cout<<"Enter author\n";
               cin>>author1;
               l.getBooksByAuthor(author1);
               break;
         
       	case 6: 
               cout<<"List of books is:\n";
               l.getListOfBooks();
               break;
        case 7:
               cout<<"Please type author :";
               cin>>author1;
               cout<<"Please type title :";
               cin>>title1;
               cout<<"Please type number of pages: ";
               cin>>numberOfPages1 ;
               l.returnBook(author1,title1,numberOfPages1);
               break;
 
        case 8:
               
               default: exit(0);
            }

    }

return 0;



}

