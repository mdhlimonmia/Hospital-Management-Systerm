#include <iostream>
#include "limon_stl.h"
#include "time_date.h"
#include "get_depart_name.h"
#include "Diseases_Department.h"
#include "select_doctor.h"
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
     p.department_id = Select_Department(p.diseases);

     p.department_name = get_department_name(p.department_id);

     p.doctor_name = search_doctor(p.department_id);

     pr td;
     td = currentDateTime();
     p.ad_time = td.second;
     p.ad_date = td.first;
     ID++;

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

void patient::print(patient p)
{
     // cout << "...................Patient Information...................\n";
     cout << "\n\nID: " << p.id << endl;
     cout << "Name: " << p.name << endl;
     cout << "Age: " << p.age << endl;
     cout << "Gender: " << p.gender << endl;
     cout << "Blood Group: " << p.blood << endl;
     cout << "Phone Number: " << p.phone << endl;
     cout << "Address: " << p.address << endl;
     cout << "Problem: " << p.diseases << endl;
     cout << "Department: " << p.department_name << endl;
     cout << "Doctor: " << p.doctor_name << endl;
     cout << "Total Pay: " << p.pay << endl;
     // cout << "Due: " << p.due << endl;
     cout << "Admission Time: " << p.ad_time << endl;
     cout << "Admission Date: " << p.ad_date << endl;
};

void patient::all_patient()
{
     cout << "...................Patient Information...................\n";
     patient p;
     ifstream read;
     read.open("patient.txt");
     while (!read.eof())
     {
          read >> p.id;
          read.ignore();
          getline(read, p.name);
          read >> p.age;
          read >> p.gender;
          read >> p.blood;
          read >> p.phone;
          read.ignore();
          getline(read, p.address);
          getline(read, p.diseases);
          read >> p.department_id;
          read.ignore();
          getline(read, p.department_name);
          // read.ignore();
          getline(read, p.doctor_name);
          read >> p.pay;
          read >> p.due;
          read >> p.ad_time;
          read >> p.ad_date;
          print(p);
     }
     read.close();
}

int patient::search_patient()
{
     string key;
     int id;
     cout << "Enter Patient Id / Name: ";
     cin.ignore();
     getline(cin, key);
     bool num = 0;

     if (isdigit(key[0]))
     {
          num = 1;
          id = stoi(key);
     }

     key = tostrlwr(key);
     patient p;
     ifstream read;
     read.open("patient.txt");
     while (!read.eof())
     {
          read >> p.id;
          read.ignore();
          getline(read, p.name);
          read >> p.age;
          read >> p.gender;
          read >> p.blood;
          read >> p.phone;
          read.ignore();
          getline(read, p.address);
          getline(read, p.diseases);
          read >> p.department_id;
          read.ignore();
          getline(read, p.department_name);
          // read.ignore();
          getline(read, p.doctor_name);
          read >> p.pay;
          read >> p.due;
          read >> p.ad_time;
          read >> p.ad_date;
          if (num && p.id == id)
          {
               cout << "...................Patient Information...................\n";
               print(p);
               read.close();
               return p.id;
          }
          else if (!num && tostrlwr(p.name) == key)
          {
               cout << "...................Patient Information...................\n";
               print(p);
               read.close();
               return p.id;
          }
     }
     read.close();
     return 0;
}

void patient::release_patient()
{
     int id = search_patient();
     if (id != 0)
     {
          int k = 1;
          string choice;
          cout << "Are You Want to Release (y/n): ";
          cin >> choice;
          if (tolower(choice[0]) == 'y')
          {
               patient re;
               pr td = currentDateTime();
               re.re_date = td.first;
               re.re_time = td.second;
               patient p;
               ofstream temp;
               temp.open("temp.txt");
               ifstream read;
               read.open("patient.txt");

               while (!read.eof())
               {
                    read >> p.id;
                    read.ignore();
                    getline(read, p.name);
                    read >> p.age;
                    read >> p.gender;
                    read >> p.blood;
                    read >> p.phone;
                    read.ignore();
                    getline(read, p.address);
                    getline(read, p.diseases);
                    read >> p.department_id;
                    read.ignore();
                    getline(read, p.department_name);
                    getline(read, p.doctor_name);
                    read >> p.pay;
                    read >> p.due;
                    read >> p.ad_time;
                    read >> p.ad_date;

                    if (p.id == id && have_to_pay(p))
                    {
                         k = 0;
                         ofstream past_patient;
                         past_patient.open("past_patient.txt", ios::app);

                         past_patient << "\n"
                                      << p.id;
                         past_patient << "\n"
                                      << p.name;
                         past_patient << "\n"
                                      << p.age;
                         past_patient << "\n"
                                      << p.gender;
                         past_patient << "\n"
                                      << p.blood;
                         past_patient << "\n"
                                      << p.phone;
                         past_patient << "\n"
                                      << p.address;
                         past_patient << "\n"
                                      << p.diseases;
                         past_patient << "\n"
                                      << p.department_id;
                         past_patient << "\n"
                                      << p.department_name;
                         past_patient << "\n"
                                      << p.doctor_name;
                         past_patient << "\n"
                                      << p.pay;
                         past_patient << "\n"
                                      << p.due;
                         past_patient << "\n"
                                      << p.ad_time;
                         past_patient << "\n"
                                      << p.ad_date;
                         past_patient << "\n"
                                      << re.re_time;
                         past_patient << "\n"
                                      << re.re_date;
                         past_patient.close();
                    }
                    else
                    {
                         temp << "\n"
                              << p.id;
                         temp << "\n"
                              << p.name;
                         temp << "\n"
                              << p.age;
                         temp << "\n"
                              << p.gender;
                         temp << "\n"
                              << p.blood;
                         temp << "\n"
                              << p.phone;
                         temp << "\n"
                              << p.address;
                         temp << "\n"
                              << p.diseases;
                         temp << "\n"
                              << p.department_id;
                         temp << "\n"
                              << p.department_name;
                         temp << "\n"
                              << p.doctor_name;
                         temp << "\n"
                              << p.pay;
                         temp << "\n"
                              << p.due;
                         temp << "\n"
                              << p.ad_time;
                         temp << "\n"
                              << p.ad_date;
                    }
               }
               read.close();
               temp.close();
               remove("patient.txt");
               rename("temp.txt", "patient.txt");
               if(k) cout << "The Patient is Not Release\n";
               else cout << "Successfully released the patient.\n";
          }
          else
               cout << "The Patient is Not Release\n";
     }
     else
          cout << "Patient not found.\n";
}

