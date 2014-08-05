	HANDLE hThread;
    unsigned threadID;

    printf( "Creating second thread...\n" );

    // Create the second thread.
    hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc, NULL, 0, &threadID );

    // Wait until second thread terminates. If you comment out the line
    // below, Counter will not be correct because the thread has not
    // terminated, and Counter most likely has not been incremented to
    // 1000000 yet.
    WaitForSingleObject( hThread, INFINITE );
    printf( "Counter should be 1000000; it is-> %d\n", Counter );
    // Destroy the thread object.
    CloseHandle( hThread );
    
    
    
    
    			printf("Calling thread for player1\n");

			cout<<(hThread = (HANDLE)_beginthread(Player_1, 0, NULL));
Checkers;

Board		_arr[8][8];
Params		*_move;
bool		_isTimeExceeded;
HANDLE		hThread;
unsigned	threadID;

