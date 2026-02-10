#include "Book.h"

Book::Book(int id,string title,string author)
    : id(id),title(title),author(author),isIssued(false) {}

int Book::getId() const 
{
    return id;
}
string Book::getTitle() const
{
    return title;
}
string Book::getAuthor() const
{
    return author;
}
bool Book::getisIssued() const
{
    return isIssued;
}
void Book::setIssued(bool status)
{
    isIssued=status;
}