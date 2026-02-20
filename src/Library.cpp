#include <iostream>
#include<fstream>       
#include<sstream>
#include "Library.h"

using namespace std;

Library::Library()
{
    loadBooksFromFile();
    loadUsersFromFile();
}

void Library::saveBooksToFile() const
{
    ofstream file("books.txt");

    for(const auto &book : books)
    {
        file<<book.toFileString()<<endl;
    }
    file.close();
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


void Library::saveBooksToFile() const
{
    ofstream file("books.csv");

    for(const Book &book : books)
    {
        file<< book.getId() <<","
            << book.getTitle() <<","
            << book.getAuthor() <<","
            << book.getisIssued() <<","
            << book.getIssuedToUserId() << endl;
    }
    
    cout << "Saving books...\n";

    file.close();
}

void Library::loadBooksFromFile()
{
    ifstream file("books.csv");
    
    if(!file.is_open())
        return;

    string line;

    while(getline(file,line))
    {
        stringstream ss(line);
        string token;

        int id;
        string title,author;
        bool isIssued;
        int issuedTo;

        getline(ss,token,',');
        id=stoi(token);

        getline(ss,title,',');
        getline(ss,author,',');

        getline(ss,token,',');
        isIssued = stoi(token);

        getline(ss,token,',');
        issuedTo=stoi(token);

        Book book(id,title,author);
        book.setIssued(isIssued);
        book.setIssuedToUser(issuedTo);

        books.push_back(book);
    }
    cout << "Loading books...\n";


    file.close();
}

void Library::saveUsersToFile() const
{
    ofstream file("users.csv");

    for(const User &user : users)
    {
        file << user.getId()<<","
             << user.getName()<<endl;
    }
    
    cout << "Saving users...\n";

    file.close();
}

void Library::loadUsersFromFile()
{
    ifstream file("users.csv");

    if(!file.is_open())
        return;
    
        string line;

        while(getline(file,line))
        {
            stringstream ss(line);
            string token;

            int id;
            string name;

            getline(ss,token,',');
            id=stoi(token);

            getline(ss,name,',');

            User user(id,name);
            users.push_back(user);
        }
        cout << "Loading users...\n";


        file.close();
}

void Library::loadBooksFromFile()
{
    ifstream file("books.txt");
    string line;

    while(getline(file,line))
    {
        stringstream ss(line);
        string idStr , title, author, issuedStr, userIdStr;

        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, issuedStr, ',');
        getline(ss, userIdStr, ',');

        int id=stoi(idStr);
        bool issued = stoi(issuedStr);
        int userId = stoi(userIdStr);

        Book book(id,title,author);
        book.setIssued(issued);
        book.setIssuedToUser(userId);

        books.push_back(book);
    }
    file.close();
}

void Library::saveUsersToFile() const
{
    ofstream file("users.txt");

    for(const auto &user :users)
    {
        file<< user.toFileString() <<endl;
    }
    file.close();
}

void Library::loadUsersFromFile() 
{
    ifstream file("users.txt");
    string line;

    while(getline(file,line))
    {
        stringstream ss(line);
        string idStr,name;

        getline(ss,idStr,',');
        getline(ss,name,',');

        int id=stoi(idStr);

        User user(id,name);
        users.push_back(user);
    }
    file.close();
}