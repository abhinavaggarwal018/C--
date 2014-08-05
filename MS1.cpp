#include<abhinav.h>

using namespace std;

int n;

vector<int> find_permute(const string &str)
{
	n=str.length();
	vector<int> arr(n+1);
	
	arr[0]=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='I')
			arr[i+1]=arr[i]+1;
		else
			arr[i+1]=arr[i]-1;
	}
	
	int minm=100;
	for(int i=0;i<=n;i++)
		minm=min(arr[i],minm);
		
	for(int i=0;i<=n;i++)
		arr[i]=arr[i]-minm+1;
		
	return arr;
}

int main()
{
	string str;
	cin>>str;
	
	vector<int> vec=find_permute(str);
	
	for(int i=0;i<n+1;i++)
		cout<<vec[i]<<" ";

}
