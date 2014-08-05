#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<fstream>
#include<string>
using namespace std;
/* Head ends here */

char str[5][10];

struct move
{
    int x;
    int y;
    
    move(int x1,int y1)
    {
    	x=x1;
    	y=y1;
    }
}ans(0,0);

int cost_min;

void dfs(vector <string> board, int cost, int x, int y, int level)
{
	bool flag=false;

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            if(board[i][j]=='d')
            {
            	flag=true;
            	
                board[i][j]='-';
                
                dfs(board,cost+abs(x-i)+abs(y-j)+1,i,j,1);
                
                board[i][j]='d';
            }
        }
    }
    
    if(flag==false && level!=0)
    {
    	
		if(cost<cost_min)
    	{
    		ans.x=x;
            ans.y=y;
    	}
    	return;
    }
    
    if(flag==false && level==0)
    {
		for(int i=2;i<5;i++)
		{
			if((x+i<5) &&board[x+i][y]=='o')
			{
				ans.x=x+i;
				ans.y=y;
				return;
			}
	
			if((x-i>0) &&board[x-i][y]=='o')
			{
				ans.x=x-i;
				ans.y=y;
				return;
			}
	
			if((y+i<5) &&board[x][y+i]=='o')
			{
				ans.x=x;
				ans.y=y+i;
				return;
			}
	
			if((y-i<5) &&board[x][y-i]=='o')
			{
				ans.x=x;
				ans.y=y-i;
				return;
			}
		}

		if((x+2<5))
		{
			ans.x=x+2;
			ans.y=y;
			return;
		}

		if((x-2>0))
		{
			ans.x=x-2;
			ans.y=y;
			return;
		}

		if((y+2<5))
		{
			ans.x=x;
			ans.y=y+2;
			return;
		}

		if((y-2<5))
		{
			ans.x=x;
			ans.y=y-2;
			return;
		}

			
    }
}

void print(vector<string> board)
{
	
	fstream file;
    string filename = "myfile.txt";    

    file.open( filename.c_str() );

	for(int i=0;i<5;i++)
		file<<board[i]<<"\n";	

    file.close();
}


void next_move( int posr, int posc, vector <string> board) {
	
	fstream file;
    string filename = "myfile.txt";    

	file.open( filename.c_str() );

	if( file )
    {
	
		for(int i=0;i<5;i++)
			cin>>str[i];
		
		file.close();
	

		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(str[i][j]=='-')
				{
					if(board[i][j]=='o')
						board[i][j]='-';
				}
			}
		}	
	}

    if(board[posr][posc]=='d')
    {
	    cout<<"CLEAN\n";
	    board[posr][posc]='-';
        print(board);
		return;
    }
    
    cost_min=INT_MAX;
    dfs(board,0,posr,posc,0);
    cout<<posr<<" "<<posc<<" "<<ans.x<<" "<<ans.y<<"\n";
    
	if(posr<ans.x)
    {
        cout<<"DOWN\n";
        print(board);
        return;
    }

    if(posr>ans.x)
    {
        cout<<"UP\n";
        print(board);
        return;
    }

    if(posc<ans.y)
    {
        cout<<"RIGHT\n";
        print(board);
        return;
    }

    if(posc>ans.y)
    {
        cout<<"LEFT\n";
    	print(board);
	    return;
    }
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
	cout<<0;
    next_move(pos[0], pos[1], board);
    return 0;
}

/*
0 0
b-ooo
--ooo
ooooo
ooooo
ooooo
*/
