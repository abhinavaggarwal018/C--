#include<stdio.h>
//#include<iostream>
long long int collection,bag;
int n,num,flag,i,m,t,a[10005],i1;
long long int b_search(int start,int end)
{
//	std::cout<<"\n"<<start<<" "<<end;
	//std::cin>>q;

		collection=start+(end-start)/2;
			flag=0;
		if(collection<1)
		{
			return b_search(start+(end-start)/2+1,end);	
		}
		if(collection==1)
			flag=3;
//	std::cout<<"\ncollection: "<<collection;

	bag=n-collection;
///	std::cout<<"\nbag"<<bag;
	for(i=1;i<m;i++)
	{
		
	//	std::cout<<"\n";
		for(i1=0;i1<m;i1++)
	//	std::cout<<a[i1]<<" ";
	//	std::cout<<"\na[i]: "<<a[i]<<"a[i-1]: "<<a[i-1]<<"i: "<<i;
		num=a[i]-a[i-1];
	//	std::cout<<"\nbag: "<<bag<<"collection: "<<collection<<"num: "<<num;
		if(num!=0)
		{
			collection+=num;
			bag-=num;
		}
		else
			collection--;
		
	//	std::cout<<"\nbag: "<<bag<<"collection: "<<collection;
		
		if(collection<1)
		{
			flag=1;
			break;
		}
		if(bag<0)
		{
			flag=0;
			break;
		}
		if(collection==1)
		{
			flag=3;
		}
	}	
	if(start>=end&&flag!=3)
		return -1;
	if(flag==3)
		return start+(end-start)/2;
	if(flag==1)
		return b_search(start+(end-start)/2+1,end);		
	else
		return b_search(start,start+(end-start)/2);

}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
	
		for(i=0;i<m;i++)
		scanf("%d",&a[i]);
		printf("%lld\n",b_search(0,n));
	}
	return 0;
}
