// SRTF and RR algorithm
#include<bits/stdc++.h>
using namespace std;

void compute_tat(int tat[],int n,int bt[],int wt[]){
    for(int i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
    }
}

void compute_wt(int wt[],int n,int art[],int rt[]){
    int comp = 0,t=0,min = INT_MAX;
    int shrt = 0, ft;
    bool check = false;
    int bt[n];
    for(int i=0;i<n;i++){
        bt[i] = rt[i];
    }
    while(comp!=n){
        // find shortest process

        for(int j=0;j<n;j++){
            if((art[j] <= t) && (bt[j] < min) && bt[j] > 0){
                min = bt[j];
                shrt = j;
                check = true;
            }
        }
        if(check == false){
            t++;
            continue;
        }
        bt[shrt]--;

        min = bt[shrt];
        if(min == 0){
            min = INT_MAX;
        }
        if(bt[shrt] == 0){
            comp++;
            check=false;
            ft = t+1;
            wt[shrt] = ft - bt[shrt] - art[shrt];
            if(wt[shrt]<0){wt[shrt]=0;}
        }
        t++;
    }
}

int main(){
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    
    int tat[n],wt[n],burst_time[n],arrival_time[n];
    
    for(int i=0;i<n;i++){
        cout << "Enter burst time for process " << (i+1) << " : ";
        cin >> burst_time[i];
    }
    
    for(int i=0;i<n;i++){
        cout << "Enter arrival time for process " << (i+1) << " : ";
        cin >> arrival_time[i];
    }

    int avg_tat=0,avg_wt=0;
    compute_wt(wt,n,arrival_time,burst_time);
    compute_tat(tat,n,burst_time,wt);

    for(int i=0;i<n;i++){
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    cout << "Process\tArrival Time\tBurst time\tWaiting Time\tTurn Around Time" << endl;
    for(int i=0;i<n;i++){
        cout << (i+1) << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "Average turn around time (TAT) : " << float(avg_tat)/float(n) << endl;
    cout << "Average waiting time (WT) : " << float(avg_wt)/float(n) << endl;

    return 0;
}