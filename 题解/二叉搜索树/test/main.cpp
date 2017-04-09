#include <stdio.h>
#include <string.h>
int a[1024],b[1024];
void cta(char c,int i)//这个和下面可以合并一个，用指针传递数组
{
    if(a[i]==0)
      {a[i]=c;return;}
    if(a[i]>c)
     cta(c,i<<1);
     else
     cta(c,i<<1|1);
}
void ctb(char c,int i)
{
    if(b[i]==0)
      {b[i]=c;return;}
    if(b[i]>c)
     ctb(c,i<<1);
     else
     ctb(c,i<<1|1);
}
int cmp(int j)//这里是让构建好的2棵树比较！
{
    int m1,m2;
    if(a[j]!=b[j])
     return 0;
    if(a[j]==0)
     return 1;
     m1=cmp(j<<1);
     m2=cmp(j<<1|1);
    return m1>m2?m2:m1;//递归回程，判断树是否一样
}
int main()
{ int i,n;
  char c[13],s[13];
  while(scanf("%d",&n),n)
  {   memset(a,0,sizeof(a));
      scanf("%s",c);//输入原序列
      for(i=0;c[i]!='\0';i++)
         cta(c[i],1);
      while(n--)
      { memset(b,0,sizeof(b));//开始这里和a放一起了，就错了！
         scanf("%s",s);
        for(i=0;s[i]!='\0';i++)
           ctb(s[i],1);
        if(cmp(1))
        printf("YES\n");
        else
        printf("NO\n");
      }
  }
  return 0;
}
