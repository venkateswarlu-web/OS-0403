#include <stdio.h>
#include <string.h>
#define D 5
#define F 10

char dir[D][F][20]; int fc[D]={0};

int main(){
    int ch, d; char fname[20];
    while(1){
        printf("\n1.Create 2.Delete 3.Display 4.Exit\nChoice: "); scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Subdir (0-%d): ",D-1); scanf("%d",&d);
                if(d<0||d>=D){printf("Invalid!\n"); break;}
                printf("File name: "); scanf("%s",fname);
                for(int i=0;i<fc[d];i++) if(strcmp(dir[d][i],fname)==0){printf("Exists!\n"); goto skip1;}
                if(fc[d]<F){strcpy(dir[d][fc[d]++],fname); printf("Created.\n");} else printf("Full!\n");
                skip1:; break;
            case 2:
                printf("Subdir (0-%d): ",D-1); scanf("%d",&d);
                if(d<0||d>=D){printf("Invalid!\n"); break;}
                printf("File name: "); scanf("%s",fname);
                for(int i=0;i<fc[d];i++){
                    if(strcmp(dir[d][i],fname)==0){for(int j=i;j<fc[d]-1;j++) strcpy(dir[d][j],dir[d][j+1]); fc[d]--; printf("Deleted.\n"); goto skip2;}
                }
                printf("Not found!\n"); skip2:; break;
            case 3:
                for(int i=0;i<D;i++){printf("Subdir %d:\n",i); if(fc[i]==0) printf(" Empty\n"); else for(int j=0;j<fc[i];j++) printf(" %s\n",dir[i][j]);} break;
            case 4: return 0;
            default: printf("Invalid!\n");
        }
    }
}
