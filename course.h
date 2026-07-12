#ifndef COURSE_H
#define COURSE_H

struct Course
{
    int id;
    char name[50];
    int credits;
    int sem;
    int facultyId;
};

void courseMenu();

void addCourse(struct Course *course, int *count);
void viewCourse(struct Course *course, int count);
void searchCourse(struct Course *course,int count);
void deleteCourse(struct Course *course,int *count);
void updateCourse(struct Course *course,int count);
void saveCourse(struct Course *course,int count);
void loadCourse(struct Course *course,int *count);


#endif