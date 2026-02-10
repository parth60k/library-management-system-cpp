#include <iostream>
#include "Library.h"

using namespace std;

Library::Library()
{
    
}
void Library::addBook()
{
    int id;
    string title,author;

    cout<<"Enter Book Id: ";
    cin>> id;
    cin.ignore();

    cout<<"Enter book title: ";
    getline(cin,title);

    cout<<"Enter author name: ";
    getline(cin,author);

    Book newBook(id,title,author);
    books.push_back(newBook);

    cout<<"Book added successfully!"<<endl;
}

void Library::displayBooks() const
{
    if(books.empty()){
        cout<<"No books available"<<endl;
        return;
    }

    cout<<"\n---- Book List ----"<<endl;
    for(const Book& book : books)
    {
        cout<<" Id: "<< book.getId()
            <<", Title: "<< book.getTitle()
            <<", Author: "<< book.getAuthor()
            <<", Issued: "<< (book.getisIssued() ? "Yes" : "No")
            << endl;
    }
}