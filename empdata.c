#include <stdio.h>
#include <string.h>
#include "readfile.h"

// Employee structure definition
typedef struct {
    int id;
    char firstName[64];
    char lastName[64];
    int salary;
} Employee;


// Function to print the employee database
void print_database(Employee *employees, int size) {
    printf("ID\tFirst Name\tLast Name\tSalary\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n", employees[i].id, employees[i].firstName, employees[i].lastName, employees[i].salary);
    }
}

// Function to perform a linear search by employee ID
int lookup_employee_by_id(Employee *employees, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to perform a linear search by employee last name
int lookup_employee_by_last_name(Employee *employees, int size, char *last_name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(employees[i].lastName, last_name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add an employee to the database
int add_employee(Employee *employees, int *num_employees, int id, const char *first_name, const char *last_name, int salary) {
    if (id < 100000 || id > 999999 || salary < 30000 || salary > 150000) {
        return -1;
    }

    employees[*num_employees].id = id;
    strcpy(employees[*num_employees].firstName, first_name);
    strcpy(employees[*num_employees].lastName, last_name);
    employees[*num_employees].salary = salary;
    (*num_employees)++;
    return 0;
}

int main(int argc, char *argv[]) {
    // Check if the user provided a filename as an argument
    if (argc != 2) {
        printf("Usage: ./workerDB <filename>\n");
        return 1;
    }

    // Open the input file
    int ret = open_file(argv[1]);
    if (ret == -1) {
        printf("Error opening file.\n");
        return 1;
    }

    Employee employees[1024];
    int num_employees = 0;

    // Read the file and store the data in the employees array
    while (1) {
        int id;
        ret = read_int(&id);
        if (ret == -1) break;
        employees[num_employees].id = id;

        read_string(employees[num_employees].firstName);
        read_string(employees[num_employees].lastName);

        int salary;
        ret = read_int(&salary);
        if (ret == -1) break;
        employees[num_employees].salary = salary;

        num_employees++;
    }

    // Close the file
    close_file();

    int choice;
    
    // Main loop for menu interaction

    while (1) {
        printf("\n1. Print the Database\n2. Lookup employee by ID\n3. Lookup employee by last name\n4. Add an Employee\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        //Option 1
        if (choice == 1) {
            print_database(employees, num_employees);
        //Option 2
        } else if (choice == 2) {
            int id;
            printf("Enter employee ID: ");
            scanf("%d", &id);
            int index = lookup_employee_by_id(employees, num_employees, id);
            if (index == -1) {
                printf("Employee not found.\n");
            } else {
                printf("Employee found: ID: %d, First Name: %s, Last Name: %s, Salary: %.2f\n", employees[index].id, employees[index].firstName, employees[index].lastName, employees[index].salary);
            }
        //Option 3
        } else if (choice == 3) {
            char last_name[50];
            printf("Enter employee last name: ");
            scanf("%s", last_name);
            int index = lookup_employee_by_last_name(employees, num_employees, last_name);
            if (index == -1) {
                printf("Employee not found.\n");
            } else {
                printf("Employee found: ID: %d, First Name: %s, Last Name: %s, Salary: %.2f\n", employees[index].id, employees[index].firstName, employees[index].lastName, employees[index].salary);
            }
        //Option 4
        } else if (choice == 4) {
            int id, salary;
            char first_name[50], last_name[50];
            printf("Enter employee ID (100000-999999): ");
            scanf("%d", &id);
            printf("Enter employee first name: ");
            scanf("%s", first_name);
            printf("Enter employee last name: ");
            scanf("%s", last_name);
            printf("Enter employee salary (30000-150000): ");
            scanf("%d", &salary);
            int result = add_employee(employees, &num_employees, id, first_name, last_name, salary);
            if (result == -1) {
                printf("Invalid input. Employee not added.\n");
            } else {
                printf("Employee added successfully.\n");
            }
        //Option 5
        } else if (choice == 5) {
                    break;
        } else {
            printf("Invalid choice.\n");
        }
    }
}
