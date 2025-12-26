#include <stdio.h>
#include <string.h>

struct File {
    char name[50];
    int owner_perm;  // Owner permissions (0–7)
    int group_perm;  // Group permissions (0–7)
    int other_perm;  // Others permissions (0–7)
};

void show_permissions(int perm) {
    printf("%c", (perm & 4) ? 'r' : '-');
    printf("%c", (perm & 2) ? 'w' : '-');
    printf("%c", (perm & 1) ? 'x' : '-');
}

int main() {
    struct File file;
    char user_type[10];
    int action;

    strcpy(file.name, "demo.txt");
    file.owner_perm = 7;  // rwx
    file.group_perm = 5;  // r-x
    file.other_perm = 4;  // r--

    printf("File Name: %s\n", file.name);
    printf("Permissions:\n");
    printf("Owner : "); show_permissions(file.owner_perm); printf("\n");
    printf("Group : "); show_permissions(file.group_perm); printf("\n");
    printf("Others: "); show_permissions(file.other_perm); printf("\n\n");

    printf("Enter user type (owner/group/other): ");
    scanf("%s", user_type);

    printf("Choose action: 1-Read, 2-Write, 3-Execute: ");
    scanf("%d", &action);

    int perm = 0;
    if (strcmp(user_type, "owner") == 0)
        perm = file.owner_perm;
    else if (strcmp(user_type, "group") == 0)
        perm = file.group_perm;
    else
        perm = file.other_perm;

    int allowed = 0;
    if (action == 1 && (perm & 4)) allowed = 1;
    else if (action == 2 && (perm & 2)) allowed = 1;
    else if (action == 3 && (perm & 1)) allowed = 1;

    if (allowed)
        printf("\n✅ Access granted: You can perform this operation.\n");
    else
        printf("\n❌ Access denied: Permission not allowed.\n");

    return 0;
}
