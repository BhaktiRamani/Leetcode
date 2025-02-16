#include<stdio.h>
#include<string.h>

// Checks if str2 exists inside str1
void my_strstr(const char* str1, const char* str2);

int main()
{
printf("check point 1 \n");
    const char *str1 = "hello world";
    const char* str2 = "hel";
    my_strstr(str1, str2);
}
void my_strstr(const char* str1, const char* str2)
{   
    if (*str2 == '\0') {  // If str2 is an empty string, it exists anywhere in str1.
        printf("It exists\n");
        return;
    }

    const char *start = str1;  // Store the start of str1 to reset it after each check

    // Loop through str1
    while (*str1 != '\0') {
        // If the characters match, start checking the rest of str2
        if (*str1 == *str2) {
            const char* s1 = str1;
            const char* s2 = str2;

            // Check the rest of str2
            while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) 
            {
                s1++;
                s2++;
            }

            // If we reached the end of str2, it means we found a match
            if (*s2 == '\0') {
                printf("It exists\n");
                return;
            }
        }
        str1++;  // Move to the next character in str1
    }

    // If no match was found
    printf("It does not exist\n");
}