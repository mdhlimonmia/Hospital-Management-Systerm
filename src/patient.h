#include <iostream>
#include <fstream>

using namespace std;

int ID;

class patient
{
private:
     int id;
     string name;
     string age;
     string gender;
     string blood;
     string phone;
     string address;
     string diseases;
     int department_id;
     string department_name;
     string doctor_name;
     int pay = 0;
     int due = 0;
     string ad_time;
     string ad_date;
     string re_time;
     string re_date;

public:
     void add_patient();
     void all_patient();
     void print(patient);
     int search_patient();
     void release_patient();
     void update_patient_info();
     int have_to_pay(patient id);
};

void patient::add_patient()
{
     ifstream read;
     read.open("patient_id.txt");
     if (!read.fail())
          read >> ID;
     else
          ID = 0;
     read.close();

     patient p;
     cout << "\n...................Enter Patient Information...................\n";
     cin.ignore();
     cout << "Name: ";
     getline(cin, p.name);
     cout << "Age: ";
     cin >> p.age;
     cout << "Gender: ";
     cin >> p.gender;
     cout << "Blood Group: ";
     cin >> p.blood;
     cout << "Phone Number: ";
     cin >> p.phone;
     cin.ignore();
     cout << "Address: ";
     getline(cin, p.address);
     // cin.ignore();
     cout << "What is Your Problem: ";
     getline(cin, p.diseases);
  

     ofstream write;
     write.open("patient.txt", ios::app);
     write << "\n"
           << ID;
     write << "\n"
           << p.name;
     write << "\n"
           << p.age;
     write << "\n"
           << p.gender;
     write << "\n"
           << p.blood;
     write << "\n"
           << p.phone;
     write << "\n"
           << p.address;
     write << "\n"
           << p.diseases;
     write << "\n"
           << p.department_id;
     write << "\n"
           << p.department_name;
     write << "\n"
           << p.doctor_name;
     write << "\n"
           << p.pay;
     write << "\n"
           << p.due;
     write << "\n"
           << p.ad_time;
     write << "\n"
           << p.ad_date;
     write.close();

     write.open("patient_id.txt");
     write << ID;
     write.close();
     cout << "\n...........Successfully admission the patient.............\n";
     cout << "Name: " << p.name << endl;
     cout << "Patient ID: " << ID << endl;
     cout << "Department: " << p.department_name << endl;
     cout << "Doctor: " << p.doctor_name << endl;
     cout << "Please don't forget the patient ID.\n";
};