//
//  main.c
//  kk
//
//  Created by jia jia  on 2019/8/9.
//  Copyright © 2019年 jia jia . All rights reserved.
//

#include <stdio.h>
#include "string.h"
#define A 10
float max(float a , float b)
{
    float k ;
    k= a>b? a:b ;
    return k;
}


int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
//
//    long int a= 2e3,b=2E2 ;char c ;
//    c='\123';
//
//
//   for (;c=getchar()!='\n';){}
//    printf("%c",c);
    
//    printf("%c",c);
    
//    printf("\101");
    
//   printf("\x41");
    
//     printf("%d%d",c);
    
//    int i = 1 ,sum= 0;
//
//    while(i<=100){
//
//
//        sum+=i;
//
//         i++;
//
//        /*上面这2个货不能互换，换了会差100，因为多加一个101，少加一个1*/
//    }
//    printf("sum=%d",sum);
    
    
//    int sum=0 ;
//    //for (int i =1 ;i<=100;i++)
//    for (int i=100 ; i>=1;i--)
//    {sum+=i;}
//    printf("sum=%d",sum);
    //    return 0;}
    
//    for (;c=getchar()!='\n';){}
//        printf("%c",c);

    
//   long sum=0;
//    for (int i =10 ;i<=150;i++)
//    {
//        if(i%2!=0)
//        {sum= sum+i*i;}
//
//    }
//    printf("sum=%d",sum );
//
    
//    float sum=0,s=1 ;
//    int j;
//
//
//        for(j=1;j<=10;j++)
//        {
//            s=s*j;
//            sum= sum + 1/s;}
//
//
//    printf("sum=%.5f",sum );
    
//    int i,j,k;
//
//    int a =999;
//    while (a>=100)
//    {
//        i=a%10;
//        k=a/100;
//        j= a/10-10*k;
//
//        if(a==i*i*i+j*j*j+k*k*k){
//            printf ("shuixianis %d",a);
//        }
//        a--;
//
//    }
//    int k=5 ;
//    for(int i=1; i<=k;i++ )
//    {
//
//        for(int l=1;l<6-i;l++)
//        { putchar(' ');
//            //puts(" ");
//        }
//
//        for(int j=1; j<=2*i-1;j++ )
//        {
//
//            printf("%d",j);
//
//        }
//        printf("\n");
//    }
    
    
    
   
    
//    float a = 7  ;float b= 9;
//
//    printf ("%f",max(a,b));
    
    //求阶乘的和 factsum 阶乘的和可能是一个很大的数，所以定义的时候要用long来定义，因为不再是常用的int char void，所以放在后面的时候要在主函数里声明函数
//
//    long fact(int n);
//
//    int k ;
//    printf("你想求谁的阶乘？") ;
//    scanf("%d",&k);
//    printf("%ld\n",fact(k) ) ;
//
    //来玩递归
//    int m ,n ,k ;
//    scanf("%d%d",&m,&n);
//    if (m<n)
//        k=n;n=m;m=k;
//     printf("%d\n",gcd(m,n) ) ;
//
    
    //超绝可爱汉诺塔
//    int n ;
//    printf("几层塔？");
//    scanf("%d",&n);
//    void hanoi(int n ,char a, char b, char c);
//    hanoi(n, 'A', 'B', 'C');
    
    //printf ("%d", sizeof(long));
    void yh(int a[][A],int n);
    void max1(int a[],int b);
    void sort1(int a[],int b);
    int a[5]= {2,3,4,1,2};
  // sort1(a,5);
    
    int b[5][A];
    //yh(b,5);
    
    // 回文数
    
    
    //命令行参数
//    int i=1,n=argc;
//    printf("argc=%d\n",n);
//    printf("\n程序名:%s",*argv);
//    argv++;n--;
//    while (i<=n)
//    {
//        printf("\n参数%d:%s",i,*argv);
//        i++;
//        argv++;
//    }
    
    //指针法降序排列
//    int d[] = {8,5,2,7,7};
//    //printf("%d",sizeof(d)/4);
//    int n =sizeof(d)/4;
//    int i,*p2,temp,*p1=d;
//    for(;p1<d+n-1;p1++)//最终数组存放准备
//        for(p2=p1+1;p2<d+n;p2++)//遍历比较
//            if(*p1<*p2)
//            {temp=*p1;*p1=*p2;*p2=temp;}
//    for(i=0,p1=d;i<n;i++,p1++) printf("%3d" ,*p1);
//    p1--;
//    printf("max= %d, min= %d", *(p1-n+1),*p1);
    
    //频度计数
    
    int i,j,k,sum=0;
    int n=10,a,count= 0;
    for (i=0;i<n;i++)
    
return 0;}


//long fact(int n) //阶乘函数
//{
//    long fact=1;
//    for (int i=1 ;i<=n;i++)
//        fact=fact*i ;
//
//    return fact ;
//}
//
//long factsum(int n)
//
//{
//    long fs=0;
//    long fact(int n);
//    for (int i=1 ;i<=n;i++)
//        fs=fs+ fact(i);
//    return fs ;
//}

long fact(int n)
{
    
    if (n==0)
        return 1 ;
    else
        return(n*fact(n-1));
}

//辗转相除法 爱的魔力转圈圈

//int gcd(int m, int n)
//{
//
//    if(m%n == 0 )
//        return n;
//     else
//        return gcd(n,m%n);
//}

void hanoi(int n , char a ,char b, char c )

{
    if (n==1)
        printf("%c-->%c\n",a,c);
    else
    { hanoi(n-1, a, c, b);
        printf("%c-->%c\n",a,c);
        hanoi(n-1, b, a, c);}
    }

void max1( int a[], int b )
{
    int k=a[0] ;
    for (int i =1 ;i<b;i++)
        {
        k= k>a[i]? k:a[i];
        }
    printf ("%d",k);
}

void sort1 (int a[],int b)
{
    int i,j,k,t;
    //for (j=0;j<b;j++)
    for (t=0;t<b-1;t++)
    {  k=t ;
        for (i=t+1;i<b;i++)
        if (a[k]<a[i])
          k=i;
       // printf("%d",k);
        if (k!=t){ j= a[t];a[t]=a[k];a[k]=j;}
    }
    
    for (int c=0;c<b;c++)
    {printf ("%d",a[c]);}
    
}

void yh(int a[][A], int n ) //杨辉三角
{
    int i,j;
    for (i=0;i<n;i++)
    {
        a[i][0]=1; a[i][i]=1 ;
    }
    
   for (i=2;i<n;i++)
       for(j=1;j<n;j++)
       {a[i][j]=a[i-1][j]+a[i-1][j-1];}
    
    for (i=0; i<n;i++)
    {   for(j=0;j<=i;j++)
            printf("%-6d",a[i][j]);
        printf("\n");}
}
