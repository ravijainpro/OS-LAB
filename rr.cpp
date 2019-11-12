#include <iostream>
using namespace std;
 
struct rr{
    char pname[20];
    int at, bt, bt_cpy, wait, tat;
}p[10];
 
int main() {
    int i, n, full, t_quan, total_time=0;
    float avg_time=0;
    cout << "Enter # of Process and time quantum.\n";
    cin >> n >> t_quan;
    for(i=0; i<n; i++) {
        cout << "Enter Process Name, arrival time & Burst Time.\n";
        cin >> p[i].pname >> p[i].at >> p[i].bt;
        p[i].bt_cpy = p[i].bt;
    }
    full=n;
    while(full) {
        int check=0; // a check for no of process completed.. this may be equal to 0 in case all the process AT != 0 .. 
                    // so we got to increment the total_time, else this will end up in infinite loop
        cout << "\nSTART: Current time: " << total_time << "\n";
        for(i=0; i<n; i++) {
            if(p[i].at <= total_time && p[i].bt >= t_quan) {
                p[i].bt-=t_quan;
                total_time+=t_quan;
            }
            else if(p[i].at <= total_time &&p[i].bt!=0) {
                total_time+=p[i].bt;
                p[i].bt=0;
            }
            else {
                continue;
            }
            cout << "Process: " << p[i].pname << "; Time: " << total_time << "; Remaining time " << p[i].bt << "\n";
            if(!p[i].bt) {
                check++;
                full-=1;
                p[i].tat=total_time;
            }
        }
        if(!check) {
            total_time++;
        }
        cout << "\nEND: Current time: " << total_time << "\n";
    }
    for(i=0; i<n; i++) {
        p[i].wait=p[i].tat-p[i].bt_cpy;
        cout << "Process: " << p[i].pname << " AT:" <<  p[i].at << " BT:"<< p[i].bt_cpy << " WT:" << p[i].wait << " TAT:" << p[i].tat << "\n";
        avg_time+=p[i].wait;
    }
    avg_time/=n;
    cout << "Avg WT: " << avg_time << "\n";
}
