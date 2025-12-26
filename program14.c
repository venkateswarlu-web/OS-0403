#include <stdio.h>
#include <string.h>
#define MAX 20
char dir[MAX][20]; int count=0;

int main() {
    int ch; char fname[20];
    while(1){
        printf("\n1.Create 2.Delete 3.Display 4.Exit\nChoice: "); 
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter file name: "); scanf("%s",fname);
                for(int i=0;i<count;i++) if(strcmp(dir[i],fname)==0){printf("File exists!\n"); goto skip1;}
                if(count<MAX){strcpy(dir[count++],fname); printf("File created.\n");} else printf("Directory full!\n");
                skip1:; break;
            case 2:
                printf("Enter file name: "); scanf("%s",fname);
                for(int i=0;i<count;i++) if(strcmp(dir[i],fname)==0){for(int j=i;j<count-1;j++) strcpy(dir[j],dir[j+1]); count--; printf("File deleted.\n"); goto skip2;}
                printf("File not found!\n"); skip2:; break;
            case 3:
                if(count==0) printf("Directory empty.\n"); else {printf("Files:\n"); for(int i=0;i<count;i++) printf("%s\n",dir[i]);} break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
