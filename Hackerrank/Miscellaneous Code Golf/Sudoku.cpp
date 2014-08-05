#include<iostream>
#include<vector>

using namespace std;
int hash[10];
/* Head ends here */
bool sudoku_solve(int grid[9][9], int x, int y) {
    if(x==8 && y==8)
    {
        for(int i=0;i<9;i++)
        {    
            for(int j=0;j<9;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;
    }
    
    if(grid[x][y]!=0)
    {
        for(int i=x;i<9;i++)
        {
            for(int j=y;j<9;j++)
            {
                if(grid[i][j]==0)
                    return sudoku_solve(grid,i,j);
            }
        }
    }
    
    for(int i=0;i<10;i++)
        hash[i]=false;
    
    for(int i=0;i<9;i++)
        hash[grid[x][i]]=true;
    
    for(int i=0;i<9;i++)
        hash[grid[i][y]]=true;

    int a=x/3;
    int b=y/3;
    
    for(int i=a;i<a+3;i++)
    {
        for(int j=b;j<b+3;j++)
        {
            hash[grid[i][j]]=true;
        }
    }
    
    for(int i=1;i<=9;i++)
    {
        if(!hash[i])
        {
            grid[x][y]=i;
            if(sudoku_solve(grid,x,y)==true)
                return true;
            grid[x][y]=0;
        }    
    }
    return false;
}

/* Tail starts here */
int main(void) {
    int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        if(sudoku_solve(board,0,0))
        	cout<<"YES";
    }
    return 0;
}
