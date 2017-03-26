#include <stdio.h>
#include <stdlib.h>

#define N 1000

typedef struct Stu {
	char No[20];
	char Name[10];
	float Num1;
	float Num2;
	float Num3;
	float Avg;
	struct Stu *next;
}Node, *Link;

int n;
int i, j;
float sum;
Link p, head, head_new, x;

void sort() {
	Link pre, p1=NULL, pmax, p_new=NULL;
	for (i = 1; i <= n; ++ i) {
		pmax = p = head;//p遍历链表  pmax记录最大值位置
		pre = NULL;
		while (p != NULL) {
			if (p->Avg>pmax->Avg) {
				pmax = p;
				pre = p1;
			}
			p1 = p;
			p = p->next;
		}
		if (i == 1 ){ p_new = head_new = pmax; }
		else { p_new->next = pmax; p_new = p_new->next; }
		if (pre == NULL) { head = pmax->next; }
			else { pre->next = pmax->next; }
	}
	p_new->next = NULL;
}

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {

		x = (Link)malloc(sizeof(Node));
		if (i == 1) {
			head = x;
			p = head;
		}
		else {
			p->next = x;
			p = x;
		}
		
		{	scanf("%s", &p->No);
			scanf("%s", &p->Name);
			scanf("%f", &p->Num1);	
			scanf("%f", &p->Num2);
			scanf("%f", &p->Num3);
		}
		sum = p->Num1 + p->Num2 + p->Num3;
		p->Avg = sum / 3;
	}
	p->next = NULL;
	//sort
	sort();
	//output
	p = head_new;
	for (i = 1; i <= n; i++) {
		printf("%s %s %.2f %.2f %.2f %.2f %d\n", p->No, p->Name,
			p->Num1, p->Num2, p->Num3, p->Avg, i);
		p = p->next;
	}
	return 0;
}
