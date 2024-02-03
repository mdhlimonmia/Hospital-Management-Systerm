#include <bits/stdc++.h>
using namespace std;

string get_department_name(int n){
    map<int, string> Name_Department;
    Name_Department[0] = "Medicine";
    Name_Department[1] = "Cardiology";
    Name_Department[2] = "Oncology";
    Name_Department[3] = "Infections";
    Name_Department[4] = "Surgery";
    Name_Department[5] = "Neurology";
    Name_Department[6] = "Nephrology";
    Name_Department[7] = "Psychiatry";
    Name_Department[8] = "Orthopedics";
    Name_Department[9] = "Obstetrics&Gynecology(OB/GYN)";
    Name_Department[10] = "Pediatrics&Neonatology";
    Name_Department[11] = "EYE";
    Name_Department[12] = "Skin,Allergy,Leprosy&Sexual";
    Name_Department[13] = "ENT";
    Name_Department[14] = "Dental";

    // for(auto u:Name_Department)cout<<u.first<<" "<<u.second<<endl;
    // cout<<Name_Department[2]<<endl;
    return Name_Department[n];
}