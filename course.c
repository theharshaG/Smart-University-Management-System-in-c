#include <stdio.h>
#include <stdlib.h>
#include "course.h"

void courseMenu()
{
    struct Course course[100];
    int count = 0;
    int ch;

    do
    {
        printf("\n===== COURSE MANAGEMENT =====\n");
        printf("1. Add Course\n");
        printf("2. View Course\n");
        printf("3. Search Course\n");
        printf("4. Update Course\n");
        printf("5. Delete Course\n");
        printf("6. Save Course\n");
        printf("7. Load Course\n");
        printf("8. Back\n");

        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                addCourse(course, &count);
                break;

            case 2:
                viewCourse(course, count);
                break;

            case 3:
                // searchCourse(course, count);
                break;

            case 4:
                // updateCourse(course, count);
                break;

            case 5:
                // deleteCourse(&course, &count);
                break;

            case 6:
                // saveCourse(course, count);
                break;

            case 7:
                // loadCourse(&course, &count);
                break;

            case 8:
                printf("Returning...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(ch != 8);

}

void addCourse(struct Course *course, int *count)
{

    printf("Enter Course ID: ");
    scanf("%d", &course[*count].id);

    printf("Enter Course Name: ");
    scanf("%s", course[*count].name);

    printf("Enter Credits: ");
    scanf("%d", &course[*count].credits);

    printf("Enter Semester: ");
    scanf("%d", &course[*count].sem);

    printf("Enter Faculty ID: ");
    scanf("%d", &course[*count].facultyId);

    (*count)++;

    printf("Course Added Successfully.\n");
}

void viewCourse(struct Course *course, int count)
{
    if(count == 0)
    {
        printf("No Course Added.\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        printf("\n====== UNIVERSITY COURSE ======\n");
        printf("Course ID        : %d\n", course[i].id);
        printf("Course Name      : %s\n", course[i].name);
        printf("Credits          : %d\n", course[i].credits);
        printf("Semester         : %d\n", course[i].sem);
        printf("Faculty ID       : %d\n", course[i].facultyId);
        printf("==================================\n");
    }
}