unsigned Power(unsigned n,unsigned p)
{
   unsigned main=n; //用main保存结果
   unsigned odd=1; //odd用来计算“剩下的”乘积
   while( p > 1){//一直计算，直到指数小于或等于1
    // 如果指数p是奇数，则说明计算后会剩一个多余的数，那么在这里把它乘到结果中
        if((p % 2) != 0)odd*=main; //把“剩下的”乘起来
        main*=main; //主体乘方
        p/=2; //指数除以2
   }
   return main*odd; //最后把主体和“剩下的”乘起来作为结果
}

int main(){

    return 0;
}
