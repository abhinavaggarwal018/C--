    #include<iostream>
    #include<string>
    using namespace std;
    int main()
    {	
    int l1,k=0, i, l2,j,p;
    char s_num1[110], s_num2[110], s_ans[111];
    int tens=0, ones, ans;
    cin>>s_num1;
    cin>>s_num2;
    //cout<<(int) s_num1[0];
    for(l1=0;s_num1[l1]!='\0';l1++);
    for(l2=0;s_num2[l2]!='\0';l2++);
    l1--;
    l2--;
    for(i=l1, j = l2;(i>=0)&&(j>=0);i--,j--){
    ans = (int) s_num1[i] + (int) s_num2[j] + tens - 2*48;
    ones=ans%10;
    tens=ans/10;
    s_ans[k] = ones + 48;
    k++;
    }
    while(i>=0){
    cout<<"str 1 bigger\n";
    ans = tens + (int) s_num1[i] -48;
    ones=ans%10;
    tens=ans/10;
    s_ans[k] = ones + 48;
    k++;
    i--;
    }
    while(j>=0){
    cout<<"str2 biigger\n";
    ans = tens + (int) s_num2[j] -48;
    ones=ans%10;
    tens=ans/10;
    s_ans[k] = ones + 48;
    k++;
    j--;
    }
    if(tens!=0)
    s_ans[k++] = tens+48;	
    cout<<k<<endl;
    for(p=k-1;p>=0;p--)
    cout<<s_ans[p];
    return 0;
    }

int compute()
{
	for(int i=0;i<n;i++)
	{
		if((3*n*r + n + 2^n-1)<t)
		continue;
		else 
		cout<<"Case #"<<l<<<<": "<<n;
	}
}
