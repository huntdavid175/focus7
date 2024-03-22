#include <stdio.h>

int main(void)
{
    FILE *fp = NULL; // File pointer for text file

    FILE *fpb = NULL; // File pointer for binary file

    const unsigned short kBinaryData[] = {26946, 24942, 31090,
                                          25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308};

    if ((fp = fopen("myTextFile.txt", "w")) != NULL)
    {

        for (int i = 0; i < 2; i++)
        {
            if (fprintf(fp, "This is line %d\n", i + 1) < 0)
            {
                printf("Cant write to file");
                return -2;
            }
        }

        if (fclose(fp) != 0)
        {
            printf("Cannot close file");
            return -1;
        }
    }
    else
    {
        printf("File not opened");
        return -1;
    }

    // Binary File open

    if ((fpb = fopen("myEvenDataList.data", "wb")) != NULL)
    {
        int lengthOfArray = sizeof(kBinaryData) / sizeof(kBinaryData[0]);

        for (int i = 0; i < lengthOfArray; i++)
        {
            if (kBinaryData[i] % 2 == 0)
            {
                size_t element_written = fwrite(&kBinaryData[i], sizeof(unsigned short), 1, fpb);
                if (element_written < 1)
                {
                    printf("File not written");
                    return -1;
                }
            }
        }

        if (fclose(fpb) != 0)
        {
            printf("Cannot close file");
            return -1;
        }
    }
    else
    {
        printf("Binary file not opened");
        return -1;
    }

    return 0;
}