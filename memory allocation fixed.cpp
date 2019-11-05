#include <iostream>
#include <string.h>
#define Blockmaxsize 10
#define completeSize 50
using namespace std;

struct fixed {
    float sizeAllocated;
    char proname[10];
}p[10];

int main() {
    int n;
    char temp2[10];
    float temp1, temp3=completeSize;
    cout << "Enter Number of process\n";
    cin >> n;
    for(int i=0; i<n && temp3>0; i++) {
        cout << "Enter the process name and size\n";
        cin >> temp2 >> temp1;
        if(temp1 > Blockmaxsize) {
            cout << "Can't take this process size greater than maxsize of block\n";
            i--;
            n--;
            continue;
        }
        if(temp3-temp1<0) {
            cout << "Can't allocate this process\nMemory overflow\nSize Remaining is : " << temp3 << "\n";
            i--;
            n--;
            continue;
        }
        strcpy(p[i].proname,temp2);
        p[i].sizeAllocated=temp1;
        temp3-=temp1;
    }
    for(int i=0; i<n; i++) {
        cout << " Process Name : " << p[i].proname << " Size Allocated : " << p[i].sizeAllocated << " Fragmented Size : " << Blockmaxsize-p[i].sizeAllocated << "\n";
    }
    return 0;
}