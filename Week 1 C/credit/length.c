#include <stdio.h>
#include <cs50.h>

// 普通方法
int length(long m);

// 递归方法
int length_re(long m);

int main(void)
{
    long m = get_long("Number:");
    printf("lenth(m)=%i\n", length(m));
    printf("length_re(m)=%i\n", length_re(m));
}

int length(long m)
{
    int sum = 0;
    while (m)
    {
        m /= 10;
        sum++;
    }
    return sum;
}

int length_re(long m)
{
    if (m == 0)
    {
        return 0;
    }
    else
    {
        return length(m / 10) + 1;
    }
}