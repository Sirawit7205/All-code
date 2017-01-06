#include<stdio.h>

void p(int n,int x){
     int m=n%10;
     if(n>10) p(n/10,x+1);
     if(m==0)return;
     if(m==1&&x>0)printf("หนึ่ง");
     if(m==1&&x==0)printf("เอ็ด");
     if(m==2&&x!=1)printf("สอง");
     if(m==2&&x==1)printf("ยี่");
     if(m==3)printf("สาม");
     if(m==4)printf("สี่");
     if(m==5)printf("ห้า");
     if(m==6)printf("หก");
     if(m==7)printf("เจ็ด");
     if(m==8)printf("แปด");
     if(m==9)printf("เก้า");
     if(x==1) printf("สิบ");
     if(x==2) printf("ร้อย");
     if(x==3) printf("พัน");
     if(x==4) printf("หมื่น");
     if(x==5) printf("แสน");
     if(x==6) printf("ล้าน");
  }

int main() {
    p(7654321,0);
    return 0;
}
