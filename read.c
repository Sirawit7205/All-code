#include<stdio.h>

void p(int n,int x){
     int m=n%10;
     if(n>10) p(n/10,x+1);
     if(m==0)return;
     if(m==1&&x>0)printf("˹��");
     if(m==1&&x==0)printf("���");
     if(m==2&&x!=1)printf("�ͧ");
     if(m==2&&x==1)printf("���");
     if(m==3)printf("���");
     if(m==4)printf("���");
     if(m==5)printf("���");
     if(m==6)printf("ˡ");
     if(m==7)printf("��");
     if(m==8)printf("Ỵ");
     if(m==9)printf("���");
     if(x==1) printf("�Ժ");
     if(x==2) printf("����");
     if(x==3) printf("�ѹ");
     if(x==4) printf("����");
     if(x==5) printf("�ʹ");
     if(x==6) printf("��ҹ");
  }

int main() {
    p(7654321,0);
    return 0;
}
