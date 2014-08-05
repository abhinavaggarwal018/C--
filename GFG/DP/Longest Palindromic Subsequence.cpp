#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int ans[100][100];

int lpsRecur(char seq[], int start, int end, int ans)
{
	int end_ind;
	if(start==end)
		return 1;
		
	if(start>end)
		return 0;
		
	for(int i=end;i>=start;i--)
		if(seq[i]==seq[start])
		{
			end_ind=i;
			break;
		}
	
	if(start==end_ind)
		return max(ans+1,lpsRecur(seq,start+1,end,ans));
	else
		return max(ans+2+lpsRecur(seq,start+1,end_ind-1,ans),ans+lpsRecur(seq,start+1,end,ans));
}

int lps(char seq[], int start, int end, int answ)
{
	if(ans[start][end])
		return ans[start][end];
				
	int end_ind;
	
	if(start==end)
	{
		ans[start][end]=1;
		return ans[start][end];
	}	
		
	if(start>end)
		return 0;

	for(int i=end;i>=start;i--)
		if(seq[i]==seq[start])
		{
			end_ind=i;
			break;
		}
	
	if(start==end_ind)
		ans[start][end]=max(answ+1,lps(seq,start+1,end,answ));		
	else
		 ans[start][end]=max(answ+2+lps(seq,start+1,end_ind-1,answ),answ+lps(seq,start+1,end,answ));
		 
	return ans[start][end];	 
}


int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d", lps(seq, 0, n-1,0));
    getchar();
    return 0;
}
