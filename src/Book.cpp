#include "Book.h"

Book::Book(int id,string title,string author)
    : id(id),title(title),author(author),
    isIssued(false),issuedToUserId(-1) {}

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
int Book::getIssuedToUserId() const
{
    return issuedToUserId;
}
void Book::setIssuedToUser(int userId)
{
    issuedToUserId = userId;
}
string Book::toFileString() const
{
    return to_string(id) + ","+ title + "," + 
    to_string(isIssued) + "," + to_string(issuedToUserId);
}