#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,lim,par=0,nameLen,descLen;
    char input[1005]={}, moduleName[105]={}, moduleDesc[305]={};

    FILE *fp;
    fp = fopen("output.txt","a");

    printf("Enter row limit:");
    scanf("%d ",&lim);

    for(i=0;i<lim;i++)
    {
        fgets(input,1000,stdin);

        nameLen=0;
        descLen=0;
        par=0;

        for(j=0;j<strlen(input);j++)
        {
            if(input[j]=='"'&&par==0)
            {
                par++;
                j++;
                while(input[j]!='"')
                {
                    moduleName[nameLen]=input[j];
                    nameLen++;
                    j++;
                }
            }
            else if(input[j]=='"'&&par==1)
            {
                j++;
                while(input[j]!='"')
                {
                    moduleDesc[descLen]=input[j];
                    descLen++;
                    j++;
                }
            }
        }

        for(j=0;j<strlen(moduleName);j++)
        {
            if((j==0||moduleName[j-1]==' ')&&moduleName[j]>=97)
                moduleName[j]-=32;
        }

        printf("\nProcessed: %s = %s\n\n",moduleName,moduleDesc);
        fprintf(fp, "<tr>\n\t<td>%s</td>\n\t<td>%s</td>\n\t<td></td>\n</tr>\n",moduleName,moduleDesc);

        memset(moduleName,0,100);
        memset(moduleDesc,0,300);
    }
    fclose(fp);
    return 0;
}
