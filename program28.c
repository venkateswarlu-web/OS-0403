#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50], pattern[50], line[200];
    int line_no = 1, found = 0;

    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    printf("\nLines containing '%s':\n", pattern);
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, pattern)) {   // strstr() checks if pattern exists in the line
            printf("Line %d: %s", line_no, line);
            found = 1;
        }
        line_no++;
    }

    if (!found)
        printf("Pattern not found in the file.\n");

    fclose(fp);
    return 0;
}
