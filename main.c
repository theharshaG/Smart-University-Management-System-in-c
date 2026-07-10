#include <stdio.h>
#include "student.h"
#include "faculty.h"
#include "course.h"

int main()
{
    int choice;

    do
    {
        printf("\n===== SMART UNIVERSITY =====\n");
        printf("1. Student Management\n");
        printf("2. Faculty Management\n");
        printf("3. Course Management\n");
        printf("4. Library Management\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                studentMenu();
                break;

            case 2:
                facultyMenu();
                break;

            case 3:
                courseMenu();
                break;

            case 4:
                //libraryMenu();
                break;

            case 5:
                printf("Thank you");
                break;

            
            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}