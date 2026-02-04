#include <stdio.h>
typedef struct{
    int sapId;
    char name[100];
    int batch;
} Student;
int main(){
    Student students[3];
    for(int i=0;i<3;i++){
        printf("Student %d\n",i+1);
        printf("Enter name: ");
        fgets(students[i].name,sizeof(students[i].name),stdin);
        printf("Enter SAP: ");
        scanf("%d",&students[i].sapId);
        printf("Enter Batch: ");
        scanf("%d",&students[i].batch);
        getchar();
    }
    

    printf("\n Student Details\n");
    for(int i=0;i<3;i++){
        printf("Student %d\n",i+1);
        printf("Name: %s\n",students[i].name);
        printf("SAP id:%d\n",students[i].sapId);
        printf("Batch:%d\n",students[i].batch );   
    }
    return 0;
}