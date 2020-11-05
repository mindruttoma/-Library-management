
#include "Library.h"
using namespace std;

//Item 4: Make sure that objects are initialized before they’re used.
Library::Library()
{
    books={};
}

//Item 4: Make sure that objects are initialized before they’re used.
Library::Library(Book book)
{
    books.push_back(book);
}

//Item 4: Make sure that objects are initialized before they’re used.
Library::Library(vector<Book>books)
{
    this->books=books;
}

void Library::returnBook(string author , string title , int numberOfPages)
{
    for(int i=0; i<this->books.size(); i++)
        if((this->books[i].getAuthor() == author) && (this->books[i].getTitle()==title))
        {
            this->books[i].setNumberOfSameBooks(this->books[i].getNumberOfSameBooks()+1);
            return;
        }
    Book book(title,author,numberOfPages,1);
    this->addBook(book);
    return;
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
       if(this->books[i].getAuthor()==author)
       {
           books[i].displayInfo();
       }
   }
}


int main()
{   
    Book m1("Poezii","Eminescu",200,5);
    Book m2("Povesti","Creanga",150,6);
    Book m3("Comedii","Caragiale",400,7);
    
    //Item 5: Know what functions C++ silently writes and calls.
    //copy constructor
    Book m4=m3;
    cout<<m4.getTitle()<<"\n";
    cout<<m3.getTitle()<<"\n";
    
    //Item 6: Explicitly disallow the use of compiler generated functions you do not want
    //copy constructor is private
    Library b1(m1);
    //Library b2=b1;
    //assigment operator is private
    //Library b3;
    //b3=b1;



    
    
  /*  Book b1;
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

*/

}


