//
//  main.c
//  xunxvbiao
//信仰之跃 来实现我的第一个数据结构
//  Created by jia jia  on 2019/8/16.
//  Copyright © 2019年 jia jia . All rights reserved.
//

#include <stdio.h>

//先用数组来表示一个线性表

#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];// 线性表占用的数组空间
    int last;// 线性表中最后一个元素的下标值，空表要置为-1
}SeqList; // 这花括号后面带个自定义的名字，以后再定义的时候就很舒服了
//这样就可以定义变量了

/* 初始化线性表*/

//定义操作1 —— 初始化

SeqList *InitList() //无参数形式 这里面如果形参是一级指针会出问题
{
    SeqList *p;
    p= (SeqList *)malloc(sizeof (SeqList));//申请顺序表的空间 前面(SeqList *)，因为p是指针，所以强制类型转换了
    p->last = -1 ;
    return p;// 这返回的是一个地址
}

//操作2 —— 按内容查找 给一个元素，在表里找到一样的，返回位置序号（位置序号是从1开始的），否则返回-1

int Locate(SeqList *L, ElemType e )// 这个地方放第一个参数放L也可以，但是开销大，经济考虑用z地址指针形式
{
    int i ;
    for ( i=1 ; i<=L->last ;i++)
        if(L->elem[i]==e) return i+1 ;
    return -1 ;
}

//操作3 按照序号查找，找到第i个元素
ElemType GetData(SeqList *L,int i)
{
    if(i<=L->last+1) return L->elem[i-1];
    else printf( "%d id wrong\n",i );
    return -1;
}

//操作4 插入操作

#define ERROR -1
#define OK 1
int InsList(SeqList *L,int i, ElemType e ) // 这个i就是输入要插入元素的位置，e是插谁
{
    int k ;// 循环的时候用它了
    if ((i<1)||(i>L->last+2)) //判断插入位置是不是在设定范围里,注意，插入操作是可以在最最后插的，所以判断的时候是last+2,因为last+1 是a[n]，也就是最后一个的后一个
    {
        printf("插入位置不合法");
        return (ERROR);
    }
    if(L->last>=MAXSIZE-1) // 看看还有没有地方插了
    {
        printf("表满了，没地方了");
        return (ERROR);
    }
    
    for (k=L->last;k>=i-1;k--) //这个是一个循环，先把i后面的元素都往后挪，给i位置腾空，第i个元素的下标是i-1，注意序号和下标的区别
        L->elem[k+1]=L->elem[k];
    L->elem[i-1]=e;// 插
    L->last++ ; //插入之后长度增加
    return (OK); // ojbk
    
    //平均移动次数是 n/2 ,所以时间复杂度是O（n）
}

//操作5 删除 删除第i个元素，用指针e返回它的值

int DelList(SeqList *L,int i ,ElemType *e)
{
    int k ;
    if (i<1||i>L->last+1)
    {    printf("非法输入");
        return (ERROR);
        
    }
    for (k=i;k<=L->last;k++)
        L->elem[k-1]=L->elem[k];
    L->last--;
    return  (OK);
    
    // (n-1)/2   O(n)
}

//例题

void mergeList(SeqList *LA , SeqList *LB ,  SeqList *LC)
{
    int i,j,k;
    i=0;j=0;k=0;
    
    while (i<=LA->last&&j<=LB->last) // 比较
    {  if(LA->elem[i]<LB->elem[j])
         { LC->elem[k]=LA->elem[i];
             i++;k++;
          }
        else
        { LC->elem[k]=LB->elem[j];
            j++;k++;}
    }
    
    while(i<=LA->last) // 吃剩饭
    {
        LC->elem[k] = LA->elem[i];
        i++;k++;
    }
    
    while(j<=LB->last)
    {
        LC->elem[k] = LB->elem[j];
        j++;k++;
    }
    
    LC->last = LB->last+LA->last+1;  // 新下标， 这是下标，所以要+1
}
int main(int argc, const char * argv[]) {
    
/*
    SeqList L;  //第一种定义方式
    //scanf("%d",&L.elem[1]);  //这个直接输入是不好用的 奇怪了 但是编译OK
      printf("%d",L.elem[1]);
      printf("%d",L.elem[L.last]); // 最后一个元素怎么写，总共有last+1 个元素
    //输出测试
 */
 
 /*
    SeqList La , *L; // 第二种定义方式
    L= &La;
  printf("%d",L->elem[1]); // 用指针怎么输出
*/
    
   
    //练习开始 使用之前定义的操作
    int i ;
    SeqList *p ;
    p=InitList();
   // printf("%d\n",p->last);//如果返回-1 那说明初始化成功了
    
    for(i=0;i<10;i++) p->elem[i]=i+50; //给表前十个元素赋值
    p->last = i-1;//这个就是上边的i ，指针指向表最后一个有效元素，应该是9 ， 指的元素应该是59
    //printf( "%d\n", p->last); // 最后一个元素的位置
    //printf( "%d\n",p->elem[p->last]);//输出最后一个元素
    i = Locate( p, 54);//找到元素54在表里的位置
    // printf("%d\n",i);输出位置
// printf("%d\n",GetData(p, 5));// 找到位置是5的元素
    
    //练习题 将两个有序递增序列合成一个顺序表，LA(1,2,5) LB(1,3,4,4)--> LC(1,1,2,3,4,4,5)
    
    SeqList *p1 ;
    SeqList *p2 ;
    SeqList *p3 ;
    p1 = InitList();
    p2 = InitList();
    p3 = InitList();
    int a[3]= {1,2,5};
    int b[4] = {1,3,4,4};
    for (int h=0 ; h< 3;h++)
        p1->elem[h]=a[h];
    p1->last = 2;
    
    for (int g=0;g<4;g++)
        p2->elem[g]=b[g];
      p2->last = 3;
    
    mergeList( p1 ,p2 , p3);
  
    
    for (int f= 0;f<p3->last+1;f++)
       printf("    %d" , p3->elem[f]);
    
    //定义 赋值 循环比元素 谁小谁入列 剩下的统统插到尾巴里
       //定义函数去了 见mergelist
    
    
    return 0;
}
