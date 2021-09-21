#include<iostream>
using namespace std;
int main()
{
    int p,r;
    cout<<"Enter the number of process: ";
    cin>>p;
    cout<<"Enter the number of resource: ";
    cin>>r;
    int max[p][r], allocation[p][r], need[p][r], i,j, available[r], copy_av[r], finish[p];
    for(i=0;i<p;i++)
    {
        cout<<"Max for P"<<i<<":\n";
        for(j=0;j<r;j++)
        {
            cout<<"R"<<j<<":";
            cin>>max[i][j];
        }
    }
    for(i=0;i<p;i++)
    {
        cout<<"Allocation for P"<<i<<":\n";
        for(j=0;j<r;j++)
        {
            cout<<"R"<<j<<":";
            cin>>allocation[i][j];
            need[i][j]=max[i][j]-allocation[i][j];
        }
        finish[i]=0;
    }
    cout<<"Available:\n";
    for(i=0;i<r;i++)
    {
        cout<<"R"<<i<<":";
        cin>>available[i];
        copy_av[i]=available[i];
    }
    int c=0, sequence[p], accept=0, e=0;
    while(c!=p)
    {
        for(i=0;i<p;i++)
        {
            if(finish[i]==0)
                {
                    accept = 0;
                    for(j=0;j<r;j++)
                    {
                        if(need[i][j]>available[j])
                            {
                                accept = 1;
                                break;
                            }
                    }
                    if(accept==0)
                    {
                        finish[i]=1;
                        sequence[c]=i;
                        c++;
                        for(j=0;j<r;j++)
                        {
                            available[j]=available[j]+allocation[i][j];
                        }
                    }
                }
        }
        e=0;
        for(i=0;i<r;i++)
        {
            if(available[i]!=copy_av[i])
            {
                e=1;
                break;
            }
        }
        if(e==1)
        {
            for(i=0;i<r;i++)
                copy_av[i]=available[i];
        }
        else if(e==0)
            break;
    }
    if(c!=p)
        cout<<"\nDeadlock occurs.\n";
    else
    {
        cout<<"\nDeadlock doesn't occur.\nSafe Sequence = <";
        for(i=0;i<p;i++)
        {
            cout<<"P"<<sequence[i];
            if(i!=(p-1))
                cout<<", ";
        }

        cout<<">\n";
    }
}
