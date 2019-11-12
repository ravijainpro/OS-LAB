//ONE BUG THERE....AND THIS IS NOT EFFICENT ONE!!!...if heap was used it would have been efficient..

#include <iostream>
#define SIZE 10
using namespace std;

struct priority {
    char pname[10];
    int tat, bt, wt, at, ft, priority, bt_cpy;
}P[SIZE];

//TO-DO: Fix this! all must not be global.. 
int i, temp=0, n, order[2][SIZE];
float avgTAT=0;
   
void take_input() {
    cout << "Enter number of Process\n";
    cin >> n;
    for(i=0; i<n; i++) {
        cout << "Enter the process name, AT, BT and Priority for " << i+1 << "th process\n";
        cin >> P[i].pname >> P[i].at >> P[i].bt >> P[i].priority;
        P[i].bt_cpy=P[i].bt;
        order[0][i]=i;
        order[1][i]=P[i].priority;
    }
}

void sort() {
    for(i=n-1; i > 0; i--) {
        int t1=i;
        for(int j=i-1; j>=0; j--) {
            if(order[1][j] < order[1][t1]) {
                t1=j;
            }
        }
        //basic swapping
        if(t1!=i) {
            int t2=order[1][t1];
            order[1][t1]=order[1][i];
            order[1][i]=t2;
            t2=order[0][t1];
            order[0][t1]=order[0][i];
            order[0][i]=t2;
        }
    }
}

void simulation() {
    int full=n;
    while(full) {
        int check=0;
        for(i=0; i<n; i++) { 
            //skip those process which are completed or whcih haven't yet arrived
            if(!P[order[0][1]].bt_cpy || P[order[0][i]].at>temp) {
                continue;
            }
            P[order[0][i]].bt_cpy-=1;
            //if process done.. => complete the req attributes 
            if(!P[order[0][i]].bt_cpy) {
                check++;
                P[order[0][i]].ft=temp; // FT done
                P[order[0][i]].tat=P[order[0][i]].ft-P[order[0][i]].at; // TAT=FT-AT done
                P[order[0][i]].wt=P[order[0][i]].tat-P[order[0][i]].bt; // WT=TAT-BT done
                full--; //one down!
            }
            temp++;
        }
        if(!check) { //no work done...kick up time
            temp++;
        }
    }
}

void print() {
    for(i=0; i<n; i++) {
        cout << "PN, AT, FT, BT, WT, TAT := " << P[i].pname << " " << P[i].at << " " << P[i].ft << " " << P[i].bt << " " << P[i].wt << " " << P[i].tat << "\n";
    }
    for(i=0; i<n; i++) {
        avgTAT+=P[i].tat;
    }
    avgTAT=avgTAT/n;
    cout << "Avg TAT is " << avgTAT << "\n";
    
}

int main() {
    //take i/p
    take_input();     
    //Sort order accroding to the priority
    sort();
    //simulation of priority
    simulation();
    //print
    print();
    return 0;
}
