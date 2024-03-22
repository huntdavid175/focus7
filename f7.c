#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;

    FILE *fpb = NULL;

    const unsigned short kBinaryData[] = {26946, 24942, 31090,
                                          25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308};

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
        printf("Cannot close file");
    }

    // Binary File open

    if ((fpb = fopen("binarylist.data", "wb")) != NULL)
    {
        int lengthOfArray = sizeof(kBinaryData) / sizeof(kBinaryData[0]);

        for (int i = 0; i < lengthOfArray; i++)
        {
            if (kBinaryData[i] % 2 == 0)
            {
                fwrite(&kBinaryData[i], sizeof(unsigned short), 1, fpb);
            }
        }

        fclose(fpb);
    }
    else
    {
        printf("Binary file not opened");
    }

    return 0;
}