//
//  jingtailianbiao.c
//  lianbiao
//
//  Created by jia jia  on 2019/8/19.
//  Copyright © 2019年 jia jia . All rights reserved.
//对于没有指针的高级语言，可以用顺序存储结构数组实现链表 静态链表

//data域和cursor域 一个村数据 一个存后继结点数组的下标
//下标 头0 尾-1

#define Maxsize 100

typedef char Elemtype ;
typedef struct
{
    Elemtype data;
    int cursor;  //cursor 是游标
}Component,StaticList[Maxsize];
//component 是数组的 元素的类型
//StaticList类型是数组行

//游标

//初始化
 void initial(StaticList space , int *av) // av就是备用链表的指针

{
    int k;
    space[0].cursor=-1;
    for(k=1;k<Maxsize-1;k++)//留了一个，因为尾巴要赋值-1，不符合规律了
        space[k].cursor=k+1;
    space[Maxsize-1].cursor=-1;
    *av=1 ;//这个地方指的是1 不是0位
}

//分配结点 空间
int getnode(StaticList space,int *av)
{
    int i ;
    i=*av;//
    *av =space[*av].cursor;//摘下的元素，备用表指针下移
    return i;
}


//回收结点

void freenode(StaticList space,int *av,int k )//把空闲结点头插到b空闲链表 
{space[k].cursor=*av; //
    *av=k;
}