void patient::update_patient_info()
{
     int id;
     id = search_patient();
     if (id != 0)
     {
          string choice;
          cout << "Are You Want to Release (y/n): ";
          cin >> choice;
          if (tolower(choice[0]) == 'y')
          {
               patient p, new_p;

               cout << "\n...................Enter Update Patient Information...................\n";
               cin.ignore();
               cout << "Updated Name: ";
               getline(cin, new_p.name);
               cout << "Updated Age: ";
               cin >> new_p.age;
               cout << "Updated Gender: ";
               cin >> new_p.gender;
               cout << "Updated Blood Group: ";
               cin >> new_p.blood;
               cout << "Updated Phone Number: ";
               cin >> new_p.phone;
               cin.ignore();
               cout << "Updated Address: ";
               getline(cin, new_p.address);

               cout << "What is Your Problem: ";
               getline(cin, new_p.diseases);
               new_p.department_id = Select_Department(new_p.diseases);

               new_p.department_name = get_department_name(new_p.department_id);

               new_p.doctor_name = search_doctor(new_p.department_id);
               ofstream temp;
               temp.open("temp.txt");
               ifstream read;
               read.open("patient.txt");

               while (!read.eof())
               {
                    read >> p.id;
                    read.ignore();
                    getline(read, p.name);
                    read >> p.age;
                    read >> p.gender;
                    read >> p.blood;
                    read >> p.phone;
                    read.ignore();
                    getline(read, p.address);
                    getline(read, p.diseases);
                    read >> p.department_id;
                    read.ignore();
                    getline(read, p.department_name);
                    getline(read, p.doctor_name);
                    read >> p.pay;
                    read >> p.due;
                    read >> p.ad_time;
                    read >> p.ad_date;

                    if (p.id == id)
                    {
                         temp << "\n"
                              << p.id;
                         temp << "\n"
                              << new_p.name;
                         temp << "\n"
                              << new_p.age;
                         temp << "\n"
                              << new_p.gender;
                         temp << "\n"
                              << new_p.blood;
                         temp << "\n"
                              << new_p.phone;
                         temp << "\n"
                              << new_p.address;
                         temp << "\n"
                              << new_p.diseases;
                         temp << "\n"
                              << new_p.department_id;
                         temp << "\n"
                              << new_p.department_name;
                         temp << "\n"
                              << new_p.doctor_name;
                         temp << "\n"
                              << new_p.pay;
                         temp << "\n"
                              << new_p.due;
                         temp << "\n"
                              << p.ad_time;
                         temp << "\n"
                              << p.ad_date;
                    }
                    else
                    {
                         temp << "\n"
                              << p.id;
                         temp << "\n"
                              << p.name;
                         temp << "\n"
                              << p.age;
                         temp << "\n"
                              << p.gender;
                         temp << "\n"
                              << p.blood;
                         temp << "\n"
                              << p.phone;
                         temp << "\n"
                              << p.address;
                         temp << "\n"
                              << p.diseases;
                         temp << "\n"
                              << p.department_id;
                         temp << "\n"
                              << p.department_name;
                         temp << "\n"
                              << p.doctor_name;
                         temp << "\n"
                              << p.pay;
                         temp << "\n"
                              << p.due;
                         temp << "\n"
                              << p.ad_time;
                         temp << "\n"
                              << p.ad_date;
                    }
               }
               read.close();
               temp.close();
               remove("patient.txt");
               rename("temp.txt", "patient.txt");
               cout << "\n.......Successfully Updated the patient..........\n";
          }
          else
               cout << "......The Patient is not changes.......\n";
     }
     else
          cout << "....Patient not found. Please Enter the right info........\n";
}

int patient::have_to_pay(patient p)
{
     string ad = p.ad_date;
     pr td;
     td = currentDateTime();
     string cd = td.first;
     int day1 = ((ad[5] - '0')*10 + ad[6] - '0')*30 + (ad[8]-'0')*10 + ad[9] - '0';
     int day2 = ((cd[5] - '0')*10 + cd[6] - '0')*30 + (cd[8]-'0')*10 + cd[9] - '0';

     int total = (day2 - day1)*950;
     if(total <= 500) return 1;
     cout<<"You Have to Pay: "<<total;
     cout<<"\nPlease Enter Amount: ";
     int get_money;
     cin>>get_money;
     if(500 >= total - get_money) return 1;
     else{
          cout<<"Sorry, You are not pay minimum money.\n";
          return 0;
     }
}