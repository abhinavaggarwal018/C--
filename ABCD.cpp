#include<iostream>
using namespace std;
char input[100005],output[100005]="AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
int n,count[4]={0};

int dfs(int i)
{
	bool iter[]={true,true,true,true}; //if iter[i] is true means we have to call its associated DFS 
	//iter[0]='A' iter[1]='B' iter[2]='C' iter[3]='D'
	cout<<"i:"<<i<<"n:"<<n<<"\n";
	if(i<2*n)
	{	
		for(int j=0;j<4;j++)
		cout<<iter[j]<<"\t";
		cout<<"\n";
		cout<<input[i]<<"\n";
		//cout<<(input[i]=='B');
		if(input[i]=='A')
		{
			iter[0]=false;
			cout<<"A"<<iter[0];
		}
		if(input[i]=='B')
		{
			iter[1]=false;
			cout<<"B"<<iter[1];
		}	
		if(input[i]=='C')
		{
			iter[2]=false;
			cout<<"C"<<iter[2];
		}
		if(input[i]=='D')
		{
			iter[3]=false;
			cout<<"D"<<iter[3];
		}
		for(int j=0;j<4;j++)
		cout<<iter[j]<<"\t";
		cout<<"\n";
			
		if(i>0&&output[i-1]=='A')
			iter[0]=false;
		if(i>0&&output[i-1]=='B')
			iter[1]=false;
		if(i>0&&output[i-1]=='C')
			iter[2]=false;
		if(i>0&&output[i-1]=='D')
			iter[3]=false;
		
		for(int j=0;j<4;j++)
		cout<<iter[j]<<"\t";
		cout<<"\n";
			
		for(int i1=0;i1<4;i1++)
		{
			if (input[i1]==true&&count[i1]>0)
			{
				
				input[i1]--;
				output[i]=char('A'+i1);
				cout<<"o/p"<<output[i];
				cout<<"23";
				dfs(i+1);
			}
		}
			
	}
	else 
	return 0;
}
int main()
{
	cin>>n;
	cin>>input;
	cout<<input;
	count[0]=n;
	count[1]=n;
	count[2]=n;
	count[3]=n;
	output[2*n]='\0';
				
	for(int i=0;i<n;i++)
	{
		if(input[i]=='A')
			count[0]--;
		else if(input[i]=='B')
			count[1]--;
		else if(input[i]=='C')
			count[2]--;
		else if(input[i]=='D')
			count[3]--;
	}
	cout<<"1";
	dfs(0);
	cout<<"2";
	cout<<output;
}
