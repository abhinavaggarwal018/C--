#include<iostream>
using namespace std;
int main()
{

    int arr[500],min1[500],max1[500];
    int n,i,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i>0)
        min1[i]=min(min[i-1],arr[i]);
        else
        min1[0]=arr[0];

    }
    for(i=n-1;i>=;i--)
    {
        if(i<n-1)
        max1[i]=max(max[i+1],arr[i]);
        else
        max1[n-1]=arr[n-1];
    }
    for(i=0;i<n;i++)
    {
        ans=max(max[i]-min[i],ans)
    }
}

