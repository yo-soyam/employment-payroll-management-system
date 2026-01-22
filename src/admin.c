#include "../headers/admin.h"
#include "../headers/models.h"
#include <stdio.h>
#include <string.h>

void addEmployee() {
  struct employee e;
  printf("Add new employee\n");
  printf("Employee ID:");
  scanf("%d", &e.id);
  printf("Name:");
  scanf("%s", e.name);
  printf("Department:");
  scanf("%s", e.department);
  printf("Salary:");
  scanf("%f", &e.salary);
  printf("Allowance:");
  scanf("%f", &e.allowance);
  printf("Deduction:");
  scanf("%f", &e.deduction);
  FILE *fp = fopen("data/employees.dat", "a");
  if (fp == NULL) {
    printf("unable to open database");
    return;
  }
  fprintf(fp, "%d %s %s %f %f %f\n", e.id, e.name, e.department, e.salary,
          e.allowance, e.deduction);
  fclose(fp);
}

void viewAllEmployees() {
  struct employee e;
  FILE *fp = fopen("data/employees.dat", "r");
  if (fp == NULL) {
    printf("unable to open database");
    return;
  }
  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) != EOF) {
    printf("Employee ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Department: %s\n", e.department);
    printf("Salary: %f\n", e.salary);
    printf("Allowance: %f\n", e.allowance);
    printf("Deduction: %f\n", e.deduction);
    printf("\n");
  }
  fclose(fp);
}

void updateEmployeeSalary() { printf("Update Employee Salary Placeholder\n"); }

void adminDeleteEmployee() { printf("Delete Employee Placeholder\n"); }

void adminGeneratePayroll() { printf("Generate Payroll Placeholder\n"); }

void adminViewPayroll() { printf("View Payroll Placeholder\n"); }

void adminMenu() {
  int choice;
  do {
    printf("\n--- Admin Menu ---\n");
    printf("1. Add Employee\n");
    printf("2. View All Employees\n");
    printf("3. Update Employee Salary\n");
    printf("4. Delete Employee\n");
    printf("5. Generate Payroll\n");
    printf("6. View Payroll\n");
    printf("7. Logout\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addEmployee();
      break;
    case 2:
      viewAllEmployees();
      break;
    case 3:
      updateEmployeeSalary();
      break;
    case 4:
      adminDeleteEmployee();
      break;
    case 5:
      adminGeneratePayroll();
      break;
    case 6:
      adminViewPayroll();
      break;
    case 7:
      printf("Logging out...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 7);
}
