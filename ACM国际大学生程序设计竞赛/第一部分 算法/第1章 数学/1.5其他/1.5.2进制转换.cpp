string transform(int x,int y,string s){
	string res = "";
	int sum = 0;
	for(int i = 0;i < s.length();++i){
		if(s[i] == '-') continue;
		if('0' <= s[i] &&s [i] <= '9'){
			sum = sum *x + s[i] - '0';
		}else{
			sum = sum * x + s[i] - 'A' + 10;
		}
	}
	while(sum){
		char tmp = sum % y;
		sum /= y;
		if(tmp <= 9){
			tmp += '0';
		}else{
			tmp = tmp - 10 + 'A';
		}
		res += tmp;
	}
	if(res.length() == 0) res = "0";
	if(s[0] == '-') res += '-';
	return res;
}
