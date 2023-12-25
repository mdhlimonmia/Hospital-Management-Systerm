#include <bits/stdc++.h>
using namespace std;

class doctor
{
      int id;
      string name;
      string degree;
      string gender;
      string specialist;
      int department_id;
      string department_name;
      string collage;
      string phone;
      // int number_of_patient;

public:
      void add_doctor();
      void doctor_list();
      void a_doctor(int id);
      void a_doctor(string name);
      void print(doctor);
      string select_doctor(int n);
};

void doctor::add_doctor()
{
      int ID;
      ifstream read;
      read.open("doctor_id.txt");
      if (!read.fail())
      {
            read >> ID;
      }
      else
            ID = 0;
      read.close();

      doctor d;
      cout << "........Enter Info of Doctor................\n";

      cout << "Name: ";
      cin.ignore();
      getline(cin, d.name);

      cout << "Degree: ";
      cin.ignore();
      getline(cin, d.degree);

      cout << "Gender: ";
      cin >> d.gender;

      cout << "Specialist: ";
      cin.ignore();
      getline(cin, d.specialist);

      d.department_id = Select_Department(d.specialist);
      d.department_name = get_department_name(d.department_id);

      cout << "Collage: ";
      cin.ignore();
      getline(cin, d.collage);

      cout << "Phone Number: ";
      cin >> d.phone;
      ID++;

      ofstream write;
      write.open("doctor.txt", ios::app);

      write << "\n"
            << ID;
      write << "\n"
            << d.name;
      write << "\n"
            << d.degree;
      write << "\n"
            << d.gender;
      write << "\n"
            << d.specialist;
      write << "\n"
            << d.department_id;
      write << "\n"
            << d.department_name;
      write << "\n"
            << d.collage;
      write << "\n"
            << d.phone;
      write.close();

      cout << "\n....Successfully add new doctor.......\n";
      cout << "Doctor Name: " << d.name << endl;
      cout << "Doctor ID: " << ID << endl;
      cout << "Department: " << d.department_name << endl;

      write.open("doctor_id.txt");
      write << ID;
      write.close();
}

void doctor::print(doctor d)
{
      //    cout<<"\n\n....Doctor Details............\n\n";
      cout << "\n\nID: " << d.id << endl;
      cout << "Name: " << d.name << endl;
      cout << "Degree: " << d.degree << endl;
      cout << "Gender: " << d.gender << endl;
      cout << "Specialist: " << d.specialist << endl;
      cout << "Department: " << d.department_name << endl;
      cout << "Collage: " << d.collage << endl;
      cout << "Phone Number: " << d.phone << endl;
      cout << endl;
}

void doctor::doctor_list()
{
      cout << "\n\n....Doctor Details............\n\n";

      doctor d;
      ifstream read;
      read.open("doctor.txt");
      while (!read.eof())
      {
            read >> d.id;
            read.ignore();
            getline(read, d.name);
            read.ignore();
            getline(read, d.degree);
            read >> d.gender;
            read.ignore();
            getline(read, d.specialist);
            read >> d.department_id;
            read.ignore();
            getline(read, d.department_name);
            read.ignore();
            getline(read, d.collage);
            read >> d.phone;
            print(d);
      }
      read.close();
}
