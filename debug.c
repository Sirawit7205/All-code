#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int std_num,score[2][51]={{0}}; //int std_num,score[2]{50}=[0]; 1. array ใช้วงเล็บสี่เหลี่ยม 2. ประกาศเป็น 0 ใช้วงเล็บปีกกา 3. array ไม่ประกาศเผื่อ \0
void add_std_num(void);
int sum_score(void);
char callgrade(int);
void add_score(void);
void sort_score(void);
void print_score(); //void print_score(void); 7. ประกาศ parameters เป็น void แต่ใส่ int i ตอนใช้
void gotoxy(int , int );
void clearline(int , int);

int main() { //int main()( 4. function ใช้วงเล็บปีกกา
    char c; //เพิ่มเพื่อแก้ข้อ 14
    do{
        print_score();
        printf("\nContinue Press \' Y \' or Any to Exit");
        c=getch(); //เพิ่มเพื่อแก้ข้อ 14
    }while(c=='Y'); //while(getch()=='y'); 14. getch ต้องมีตัวแปรรองรับ แล้วจึงมาเปรียบเทียบ
    return 0;
}

void gotoxy(int x, int y){
    COORD scr;
    HANDLE cur= GetStdHandle(STD_OUTPUT_HANDLE);
    scr.X = x; scr.Y = y;
    SetConsoleCursorPosition(cur,scr);
}
void clearline(int x, int y){
    gotoxy(x,y); //gotoxy(x,y,z); 5. gotoxy มี parameters สองตัว
    printf(" \r");
}
void add_std_num(void){
    std_num=0;
    do{
        system("cls");
        printf("Input the number of students -> ");
        scanf("%d",&std_num); //scanf("%d",$std_num); 6. scanf ใช้ %
    }while(std_num<0 || std_num>50);
}
int sum_score(){
    int sc1=71,sc2=31,sum=0;
    while(sc1<0 || sc1>70){
        clearline(0, 1);
        printf("Keep Score ");
        scanf("%d",&sc1);
    }
    while(sc1<0 || sc2>30){
        clearline(0, 2);
        printf("Test Score ");
        scanf("%d",&sc2);
    }
    sum=sc1+sc2;
    if(sum==49 || sum==59 || sum==69 || sum==79 /*sum>=79 10. == ไม่ใช่ >= เพราะเอา 79 อย่างเดียว*/){
       printf("\nPress \' Y \' to Add 1 point or Any To Don\'t ");
       sum+=(getch()!='y')? 1 :0 ;
    }
    return sum;
}
char cal_grade(int sc){
    if(sc>79 /*sc>89 11. >=80 = A */)return 'A';
    else if(sc>69)return 'B';
    else if(sc>59)return 'C';
    else if(sc>49)return 'D';
    else return 'F';
}
void add_score(void){
    add_std_num();
    int i;
    for(i=0;i<std_num;i++){
        system("cls");//system("csl"); 9. cls = clear screen
        printf("ADD SCORE STUDENT NO.%d\n",i+1);
        score[0][i]=i+1;
        score[1][i]=sum_score();
    }
}
void sort_score(void){
    add_score();
    int i,j,temp[2];
 for(i=0;i<std_num;i++) //for(i=0;i<std_num;i++); 13. ไม่ใส่ semi colon หลัง function
       for(j=0;j<i;j++)
            if(score[1][i]> score[1][j]){
temp[0]= score[0][i];
temp[1]= score[1][i];
score[0][i]=score[0][j];
score[1][i]=score[1][j];
score[0][j]=temp[0];
score[1][j]=temp[1];
}
}
void print_score(int i){
    sort_score();
    //int i; 8. i ประกาศตอนเรียก function แล้ว
    system("cls");
    printf("========== DESC SORTED ==========\n");
    for(i=0;i<std_num;i++)
 printf("| No.%d | Score->%d | Grade-> %c |\n",score[0][i],score[1][i],cal_grade(score[1][i])/*cal_grade(score[1]) 12. score เป็น array สองมิติ*/);
    printf("=================================\n");
}
