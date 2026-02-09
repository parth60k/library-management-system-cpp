#ifndef BOOK_H
#define BOOK_H

#include<string>
using namespace std;

class Book
{
    private:
        int bookId;
        string title;
        string author;
        bool isIssued;

    public:
        Book(int id,const string& title,const string& author);
        
        int getBookId() const;
        string getTitle() const;
        string getAuthor() const;
        bool getisIssued() const;
        void setIssued(bool status);

};

#endif