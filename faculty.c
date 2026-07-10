#include <stdio.h>
#include "faculty.h"

void facultyMenu()
{
    int ch;
    struct Faculty fac[100];
    int count=0;

    do{
        printf("\n=====FACULTY MANAGEMENT=====\n");
        printf("\n1. Add Faculty\n");
        printf("2. View Faculty\n");
        printf("3. Search Facuty\n");
        printf("4. Update Faculty\n");
        printf("5. Delete Faculty\n");
        printf("6. Save Faculty\n");
        printf("7. Load Faculty\n");
        printf("8. Back\n");
    
        printf("enter choice:");
        scanf("%d",&ch);
    
        switch(ch){
            case 1: 
                addFaculty(fac,&count);
                break;
            
            case 2:
                viewFaculty(fac,count);
                break;

            case 3:
                searchFaculty(fac,count);
                break;

            case 4:
                updateFaculty(fac,count);
                break; 
                
            case 5:
                deleteFaculty(fac,&count);
                break;

            case 6:
                saveFaculty(fac,count);
                break;

            case 7:
                loadFaculty(fac,&count);
                break;

            case 8:
                printf("Returning to Main Menu...\n"); 
                break;

            default:
                printf("Invalid input");
                break;
            
    }
    }while(ch != 8);
    
}
void addFaculty(struct Faculty *fac, int *count){
    printf("Enter Faculty ID:");
    scanf("%d",&fac[*count].id);
    
    printf("Enter Faculty Name:");
    scanf("%s",fac[*count].name);

    printf("Enter gender:");
    scanf("%s",fac[*count].gender);
    
    printf("Enter department:");
    scanf("%s",fac[*count].department);
    
    printf("Enter Designation:");
    scanf("%s",fac[*count].designation);
    
    printf("Enter Salary :");
    scanf("%f",&fac[*count].salary);
       
    (*count)++;
    
    printf("\nFaculty Added Successfully!\n");
}

void viewFaculty(struct Faculty *fac, int count)
{
    if(count==0){
        printf("No faculty added");
    }
    else{
        printf("\n========= Faculty Details =========\n");
        for(int i = 0; i < count; i++)
        {
            printf("Faculty ID         : %d\n", fac[i].id);
            printf("Faculty Name       : %s\n", fac[i].name);
            printf("Gender             : %s\n", fac[i].gender);
            printf("Department         : %s\n", fac[i].department);
            printf("designation        : %s\n", fac[i].designation);
            printf("Salary             : %.2f\n",fac[i].salary);
            printf("===================================\n");

            break;
        }
}
}
void searchFaculty(struct Faculty *fac ,int count)
{
    int key;
    int found = 0;

    if(count==0){
        printf("No faculty");
        return;
    }
    printf("Enter Id to search:");
    scanf("%d",&key);
    for(int i=0;i<count;i++){
        if(key==fac[i].id){
            found=1;
            printf("\n==========Faculty Details============\n");
            printf("Faculty ID         : %d\n", fac[i].id);
            printf("Faculty Name       : %s\n", fac[i].name);
            printf("Gender             : %s\n", fac[i].gender);
            printf("Department         : %s\n", fac[i].department);
            printf("designation        : %s\n", fac[i].designation);
            printf("Salary             : %.2f\n",fac[i].salary);
            printf("===================================\n");

            break;
        }
    }
    if(found==0){
        printf("Faculty not found");
        return;
    }
}
void updateFaculty(struct Faculty *fac ,int count)
{
    if(count==0)
    {
        printf("No faculty");
        return;
    }
    int found=0;
    int key;
    printf("Enter Id to update:");
    scanf("%d",&key);

    for(int i=0;i<count;i++)
    {
    if(key==fac[i].id)
    {
        found=1;

        printf("Enter new name:");
        scanf("%s",fac[i].name);

        printf("Enter gender:");
        scanf("%s",fac[i].gender);

        printf("Enter Department:");
        scanf("%s",fac[i].department);

        printf("Enter Designation:");
        scanf("%s",fac[i].designation);

        printf("Enter salary:");
        scanf("%f",&fac[i].salary);

        printf("Updated Successfully\n");
        break;
    }
}

if(found==0)
    printf("Faculty not found\n");
}
void deleteFaculty(struct Faculty *fac ,int *count)
{
    if(*count==0){
        printf("No faculty");
        return;
    }
    int key;
    int found=0;
    printf("Enter Id to delete:");
    scanf("%d",&key);

    for(int i=0;i< *count;i++){
        if(key==fac[i].id){
            found=1;
            for(int j=i;j<*count-1;j++)
            {
                fac[j]=fac[j+1];
            }
            (*count)--;
            printf("Faculty deleted successfully\n");
            break;
        }
    }
    if(!found)
        printf("Faculty not found");
}
void saveFaculty(struct Faculty *fac ,int count)
{

    FILE *fp=fopen("faculty.txt","w");

    if(fp==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    fprintf(fp,"%d\n",count);
    for(int i=0;i<count;i++){
        fprintf(fp,"%d %s %s %s %s %.2f\n",
        fac[i].id,
        fac[i].name,
        fac[i].gender,
        fac[i].department,
        fac[i].designation,
        fac[i].salary);
    }
    fclose(fp);
    printf("Faculty Save successfully\n");
}
void loadFaculty(struct Faculty *fac, int *count)
{
    FILE *fp = fopen("faculty.txt", "r");

    if(fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    fscanf(fp, "%d", count);

    for(int i = 0; i < *count; i++)
    {
        fscanf(fp, "%d %49s %9s %29s %29s %f",
               &fac[i].id,
               fac[i].name,
               fac[i].gender,
               fac[i].department,
               fac[i].designation,
               &fac[i].salary);
    }

    fclose(fp);

    printf("Faculty loaded successfully\n");
}