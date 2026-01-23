#include "../headers/employee.h"
#include "../headers/utils.h"
#include <stdio.h>
#include <string.h>

void viewProfile(char *username) {
  struct employee e;
  FILE *fp = fopen("data/employees.dat", "r");
  int found = 0;

  clearScreen();
  printHeader("My Profile");

  if (fp == NULL) {
    printf("Unable to access employee records.\n");
    waitForEnter();
    return;
  }

  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) == 6) {
    if (strcmp(e.name, username) == 0) {
      found = 1;
      printf("ID:          %d\n", e.id);
      printf("Name:        %s\n", e.name);
      printf("Department:  %s\n", e.department);
      printf("Base Salary: %.2f\n", e.salary);
      printf("Allowance:   %.2f\n", e.allowance);
      printf("Deduction:   %.2f\n", e.deduction);
      break;
    }
  }

  if (!found) {
    printf("Profile not found for user: %s\n", username);
  }

  fclose(fp);
  waitForEnter();
}

void viewSalary(char *username) {
  struct payroll p;
  FILE *fp = fopen("data/payroll.dat", "r");
  int found = 0;

  clearScreen();
  printHeader("My Salary Records");

  if (fp == NULL) {
    printf("Unable to access payroll records.\n");
    waitForEnter();
    return;
  }

  printf("%-10s %-20s %-10s %-10s %-10s %-10s\n", "ID", "Name", "Basic",
         "Allow", "Deduct", "Net");
  printDivider();

  while (fscanf(fp, "%d %s %f %f %f %f\n", &p.empId, p.name, &p.basic,
                &p.allowance, &p.deduction, &p.netSalary) == 6) {
    if (strcmp(p.name, username) == 0) {
      found = 1;
      printf("%-10d %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n", p.empId, p.name,
             p.basic, p.allowance, p.deduction, p.netSalary);
    }
  }

  if (!found) {
    printf("\nNo salary records found for user: %s\n", username);
  }

  fclose(fp);
  waitForEnter();
}

void employeeMenu(char *username) {
  int choice;
  do {
    clearScreen();
    printHeader("Employee Menu");
    printf("Welcome, %s\n", username);
    printDivider();
    printf("1. View Profile\n");
    printf("2. View Salary Details\n");
    printf("3. Logout\n");
    printDivider();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      viewProfile(username);
      break;
    case 2:
      viewSalary(username);
      break;
    case 3:
      printf("Logging out...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
      waitForEnter();
    }
  } while (choice != 3);
}
