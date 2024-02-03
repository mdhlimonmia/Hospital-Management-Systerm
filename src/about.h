#include<bits/stdc++.h>
using namespace std;

void about(){
    ifstream read;
    read.open("about.txt");
    string s;
    cout<<endl<<endl;
    while (getline(read,s))
    {
        cout<<"\t"<<s<<endl;
    }
    
}