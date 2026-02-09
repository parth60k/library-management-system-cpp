#include "User.h"

User::User(int id,const string& name)
    : userId(id),name(name) {}

int User::getUserId() const
{
    return userId;
}
string User::getName() const
{
    return name;
}