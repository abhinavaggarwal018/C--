#include<stdio.h>
//see about the first element if its included in ans.
#include<string.h>
int max_cnt,val,prev_cnt,curr_size,prev_size,t,index1=0,nxt=0,max_index;;
char str[20005];
int find1(int nxt)
{
	int i;
	for(i=nxt;i<max_index;i++)
	{
		if(str[i]==' '&&str[i+1]!=' ')
		return i;
	}
	return max_index;
}
int find()
{
	int i;
	for(i=index1+1;i<max_index;i++)
	{
		if(str[i]==' '&&str[i-1]!=' ')
		return i;
	}
	return max_index;
}
int main()
{
int i;
	scanf("%d",&t);
	fflush(stdin);
	while(t--)
	{
		max_cnt=0;prev_cnt=0;curr_size=0,prev_size=0,index1=-1,nxt=0,max_index;
		gets(str);
		max_index=strlen(str);
		val=0;
		for(i=0;i<max_index;i++)
		{
			if(str[i]!=' ')
			val=1;
		}
		if(val==0)
		break;
		while(1)
		{
			nxt=find();
			//std::cout<<nxt;
			curr_size=nxt-index1-1;
		/*	std::cout<<"Max Index:"<<max_index<<"   ";
			std::cout<<"Curr Size:"<<curr_size<<"   ";
			std::cout<<"Prev Size:"<<prev_size<<"   ";
			std::cout<<"Prev Cnt:"<<prev_cnt<<"   ";
			std::cout<<"Max Cnt:"<<max_cnt<<"   ";
		*/	index1=find1(nxt);
		//	std::cout<<"Index:"<<index<<"\n";
			if(curr_size==prev_size)
				prev_cnt++;
			else
				{
					if(max_cnt<prev_cnt)
						max_cnt=prev_cnt;
					prev_cnt=1;
					prev_size=curr_size;
				}
		/*	
			std::cout<<"Max Index:"<<max_index<<"   ";
			std::cout<<"Curr Size:"<<curr_size<<"   ";
			std::cout<<"Prev Size:"<<prev_size<<"   ";
			std::cout<<"Prev Cnt:"<<prev_cnt<<"   ";
			std::cout<<"Max Cnt:"<<max_cnt<<"\n";
			std::cout<<"Index:"<<index<<"   ";
		*/	if(index1==max_index)
				{
					if(max_cnt<prev_cnt)
						max_cnt=prev_cnt;
					break;
				}
			
		}
		printf("%d\n",max_cnt);
		//fflush(stdin);
	}
	return 0;
}
