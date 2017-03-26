#include <iostream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int NN = 10 +2;
int N;
int sum = 0;

vector <int> a(NN);

void input()
{
	cin >> N; 
}
int jiecheng(int n)
{
	if(n == 1)return 1;
	if(a[n] != 0)return a[n];
	else return n*jiecheng(n - 1);
}
void calc()
{
	for(int i = 1; i <= N; i ++)
	{
		sum += jiecheng(i);
	}
}
void output()
{
	cout << sum << endl; 
}
int main(int argc, char** argv) {
	input();
	calc();
	output();
	
	return 0;
}
