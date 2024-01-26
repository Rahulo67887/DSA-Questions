#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct employee{
    char name[50];
    int salary;
    int employeeID;
};

int main()
{
    int n;
    printf("Enter the number of employee:");
    scanf("%d", &n);
    struct employee *emp=(struct employee *)malloc(n*sizeof(struct employee));
    for(int i=0; i<n; i++){   
        printf("Enter name of employee %d:", i+1);
        scanf("%s", emp[i].name);
        printf("Enter the salary of employee %d:", i+1);
        scanf("%d", &emp[i].salary);
        printf("Enter the ID of employee %d:", i+1);
        scanf("%d", &emp[i].employeeID);
		printf("\n");
    }


	for(int i=0; i<n; i++){
		printf("Name of employee %d: %s\n", i+1, emp[i].name);
		printf("Salary of employee %d: %d\n", i+1, emp[i].salary);
		printf("EmployeeID of employee %d: %d\n", i+1, emp[i].employeeID);
		printf("\n");
	}

    return 0;
}