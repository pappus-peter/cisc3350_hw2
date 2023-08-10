#include <stdio.h>                    // ‘#include’ statements of necessary libraries,
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    if (argc == 1)                    // Check how many command-line arguments are provided
    {
        printf ("No file name was provided. ");
        exit(EXIT_FAILURE); 
    } 
    else 
    {
        int i=1;                        // integer i in the for-loop
        int isDisplayNum = 0;           // boolean that is used in flag "-n"
        int counter = 1;                // counter of line that is used in flag "-n"
        if (strcmp(argv[1], "-n") == 0) // if the 2nd argument is a flag "-n"
        {
            isDisplayNum = 1;           // number of line will be printed 
            i+=1;                       // i is increased, so the flag "-n" will not be read
        }                               // originally planned to use switch-case for different flags, but I was unable to use string "-n" in switch   
                                        // more flags can be added by using else if 

        for (i=i; i < argc; i++)
        {
            FILE * file; 
            file = fopen (argv[i], "r"); // file is opened in read mode
            if (file == NULL)
            {
                printf("Error occured while opening this file");
                exit(EXIT_FAILURE);
            }
            else
            {
                char * linesArr = malloc (400 * sizeof(char));  // Allocate a char array on the heap
                while (fgets (linesArr, 400, file) != NULL)     // fgets() / reading line by line 
                {
                    if(isDisplayNum == 1)
                    {
                        printf("Line %d: ", counter);           // line counter that is added before everyline 
                        counter++;
                    }
                    printf("%s", linesArr);
                }

                free(linesArr);                                 // Free the heap memory
                fclose(file);                                   // closing file
            }
        }
        
    }
    return EXIT_SUCCESS;

}