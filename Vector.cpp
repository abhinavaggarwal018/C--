#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	
	vector<int>::iterator it;
	for(int i=0;i<n;i++)
		cout<<arr[i];
	arr.clear();
	arr.assign(7,1);
	cout<<"ME\n";
	for(it=arr.begin();it!=arr.end();it++)
		cout<<*it;
}
