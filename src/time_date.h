#include <bits/stdc++.h>
using namespace std;

#define pr pair<string,string>


const pr currentDateTime() {
    time_t     now = time(0);
    struct tm  t_struct;
    char       date[30];
    char       time[30];
    t_struct = *localtime(&now);
    strftime(date, sizeof(date), "%Y-%m-%d", &t_struct);
    strftime(time, sizeof(time), "%X", &t_struct);
    pr s; 
    s = {date,time};
    return s;
}
