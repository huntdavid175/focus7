/*
 * FILE : m3.cpp
 * PROJECT : SENG1000 - Major #3
 * PROGRAMMER : Fawaz Dogbe (8982570)
 * FIRST VERSION : 2024-03-08
 * DESCRIPTION :
 * This program allows guests book rooms at a hotel and displays their total cost …
 */

#include <stdio.h>

#pragma warning(disable : 4996) // required by Visual Studio

int main(void)
{
    FILE *fp = NULL; // File pointer for text file

    FILE *fpb = NULL; // File pointer for binary file

    const unsigned short kBinaryData[] = {26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308};

    /*Text file open */
    if ((fp = fopen("myTextFile.txt", "w")) != NULL) // Open file and check for error
    {

        for (int i = 0; i < 2; i++) // Loop to write in file
        {
            if (fprintf(fp, "This is line %d\n", i + 1) < 0) // Write file and check for error simultaneously
            {
                printf("Cant write to file"); // If error in writing to file, print error message and exit code
                return -2;
            }
        }

        if (fclose(fp) != 0)
        {
            printf("Cannot close file"); // Print error message and exit if file failed to close
            return -1;
        }
    }
    else
    {
        printf("File not opened"); // Print error message and exit if file failed to open
        return -1;
    }

    /*Binary File open */

    if ((fpb = fopen("myEvenDataList.data", "wb")) != NULL) // Open binary file and check for error
    {
        int lengthOfArray = sizeof(kBinaryData) / sizeof(kBinaryData[0]); // Find the length of the array

        for (int i = 0; i < lengthOfArray; i++) // Loop through array
        {
            if (kBinaryData[i] % 2 == 0) // Check if current array item is an even number
            {
                size_t elements_written = fwrite(&kBinaryData[i], sizeof(unsigned short), 1, fpb);
                if (elements_written < 1) // Check for error in file written
                {
                    printf("File not written"); // If error, print error and exit
                    return -1;
                }
            }
        }

        if (fclose(fpb) != 0) // Close binary file and check for error
        {
            printf("Cannot close file"); // Print error message and exit if error
            return -1;
        }
    }
    else
    {
        printf("Binary file not opened"); // Print error if file not opened and exit
        return -1;
    }

    return 0;
}