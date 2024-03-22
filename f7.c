#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;

    if ((fp = fopen("text.txt", "w")) != NULL)
    {
        if (fprintf(fp, "This is first line\n") < 0)
        {
            printf("Cant write to file");
            return -2;
        }
    }
    else
    {
        printf("File not opened");
    }

    return 0;
}