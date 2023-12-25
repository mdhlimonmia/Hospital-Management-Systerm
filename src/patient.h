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
