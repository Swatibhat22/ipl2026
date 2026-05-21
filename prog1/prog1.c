#include <stdio.h>
#define <stdlib.h>
#define MAX 100
#define FILENAME "students.dat"
#define TFILENAME "tstu.dat"
typedef struct{
    int id;
    char name[50];
    float marks;
}Student;

void inputdata(Student s[], int n);
void storedata(Student s[], int n, const char *filename);
void display_mth_record(const char *filename, int m);
void deleterecord(const char *filename, int n);


int main(){
    int n, m, a;
    Student s[MAX];
    printf("Enter the number of students:");
    scanf("%d",&n);
    if(n<=0 || n>MAX){
        printf("Invalid input!\n");
        return 0;

    }
    inputdata(s, n);
    storedata(s, n, FILENAME);
    display_mth_record(FILENAME,m);
    deleterecord(FILENAME,n);
    return 0;
}

void inputdata(Student s[], int n){
    for(int i=0; i<n; i++){
        
    }
}
