#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 加密算法
string cipher(string plaintext, string key);
// 获取字母位置
int get_index(char ch);
// 检测重复字母
int detect_duplicate(string key);

int main(int argc, string argv[])
{
    // 参数必须为两个
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    // 输入的key必须为26位
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // key内不能出现非字母字符
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
        }
    }

    // key内不能出现重复字母
    if (detect_duplicate(key) > 1)
    {
        return 1;
    }

    // 获取明文
    string plaintext = get_string("plaintext:  ");
    // 加密
    string ciphertext = cipher(plaintext, argv[1]);
    printf("ciphertext: %s\n", ciphertext);
}

// 加密算法
string cipher(string plaintext, string key)
{
    // 加密字符串返回
    string ciphertext = plaintext;
    // 标记大小写
    int flag;
    char ch;
    int index;
    // 遍历明文字符串
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        flag = (int)isupper(plaintext[i]);
        ch = plaintext[i];
        // 如果是字母，则加密
        if (isalpha(ch))
        {
            ch = key[get_index(ch)];
            // 再根据大小写转换一下
            if (flag)
            {
                // 直接更改原字符串
                ciphertext[i] = toupper(ch);
            }
            else
            {
                ciphertext[i] = tolower(ch);
            }
        }
        else
        {
            ciphertext[i] = ch;
        }
    }
    return ciphertext;
}

// 获取字母在字母表中的位置
int get_index(char ch)
{
    int index;
    // 非字母返回0
    if (isalpha(ch))
    {
        // 统一转为大写,减去65，就是位置
        return index = toupper(ch) - 65;
    }
    else
    {
        return 0;
    }
}

// 检测key是否重复，重复返回非0，不重复返回0
int detect_duplicate(string key)
{
    int count;
    // 遍历字母表，遍历给定字符串（统一转为大写）来进行对比
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        count = 0;
        for (int i = 0, len = strlen(key); i < len; i++)
        {
            if (ch == toupper(key[i]))
            {
                count++;
                if (count > 1)
                {
                    return count;
                }
            }
        }
    }
    return count;
}