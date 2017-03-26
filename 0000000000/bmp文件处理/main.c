#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

unsigned char _max(unsigned char *a)
{
    int p=0,i;
    for(i=1;i<3;i++)
        if(a[i]>a[p])p=i;
    return a[p];
}

unsigned char _min(unsigned char *a)
{
    int p=0,i;
    for(i=1;i<3;i++)
        if(a[i]<a[p])p=i;
    return a[p];
}

FILE *open_file(char *filename,char *mode)
{
    FILE *fp=fopen(filename,mode);
    if(fp == NULL){
        printf("文件打开失败\n");
        exit(-1);
    }

    return fp;
}

void rgb_to_hsv(unsigned char *a,float *b)
{
/*
max=max(R,G,B):
min=min(R,G,B)
V=max(R,G,B)
S=(max-min)/max:
ifR = max,H =(G-B)/(max-min)* 60
ifG = max,H = 120+(B-R)/(max-min)* 60
ifB = max,H = 240 +(R-G)/(max-min)* 60
ifH < 0,H = H+ 360
*/
    b[2] = (float)_max(a);//
    b[1] = (_max(a)-_min(a))/(float)_max(a);//
    if(a[2] == _max(a))b[0] =(a[1]-a[0])/(float)(_max(a)-_min(a))* 60.0;
    else if(a[1] == _max(a))b[0] = 120+(a[0]-a[2])/(float)(_max(a)-_min(a))* 60.0;
    else if(a[0] == _max(a))b[0] = 240 +(a[2]-a[1])/(float)(_max(a)-_min(a))* 60.0;
    else if(b[0] < 0)b[0] = b[0] + 360.0;
}

void hsv_to_rgb(unsigned char *a,float *b)
{
/*
if s = 0
R=G=B=V
else
H /= 60;

i = INTEGER(H)
f = H - i

a = V * ( 1 - s )
b = V * ( 1 - s * f )
c = V * ( 1 - s * (1 - f ) )

switch(i)
case 0: R = V; G = c; B = a;
case 1: R = b; G = v; B = a;
case 2: R = a; G = v; B = c;
case 3: R = a; G = b; B = v;
case 4: R = c; G = a; B = v;
case 5: R = v; G = a; B = b;
*/
    if(b[1] == 0)a[0] =a[1] =a[2] =(unsigned char)b[2];
    else b[0] /= 60;

    unsigned char i = (unsigned char)b[0];
    float f = b[0]-i;

    unsigned char a1 = (unsigned char)(b[2] * ( 1 - b[1] ));
    unsigned char b1 = (unsigned char)(b[2] * ( 1 - b[1] * f ));
    unsigned char c1 = (unsigned char)(b[2] * ( 1 - b[1] * (1 - f )));

    switch(i)
    {
        case 0: a[2] = (unsigned char)b[2];a[1] = c1;a[0] = a1;break;
        case 1: a[2] = b1;a[1] = (unsigned char)b[2];a[0] = a1;break;
        case 2: a[2] = a1;a[1] = (unsigned char)b[2]; a[0] = c1;break;
        case 3: a[2] = a1;a[1] = b1;a[0] = (unsigned char)b[2];break;
        case 4: a[2] = c1;a[1] = a1;a[0] = (unsigned char)b[2];break;
        case 5: a[2] = (unsigned char)b[2];a[1] = a1;a[0] = b1;break;
    }


}

/*
    a[0]=0;//blue
    a[1]=0;//green
    a[2]=0;//red
*/

int change(float *b){
    if(b[2]<50)b[2]+=30;
    else if(b[2]<100)b[2] +=20;
    else if(b[2]<150)b[2] +=15;
    else if(b[2]<210)b[2] += 0;
    return 0;
}

int main()
{
    FILE *fp1, *fp2;
    unsigned char offset[10];
    long val_offset = 0;
    unsigned char a[3];//BGR
    float b[3];//HSV
    int i;

    /*准备要操作的bmp文件*/
    printf("将文件放入同一目录下，并命名为test.bmp\n");
    /*打开文件进行操作*/
    fp1 = open_file("test.bmp","rb");
    system("copy test.bmp new.bmp");
    fp2 = open_file("new.bmp","wb");
    /*找到位图数据起始点*/
    fseek(fp1,10L,SEEK_SET);
    fread(offset,1,4,fp1);
    val_offset = offset[0]+offset[1]*16*16+offset[2]*16*16*16*16+offset[3]*16*16*16*16*16*16*16*16;
    /*操作文件*/
    fseek(fp1,val_offset,SEEK_SET);
    fseek(fp2,val_offset,SEEK_SET);
    while(fread(a,1,3,fp1)!=0){
        //change(a);
        rgb_to_hsv(a,b);
        change(b);
        hsv_to_rgb(a,b);
        fwrite(a,1,3,fp2);
    }
    /*复制位图头信息*/
    fseek(fp1, 0, SEEK_SET);
    fseek(fp2, 0, SEEK_SET);
    for(i = 0; i < val_offset; i ++){
        fread(a, 1, 1, fp1);
        fwrite(a, 1, 1, fp2);
    }
    /*关闭文件*/
    fclose(fp1);
    fclose(fp2);
    /**/
    printf("转换完成\n");

    return 0;
}
