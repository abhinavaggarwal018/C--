#include<iostream>
#define l(a,b,c) for(a=b;a<=c;a++)
using namespace std;
int t,n,val[105][105],i,j,max1;
{l(i,1,n)l(j,1,i)val[i][j]=max(val[i-1][j],val[i-1][j-1])+val[i][j];l(i,0,n){if(val[n][i]>max1)max1=val[n][i];}cout<<max1<<"\n";}
int main(){cin>>t;max1=0;l(l,0,t-1){cin>>n;l(i,0,n){l(j,0,n)val[i][j]=0;l(j,1,i)cin>>val[i][j];}}}
