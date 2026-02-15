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

void Library::addUser()
{
    int id;
    string name;

    cout<<"Enter user ID: ";
    cin>>id;
    cin.ignore();

    cout<<"Enter user name: ";
    getline(cin,name);

    User newUser(id, name);
    users.push_back(newUser);

    cout<<"USer added succcessfully!"<<endl;

}

void Library::displayUsers() const
{
    if(users.empty())
    {
        cout<<"No users available"<<endl;
        return;
    }
    cout<<"\n----  User List  ----"<<endl;
    for(const User& user : users)
    {
        cout<<"ID: "<<user.getId()
            <<", Name: "<<user.getName()<<endl;
    }
}

Book* Library::findBookById(int id)
{
    for(auto &book : books)
    {
        if(book.getId() == id)
        return &book;
    }
    return nullptr;
}

User* Library::findUserById(int id)
{
    for(auto &user : users)
    {
        if(user.getId() == id)
        return &user;
    }
    return nullptr;
}

void Library::issueBook()
{
    int bookId,userId;

    cout<<"Enter Book ID: ";
    cin>>bookId;

    Book* book= findBookById(bookId);
    if(!book)
    {
        cout<<"Book not found"<<endl;
        return;
    }
    if(book->getisIssued())
    {
        cout<<"Book already issued"<<endl;
        return;
    }

    cout<<"Enter User ID: ";
    cin>>userId;

    User* user= findUserById(userId);
    if(!user)
    {
        cout<<"User not found"<<endl;
        return;
    }
    
    book->setIssued(true);
    book->setIssuedToUser(userId);

    cout<<"Book issued successfully to "<<user->getName()<<"!"<<endl;
}

void Library::returnBook()
{
    int bookId;

    cout<<"Enter Book ID to return: ";
    cin>>bookId;

    Book* book =findBookById(bookId);
    if(!book)
    {
        cout<<"Book not found"<<endl;
        return;
    }

    if(!book->getisIssued())
    {
        cout<<"Book is not issued"<<endl;
        return;
    }

    book->setIssued(false);
    book->setIssuedToUser(-1);

    cout<<"Book returned successfully!"<<endl;
}