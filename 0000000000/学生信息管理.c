#include <stdio.h>
#include <stdlib.h>

#define N 1000

typedef struct Stu{
	int No;
	char Name[10];
	int Num1;
	int Num2;
	int Num3;
	float Avg;
	struct Stu *next;
}Node,*Link;

int n;
int i,j;
float sum;
Link p,head,head_new,new;

void sort(){
	Link pre,p1,pmax,p_new;
	p_new=head_new;

	while(head->next!=NULL){
		pmax=p=head->next;
		while(p!=NULL){
			if(p->Avg>pmax->Avg){
				pmax=p;
				pre=p1;
			}
			p1=p;
			p=p->next;
		}
		p_new=pmax;p_new->next=p_new;
		pre->next=pmax->next;
	}
	p_new->next=NULL;
}

int main(){
	scanf("%d",&n);
	p=head;
	for(i=1;i<=n;i++){
		p->next=(Link)malloc(sizeof(Node));
		p=p->next;
		scanf("%d%s",&p->No,&p->Name);
		scanf("%d%d%d",&p->Num1,&p->Num2,&p->Num3);
		sum=p->Num1+p->Num2+p->Num3;
		p->Avg=sum/3;
		p->No=i;

	}
	p->next=NULL;
	//sort
	sort(1,n);
	//output
	p=head_new;
	p=p->next;
	for(i=1;i<=n;i++){
		printf("%d %s %d %d %d %.2f %d\n",p->No,p->Name,
			p->Num1,p->Num2,p->Num3,p->Avg,i);
		p=p->next;
	}
	return 0;
}

