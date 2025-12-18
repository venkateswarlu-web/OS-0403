#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    // Open source file for reading
    src_file = fopen("source.txt", "rb");
    if (src_file == NULL) {
        perror("Failed to open source file");
        exit(1);
    }

    // Open destination file for writing (create or truncate)
    dest_file = fopen("destination.txt", "wb");
    if (dest_file == NULL) {
        perror("Failed to open destination file");
        fclose(src_file);
        exit(1);
    }

    // Copy loop
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
        if (bytes_written != bytes_read) {
            perror("Write error");
            fclose(src_file);
            fclose(dest_file);
            exit(1);
        }
    }

    if (ferror(src_file)) {
        perror("Read error");
    }

    // Close files
    fclose(src_file);
    fclose(dest_file);

    printf("File copied successfully.\n");

    return 0;
}
