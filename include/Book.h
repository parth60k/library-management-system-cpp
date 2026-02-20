#ifndef BOOK_H
#define BOOK_H

#include<string>
using namespace std;

class Book
{
    private:
        int id;
        string title;
        string author;
        bool isIssued;
        int issuedToUserId;

    public:
        Book(int id,string title,string author);
        
        int getId() const;
        string getTitle() const;
        string getAuthor() const;
        bool getisIssued() const;
        void setIssued(bool status);

        int getIssuedToUserId() const;
        void setIssuedToUser(int userId);
        string toFileString() const;

};

#endif