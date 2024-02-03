#include <bits/stdc++.h>
#include "authority.h"
#include "about.h"

using namespace std;

int main()
{
    cout << "\n\t\t\t\t............Welcome To TechMed Solutions Hospital............\n";

    string n = "1";
    while (n[0] - '0')
    {
        cout << "\n1.Admission.  "
             << "2.Doctor List.  "
             << "3.Patient Details.  "
             << "4.Payment.  "
             << "5.Patient_Release.  "
             << "6.Update Patient info.  "
             << "7.Authority Dashboard.  "
             << "8.About.  "
             << "0.Exit.\n\n";
        cout << "Enter Your Choice:  ";
        cin >> n;
        switch (n[0])
        {
        case '1':
        {
            patient p;
            p.add_patient();
            break;
        }
        case '2':
        {
            doctor d;
            d.doctor_list();
            break;
        }
        case '3':
        {
            patient p;
            p.search_patient();
            break;
        }
        case '4':
        {
            // p.have_to_pay(p.search_patient());
            break;
        }
        case '5':
        {
            patient p;
            p.release_patient();
            break;
        }
        case '6':
        {
            patient p;
            p.update_patient_info();
            break;
        }
        case '7':
        {
            Authority();
            break;
        }
        case '8':
        {
            about();
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
    cout << "\n\t\t\t\t...........Thanks. Wishing you good health...........\n";
}
