#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>
#include "Book.h"



class Library
{
    private:
        vector<Book> books;
        

    public:
        Library();

        void addBook();
        void displayBooks() const;

};
#endif