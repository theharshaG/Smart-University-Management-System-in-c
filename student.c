#include <stdio.h>
struct Student
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char department[30];
    int sem;
    float cgpa;
};
void addStudent(struct Student *stu ,int *count);
void viewStudent(struct Student *stu ,int count);

int main()
{
    int ch;
    
    struct Student stu[100];
    int count=0;
    do{
    printf("\n1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Save Students\n");
    printf("7. Load Students\n");
    printf("8. Back\n");
    
    printf("enter choice:");
    scanf("%d",&ch);
    
    switch(ch){
        case 1: 
            addStudent(stu,&count);
            break;
            
        case 2:
            viewStudent(stu,count);
            break;
            
        default:
            printf("Invalid input.");
            
    }
    }while(ch!=8);
    

    return 0;
}
void addStudent(struct Student *stu,int *count){
    printf("enter student ID:");
    scanf("%d",&stu[*count].id);
    
    printf("enter student Name:");
    scanf("%s",stu[*count].name);
    
    printf("enter student age:");
    scanf("%d",&stu[*count].age);
    
    printf("enter gender:");
    scanf("%s",stu[*count].gender);
    
    printf("enter department:");
    scanf("%s",stu[*count].department);
    
    printf("enter semister:");
    scanf("%d",&stu[*count].sem);
    
    printf("enter CGPA:");
    scanf("%f",&stu[*count].cgpa);
       
    (*count)++;
    
    printf("\nStudent Added Successfully!\n");
}
void viewStudent(struct Student *stu,int count){
    
    if(count==0){
        printf("No Student\n");
    }
    else{
    printf("\nStudents details");
    printf("\n=========================\n");
    for(int i=0;i<count;i++){
        printf("Student ID         : %d\n", stu[i].id);
        printf("Student Name       : %s\n", stu[i].name);
        printf("Age                : %d\n", stu[i].age);
        printf("Gender             : %s\n", stu[i].gender); 
        printf("Department         : %s\n", stu[i].department);
        printf("Semester           : %d\n", stu[i].sem);
        printf("CGPA               : %.2f\n", stu[i].cgpa);  
        printf("\n==========================\n");
    }
    }
    
}





