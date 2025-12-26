#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) { perror("open"); return 1; }

    write(fd, "UNIX I/O Demo", 13);

    // fcntl demo
    int flags = fcntl(fd,F_GETFL);
    if (flags == -1) perror("fcntl");
    else printf("Flags: %d\n", flags);

    // lseek demo
    lseek(fd, 0, SEEK_SET);

    // stat demo
    struct stat s;
    if (stat("sample.txt", &s) == 0)
        printf("File Size: %ld bytes\n", s.st_size);
    else perror("stat");

    // opendir & readdir demo
    DIR *d = opendir(".");
    struct dirent *de;
    printf("Files in Directory:\n");
    while ((de = readdir(d)) != NULL)
        printf(" %s\n", de->d_name);
    closedir(d);

    close(fd);
    return 0;
}

