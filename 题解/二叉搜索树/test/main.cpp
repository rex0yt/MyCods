#include <stdio.h>
#include <string.h>
int a[1024],b[1024];
void cta(char c,int i)//�����������Ժϲ�һ������ָ�봫������
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
int cmp(int j)//�������ù����õ�2�����Ƚϣ�
{
    int m1,m2;
    if(a[j]!=b[j])
     return 0;
    if(a[j]==0)
     return 1;
     m1=cmp(j<<1);
     m2=cmp(j<<1|1);
    return m1>m2?m2:m1;//�ݹ�س̣��ж����Ƿ�һ��
}
int main()
{ int i,n;
  char c[13],s[13];
  while(scanf("%d",&n),n)
  {   memset(a,0,sizeof(a));
      scanf("%s",c);//����ԭ����
      for(i=0;c[i]!='\0';i++)
         cta(c[i],1);
      while(n--)
      { memset(b,0,sizeof(b));//��ʼ�����a��һ���ˣ��ʹ��ˣ�
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
