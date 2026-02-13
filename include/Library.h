#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>
#include "Book.h"
#include "User.h"



class Library
{
    private:
        vector<Book> books;
        vector<User> users;

    public:
        Library();

        void addBook();
        void displayBooks() const;

        void addUser();
        void displayUsers() const;

};
#endif