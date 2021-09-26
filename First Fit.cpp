#include<iostream>
using namespace std;
int main()
{
    int b, p;
    cout<<"Enter the number of memory blocks: ";
    cin>>b;
    int block[b], allocation[b], flag[b], i, j;
    cout<<"Enter the size of the block:\n";
    for(i=0;i<b;i++)
    {
        cout<<"Block "<<i<<": ";
        cin>>block[i];
        allocation[i]=0;
        flag[i]=0;
    }
    cout<<"Enter the number of process: ";
    cin>>p;
    int process[p];
    cout<<"Enter the size of process:\n";
    for(i=0;i<p;i++)
    {
        cout<<"Process "<<i<<": ";
        cin>>process[i];
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<b;j++)
        {
            if(flag[j]==0 && block[j]>=process[i])
            {
                allocation[j]=i;
                flag[j]=1;
                break;
            }
        }
    }
    cout<<"Block Number  Block size  Allocated Process  Process Size\n";
    for(i=0;i<b;i++)
    {
        cout<<"  "<<i<<"\t\t"<<block[i]<<"\t";
        if(flag[i]==1)
        {
            cout<<"\t"<<allocation[i]<<"\t\t"<<process[allocation[i]]<<endl;
        }
        else
            cout<<"   Not Allocated\n";
    }
}
