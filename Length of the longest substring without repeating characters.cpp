#include<iostream>//wrong but small mistake
#include<string>
#include<vector>

using namespace std;

void longest_substring(string str)
{
	int len=str.length();
	vector<int>	vec(26,-1);
	vector<int>	index;
	int cnt=0,max_cnt=0,flag=-1;
	
	for(int i=0;i<26;i++)
		vec[i]=-1;
				
	for(int i=0;i<len;i++)
	{
		cout<<"i:"<<i<<"v:"<<vec[str[i]-'a']<<"\n";
		
		if(cnt==max_cnt)
			index.push_back(i-max_cnt);
		
		if(cnt>max_cnt)
		{
			max_cnt=cnt;
			index.clear();
			//cout<<"size:"<<index.size();
			index.push_back(i-max_cnt);
		}

		if	( vec[str[i]-'a']==-1||vec[str[i]-'a']<=i-max_cnt )
		{
			cnt++;
			vec[str[i]-'a']=i;
		}
		
		else
		{	
			if(vec[str[i]-'a']>i-max_cnt&&flag!=i)
			{
				flag=i;
				i--;
			}
			cnt=0;	
			for(int i=0;i<26;i++)
				vec[i]=-1;
		}

		cout<<"max_cnt:"<<max_cnt<<"\n";
	}
	cout<<max_cnt<<" "<<index.size()<<"\n";	
	cout<<cnt;
	if(cnt>max_cnt)
	{
		max_cnt=cnt;
		index.clear();
		cout<<index.size();
		index.push_back(len-max_cnt);
	
	}
	else if(cnt==max_cnt)
		index.push_back(len-max_cnt);
	
	cout<<max_cnt<<" "<<index.size()<<"\n";		
	
	for(int i=0;i<index.size();i++)
	{
		cout<<"String is:";	

		for(int j=0;j<max_cnt;j++)	
			cout<<str[index[i]+j];
		
		cout<<"\n";
	}
	
	index.clear();
}

int main()
{
	string str;
	while(1)
	{
		cin>>str;
		longest_substring(str);
	}
}
