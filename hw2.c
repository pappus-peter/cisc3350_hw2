#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if (argc == 1) 
    {
        printf ("No file name was provided. ");
        exit(EXIT_FAILURE); 
    } 
    else 
    {
        // Declare and open a file in write mode 
        FILE * file; 
        file = fopen (argv[1], "r"); 
        if (file == NULL) // If the file didn't open successfully, the pointer will be NULL.
        {
           printf("Error occured while opening this file");
           exit(EXIT_FAILURE);
        }
        else
        {
            char * linesArr = malloc (400 * sizeof(char)); // Allocate a char array on the heap
            int counter = 1;
            // The following loop reads entire lines from the file and prints them out:
            while (fgets (linesArr, 400, file) != NULL)
            {
                printf("Line %d: %s", counter, linesArr);
                counter++;
            }
            printf("\n");

            free(linesArr); // Free the heap memory (remember there is no garbage collection in C!)
            fclose(file); // Close the file to release all the resources and prevent leakage!
        }
    }
    return EXIT_SUCCESS;


}