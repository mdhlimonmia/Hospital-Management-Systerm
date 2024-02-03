#include <bits/stdc++.h>
#include "security_check.h"
#include "patient.h"

using namespace std;

void Authority()
{
    security s;
    int k = s.Authority();
    if (k)
    {
        string n = "1";
        while (n[0] - '0')
        {
            cout << "\n\n1.All Patient.   "
                 << "2.Add Doctor.   "
                 << "3.Update Doctor.   "
                 << "4.Delate Doctor.   "
                 << "5.Change Password.   "
                 << "0.Back Home.   \n\n";

            cout << "Enter Your Choice:  ";
            cin >> n;
            switch (n[0])
            {
            case '1':
            {
                patient p;
                p.all_patient();
                break;
            }
            case '2':
            {
                doctor d;
                d.add_doctor();
                break;
            }
            case '3':
            {
                doctor d;
                // d.add_doctor();
                break;
            }
            case '4':
            {
                doctor d;
                // d.add_doctor();
                break;
            }
            case '5':
            {
                // change password
                break;
            }
            default:
            {
                if (n[0] != '0')
                    cout << "\nInvalid Choice....\n";
                break;
            }
            }
        }
        return;
    }
}