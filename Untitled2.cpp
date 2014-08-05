    #include <iostream>
    #include <cstdio>
    #include<queue>
    #include<utility>
    using namespace std;
    char arr[50][50];
    int vis[50][50];
    int h,w,len;
    pair<int,int>letter;
    queue<pair<int,int> >myqueue;
    int main()
    {
    int t=1;	
    scanf("%d %d",&h,&w);
    while(h!=0 && w!=0)
    {
    int i,j,x,y,maximum=0;
    for(i=0;i<h;i++)
    {
    for(j=0;j<w;j++)
    {
    scanf("%c",&arr[i][j]);
    }
    fflush(stdin);
    }
    for(i=0;i<h;i++)
    {
    for(j=0;j<w;j++)
    {
    vis[i][j]=0;
    }
    }
    for(i=0;i<h;i++)
    {
    for(j=0;j<w;j++)
    {
    if(arr[i][j]=='A')
    {
    letter=make_pair(i,j);
    vis[i][j]=1;
    myqueue.push(letter);
    }
    }
    while(!myqueue.empty())
    {
    pair<int,int>prev;
    prev=myqueue.front();
    myqueue.pop();
    x=prev.first;
    y=prev.second;
    int turnx[]={-1,-1,0,1,1,1,0,-1};
    int turny[]={0,1,1,1,0,-1,-1,-1};
    for(int k=0;k<8;k++)
    {
    int p=x+turnx[k];
    int q=y+turny[k];
    if(p>=0 && p<h && q>=0 && q<w)
    {
    if(arr[p][q]==arr[x][y]+1 && !vis[p][q])
    {
    vis[p][q]=1;
    myqueue.push(make_pair(p,q));
    }
    }
    }
    }
    len=arr[x][y]-64 +1;
    }
    if(maximum<len)
    maximum=len;
    printf("Case %d: %d",t++,maximum);
    scanf("%d %d",&h,&w);
    }
    return 0;
    }
