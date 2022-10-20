#include <iostream>

using namespace std;

class Library
{
private:
       string name;
       int uid, passwd;

public:
       void registering()
       {
              cout << "Enter your Name: ";
              cin.ignore('\n');
              getline(cin, name);

              cout << "Enter a UniqueID (integer): ";
              cin >> uid;

              cout << "Enter Password (integer): ";
              cin >> passwd;
       }

       void login()
       {
              int luid, lpasswd;

              cout << "\n\nEnter UID : ";
              cin >> luid;

              cout << "Enter password : ";
              cin >> lpasswd;

              if (uid == luid && passwd == lpasswd)
                     cout << "\nLogged in Successfully!\n";
              else
                     cout << "\nLogin Unsuccessful.....Try again.\n\n";
       }

       void logout()
       {
              cout << "\nLogged out Successfully!\n";
              exit(0);
       }
};

class User : public Library
{
private:
       int fine = 0, days, ch, amt = 0;

public:
       void issue_b()
       {
              if (fine == 0)
              {
                     cout << "\nBook Issued for 30 days\n";
              }

              else
              {
                     cout << "\nKindly pay the Fine Amount to be eligible to Issue Another Book\n";
              }
       }

       void return_b()
       {
              cout << "For how many days has the Book been Borrowed: ";
              cin >> days;

              if (days > 30)
              {
                     days -= 30;
                     fine = days * 5;

                     cout << "$" << fine << " to be paid for late submission";

                     cout << "\nWould you like to pay the fine now? (1 for YES | other int for NO {0-9}): ";
                     cin >> ch;

                     if (ch == 1)
                            pay();

                     else
                            cout << "\n\n";
              }
       }

       void pay()
       {
              cout << "Enter the Amount to Pay: ";
              cin >> amt;

              if (amt == fine)
              {
                     fine = 0;
                     cout << "\nThank you for Paying!\n";
              }

              else
              {
                     cout << "\nAmount does not match the fine to be Paid\n";
              }
       }

       void list_b()
       {
              cout << "\n\nName\t\tISBN\n";
              cout << "One Piece\t\t101\n";
              cout << "Naruto\t\t102\n";
              cout << "Bleach\t\t103\n";
       }

       void renew_libcard()
       {
              if (fine == 0)
                     cout << "\nLibrary Card Renewed!\n";
              else
                     cout << "\nCannot Renew due to Unpaid Dues!\n";
       }
};

int main()
{
       int ch;
       User ob;
       ob.registering();

       while (true)
       {
              cout << "\n\nLMS MENU\n1. Login\n2. Issue a Book\n3. Return a Book\n4. List Books\n5. Renew Library Card\n6. Logout\n\nEnter Choice: ";
              cin >> ch;

              switch (ch)
              {
              case 1:
                     ob.login();
                     break;

              case 2:
                     ob.issue_b();
                     break;

              case 3:
                     ob.return_b();
                     break;

              case 4:
                     ob.list_b();
                     break;

              case 5:
                     ob.renew_libcard();
                     break;

              case 6:
                     ob.logout();
                     break;

              default:
                     cout << "\nInvalid Choice.....Try again!\n\n";
              }
       }
}

/*
Output :::>

LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 1


Enter UID : 2022
Enter password : 1234

Logged in Successfully!


LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 2

Book Issued for 30 days


LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 4


Name            ISBN
One Piece               101
Naruto          102
Bleach          103


LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 3
For how many days has the Book been Borrowed: 30


LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 2

Book Issued for 30 days


LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 3
For how many days has the Book been Borrowed: 31
$5 to be paid for late submission
Would you like to pay the fine now? (1 for YES | other int for NO {0-9}): 1
Enter the Amount to Pay: 5

Thank you for Paying!


LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 5

Library Card Renewed!


LMS MENU
1. Login
2. Issue a Book
3. Return a Book
4. List Books
5. Renew Library Card
6. Logout

Enter Choice: 6

Logged out Successfully!
*/
