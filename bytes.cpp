    #include<stdio.h>
    #include<string.h>
    int main()
    {
    int t,i,i1;
    char str[55];
    char ans[55];
    scanf("%d",&t);
    int flag=0;
    for(i1=0;i1<t;i1++)
    {
    flag=0;
    scanf("%s",&str);
    //printf("strlen(str):%d",strlen(str));
    int start=strlen(str)-1;
    for(i=start;i>=0;i--)
    {
    if(str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='7')
    {
    printf("NO\n");
    flag=1;
    break;
    }
    else
    {
    switch(str[i])
    {
    case '1': ans[strlen(str)-i-1]='1';
    break;
    case '6': ans[strlen(str)-i-1]='9';
    break;
    case '8': ans[strlen(str)-i-1]='8';
    break;
    case '9': ans[strlen(str)-i-1]='6';
    break;
    case '0': ans[strlen(str)-i-1]='0';
    break;
    }
    }
    }
    if(flag==0)
    {
    ans[strlen(str)-i]='\0';
    printf("YES\n%s\n",ans);
    // printf("strlen(ans):%d",strlen(ans));
    }
    }
   return 0; 
    } 
