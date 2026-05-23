#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int id;
    char name[50];
    float marks;
} Student;

void inputStudents(Student s[], int n);
void writeToFile(Student s[], int n, long pos[]);
void displayPositions(long pos[], int n);
void displayRecord(long position);

int main()
{
    Student s[MAX];
    long pos[MAX];
    int n, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputStudents(s, n);

    writeToFile(s, n, pos);

    displayPositions(pos, n);

    printf("\nEnter record number to display: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= n)
    {
        displayRecord(pos[choice - 1]);
    }
    else
    {
        printf("Invalid record number\n");
    }

    return 0;
}

void inputStudents(Student s[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void writeToFile(Student s[], int n, long pos[])
{
    FILE *fp;
    int i;

    fp = fopen("students.dat", "wb");

    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }

    for(i = 0; i < n; i++)
    {
        pos[i] = ftell(fp);

        fwrite(&s[i], sizeof(Student), 1, fp);
    }

    fclose(fp);
}

void displayPositions(long pos[], int n)
{
    int i;

    printf("\nSeek Positions:\n");

    for(i = 0; i < n; i++)
    {
        printf("Record %d -> Position %ld\n", i + 1, pos[i]);
    }
}

void displayRecord(long position)
{
    FILE *fp;
    Student s;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }

    fseek(fp, position, SEEK_SET);

    fread(&s, sizeof(Student), 1, fp);

    printf("\nStudent Record:\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    fclose(fp);
}