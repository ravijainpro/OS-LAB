#include <iostream>
#define SIZE 10
using namespace std;

struct priority {
    char pname[10];
    int tat, bt, wt, at=0, ft, priority;
}P[SIZE];
 
int main() {
    int i, temp=0, n, order[2][SIZE];
    float avgTAT=0;
    cout << "Enter number of Process\n";
    cin >> n;
    for(i=0; i<n; i++) {
        cout << "Enter the process name, BT and Priority for " << i+1 << "th process\n";
        cin >> P[i].pname >> P[i].bt >> P[i].priority;
        order[0][i]=i;
        order[1][i]=P[i].priority;
    } 
    //Sort order accroding to the priority
    for(i=n-1; i > 0; i--) {
        int t1=i;
        for(int j=i-1; j>=0; j--) {
            if(order[1][j] < order[1][t1]) {
                t1=j;
            }
        }
        if(t1!=i) {
            int t2=order[1][t1];
            order[1][t1]=order[1][i];
            order[1][i]=t2;
            t2=order[0][t1];
            order[0][t1]=order[0][i];
            order[0][i]=t2;
        }
    }

    //simulation of priority scheduling with AT=0
    for(i=0; i<n; i++) { 
        P[order[0][i]].ft=P[order[0][i]].bt+temp;
        P[order[0][i]].tat=P[order[0][i]].ft-P[order[0][i]].at;
        temp=P[order[0][i]].ft;
        P[order[0][i]].wt=P[order[0][i]].tat-P[order[0][i]].bt;
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