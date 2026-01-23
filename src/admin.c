#include "../headers/admin.h"
#include "../headers/models.h"
#include "../headers/utils.h"
#include <stdio.h>
#include <string.h>

void addEmployee() {
  struct employee e;
  clearScreen();
  printHeader("Add New Employee");
  printf("Employee ID: ");
  scanf("%d", &e.id);
  printf("Name: ");
  scanf("%s", e.name);
  printf("Department: ");
  scanf("%s", e.department);
  printf("Salary: ");
  scanf("%f", &e.salary);
  printf("Allowance: ");
  scanf("%f", &e.allowance);
  printf("Deduction: ");
  scanf("%f", &e.deduction);

  FILE *fp = fopen("data/employees.dat", "a");
  if (fp == NULL) {
    printf("Unable to open database\n");
    waitForEnter();
    return;
  }
  fprintf(fp, "%d %s %s %f %f %f\n", e.id, e.name, e.department, e.salary,
          e.allowance, e.deduction);
  fclose(fp);
  printf("\nEmployee added successfully!\n");
  waitForEnter();
}

void viewAllEmployees() {
  struct employee e;
  clearScreen();
  printHeader("All Employees");

  FILE *fp = fopen("data/employees.dat", "r");
  if (fp == NULL) {
    printf("Unable to open database (or no employees yet)\n");
    waitForEnter();
    return;
  }

  printf("%-10s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
  printDivider();

  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) == 6) {
    printf("%-10d %-20s %-15s %-10.2f\n", e.id, e.name, e.department, e.salary);
  }

  fclose(fp);
  waitForEnter();
}

void updateEmployeeSalary() {
  FILE *fp, *temp;
  struct employee e;
  int searchId, found = 0;

  clearScreen();
  printHeader("Update Employee Salary");

  fp = fopen("data/employees.dat", "r");
  temp = fopen("data/temp.dat", "w");

  if (!fp || !temp) {
    printf("Error opening file!\n");
    if (fp)
      fclose(fp);
    if (temp)
      fclose(temp);
    waitForEnter();
    return;
  }

  printf("Enter Employee ID to update salary: ");
  scanf("%d", &searchId);

  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) == 6) {

    if (e.id == searchId) {
      found = 1;

      printf("\nCurrent Salary: %.2f\n", e.salary);
      printf("Enter New Salary: ");
      scanf("%f", &e.salary);

      printf("Enter New Allowance: ");
      scanf("%f", &e.allowance);

      printf("Enter New Deduction: ");
      scanf("%f", &e.deduction);

      printf("\nSalary updated successfully!\n");
    }

    fprintf(temp, "%d %s %s %.2f %.2f %.2f\n", e.id, e.name, e.department,
            e.salary, e.allowance, e.deduction);
  }

  fclose(fp);
  fclose(temp);

  if (found) {
    remove("data/employees.dat");
    rename("data/temp.dat", "data/employees.dat");
  } else {
    remove("data/temp.dat");
    printf("\nEmployee ID not found!\n");
  }
  waitForEnter();
}

void adminDeleteEmployee() {
  struct employee e;
  int id, found = 0;

  clearScreen();
  printHeader("Delete Employee");

  printf("Enter ID to delete: ");
  scanf("%d", &id);

  FILE *fp = fopen("data/employees.dat", "r");
  FILE *ft = fopen("data/temp.dat", "w");

  if (fp == NULL || ft == NULL) {
    if (fp)
      fclose(fp);
    if (ft)
      fclose(ft);
    printf("Unable to open file\n");
    waitForEnter();
    return;
  }

  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) == 6) {
    if (id == e.id) {
      found = 1;
    } else {
      fprintf(ft, "%d %s %s %f %f %f\n", e.id, e.name, e.department, e.salary,
              e.allowance, e.deduction);
    }
  }
  fclose(fp);
  fclose(ft);

  if (found) {
    remove("data/employees.dat");
    rename("data/temp.dat", "data/employees.dat");
    printf("\nEmployee Deleted Successfully\n");
  } else {
    remove("data/temp.dat");
    printf("\nEmployee not found\n");
  }
  waitForEnter();
}

void adminGeneratePayroll() {
  FILE *empFile, *payFile;
  struct employee e;
  struct payroll p;

  clearScreen();
  printHeader("Generate Payroll");

  empFile = fopen("data/employees.dat", "r");
  payFile = fopen("data/payroll.dat", "w");

  if (!empFile || !payFile) {
    printf("Error opening file!\n");
    waitForEnter();
    return;
  }

  while (fscanf(empFile, "%d %s %s %f %f %f", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) != EOF) {

    p.empId = e.id;
    strcpy(p.name, e.name);
    p.basic = e.salary;
    p.allowance = e.allowance;
    p.deduction = e.deduction;
    p.netSalary = e.salary + e.allowance - e.deduction;

    fprintf(payFile, "%d %s %.2f %.2f %.2f %.2f\n", p.empId, p.name, p.basic,
            p.allowance, p.deduction, p.netSalary);
  }

  fclose(empFile);
  fclose(payFile);

  printf("Payroll generated successfully for all employees!\n");
  waitForEnter();
}

void adminViewPayroll() {
  struct payroll p;

  clearScreen();
  printHeader("Payroll Records");

  FILE *fp = fopen("data/payroll.dat", "r");

  if (fp == NULL) {
    printf("Unable to open payroll records (or no payroll generated yet).\n");
    waitForEnter();
    return;
  }

  printf("%-10s %-20s %-10s %-10s %-10s %-10s\n", "ID", "Name", "Basic",
         "Allow", "Deduct", "Net");
  printDivider();

  while (fscanf(fp, "%d %s %f %f %f %f\n", &p.empId, p.name, &p.basic,
                &p.allowance, &p.deduction, &p.netSalary) == 6) {
    printf("%-10d %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n", p.empId, p.name,
           p.basic, p.allowance, p.deduction, p.netSalary);
  }

  fclose(fp);
  waitForEnter();
}

void adminMenu() {
  int choice;
  do {
    clearScreen();
    printHeader("Admin Menu");
    printf("1. Add Employee\n");
    printf("2. View All Employees\n");
    printf("3. Update Employee Salary\n");
    printf("4. Delete Employee\n");
    printf("5. Generate Payroll\n");
    printf("6. View Payroll\n");
    printf("7. Logout\n");
    printDivider();
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
      waitForEnter();
    }
  } while (choice != 7);
}
