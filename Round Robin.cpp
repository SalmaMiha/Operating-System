//Salma Binta Islam
//ID-1109022
#include<iostream>
using namespace std;
int main()
{
    int n,i=0, tq, st=0;
    cout<<"Enter the time quantum: ";
    cin>>tq;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int p[n], bt[n], ct[n], tat[n], wt[n], cbt[n], tbt=0;
    for(i=0;i<n;i++)
    {
        cout<<"Process: P";
        cin>>p[i];
        cout<<"BT: ";
        cin>>bt[i];
        tbt += bt[i];
        cbt[i]=bt[i];
    }
    i=0;
    while(tbt!=0)
    {
        if(bt[i]>=tq)
        {
            ct[i]=st+tq;
            st+=tq;
            tbt-=tq;
            bt[i]-=tq;
        }
        else if(bt[i]<tq && bt[i]!=0)
        {
            ct[i]=st+bt[i];
            st+=bt[i];
            tbt-=bt[i];
            bt[i]=0;
        }
        if(i<(n-1))
            i++;
        else
            i=0;
    }

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i];
        wt[i]=tat[i]-cbt[i];
    }
    cout<<"Process BT\tCT\tTAT\tWT\n";
    for(i=0;i<n;i++)
    {
        cout<<"P"<<p[i]<<"\t"<<cbt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }
}
