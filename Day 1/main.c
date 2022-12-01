#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* pointer;
    char str[50];
    int x_read;
    int counter = 0;
    int max_sum = -1;

    pointer = fopen ("input.txt","r");

    if (pointer == NULL) {
        printf("File can't be opened \n");
    }

    while (fgets(str, sizeof(str), pointer) != NULL)
    {
        x_read = atoi(str);
        if(x_read != 0) {
            counter += x_read;
        }
        else {
            if(counter > max_sum) max_sum = counter;
            counter = 0;
        }
    }

    printf("%d",max_sum);
    fclose(pointer);
    return 0;
}