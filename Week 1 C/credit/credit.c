#include <stdio.h>
#include <cs50.h>

// 获取卡号长度
int get_len(long card_no);

// luhn算法
void luhn(long card_num);

int main(void)
{
    long card_no = get_long("Number: ");
    // 不是long类型则继续输入
    while (!card_no)
    {
        card_no = get_long("Number: ");
    }
    // 卡号长度不为13,15,16，则表示无效
    int len = get_len(card_no);
    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        luhn(card_no);
    }
}

// 获取卡号长度
int get_len(long card_no)
{
    int bits = 0;
    while (card_no)
    {
        card_no /= 10;
        bits++;
    }
    return bits;
}

// luhn算法
void luhn(long card_no)
{
    // 获取卡号长度
    int len = get_len(card_no);
    // luhn算法
    int sum_digits = 0;
    // 用一个数组存储每一位数字
    int num_digit[len];
    for (int i = 1; i <= len; i++)
    {
        // 从最低位开始
        int digit = (int)(card_no % 10);
        num_digit[i - 1] = digit;
        card_no /= 10;
        // 奇数位直接相加，偶数位乘2后，如果小于10直接相加，大于10则拆分后相加
        if (i % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                sum_digits += digit / 10 + digit % 10;
            }
            else
            {
                sum_digits += digit;
            }
        }
        else
        {
            sum_digits += digit;
        }
    }
    // 判断是否是10的倍数
    if (sum_digits % 10)
    {
        // 不是，则卡号无效
        printf("INVALID\n");
    }
    else
    {
        // 是，再根据位数和前两位来判断卡归属
        int first_two = num_digit[len - 1] * 10 + num_digit[len - 2];
        if ((len == 15 && first_two == 34) || (len == 15 && first_two == 37))
        {
            printf("AMEX\n");
        }
        else if (len == 13 && num_digit[len - 1] == 4)
        {
            printf("VISA\n");
        }
        else if (len == 16 && num_digit[len - 1] == 4)
        {
            printf("VISA\n");
        }
        else if (len == 16 && first_two >= 51 && first_two <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
