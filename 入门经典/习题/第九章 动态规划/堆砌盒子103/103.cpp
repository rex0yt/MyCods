/*最长上升子序列*/
#include <iostream>
#include <cstdio>

using namespace std;

int num,dim;/*num<=30,1<=dim<=10*/
const int INF = 50;
int ans[35],pv;

class box{
public:
	int No;
	int s[15];
	void input();
	int cmp(const box a);/*排序 字典序比较 是否大于a*/
	bool boxin(const box a);/*a完全小于 包含a*/
};
void box::input(){
	int i1,x,pv,k1;

	for(i1 = 0; i1 < dim; i1 ++){

		cin >> x;

		if(i1 == 0){
			s[0] = x;
			continue;
		}
		for(pv = 0;pv < i1;pv ++)
			if(x < s[pv])
				break;
			if(pv == i1){
				s[i1] = x;
				continue;
			}
			else {
				for(k1 = i1;k1 > pv;k1 --)
					s[k1] = s[k1-1];
				s[pv] = x;
			}
		}
	return ;
}
int box::cmp(const box a){

	int i2;
	for(i2 = 0; i2 < dim; i2 ++){
		if(s[i2] > a.s[i2]) return 1;
		if(s[i2] < a.s[i2]) return -1;
	}
	return 0;
}
bool box::boxin(const box a){
	int i3;
	for(i3 = 0; i3 < dim; i3++)
		if(s[i3] <= a.s[i3]) return 0;
	return 1;
}

class box seq[35],tmp;
int d[35];

void print_ans(int a){

    for(int i = 1;i <= pv;i ++){
        if((d[a]-d[i]==1)&&(seq[a].boxin(seq[i]))){
            print_ans(i);
            break;
        }
    }
    cout << seq[a].No << ' ';
}

int main() {
	int i,j;

	while(~scanf("%d",&num)){
		scanf("%d",&dim);
		for(i = 1;i <= num;i ++){/*num of box:1...num*/
			seq[i].No=i;
			seq[i].input();
		}
		/*sort box*/
		bool f = 1;
		while(f){
			f = 0;
			for(i = 1; i < num; i ++){
				if(seq[i].cmp(seq[i+1]) == 1){
					tmp = seq[i];
					seq[i] = seq[i+1];
					seq[i+1] = tmp;
					f = 1;
				}
			}
		}
		/*dp*/
		for(i = 0; i < 35; i ++) d[i] = 1;
		for(i = 2; i <= num; i ++)
			for(j = 1;j < i; j ++)
				if(seq[i].boxin(seq[j])) d[i] = max(d[i] , d[j] + 1);
		/*find d[max]*/
		pv = 1;
		for(i = 2; i <= num; i ++)if(d[i] > d[pv])pv = i;
		cout << d[pv] << endl;
		/*output*/
/*		j = pv;
		ans[d[pv]] = seq[pv].No;
		for(i = pv; i >= 1, j >= 1; i --){
			if((d[j] - d[i] == 1)&&(seq[j].boxin(seq[i]))){
                ans[j] = seq[i].No;
                j = i;
			}
		}
		for(i = 1; i < d[pv]; i++)cout << ans[i] << ' ';
		cout << ans[i] << endl;
*/      /*输出问题*/
        print_ans(pv);
        cout << endl;
	}
	return 0;
}
