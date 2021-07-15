//
// Created by zhouhui on 2021/7/14.
//https://cloud.tencent.com/developer/article/1631792
//
#include "stdio.h"

//size 16
struct DefaultAlign4
{
    int a;
    char b;
//c的地址应被sizeof(c):4整除，所以b后填充3bytes，使c的地址为8.
    int c;
//    d后应填充2bytes，使struct能被最大的成员int:4整除。
    short d;
};

//__attribute__((aligned(n)))，按照n字节对齐，但是当struct中有成员size大于n时，按照最大成员size对齐。
//所以，虽然是aligned(1),但是按照int对齐。
//size 16
struct Align1
{
    int a;
    char b;
    int c;
    short d;
}__attribute__((aligned (1)));

//pragma pack(n)，按照n字节对齐。
//size 11
#pragma pack(1)
struct AlignPragma1
{
    int a;
    char b;
    int c;
    short d;
};
#pragma pack()

//size 16
struct DefaultAlign42
{
    int a;
    char b;
//c的地址应被sizeof(c):4整除，所以b后填充3bytes，使c的地址为8.
    int c;
//    d后应填充2bytes，使struct能被最大的成员int:4整除。
    short d;
};

//成员顺序调整后，bytes16变成14。
//size 12
struct DefaultAlign4B
{
    int a;
    char b;
    short d;
    int c;
};

//取消对齐优化。
//size 11
struct AlignPacked
{
    int a;
    char b;
    int c;
    short d;
}__attribute__((packed));

//默认4bytes对齐，b地址可以被本身长度整除，a后不用补齐。长度为2，可以整除最大成员长度，b后不用补齐。
//size: 2
struct Test
{
    char a;
    char b;
};

int main()
{
    struct DefaultAlign4 defaultAlign4;
    struct DefaultAlign4B defaultAlign4b;
    struct Align1 align1;
    struct AlignPragma1 alignPragma1;
    struct DefaultAlign42 defaultAlign42;
    struct AlignPacked alignPacked;
    struct Test test;
    printf("the size of struct DefaultAlign4 is %zu\n", sizeof(defaultAlign4));
    printf("the size of struct DefaultAlign4B is %zu\n", sizeof(defaultAlign4b));
    printf("the size of struct Align1 is %zu\n", sizeof(align1));
    printf("the size of struct AlignPragma1 is %zu\n", sizeof(alignPragma1));
    printf("the size of struct DefaultAlign42 is %zu\n", sizeof(defaultAlign42));
    printf("the size of struct AlignPacked is %zu\n", sizeof(alignPacked));
    printf("the size of struct Test is %zu\n", sizeof(test));
    return 0;
}
