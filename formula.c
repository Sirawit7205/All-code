#include<stdio.h>

double x[5][5]={},minor[5][5]={},det=0,ans[5]={};

int main()
{
    int i,j,n,t;
    scanf("%d",&n);
    scanf("%lfx+%lfy+%lfz=%lf",&x[1][1],&x[1][2],&x[1][3],&x[1][4]);
    scanf("%lfx+%lfy+%lfz=%lf",&x[2][1],&x[2][2],&x[2][3],&x[2][4]);
    scanf("%lfx+%lfy+%lfz=%lf",&x[3][1],&x[3][2],&x[3][3],&x[3][4]);
	minor[1][1]=(x[2][2]*x[3][3])-(x[2][3]*x[3][2]); det+=x[1][1]*minor[1][1];
	minor[1][2]=(x[2][1]*x[3][3])-(x[2][3]*x[3][1]); det-=x[1][2]*minor[1][2]; minor[1][2]*=-1;
	minor[1][3]=(x[2][1]*x[3][2])-(x[2][2]*x[3][1]); det+=x[1][3]*minor[1][3];
	minor[2][1]=(x[1][2]*x[3][3])-(x[1][3]*x[3][2]); minor[2][1]*=-1;
	minor[2][2]=(x[1][1]*x[3][3])-(x[1][3]*x[3][1]);
	minor[2][3]=(x[1][1]*x[3][2])-(x[1][2]*x[3][1]); minor[2][3]*=-1;
	minor[3][1]=(x[1][2]*x[2][3])-(x[1][3]*x[2][2]);
	minor[3][2]=(x[1][1]*x[2][3])-(x[1][3]*x[2][1]); minor[3][2]*=-1;
	minor[3][3]=(x[1][1]*x[2][2])-(x[1][2]*x[2][1]);
	t=minor[2][1]; minor[2][1]=minor[1][2]; minor[1][2]=t;
	t=minor[3][1]; minor[3][1]=minor[1][3]; minor[1][3]=t;
	t=minor[3][2]; minor[3][2]=minor[2][3]; minor[2][3]=t;
	ans[1]=(minor[1][1]*x[1][4])+(minor[1][2]*x[2][4])+(minor[1][3]*x[3][4]);
	ans[2]=(minor[2][1]*x[1][4])+(minor[2][2]*x[2][4])+(minor[2][3]*x[3][4]);
	ans[3]=(minor[3][1]*x[1][4])+(minor[3][2]*x[2][4])+(minor[3][3]*x[3][4]);
	printf("%.4f %.4f %.4f\n",ans[1]/det,ans[2]/det,ans[3]/det);
    return 0;
}
