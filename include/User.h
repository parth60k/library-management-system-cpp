#ifndef USER_H
#define USER_H

#include<string>
using namespace std;

class User
{
    private:
        int userId;
        string name;

    public:
        User(int id,const string& name);

        int getUserId() const;
        string getName() const;
};

#endif