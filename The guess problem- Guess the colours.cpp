/*A  solution consists of four balls from a set of four different colors. The user
tries to guess the solution.

If they guess the right color for the right
spot, record it as being in the correct ‘Location’. If it’s the right color,
but the wrong spot, record it as a correct ‘Color’. For example: if the
solution is ‘BGRR’ and the user guesses ‘RGYY’ they have 1 ‘Location’ and 1
‘Color’. A correct solution would be 4 ‘Location’ and 0 ‘Color’.

Write a program to, given a solution and a
guess, calculate the response that we present to the user.*/

#include<abhinav.h>

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	
	int n=str1.length();
	
	int hash1[26],hash2[26],loc=0,col=0;
	
	for(int i=0;i<26;i++)
	{
		hash1[i]=0;
		hash2[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		if(str1[i]==str2[i])
			loc++;
			
		else
		{
			hash1[str1[i]-'A']++;
			hash2[str2[i]-'A']++;
		}
	}
	
	for(int i=0;i<26;i++)
		col+=min(hash1[i],hash2[i]);
		
	cout<<loc<<" "<<col;
	
}
