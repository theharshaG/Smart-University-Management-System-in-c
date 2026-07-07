#ifndef FACULTY_H
#define FACULTY_H

struct Faculty
{
    int id;
    char name[50];
    char gender[10];
    char department[30];
    char designation[30];
    float salary;
};

void facultyMenu();

void addFaculty(struct Faculty *fac, int *count);
void viewFaculty(struct Faculty *fac, int count);

#endif