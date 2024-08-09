#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void toLowerCase(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char string1[100], string2[100];
    
    printf("Enter the first string: ");
    scanf("%s", string1);
    
    printf("Enter the second string: ");
    scanf("%s", string2);
    
    // Convert both strings to lowercase
    toLowerCase(string1);
    toLowerCase(string2);
    
    // Compare the strings case-insensitively
    if (strcmp(string1, string2) == 0) {
        printf("Same\n");
    } else {
        printf("Not same\n");
    }    
    return 0;
}