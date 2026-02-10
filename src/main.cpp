#include<iostream>
#include "Library.h"
  using namespace std;
   
void showMenu()
{
    cout<<"\n===== Library Management System =====\n";
    cout<<"1. Add Book"<<endl;
    cout<<"2. Add User"<<endl;
    cout<<"3. Issue Book"<<endl;
    cout<<"4. Return Book"<<endl;
    cout<<"5. Display Books "<<endl;
    cout<<"0. Exit "<<endl;
    cout<<" Enter choice"<<endl;
}

int main()
{
    Library library;
    int choice;

    do{
        showMenu();
        cin>>choice;

        switch(choice)
    {


        case 1:
            library.addBook();
            break;
        case 2:
            cout<<"Add User selected"<<endl;
            break;
        case 3:
            cout<<"Issue Book selected"<<endl;
            break;
        case 4:
            cout<<"Return Book selected"<<endl;
            break;
        case 5:
            library.displayBooks();
            break;
        case 0:
            cout<<"Exiting Program..."<<endl;
            break;    
    }

      }while(choice!=0);

      return 0;
}