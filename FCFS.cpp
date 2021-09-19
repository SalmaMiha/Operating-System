//Salma Binta Islam
#include<iostream>
using namespace std;
int main()
{
    int n, i, j, t;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int p[n], at[n], bt[n], ct[n], tat[n], wt[n];
    for(i=0;i<n;i++)
    {
        cout<<"Process: P";
        cin>>p[i];
        cout<<"AT: ";
        cin>>at[i];
        cout<<"BT: ";
        cin>>bt[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                swap(at[i],at[j]);
                swap(p[i],p[j]);
                swap(bt[i],bt[j]);
            }
        }
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    cout<<"Process AT\tBT\tCT\tTAT\tWT\n";
    for(i=0;i<n;i++)
    {
        cout<<"P"<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }
}
