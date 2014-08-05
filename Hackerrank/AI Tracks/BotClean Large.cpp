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

void dfs(vector <string> board, int cost, int x, int y,  int dimh, int dimw, int level)
{
	if(level==4)
		return;	
	
	bool flag=false;

	int sum=0,ans1=INT_MIN,max_sum=INT_MAX,cnt=0;

    for(int i=0;i<dimh;i++)
        for(int j=0;j<dimw;j++)
            if(board[i][j]=='d')
            {
 				flag=true;
				sum=0;
					
			    for(int i1=0;i1<dimh;i1++)
			        for(int j1=0;j1<dimw;j1++)
						if(board[i1][j1]=='d')
							sum+=abs(i1-i)+abs(j1-j)+1;
							
				if(ans1<sum)
				{
					ans1=sum;
					ans.x=i;
					ans.y=j;
					cnt=1;
				}
				if(ans1==sum)
					cnt++;
			}
			
    for(int i=0;i<dimh;i++)
        for(int j=0;j<dimw;j++)
            if(board[i][j]=='d')
            {
 				flag=true;
				int sum1=0;
					
			    for(int i1=0;i1<dimh;i1++)
			        for(int j1=0;j1<dimw;j1++)
						if(board[i1][j1]=='d')
							sum1+=abs(i1-i)+abs(j1-j)+1;
							
				if(sum >= sum1-2)
				{
	                board[i][j]='-';
	                
	                dfs(board,cost+abs(x-i)+abs(y-j)+1,i,j,dimh,dimw,level+1);
	                
	                board[i][j]='d';
	            }
			}
}


void next_move( int posr, int posc,  int dimh, int dimw, vector <string> board) {
    if(board[posr][posc]=='d')
    {
        cout<<"CLEAN\n";
        return;
    }
    
    cost_min=INT_MAX;
    
    dfs(board,0,posr,posc, dimh, dimw,0);
    
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
   
    //add logic here
}
/* Tail starts here */
int main(void) {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
