#include <iostream>
using namespace std;
 
struct rr{
    char pro[20];
    int bt, time;
}p[10];
 
int main() {
    int i,  n, full, q, wait[10], tat[10], time=0;
    float avg=0;
    cout << "Enter # of Process and time quantum.\n";
    cin >> n >> q;
    for(i=0; i<n; i++) {
        cout << "Enter Process Name & Burst Time.\n";
        cin >> p[i].pro >> p[i].bt;
        p[i].time = p[i].bt;
    }
    full=n;
    while(full) {
        for(i=0; i<n; i++) {
            if(p[i].bt >= q) {
                p[i].bt-=q;
                time+=q;
            }
            else if(p[i].bt!=0) {
                time+=p[i].bt;
                p[i].bt=0;
            }
            else {
                continue;
            }
            cout << "Process: " << p[i].pro << "; Time: " << time << "; Remaining time " << p[i].bt << "\n";
            if(!p[i].bt) {
                full-=1;
                tat[i]=time;
            }
        }
    }
    for(i=0; i<n; i++) {
        wait[i]=tat[i]-p[i].time;
        cout << "Process: " << p[i].pro << " WT:" << wait[i] << " TAT:" << tat[i] << "\n";
        avg+=wait[i];
    }
    avg/=n;
    cout << "Avg WT: " << avg << "\n";
}