#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count[26]={0};
    int b[350];
    char a[4][100];
    int i,j;
    int max=0;
    for(i=0;i<4;i++)
    {
        gets(a[i]);
        for(j=0;j<(int)strlen(a[i]);j++)
        {
            if('A'<=a[i][j]&&'Z'>=a[i][j])
                count[a[i][j]-'A']++;
        }
    }

    for(i=350-1;i>0;i--)
        for(j=0;j<26;j++)
    {
        if(i<=count[j])b[i]=j;
        if(max<count[j])max=count[j];
    }
    for(i=max;i>0;i--)
        for(j=0;j<26;j++)
    {
        if(b[i]==j)
        {
            printf("*\n");
            break;
        }
        if(i<=count[j])printf("* ");
        else printf("  ");
    }
    for(j='A';j<='Y';j++)
        printf("%c ",j);
    printf("Z\n");

    return 0;
}
