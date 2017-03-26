#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a, b, c;

void input()
{
	cin >> a >> b >> c; 
}
void calc()
{
	if(a > b)swap(a, b);
	if(a > c)swap(a, c);
	if(b > c)swap(b, c);
}
void output()
{
	cout << a << "->" << b << "->" << c  << endl;
}
int main(int argc, char** argv) {
	input();
	calc();
	output();
	return 0;
}
