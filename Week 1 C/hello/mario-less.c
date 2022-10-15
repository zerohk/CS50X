#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Accept the pyramid’s height
    int height = get_int("Height: ");
    // Judge the height
    while (height < 1 || height > 8)
    {
        height = get_int("Height:");
    }
    int i,j;
    for (i = 0; i < height; i++)
    {
        for(j = 0;j < (height - i - 1);j++)
        {
            printf(" ");
        }
        for(;j < height;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}