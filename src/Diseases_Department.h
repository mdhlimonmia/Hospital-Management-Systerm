#include<bits/stdc++.h>
using namespace std;


int Select_Department(string s){
    map<string,int> Hos_Department;
    //cardiology
    Hos_Department["cardiology"] = 1;
    Hos_Department["heart"] = 1;
    Hos_Department["myocardial"] = 1;
    Hos_Department["hypertension"] = 1;
    Hos_Department["attack"] = 1;
    Hos_Department["chest"] = 1;

    //oncology
    Hos_Department["oncology"] = 2;
    Hos_Department["cancer"] = 2;
    Hos_Department["tumor"] = 2;

    //infections
    Hos_Department["infection"] = 3;
    Hos_Department["infections"] = 3;

    //surgery
    Hos_Department["surgery"] = 4;
    Hos_Department["appendicitis"] = 4;
    Hos_Department["neurosurgery"] = 4;
    Hos_Department["gallstones"] = 4;
    Hos_Department["fractures"] = 4;
    Hos_Department["operation"] = 4;
    Hos_Department["cesar"] = 4;
    Hos_Department["surgeon"] = 4;

    //neurology
    Hos_Department["neurology"] = 5;
    Hos_Department["stroke"] = 5;
    Hos_Department["brain"] = 5;
    Hos_Department["epilepsy"] = 5;
    Hos_Department["epilepsy"] = 5;
    Hos_Department["alzheimer's"] = 5;

    //nephrology
    Hos_Department["urinary"] = 6;
    Hos_Department["nephrology"] = 6;
    Hos_Department["urine"] = 6;
    Hos_Department["diabetic"] = 6;
    Hos_Department["kidney"] = 6;
    Hos_Department["bladder"] = 6;
    Hos_Department["urology"] = 6;

    //psychiatry
    Hos_Department["psychiatry"] = 7;
    Hos_Department["psychology"] = 7;
    Hos_Department["mental"] = 7;
    Hos_Department["depression"] = 7;
    Hos_Department["disorder"] = 7;
    Hos_Department["love"] = 7;
    Hos_Department["mind"] = 7;
    Hos_Department["drug"] = 7;

    //orthopedics
    Hos_Department["orthopedics"] = 8;
    Hos_Department["arthritics"] = 8;
    Hos_Department["ar"] = 8;
    Hos_Department["ar"] = 8;
    Hos_Department["pain"] = 8;
    Hos_Department["knee"] = 8;
    Hos_Department["bone"] = 8;
    Hos_Department["join"] = 8;
    Hos_Department["trauma"] = 8;
    Hos_Department["injury"] = 8;
    
    //Obstetrics and Gynecology (OB/GYN)
    Hos_Department["obstetrics"] = 9;
    Hos_Department["gynecology"] = 9;
    Hos_Department["childbirth"] = 9;
    Hos_Department["childbirth"] = 9;
    Hos_Department["pregnancy"] = 9;
    Hos_Department["women"] = 9;
    Hos_Department["delivery"] = 9;

    //pediatrics and neonatology
    Hos_Department["baby"] = 10;
    Hos_Department["newborn"] = 10;
    Hos_Department["child"] = 10;

    //EYE
    Hos_Department["eye"] = 11;
    Hos_Department["cornia"] = 11;

    //Skin, Allergy, Leprosy & Sexual
    Hos_Department["skin"] = 12;
    Hos_Department["allergy"] = 12;
    Hos_Department["leprosy"] = 12;
    Hos_Department["sexual"] = 12;
    Hos_Department["sex"] = 12;
    Hos_Department["hair"] = 12;
    Hos_Department["nail"] = 12;

    //Ear, Nose, Throat Specialist & Head Neck(ENT)
    Hos_Department["ent"] = 13;
    Hos_Department["ear"] = 13;
    Hos_Department["nose"] = 13;
    Hos_Department["throat"] = 13;
    Hos_Department["head"] = 13;
    Hos_Department["neck"] = 13;
    Hos_Department["nasal"] = 13;

    //Dental
    Hos_Department["dental"] = 14;
    Hos_Department["dentistry"] = 14;
    Hos_Department["cavities"] = 14;
    Hos_Department["cavite"] = 14;
    Hos_Department["tooth"] = 14;
    Hos_Department["gum"] = 14;
    Hos_Department["dentist"] = 14;
    Hos_Department["teeth"] = 14;
    Hos_Department["sensitive"] = 14;
    Hos_Department["oral"] = 14;
    Hos_Department["mouth"] = 14;


    // for(auto u:Hos_Department)cout<<u.first<<" "<<u.second<<endl;
    string t = "";
    for(auto u:s){
        if(u != ' ' && u!= ',' && u != '.') t+=tolower(u);
        else{
            int det = Hos_Department[t];
            if(det != 0) return det;
            // cout<<det<<endl;
            t = "";
        }
    }
    return Hos_Department[t];
}