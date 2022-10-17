#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int letter;
    int start = 65;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // 将字符串里的字母统一转为大写字母对应的ASCII码值，如果不是字母则会直接转换成ASCII值
        letter = toupper(word[i]);
        // 判断是否是字母,是，则找出对应的分值；不是，则分值直接为零；计入总分
        if (letter >= 65 && letter <= 90)
        {
            score += POINTS[letter - 65];
        }
    }
    return score;
}
