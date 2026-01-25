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
    if (fp == NULL) {
      printError("Unable to access employee records.");
      waitForEnter();
      return;
    }
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
    if (!found) {
      printError("Profile not found for user.");
    }
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
    if (fp == NULL) {
      printError("Unable to access payroll records.");
      waitForEnter();
      return;
    }
    waitForEnter();
    return;
  }

  printf(COLOR_BOLD "%-10s %-20s %-15s %-10s %-10s %-10s %-10s\n" COLOR_RESET,
         "ID", "Name", "Date", "Basic", "Allow", "Deduct", "Net");
  printDivider();

  while (fscanf(fp, "%d %s %s %f %f %f %f\n", &p.empId, p.name, p.date,
                &p.basic, &p.allowance, &p.deduction, &p.netSalary) == 7) {
    if (strcmp(p.name, username) == 0) {
      found = 1;
      printf("%-10d %-20s %-15s %-10.2f %-10.2f %-10.2f %-10.2f\n", p.empId,
             p.name, p.date, p.basic, p.allowance, p.deduction, p.netSalary);
    }
  }

  if (!found) {
    if (!found) {
      printError("No salary records found for user.");
    }
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
    printMenuOption(1, "View Profile");
    printMenuOption(2, "View Salary Details");
    printMenuOption(3, "Logout");
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
      printSuccess("Logging out...");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
      waitForEnter();
    }
  } while (choice != 3);
}
