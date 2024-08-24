#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to count occurrences of a keyword in a given line of text
int count_keyword_in_line(const char *line, const char *keyword) {
    int count = 0;
    const char *pos = line;
    
    // Search for keyword in the line
    while ((pos = strstr(pos, keyword)) != NULL) {
        count++;
        pos += strlen(keyword);  // Move past the last found occurrence
    }
    
    return count;
}

int main() {
    FILE *file;
    char filename[100];
    char keyword[100];
    char line[MAX_LINE_LENGTH];
    //int keyword_length;
    int total_count = 0;

    // Get the filename and keyword from the user
    printf("Enter the filename: ");
    scanf("%99s", filename);
    printf("Enter the keyword: ");
    scanf("%99s", keyword);

    //int keyword_length = strlen(keyword);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        total_count += count_keyword_in_line(line, keyword);
    }

    // Close the file
    fclose(file);

    // Output the result
    printf("The keyword '%s' appears %d times in the file.\n", keyword, total_count);

    return EXIT_SUCCESS;
}
