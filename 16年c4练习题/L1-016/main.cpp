#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N;
string tmp;
bool f = true;
bool f1;
int sum;
int quanzhong[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char jiaoyan[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

void calc()
{
	cin >> N;
	while(N --)
	{
		cin >> tmp;
		sum = 0;
		f1 = true;
		for(int i = 0; i < 17; i ++)
		{
			if(!(tmp[i] >= '0' && tmp[i] <= '9')){
				cout << tmp << endl;
				f1 = f = false;
			}
			sum += (tmp[i] - '0') * quanzhong[i];
		}
		if(f1){
			sum %= 11;
			if(tmp[17] != jiaoyan[sum]){
				f = false;
				cout << tmp << endl;
			}
		}
	}
	if(f)cout << "All passed" << endl;
}

int main(int argc, char** argv) {
	calc();
	return 0;
}
