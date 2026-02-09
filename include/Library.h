#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>
#include "Book.h"
#include "User.h"

using namespace std;

class Library
{
    private:
        vector<Book> books;
        vector<User> users;

    public:
        Library();

        void addBook(const Book& book);
        void addUser(const User& user);

};
#endif