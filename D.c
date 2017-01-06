#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,len,cnt=0,cmp[1001][2]={},min,p,tmp2;
    char word[1001][21],tmp[21];
    while(cnt>-1)
    {
        gets(tmp);
        if(tmp[0]=='0') break;
        strcpy(word[cnt],tmp);
        len=strlen(word[cnt]);
        cmp[cnt][0]=cnt;
        for(i=0;i<len;i++)
        {cmp[cnt][1]+=(tmp[i]-96);}
        cnt++;
    }
    for(i=0;i<cnt;i++)
    {
        min=9999;
        for(j=i;j<cnt;j++)
        {
            if(cmp[j][1]<min) {min=cmp[j][1]; p=j;}
        }
        tmp2=cmp[i][0]; cmp[i][0]=cmp[p][0]; cmp[p][0]=tmp2;
        tmp2=cmp[i][1]; cmp[i][1]=cmp[p][1]; cmp[p][1]=tmp2;
    }
    for(i=0;i<cnt;i++)
    {
        if(cmp[i][1]==cmp[i+1][1])
        {
            if(strcmp(word[cmp[i][0]],word[cmp[i+1][0]])>0)
            {
                tmp2=cmp[i][0]; cmp[i][0]=cmp[i+1][0]; cmp[i+1][0]=tmp2;
                tmp2=cmp[i][1]; cmp[i][1]=cmp[i+1][1]; cmp[i+1][1]=tmp2;
            }
        }
    }
    for(i=0;i<cnt;i++)
    {
        puts(word[cmp[i][0]]);
    }
    return 0;
}
