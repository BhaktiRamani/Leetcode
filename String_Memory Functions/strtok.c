#include <stdio.h>
#include <string.h>

int main()
{
    // normal strtok
    char str[100] = "Bhakti_Ramani";
    char *token = strtok(str, "_");
    printf("token = %s\n", token);
    token = strtok(str, "_");


    while(token != NULL)
    {
        printf(" %s\n", token);
        token = strtok(NULL, "_");
    }

}