#include <bits/stdc++.h>
using namespace std;

class security
{
    string id;
    string password;

public:
    int Authority();
};

int security::Authority()
{
    int t = 3;
    while (t--)
    {
        string id;
        cout << "Enter Your Id: ";
        cin >> id;
        security person;
        ifstream auth;
        auth.open("authority.txt");
        while (!auth.eof())
        {
            auth >> person.id;
            auth >> person.password;
            if (person.id == id)
            {
                string ps;
                cout << "Enter Your Password: ";
                cin >> ps;
                if (ps == person.password)
                {
                    cout << "Successfully Login\n";
                    return 1;
                }
                else
                {
                    cout << "Wrong Password\n";
                    return 0;
                }
            }
        }
        cout << "Wrong ID\n";
    }
    return 0;
}