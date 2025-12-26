#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    char directory[MAX_PATH];

    // If no argument is given, use current directory
    if (argc == 1) {
        snprintf(directory, MAX_PATH, ".\\*");
    } else if (argc == 2) {
        snprintf(directory, MAX_PATH, "%s\\*", argv[1]);
    } else {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    // Start searching the directory
    hFind = FindFirstFile(directory, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Error: Cannot open directory %s\n", argv[1]);
        return 1;
    }

    printf("Listing of directory: %s\n\n", argc == 1 ? "." : argv[1]);

    do {
        // Skip . and ..
        if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                printf("[DIR]  %s\n", findFileData.cFileName);
            else
                printf("       %s\n", findFileData.cFileName);
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
    return 0;
}

