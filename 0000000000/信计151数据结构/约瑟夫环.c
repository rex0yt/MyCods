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
	struct stu *p,*p1,*f;//p：指针位置   f：指向头 
	
	scanf("%d%d",&n,&m);getchar();
	
	for(i=1;i<=n;i++){//建立循环链表 
		if(i==1){f=(Node*)malloc(sizeof(Node));p=f;}
			else {p->next=(Node*)malloc(sizeof(Node));p=p->next;}
			
		gets(p->infom);
	}
	p->next=f;//尾指针 指向头 
	
	p=f;//p指针指向头
	while(n>0){
		for(i=1;i<m-1;i++)p=p->next;//循环m-2次
		p1=p->next;//p1指向要删除的节点
		printf("%s\n",p1->infom);//output
		p->next=p1->next;//删除p1节点
		p=p->next; 
		n --;
	}
	return 0;
}
