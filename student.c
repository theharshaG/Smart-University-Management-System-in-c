#include <stdio.h>
#include "student.h"

void studentMenu()
{
    struct Student stu[100];
    int count = 0;
    int ch;

    do
    {
        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Save Students\n");
        printf("7. Load Students\n");
        printf("8. Back\n");

        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                addStudent(stu, &count);
                break;

            case 2:
                viewStudent(stu, count);
                break;

            case 3:
                searchStudent(stu, count);
                break;

            case 4:
                updateStudent(stu, count);
                break;

            case 5:
                deleteStudent(stu, &count);
                break;

            case 6:
                saveStudents(stu, count);
                break;

            case 7:
                loadStudents(stu, &count);
                break;

            case 8:
                printf("Thank you.");
                break;

            default:
                printf("Invalid input");
                break;
        }

    } while(ch != 8);
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
    printf("\n==========Student Details=========\n");
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
void searchStudent(struct Student *stu, int count)
{
    int key;
    int found = 0;

    if(count == 0)
    {
        printf("No Students Available!\n");
        return;
    }

    printf("Enter ID to search: ");
    scanf("%d", &key);

    for(int i = 0; i < count; i++)
    {
        if(key == stu[i].id)
        {
            found = 1;

            printf("\n========= Student Details =========\n");
            printf("Student ID         : %d\n", stu[i].id);
            printf("Student Name       : %s\n", stu[i].name);
            printf("Age                : %d\n", stu[i].age);
            printf("Gender             : %s\n", stu[i].gender);
            printf("Department         : %s\n", stu[i].department);
            printf("Semester           : %d\n", stu[i].sem);
            printf("CGPA               : %.2f\n", stu[i].cgpa);
            printf("===================================\n");

            break;  
        }
    }

    if(!found)
    {
        printf("Student not found.\n");
    }
}
void updateStudent(struct Student *stu, int count)
{
    int key;
    int found = 0;

    if(count == 0)
    {
        printf("No Students Available!\n");
        return;
    }

    printf("Enter Student ID to Update: ");
    scanf("%d", &key);

    for(int i = 0; i < count; i++)
    {
        if(key == stu[i].id)
        {
            found = 1;

            printf("Enter New Name: ");
            scanf("%s", stu[i].name);

            printf("Enter New Age: ");
            scanf("%d", &stu[i].age);

            printf("Enter Gender: ");
            scanf("%s", stu[i].gender);

            printf("Enter New Department: ");
            scanf("%s", stu[i].department);

            printf("Enter New Semester: ");
            scanf("%d", &stu[i].sem);

            printf("Enter New CGPA: ");
            scanf("%f", &stu[i].cgpa);

            printf("\nStudent Updated Successfully!\n");
            break;
        }
    }

    if(!found)
    {
        printf("Student Not Found!\n");
    }
}
void deleteStudent(struct Student *stu, int *count)
{
    int key;
    int found = 0;

    if(*count == 0)
    {
        printf("No Students Available!\n");
        return;
    }

    printf("Enter Student ID to Delete: ");
    scanf("%d", &key);

    for(int i = 0; i < *count; i++)
    {
        if(key == stu[i].id)
        {
            found = 1;

            for(int j = i; j < *count - 1; j++)
            {
                stu[j] = stu[j + 1];
            }

            (*count)--;  

            printf("Student Deleted Successfully!\n");
            break;
        }
    }

    if(!found)
    {
        printf("Student Not Found!\n");
    }
}
void saveStudents(struct Student *stu, int count)
{
    FILE *fp = fopen("students.txt", "w");

    if(fp == NULL)
    {
        printf("Cannot open file!\n");
        return;
    }

    fprintf(fp, "%d\n", count);   // Save number of students

    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "%d %s %d %s %s %d %.2f\n",
                stu[i].id,
                stu[i].name,
                stu[i].age,
                stu[i].gender,
                stu[i].department,
                stu[i].sem,
                stu[i].cgpa);
    }

    fclose(fp);

    printf("Students saved successfully!\n");
}
void loadStudents(struct Student *stu, int *count)
{
    FILE *fp = fopen("students.txt", "r");

    if(fp == NULL)
    {
        printf("No saved file found!\n");
        return;
    }

    fscanf(fp, "%d", count);

    for(int i = 0; i < *count; i++)
    {
        fscanf(fp, "%d %49s %d %9s %29s %d %f",
               &stu[i].id,
               stu[i].name,
               &stu[i].age,
               stu[i].gender,
               stu[i].department,
               &stu[i].sem,
               &stu[i].cgpa);
    }

    fclose(fp);

    printf("Students loaded successfully!\n");
}
