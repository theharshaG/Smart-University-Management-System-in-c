#ifndef STUDENT_H
#define STUDENT_H

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

void studentMenu();

void addStudent(struct Student *stu, int *count);
void viewStudent(struct Student *stu, int count);
void searchStudent(struct Student *stu, int count);
void updateStudent(struct Student *stu, int count);
void deleteStudent(struct Student *stu, int *count);
void saveStudents(struct Student *stu, int count);
void loadStudents(struct Student *stu, int *count);

#endif