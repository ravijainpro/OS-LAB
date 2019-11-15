#include <bits/stdc++.h>
using namespace std;
 
struct FCFS {
    char pname[10];
    int tat, bt, wt,at,ft;
}P[10];
 
int main() {
    int i, temp=0,n;
    float avgTAT=0;
    cout << "Enter number of Process\n";
    cin >> n;
    for(i=0; i<n; i++) {
        cout << "Enter the process name, AT & BT for " << i+1 << "th process\n"; //(i+1)th process arrival time is greater than (i)th process arrival time
        cin >> P[i].pname;
        cin >> P[i].at;
        cin >> P[i].bt;
    }
    for(i=0; i<n; i++) {
        P[i].ft=P[i].bt+temp;
        P[i].tat=P[i].ft-P[i].at;
        temp=P[i].ft;
        P[i].wt=P[i].tat-P[i].bt;
    }
    for(i=0; i<n; i++) {
        cout << "PN, AT, FT, BT, WT, TAT := " << P[i].pname << " " << P[i].at << " " << P[i].ft << " " << P[i].bt << " " << P[i].wt << " " << P[i].tat << "\n";
    }
    for(i=0; i<n; i++) {
        avgTAT+=P[i].tat;
    }
    avgTAT=avgTAT/n;
    cout << "Avg TAT is " << avgTAT << "\n";
    return 0;
}
