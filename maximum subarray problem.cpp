// find two numbers going from left to right such that right-left=maximum
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
        min1[i]=min(min1[i-1],arr[i]);
        else
        min1[0]=arr[0];

    }
    for(i=n-1;i>=0;i--)
    {
        if(i<n-1)
        max1[i]=max(max1[i+1],arr[i]);
        else
        max1[n-1]=arr[n-1];
    }
    for(i=0;i<n;i++)
    {
        ans=max(max1[i]-min1[i],ans);
    }
    cout<<ans;
}

