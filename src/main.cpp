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
    cout<<"6. Display Book Users "<<endl;
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
        if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a number.\n";
        continue;
}

        switch(choice)
    {


        case 1:
            library.addBook();
            break;
        case 2:
            library.addUser();
            break;
        case 3:
            library.issueBook();
            break;
        case 4:
            library.returnBook();
            break;
        case 5:
            library.displayBooks();
            break;
        case 6:
            library.displayUsers();
            break;
        case 0:
            cout<<"Exiting Program..."<<endl;
            break; 
        default:
            cout << "Invalid choice. Try again."<<endl;   
    }

      }while(choice!=0);

      return 0;
}