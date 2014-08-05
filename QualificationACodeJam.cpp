#include<iostream>
#include<stdio.h>
//freopen("input.txt",r,stdin);
//freopen("someints.txt", "r", stdin)
//myApplication > example.txt;
using namespace std;
char grid[5][5];
bool x_won,o_won,incomplete;
int bool_int(bool a)
{
	if(a==false)
	return 0;
	return 1;
}
int main()
{
	int t;
	cin>>t;
	for(int l=0;l<t;l++)
	{
		x_won=false;
		o_won=false;
		incomplete=false;
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			cin>>grid[i][j];
//			cout<<i<<grid[i];
		}
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(grid[i][j]=='.')
					incomplete=true;
	
		for(int i=0;i<4;i++)
			{
				if(x_won==false && (grid[i][0]=='X' || grid[i][0]=='T') && (grid[i][1]=='X' || grid[i][1]=='T') && (grid[i][2]=='X' || grid[i][2]=='T') && (grid[i][3]=='X' || grid[i][3]=='T'))
					x_won =true;
				if(o_won==false && (grid[i][0]=='O' || grid[i][0]=='T') && (grid[i][1]=='O' || grid[i][1]=='T') && (grid[i][2]=='O' || grid[i][2]=='T') && (grid[i][3]=='O' || grid[i][3]=='T'))
					o_won =true;
				if(o_won==false && (grid[0][i]=='O' || grid[0][i]=='T') && (grid[1][i]=='O' || grid	[1][i]=='T') && (grid[2][i]=='O' || grid[2][i]=='T') && (grid[3][i]=='O' || grid[3][i]=='T'))
					o_won =true;
				if(x_won==false && (grid[0][i]=='X' || grid[0][i]=='T') && (grid[1][i]=='X' || grid	[1][i]=='T') && (grid[2][i]=='X' || grid[2][i]=='T') && (grid[3][i]=='X' || grid[3][i]=='T'))
					x_won =true;

			}
		if(o_won==false && (grid[0][0]=='O' || grid[0][0]=='T') && (grid[1][1]=='O' || grid	[1][1]=='T') && (grid[2][2]=='O' || grid[2][2]=='T') && (grid[3][3]=='O' || grid[3][3]=='T'))
			o_won =true;	
		if(o_won==false && (grid[3][0]=='O' || grid[3][0]=='T') && (grid[2][1]=='O' || grid	[2][1]=='T') && (grid[1][2]=='O' || grid[1][2]=='T') && (grid[0][3]=='O' || grid[0][3]=='T'))
			o_won =true;
		if(x_won==false && (grid[0][0]=='X' || grid[0][0]=='T') && (grid[1][1]=='X' || grid	[1][1]=='T') && (grid[2][2]=='X' || grid[2][2]=='T') && (grid[3][3]=='X' || grid[3][3]=='T'))
			x_won =true;	
		if(x_won==false && (grid[3][0]=='X' || grid[3][0]=='T') && (grid[2][1]=='X' || grid	[2][1]=='T') && (grid[1][2]=='X' || grid[1][2]=='T') && (grid[0][3]=='X' || grid[0][3]=='T'))
			x_won =true;
		/*cout<<"Incomplete:"<<bool_int(incomplete)<<"\n";
		cout<<"X_Won:"<<bool_int(x_won)<<"\n";
		cout<<"O_Won:"<<bool_int(o_won)<<"\n";*/
		if((x_won==true && o_won==true) || (x_won==false && o_won==false))
			{
				if(incomplete==true)
					cout<<"Case #"<<l+1<<": Game has not completed\n";
				else
					cout<<"Case #"<<l+1<<": Draw\n";
				continue;
			}
		if(x_won==true)
			cout<<"Case #"<<l+1<<": X won\n";
		if(o_won==true)
			cout<<"Case #"<<l+1<<": O won\n";
	}
}
