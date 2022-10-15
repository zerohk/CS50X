#include <stdio.h>
#include <cs50.h>

// 获取卡号长度
int get_len(long card_no);
// 判断卡号是否有效
int is_valid(long card_no);

int main(void)
{
    long card_no = get_long("Number: ");
    // 不是long类型则继续输入
    while (!card_no)
    {
        card_no = get_long("Number: ");
    }

    int status = is_valid(card_no);
    switch(status)
    {
        case 0: printf("INVALID\n");
                break;
        case 1:
                break;
    }
}

// 获取卡号长度
int get_len(long card_no)
{
    long num = 1000000000000000;
    int bits = 16;
    for (int i = 16; i > 0; i--)
    {
        if (card_no / num != 0)
        {
            break;
        }
        else
        {
            bits--;
            num /= 10;
        }
    }
    return bits;
}


// 判断卡号是否有效,为0时无效，1有效
int is_valid(long card_num)
{
    int status = 1;
    // 卡号长度小于13大于16的，一律判定为无效
    int len = get_len(card_num);
    if(len > 16 || len < 13)
    {
        return 0;
    }
    status = luhn(card_num,len);
    return status;
}

// luhn算法
int luhn(long card_num,int len)
{
    int checksum = 0;
    long num = 1000000000000000;
    int digit 
    for(i = 16;i > 0;i--)
    {
        if(i % 2 == 0)
        {

        }
    }
}