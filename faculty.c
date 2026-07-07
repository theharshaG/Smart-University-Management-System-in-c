#include <stdio.h>
#include "faculty.h"

void facultyMenu()
{
    int ch;
    struct Faculty fac[100];
    int count=0;

    do{
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

            case 8:
                break;
            
    }
    }while(ch!=8);
    
}
void addFaculty(struct Faculty *fac, int *count){
    printf("eEnter Faculty ID:");
    scanf("%d",&fac[*count].id);
    
    printf("enter Faculty Name:");
    scanf("%s",fac[*count].name);

    printf("enter gender:");
    scanf("%s",fac[*count].gender);
    
    printf("enter department:");
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
        return;
    }
    for(int i = 0; i < count; i++)
    {
        printf("\n========= Faculty Details =========\n");
        printf("Faculty ID         : %d\n", fac[i].id);
        printf("Faculty Name       : %s\n", fac[i].name);
        printf("Gender             : %s\n", fac[i].gender);
        printf("Department         : %s\n", fac[i].department);
        printf("designation        : %s\n", fac[i].designation);
        printf("Salary             : %.2f\n",fac[i].salary);
        printf("===================================\n");
    }
}
