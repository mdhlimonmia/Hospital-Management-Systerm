#include <bits/stdc++.h>
#include "patient.h"
#include "doctor.h"


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
        }
    }
    cout << "\n\t\t\t\t...........Thanks. Wishing you good health...........\n";
}
