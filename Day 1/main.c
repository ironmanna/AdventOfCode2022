#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* pointer;
    char str[50];
    int x_read;
    int counter = 0;
    int max_sum[3];

    pointer = fopen ("input.txt","r");

    if (pointer == NULL) {
        printf("File can't be opened \n");
    }

    for (int i = 0; i < 3; i++)
    {
        max_sum[i] = -1;
    }
    

    while (fgets(str, sizeof(str), pointer) != NULL)
    {
        x_read = atoi(str);
        if(x_read != 0) {
            counter += x_read;
        }
        else {
            if(counter > max_sum[2]){
                if(counter > max_sum[1]){
                    if(counter > max_sum[0]){
                        max_sum[2] = max_sum[1];
                        max_sum[1] = max_sum[0];
                        max_sum[0] = counter;
                    }
                    else {
                        max_sum[2] = max_sum[1];
                        max_sum[1] = counter;
                    }
                }
                else{
                    max_sum[2] = counter;
                }
            } 
            counter = 0;
        }
    }

    printf("%d\n",max_sum[0]+max_sum[1]+max_sum[2]);
    fclose(pointer);
    return 0;
}