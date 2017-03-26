#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int N;
int ans = 1;

void input()
{
	cin >> N;
}
void calc()
{
	for(int i = 0; i < N; i ++)
	{
		ans *= 2;
	}
}
void output()
{
	cout << "2^" << N << " = " << ans << endl;
}
int main(int argc, char** argv) {
	input();
	calc();
	output();
	return 0;
}
