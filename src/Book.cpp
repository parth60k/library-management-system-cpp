#include "Book.h"

Book::Book(int id,const string& title,const string& author)
    : bookId(id),title(title),author(author),isIssued(false) {}

int Book::getBookId() const 
{
    return bookId;
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