#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200

typedef struct{
    char user_name[20];/*较为初级的结构体*/
    char user_psw[20];
    float money;
}USER_INFO;

int user_number;
USER_INFO user_info[MAXN];
int user_current = MAXN;

void first_step();
void second_step();

void input_data(){
    int i;
    FILE *fdata;

    fdata = fopen("data.txt","r");/*最主要的函数之一辣，主要是起到把修改或导入的数据转存到储存中*/
    fscanf(fdata,"%d",&user_number);
    for(i = 0; i < user_number; ++ i){
        fscanf(fdata,"%s",user_info[i].user_name);
        fscanf(fdata,"%s",user_info[i].user_psw);
        fscanf(fdata,"%f",&user_info[i].money);
    }
    fclose(fdata);
    return ;
}

void regist(){
    char name[20];
    char psw[20];

    scanf("%s%s",name,psw);/*注册哒哒，在这里直接通过函数将其导入到储存中*/
    strcpy(user_info[user_number].user_name,name);
    strcpy(user_info[user_number].user_psw,psw);
    user_info[user_number].money = 0;
    user_number ++;

    first_step();
}

void login(){
    char name[20];
    char psw[20];
    int i;
    /*从文档中寻找匹配项*/
h:  scanf("%s",name);
    for(i = 0; i < user_number; ++ i){
        if(strcmp(name,user_info[i].user_name) == 0)break;/*通过比较数组中的大小来判断是否符合*/
    }
    if(i >= user_number){
        printf("error user name!\n");
        goto h;
    }else {
g:      scanf("%s",psw);
        if(strcmp(psw,user_info[i].user_psw) == 0){
                user_current = i;
                second_step();
        }else{
            printf("error psw\n");
            goto g;
        }
    }
}

void output_data(){
    FILE *fdata;
    int i;

    fdata = fopen("data.txt","r+"); /*从文件中读出数据*/
    fprintf(fdata,"%d\n",user_number);
    for(i = 0; i < user_number; ++ i){
        fprintf(fdata,"%s\n",user_info[i].user_name);
        fprintf(fdata,"%s\n",user_info[i].user_psw);
        fprintf(fdata,"%.2f\n",user_info[i].money);
    }
}

void first_step(){
    unsigned int code_id;

    printf("请输入操作码：\n");
s:  printf("1.注册用户\n");
    printf("2.用户登录\n");
    printf("3.退出系统\n");

    scanf("%d",&code_id);

    if(3 == code_id){
        output_data();
        exit(0);
    }else if(1 == code_id)regist();
    else if(2 == code_id)login();
    else{
        printf("操作码错误重新输入\n");
        goto s;
    }

    return ;
}

void query(){
    printf("%.2f\n",user_info[user_current].money);
    second_step();
}
void cunqian(){
    float f;
    scanf("%f",&f);
    user_info[user_current].money += f;
    second_step();
}
void qukuan(){
    float f;
    scanf("%f",&f);
    user_info[user_current].money -= f;
    second_step();
}
void quit(){
    first_step();
}

void second_step(){
    unsigned int code_id;

la: printf("请输入操作码：\n");
    printf("1.查询余额\n");
    printf("2.存款\n");
    printf("3.取款\n");
    printf("4.用户登出\n");
    scanf("%d",&code_id);

    switch(code_id){
        case 1:query();break;
        case 2:cunqian();break;
        case 3:qukuan();break;
        case 4:quit();break;
        default: goto la;
    }
    return ;
}


int main()
{

    input_data();

    first_step();

    return 0;
}
