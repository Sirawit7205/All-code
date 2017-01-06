#include<stdio.h>

int chk[105][105]={},cc=1,n,k,use[10]={},ansc[10]={},ans[10]={},q[10005][4]={},h=0,t=1,sel[10]={},dpos[10][3]={},sm[10][10]={},ansb=100000000;
char f[105][105]={},x;

void perm(int lim, int cur)
{
    int i,t=0;
    if(cur>lim)
    {
        for(i=1;i<=8;i++) if(ans[i]!=0&&sm[ans[i]][i]==0) return; else t+=sm[ans[i]][i];
        if(t<ansb) {for(i=1;i<=8;i++) ansc[i]=ans[i]; ansb=t;}
        return;
    }
    for(i=1;i<=8;i++)
    {
        if(use[i]==0) {use[i]=1; ans[cur]=sel[i]; perm(lim,cur+1); use[i]=0;}
    }
}

int main()
{
	int i,j,ta,tb,tc;
	scanf("%d %d",&n,&k);
	dpos[1][0]=1; dpos[1][1]=1; dpos[2][0]=1; dpos[2][1]=(n/2)+1; dpos[3][0]=1; dpos[3][1]=n;
	dpos[4][0]=(n/2)+1; dpos[4][1]=1; dpos[5][0]=(n/2)+1; dpos[5][1]=n;
	dpos[6][0]=n; dpos[6][1]=1; dpos[7][0]=n; dpos[7][1]=(n/2)+1; dpos[8][0]=n; dpos[8][1]=n;
	for(i=1;i<=k;i++)
	{
		for(j=0;j<n;j++) scanf("%s",f[j]);
		scanf(" %c",&x);
		sel[i]=i;
		for(j=1;j<=8;j++)
		{
			q[0][0]=dpos[j][0]; q[0][1]=dpos[j][1]; q[0][2]=0; h=0; t=1; chk[dpos[j][0]][dpos[j][1]]=cc;
			while(h<t)
			{
				ta=q[h][0]; tb=q[h][1]; tc=q[h][2]; h++;
				if(ta==(n/2)+1&&tb==(n/2)+1) {sm[i][0]++; sm[i][j]=tc; break;}
				if(ta>1&&f[ta-2][tb-1]=='O'&&chk[ta-1][tb]!=cc) {q[t][0]=ta-1; q[t][1]=tb; q[t][2]=tc+1; t++; chk[ta-1][tb]=cc;}
				if(ta<n&&f[ta][tb-1]=='O'&&chk[ta+1][tb]!=cc) {q[t][0]=ta+1; q[t][1]=tb; q[t][2]=tc+1; t++; chk[ta+1][tb]=cc;}
				if(tb>1&&f[ta-1][tb-2]=='O'&&chk[ta][tb-1]!=cc) {q[t][0]=ta; q[t][1]=tb-1; q[t][2]=tc+1; t++; chk[ta][tb-1]=cc;}
				if(tb<n&&f[ta-1][tb]=='O'&&chk[ta][tb+1]!=cc) {q[t][0]=ta; q[t][1]=tb+1; q[t][2]=tc+1; t++; chk[ta][tb+1]=cc;}
			}
			cc++;
		}
	}
    for(j=1;j<=k;j++) if(sm[j][0]==0) {printf("0 0 0 0 0 0 0 0\n-1"); return 0;}
    perm(8,1);
	if(ansb==100000000) {printf("0 0 0 0 0 0 0 0\n-1"); return 0;}
    for(j=1;j<=8;j++) printf("%d ",ansc[j]); printf("\n%d",ansb);
	return 0;
}
