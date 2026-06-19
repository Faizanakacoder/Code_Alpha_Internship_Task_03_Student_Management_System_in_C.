#include <stdio.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

int main()
{
    struct Student s[100];
    int count = 0;
    int choice, roll, i, found;

    while(1)
    {
        printf("\n=================================");
        printf("\n   STUDENT MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Roll Number: ");
                scanf("%d", &s[count].rollNo);

                printf("Enter Name: ");
                scanf(" %[^\n]", s[count].name);

                printf("Enter Marks: ");
                scanf("%f", &s[count].marks);

                count++;
                printf("\nStudent Added Successfully!");
                break;

            case 2:
                if(count == 0)
                {
                    printf("\nNo Records Found!");
                }
                else
                {
                    printf("\n\nStudent Records:\n");

                    for(i = 0; i < count; i++)
                    {
                        printf("\nRoll No : %d", s[i].rollNo);
                        printf("\nName    : %s", s[i].name);
                        printf("\nMarks   : %.2f\n", s[i].marks);
                    }
                }
                break;

            case 3:
                printf("\nEnter Roll Number to Search: ");
                scanf("%d", &roll);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(s[i].rollNo == roll)
                    {
                        printf("\nStudent Found!");
                        printf("\nRoll No : %d", s[i].rollNo);
                        printf("\nName    : %s", s[i].name);
                        printf("\nMarks   : %.2f\n", s[i].marks);

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("\nStudent Not Found!");
                }
                break;

            case 4:
                printf("\nEnter Roll Number to Update: ");
                scanf("%d", &roll);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(s[i].rollNo == roll)
                    {
                        printf("Enter New Name: ");
                        scanf(" %[^\n]", s[i].name);

                        printf("Enter New Marks: ");
                        scanf("%f", &s[i].marks);

                        printf("\nRecord Updated Successfully!");
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("\nStudent Not Found!");
                }
                break;

            case 5:
                printf("\nEnter Roll Number to Delete: ");
                scanf("%d", &roll);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(s[i].rollNo == roll)
                    {
                        int j;

                        for(j = i; j < count - 1; j++)
                        {
                            s[j] = s[j + 1];
                        }

                        count--;
                        found = 1;

                        printf("\nRecord Deleted Successfully!");
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("\nStudent Not Found!");
                }
                break;

            case 6:
                printf("\nThank You!");
                return 0;

            default:
                printf("\nInvalid Choice!");
        }
    }

    return 0;
}
