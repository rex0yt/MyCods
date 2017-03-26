#include <iostream>
#include <cstring>

using namespace std;

char s[30];
int m[]={0,1,2,3};

int len,len_p,p_f=0; 
bool f = true,s0 = false;	//s0判断上一次输出是否为零 

//大小写数字转换 
bool to_b(char tmp){
	switch(tmp){
		case '0':cout << "零";return 1;
		case '1':cout << "壹";break;
		case '2':cout << "贰";break;
		case '3':cout << "叁";break;
		case '4':cout << "肆";break;
		case '5':cout << "伍";break;
		case '6':cout << "陆";break;
		case '7':cout << "柒";break;
		case '8':cout << "捌";break;
		case '9':cout << "玖";break;
	}
	return 0;
}

void nor(int a,int w){
	switch(w){
		case 3:if(!to_b(s[a]))cout<< "仟";a++;
		case 2:if(!to_b(s[a]))cout<< "佰";a++;
		case 1:if(!to_b(s[a]))cout<< "拾";a++;
		case 0:to_b(s[a]);
	}
	return ;
}
//转换函数 
bool change(int a,int b){
	int lenab=a-b+1;
	int p1=a,p2=b;
	while(s[p1]=='0'&&p1<=b)p1++;
	while(s[p2]=='0'&&p2>=a)p2--;
	if(p1<=p2){//不全为零 
		if(p1>a){//前面有零 
			for(int i=p1;i<=p2;i++)nor(i,b-i);
		}else {//前面无零
			if(s0){cout<<"零";s0=false;}
			for(int i=a;i<=p2;i++)nor(i,b-i);
			if(p2<b)s0=true;
		}
	}
	else{//全为零 
		s0=true;
		return false;
	}
	return true;
}
int main(){
	//init
	for(int i=0;i<30;i++)s[i]='0';
	cin >> s;len = strlen(s);
	//将整数和小数分开 
	int p_dot = 0;
	while((s[p_dot] != '.') && (p_dot <25))p_dot ++;
	//判断位数
	if((p_dot>=0)&&(p_dot<=17))len_p=p_dot;
		else {len_p=len;f=false;}
	//判断位数是否溢出 
	if(len_p>=17){cout << "输入数据应小于一亿亿"; return 0;} 
	//输出前驱 
	cout<<"人民币"; 
	//处理整数 
	if(len_p>=13){
		if(change(0,len_p-13))cout << "万";
		p_f+=len_p-12;len_p=12;
	}
	if(len_p>=9){
		if(change(p_f,p_f+len_p-9))cout << "亿";
		p_f+=len_p-8;len_p=8;
	}
	if(len_p>=5){
		if(change(p_f,p_f+len_p-5))cout << "万";
		p_f+=len_p-4;len_p=4;
	}
	change(p_f,p_f+len_p-1);
	cout << "元";
	//处理小数部分
	if(f){								
		if(s[p_dot+1]!='0'){
			to_b(s[p_dot+1]);cout << "角";
		}
		else cout << "零";
		if(s[p_dot+2]!='0'){
			to_b(s[p_dot+2]);
			cout << "分" << endl;
		}
	}else cout << "整";
	return 0;
}
