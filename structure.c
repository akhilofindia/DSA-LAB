#include <stdio.h>
#include <string.h>

// Define a structure to store student information
struct Student {
    char name[50];
    int roll_no;
    int age;
    char sex;
    char address[100];
    float marks;
};

int main() {
    // Create an array to store information about 5 students
    struct Student students[5];

    // Input data for 5 students
    for (int i = 0; i < 5; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Sex (M/F): ");
        scanf(" %c", &students[i].sex);
        printf("Address: ");
        scanf("%s", students[i].address);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Print the information of students with more than 60% and 80% marks
    printf("\nStudents with more than 80%% marks:\n");
    for (int i = 0; i < 5; i++) {
        if (students[i].marks > 80) {
            printf("Name: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Age: %d\n", students[i].age);
            printf("Sex: %c\n", students[i].sex);
            printf("Address: %s\n", students[i].address);
            printf("Marks: %.2f\n\n", students[i].marks);
        }
    }

    return 0;
}