#include <iostream>
#include <cstring>

using namespace std;

char s[30];
int m[]={0,1,2,3};

int len,len_p,p_f=0; 
bool f = true,s0 = false;	//s0�ж���һ������Ƿ�Ϊ�� 

//��Сд����ת�� 
bool to_b(char tmp){
	switch(tmp){
		case '0':cout << "��";return 1;
		case '1':cout << "Ҽ";break;
		case '2':cout << "��";break;
		case '3':cout << "��";break;
		case '4':cout << "��";break;
		case '5':cout << "��";break;
		case '6':cout << "½";break;
		case '7':cout << "��";break;
		case '8':cout << "��";break;
		case '9':cout << "��";break;
	}
	return 0;
}

void nor(int a,int w){
	switch(w){
		case 3:if(!to_b(s[a]))cout<< "Ǫ";a++;
		case 2:if(!to_b(s[a]))cout<< "��";a++;
		case 1:if(!to_b(s[a]))cout<< "ʰ";a++;
		case 0:to_b(s[a]);
	}
	return ;
}
//ת������ 
bool change(int a,int b){
	int lenab=a-b+1;
	int p1=a,p2=b;
	while(s[p1]=='0'&&p1<=b)p1++;
	while(s[p2]=='0'&&p2>=a)p2--;
	if(p1<=p2){//��ȫΪ�� 
		if(p1>a){//ǰ������ 
			for(int i=p1;i<=p2;i++)nor(i,b-i);
		}else {//ǰ������
			if(s0){cout<<"��";s0=false;}
			for(int i=a;i<=p2;i++)nor(i,b-i);
			if(p2<b)s0=true;
		}
	}
	else{//ȫΪ�� 
		s0=true;
		return false;
	}
	return true;
}
int main(){
	//init
	for(int i=0;i<30;i++)s[i]='0';
	cin >> s;len = strlen(s);
	//��������С���ֿ� 
	int p_dot = 0;
	while((s[p_dot] != '.') && (p_dot <25))p_dot ++;
	//�ж�λ��
	if((p_dot>=0)&&(p_dot<=17))len_p=p_dot;
		else {len_p=len;f=false;}
	//�ж�λ���Ƿ���� 
	if(len_p>=17){cout << "��������ӦС��һ����"; return 0;} 
	//���ǰ�� 
	cout<<"�����"; 
	//�������� 
	if(len_p>=13){
		if(change(0,len_p-13))cout << "��";
		p_f+=len_p-12;len_p=12;
	}
	if(len_p>=9){
		if(change(p_f,p_f+len_p-9))cout << "��";
		p_f+=len_p-8;len_p=8;
	}
	if(len_p>=5){
		if(change(p_f,p_f+len_p-5))cout << "��";
		p_f+=len_p-4;len_p=4;
	}
	change(p_f,p_f+len_p-1);
	cout << "Ԫ";
	//����С������
	if(f){								
		if(s[p_dot+1]!='0'){
			to_b(s[p_dot+1]);cout << "��";
		}
		else cout << "��";
		if(s[p_dot+2]!='0'){
			to_b(s[p_dot+2]);
			cout << "��" << endl;
		}
	}else cout << "��";
	return 0;
}
