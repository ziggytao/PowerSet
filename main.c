//
//  main.c
//  powerset
//
//  Created by ziggytao on 17/4/8.
//
#include <stdio.h>
#define MAX 100
char value[MAX];
static int count = 0;
void show1(char arr[],int mask[],int n);
int isset(int arr[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == 1)
            return 1;
    }
    return 0;
}
void powerset(int arr[],int i,int n)//求i（从0到n － 1）开始的子集合的幂集
{
    if(i == n)//n个元素状态全部设置完毕（0 或 1）
    {
        if(isset(arr, n))//非空集 count加一
            count++;
        show1(value,arr,n);//打印value 前n个元素中状态为1的元素
        //即幂集的一个子集元素如ABCDE ABCD ABCE等 对应arr 11111 11110 11101
    }
    else
    {
        arr[i] = 1;//令首元素状态为1
        powerset(arr, i + 1, n);//求子集的幂集 此时每个幂集都额外包含arr[i]
        arr[i] = 0;//令首元素状态为0 可理解为不存在
        powerset(arr, i + 1, n);//求子集的幂集
    }
}
void show1(char arr[],int mask[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(mask[i] == 1)
            printf("%c",arr[i]);
    }
    printf("\t");
}
int main(int argc, const char * argv[]) {
    int n,mask[MAX],j;
    for(j = 0; j < MAX; j++)
    {
        mask[j] = 0;
        value[j] = 'A' + j;
    }
    printf("Enter a number:");
    scanf("%d",&n);
    while(n >= 0 && n <= 100)
    {
        printf("0\t");
        powerset(mask, 0, n);
        printf("\nTotal:%d\n",count + 1);
        count = 0;
        printf("Enter a number:");
        scanf("%d",&n);
    }
    return 0;
}
