#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;

    FILE *fpb = NULL;

    if ((fp = fopen("text.txt", "w")) != NULL)
    {

        for (int i = 0; i < 2; i++)
        {
            if (fprintf(fp, "This is line %d\n", i + 1) < 0)
            {
                printf("Cant write to file");
                return -2;
            }
        }
    }
    else
    {
        printf("File not opened");
    }

    if (fclose(fp) != 0)
    {
        print("Cannot close file");
    }

    return 0;
}