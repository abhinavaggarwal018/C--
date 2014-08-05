/*#include <span class="code-keyword"><stdio.h></span>
#include <span class="code-keyword"><windows.h></span>
#include <span class="code-keyword"><process.h>     // needed for _beginthread()</span>
*/

#include<stdio.h>
#include<windows.h>
#include<process.h>


void  silly( void * );   // function prototype
int i=0;
int main()
{
    // Our program's first thread starts in the main() function.

    printf( "Now in the main() function.\n" );

    // Let's now create our second thread and ask it to start
    // in the silly() function.


    _beginthread( silly, 0, (void*)12 );

    // From here on there are two separate threads executing
    // our one program.

    // This main thread can call the silly() function if it wants to.
	Sleep(100);
    silly( (void*)-5 );
	printf("1\n");
	
	Sleep(20000);
}

void  silly( void *arg )
{
    Sleep( i*1000 );
    i=15;
	printf( "The silly() function was passed %d\n", (INT_PTR)arg ) ;
	for(int i=0;i<1000;i++)
	{
		printf("%d ",i);
		Sleep(200);
	}
}
