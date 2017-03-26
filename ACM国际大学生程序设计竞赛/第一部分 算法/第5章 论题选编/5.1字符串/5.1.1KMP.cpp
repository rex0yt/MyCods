/*
*KMP算法 快速字符串匹配
*模式串·字符串·返回结果 下标 均是从 0 开始
*
*
*/
#include <iostream>
#include <vector>

using namespace std;

vector <int> find_substring (string pattern, string text){
    int n = pattern.size();
    vector <int> next(n + 1, 0);
    for(int i = 1; i < n; ++ i){
        int j = i;
        while(j > 0){
            j = next[j];
            if(pattern[j] == pattern[i]){
                next[i + 1] = j + 1;
                break;
            }
        }
    }
    vector <int> positions;
    int m = text.size();
    for(int i = 0, j = 0; i < m; ++ i){
        if(j < n && text[i] == pattern[j]){
            j ++;
        }else{
            while(j > 0){
                j = next[j];
                if(text[i] == pattern[j]){
                    j ++;
                    break;
                }
            }
        }
        if(j == n){
            positions.push_back(i - n + 1);
        }
    }
    return positions;
}

int main(){
    string pattern, text;
    cout <<  "input pattern and text:\n" ;
    cin >> pattern >> text;
    vector <int> ans = find_substring(pattern, text);
    vector <int> ::iterator it;
    cout << "count of ans: " << ans.size() << endl;
    cout << "position of each ans: " ;
    for(it=ans.begin();it!=ans.end();it++){
        cout << *it << " " ;
    }
    return 0;
}
