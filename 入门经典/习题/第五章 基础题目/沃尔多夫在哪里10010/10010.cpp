#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

char s[55][55];
char str[55];
int num_case, m, n, x;
int dir_x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dir_y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void get_loc(){
    bool f;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++){
            if(s[i][j] == str[0]){
                for(int l = 0; l < 8; l ++){
                    f = true;
                    for(int k = 1; k < strlen(str); k ++){
                        int new_x=i+k*dir_x[l],new_y=j+k*dir_y[l];

                        if(new_x < 0 || new_y < 0){f=false;break;}
                        if(new_x >= m || new_y >= n){f=false;break;}
                        if(s[new_x][new_y] != str[k]){f=false;break;}
                    }
                    if(f){
                        cout << i+1 << ' ' << j+1 << endl;
                        return ;
                    }
                }
            }
    }
    return ;
}


int main(){

    cin >> num_case;

    while(num_case --){
        //input
        cin >> m >> n;
        for(int i = 0; i < m; i ++) cin >> s[i];

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(('a' <= s[i][j]) && (s[i][j] <= 'z'))s[i][j] -= 32;

        cin >> x;
        while(x --){
            cin >> str;
            for(int i = 0; i < strlen(str); i ++)
                if(('a' <= str[i]) && (str[i] <= 'z'))str[i] -= 32;
            //
            get_loc();

        }
        if(num_case)cout << endl;
    }
    return 0;
}
