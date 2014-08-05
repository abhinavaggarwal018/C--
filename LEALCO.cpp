#include<iostream>
#include<stdio.h>

using namespace std;

int ans=-1,R[20],R_orig[20],i,n,k,val[20],m,t,index11,cnt;
long long int perm,perm1;
int add(int index1)
{
	R[index1]=R[index1]+1;
}

int max_val_index1_count(int a, int b)
{
	int max1=-100,cnt=0;
	for(i=a;i<b;i++)
	{
		if(R[i]>max1)
		max1=R[i];
	}
	for(i=a;i<b;i++)
	{
		if(R[i]==max1)
		cnt++;
	}
	return cnt;
}


void check(int num)
{
//	cout<<num;
//	cout<<"\nChecking for cnt:"<<cnt;
	bool flag=true;
	for(i=0;i<=n-k;i++)
	{
		val[i]=max_val_index1_count(i,i+k);
	}
	for ( i=0 ; i<n-k ; i++ )
		if(val[i]>=m)
			flag=false;
//	cout<<"\tflag:"<<flag<<"\n";
	if(flag==true && (ans>num || ans==-1) )
		{
//			int useless;
//			cout<<"Ans:"<<num;
			ans=num;
//			cin>>useless;
		}
}


int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=-1;
		scanf("%d %d %d",&n,&k,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&R[i]);
			R_orig[i]=R[i];
		}
		ans=-1;
		cnt=0;
		long long int perm=1<<n;
		while(perm--)
		{
			for(int i=0;i<n;i++)
			{
				R[i]=R_orig[i];
			}
			int index1=0;
			cnt=0;
			perm1=perm;
			while(perm1)
			{
				if((perm1&1)==1)
				{
					cnt++;
					add(index1);
//					cout<<"index1:"<<index1;
				}
				index1++;
				perm1=perm1>>1;
		//		cout<<"1;";
			}
			check(cnt);
		//	cout<<"2";
		}
	cout<<ans<<"\n";
	}
}
