#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,t,m=4,n=18;
    char data[100][100]={"   _.-=-._     .-,"," .'       '-.,' / ","(          _.  <"," `=.____.='  `._\\"};
    srand(time(NULL));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
	DWORD consize, charswritten;
	COORD screencoord = {0,0};

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	consize = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;
	
	FillConsoleOutputAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED,consize,screencoord,&charswritten);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            t=rand()%3;
        if(t==0)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
            printf("%c",data[i][j]);
        }
        else if(t==1)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
            printf("%c",data[i][j]);
        }
        else if(t==2)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
            printf("%c",data[i][j]);
        }
        }
        printf("\n");
    }	
	SetConsoleCursorPosition(hConsole, screencoord);
	printf("Cursor is here!");
	Sleep(1000);
	FillConsoleOutputAttribute(hConsole,saved_attributes,consize,screencoord,&charswritten);
	SetConsoleTextAttribute(hConsole, saved_attributes);
    return 0;
}
