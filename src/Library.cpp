#include "Library.h"

Library::Library() {}

void Library::addBook(const Book& book)
{
    books.push_back(book);
}

void Library::addUser(const User& user)
{
    users.push_back(user);
}