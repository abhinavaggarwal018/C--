#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
/* Head ends here */

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

void dfs(vector <string> board, int cost, int x, int y)
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
                
                dfs(board,cost+abs(x-i)+abs(y-j)+1,i,j);
                
                board[i][j]='d';
            }
        }
    }
    
    if(flag==false)
    {
    	
		if(cost<cost_min)
    	{
    		ans.x=x;
            ans.y=y;
    	}
    }
}

void next_move( int posr, int posc, vector <string> board) {

    if(board[posr][posc]=='d')
    {
        cout<<"CLEAN\n";
        return;
    }
    
//    cost_min=INT_MAX;
    
//    dfs(board,0,posr,posc);
    
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
			if(board[i][j]=='d')
			{
				ans.x=i;
				ans.y=j;
				
				if(posr<ans.x)
			    {
			        cout<<"DOWN\n";
			        return;
			    }
			
			    if(posr>ans.x)
			    {
			        cout<<"UP\n";
			        return;
			    }
			
			    if(posc<ans.y)
			    {
			        cout<<"RIGHT\n";
			        return;
			    }
			
			    if(posc>ans.y)
			    {
			        cout<<"LEFT\n";
			        return;
			    }

			}
		}
	}
   
    //add logic here
}
/* Tail starts here */
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
