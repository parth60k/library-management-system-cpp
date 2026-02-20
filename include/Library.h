#ifndef LIBRARY_H           // ifndef def and endif ensures that if library h is not defined define it and end it and prevents 
#define LIBRARY_H           //mutiple class occuring by it
                            //It prevents multiple inclusion of the same header file
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

        Book* findBookById(int id);
        User* findUserById(int id);

        void issueBook();
        void returnBook();

        void saveBooksToFile() const;
        void loadBooksFromFile();

        void saveUsersToFile() const;
        void loadUsersFromFile();


};
#endif