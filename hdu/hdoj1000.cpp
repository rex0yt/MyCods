#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdio>

//#define LOCAL
#define CPPIO
#define MaxN 100000

using  std::ios;
using std::cin;
using std::cout;
using std::endl;

void initProgram()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif // LOCAL

#ifdef CPPIO
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif // CPPIO

	return;
}

int main()
{
	initProgram();
	int a, b;
	while (cin >> a >> b)
	{
		cout << a + b << endl;
	}
	return 0;
}
