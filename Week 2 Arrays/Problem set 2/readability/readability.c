#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// 統計字母個數
int count_letters(string text);
// 统计单词个数
int count_words(string text);
// 统计句子个数
int count_sentences(string text);

int main(void)
{
    string input = get_string("Text:");
    int letters = count_letters(input);
    // printf("%i letters\n", letters);
    int words = count_words(input);
    // printf("%i words\n", words);
    int sentences = count_sentences(input);
    // printf("%i sentences\n", sentences);
    // L代表每一百个单词中字母的个数
    double L = (double)letters / (double)words * 100;
    // printf("%f\n", L);
    // S代表每一百个单词中句子的个数
    double S = (double)sentences / (double)words * 100;
    // printf("%f\n", S);
    // 求出Coleman-Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("%f\n", index);
    // 利用round()（需要math.h）将得到的index转为int类型
    int grade = (int)round(index);
    // 还需对grade进行判断，小于1则打印Before Grade 1；大于等于16则打印Grade 16+；
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// 统计字母个数
int count_letters(string text)
{
    int amount = 0;
    // 遍历字符串数组，如果是大小写字母，则字母数量加一
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            amount++;
        }
    }
    return amount;
}

// 统计单词个数
int count_words(string text)
{
    int amount = 0;
    // 遍历字符串数组，如果碰到空格，则单词数量加一
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
            amount++;
    }
    // 由于不会是空格结尾，所以最后单词数量还需加一
    amount++;
    return amount;
}

// 统计句子个数
int count_sentences(string text)
{
    int amount = 0;
    // 遍历字符串数组，如果碰到".","!","?"，则句子数量加一（不考虑诸如"Mr."等之类中间的"."）
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            amount++;
    }
    return amount;
}