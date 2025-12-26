#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd; char buf[50];
    fd = open("demo.txt", O_CREAT|O_WRONLY, 0644);
    write(fd, "Hello UNIX!", 11);
    close(fd);

    fd = open("demo.txt", O_RDONLY);
    read(fd, buf, 11);
    buf[11]='\0';
    printf("File Content: %s\n", buf);
    close(fd);
    return 0;
}
