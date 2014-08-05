#include<iostream>
#include<stdio.h>
/*struct tree
{
	int num;
	int num_count;
};
struct tree 
*/
int p[100005],n,m,num;
int node_count[100005]={0};
using namespace std;
int modify_parents(int num)
{
	if(num==0)
		return 0;
	node_count[num]++;
	modify_parents(p[num]);
}
int modify_and_check_parents(int num)
{
	//cout<<"Entered\n";
	if(num==0)
		return 0;
	node_count[num]++;
	//cout<<"num"<<num<<"node_count[num]"<<node_count[num]<<"\n";
	if(node_count[num]==m)
		return num;
	modify_and_check_parents(p[num]);
	
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
		scanf("%d",&p[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&num);
		if(i!=m-1)
		modify_parents(num);
		else
		cout<<modify_and_check_parents(num)<<"\n";
	}
	//for(int i=0;i<n;i++)
	//cout<<node_count[i]<<" ";
	
}
