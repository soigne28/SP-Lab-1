# Employee Database Management System
This program manages an employee database and provides a menu-driven interface for the user to interact with the database. It supports the following operations:

1. Print the Database
2. Lookup employee by ID
3. Lookup employee by last name
4. Add an Employee
5. Quit

The program takes one command-line argument, which is the name of the input file containing the employee information. The input file should contain employee data in the following format: six_digit_id, first_name, last_name, salary.

## Prerequisites
To build and run the program, you need a C compiler such as GCC installed on your system.

## Building
To compile the program, follow these steps:

1. Navigate to the directory containing the source code files: main.c, readfile.c, and readfile.h.
2. Compile the source code using the following command:

gcc -o workerDB main.c readfile.c

This command compiles the source code files and creates an executable named `workerDB`.

## Running
To run the program, use the following command:
./workerDB <input_file>

Replace `<input_file>` with the name of the input file containing the employee information.
For example, if the input file is named `small.txt`, the command would be:
./workerDB input.txt

This command starts the program, loads the employee data from the input file, and presents the menu for user interaction.

