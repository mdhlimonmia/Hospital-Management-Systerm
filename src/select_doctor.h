#include<bits/stdc++.h>
#include "doctor.h"
using namespace std;

string doctor::select_doctor(int n){
    doctor d;
    ifstream read;
    read.open("doctor.txt");
    while (!read.eof())
    {   
        read>>d.id;
        read.ignore();
        getline(read, d.name);
        read.ignore();
        getline(read, d.degree);
        read >> d.gender;
        read.ignore();
        getline(read, d.specialist);
        read>>d.department_id;
        read.ignore();
        getline(read,d.department_name);
        read.ignore();
        getline(read, d.collage);
        read >> d.phone;
        if(d.department_id == n)return d.name;
    }
    read.close();
}
string search_doctor(int n){
    doctor d;
    return d.select_doctor(n);
}