#include<stdio.h>
#include<stdlib.h>

struct stu{
	char infom[100];
	struct stu* next;
};

typedef struct stu Node;

int main(){
	int m,n;
	int i,num;
	struct stu *p,*p1,*f;//p��ָ��λ��   f��ָ��ͷ 
	
	scanf("%d%d",&n,&m);getchar();
	
	for(i=1;i<=n;i++){//����ѭ������ 
		if(i==1){f=(Node*)malloc(sizeof(Node));p=f;}
			else {p->next=(Node*)malloc(sizeof(Node));p=p->next;}
			
		gets(p->infom);
	}
	p->next=f;//βָ�� ָ��ͷ 
	
	p=f;//pָ��ָ��ͷ
	while(n>0){
		for(i=1;i<m-1;i++)p=p->next;//ѭ��m-2��
		p1=p->next;//p1ָ��Ҫɾ���Ľڵ�
		printf("%s\n",p1->infom);//output
		p->next=p1->next;//ɾ��p1�ڵ�
		p=p->next; 
		n --;
	}
	return 0;
}
