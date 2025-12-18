#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hMapFile;
    char *shared_memory;

    // Create shared memory
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        256,
        "MySharedMemory"
    );

    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    // Map view
    shared_memory = (char *) MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 256);
    if (shared_memory == NULL) {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    // Write data
    sprintf(shared_memory, "Hello from process 1!");
    printf("Data written: %s\n", shared_memory);

    // Wait for user
    printf("Press Enter to exit...\n");
    getchar();

    // Clean up
    UnmapViewOfFile(shared_memory);
    CloseHandle(hMapFile);
    return 0;
}

