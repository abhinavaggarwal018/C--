#include<fstream.h>
using namespae std;
int main()
{
    //fstream finout;
    int fib[100]={0},i,j;
    fib[0]=0;
    fib[1]=1;
    for(i=2;i<99;i++)
    fib[i]=fib[i-1]+fib[i-2];
    //finout.open("fib.txt",ios::ate)
    //for(i=0;i<99;i++)
    //finout<<fib[i]<<"\n";
    //finout.close()
}
