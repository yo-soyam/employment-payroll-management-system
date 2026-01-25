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
    printError("Unable to open database");
    waitForEnter();
    return;
  }
  fprintf(fp, "%d %s %s %f %f %f\n", e.id, e.name, e.department, e.salary,
          e.allowance, e.deduction);
  fclose(fp);
  printf("\n");
  printSuccess("Employee added successfully!");
  waitForEnter();
}

void viewAllEmployees() {
  struct employee e;
  clearScreen();
  printHeader("All Employees");

  FILE *fp = fopen("data/employees.dat", "r");
  if (fp == NULL) {
    printError("Unable to open database (or no employees yet)");
    waitForEnter();
    return;
  }

  printf(COLOR_BOLD "%-10s %-20s %-15s %-10s\n" COLOR_RESET, "ID", "Name",
         "Department", "Salary");
  printDivider();

  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) == 6) {
    printf("%-10d %-20s %-15s %-10.2f\n", e.id, e.name, e.department, e.salary);
  }

  fclose(fp);
  waitForEnter();
}

void searchEmployee() {
  struct employee e;
  int searchId;
  char searchName[50];
  int choice;
  int found = 0;

  clearScreen();
  printHeader("Search Employee");
  printf("Search by:\n");
  printf("1. ID\n");
  printf("2. Name\n");
  printf("Enter choice: ");
  scanf("%d", &choice);

  FILE *fp = fopen("data/employees.dat", "r");
  if (fp == NULL) {
    printf("Unable to open database\n");
    waitForEnter();
    return;
  }

  if (choice == 1) {
    printf("Enter Employee ID: ");
    scanf("%d", &searchId);
  } else if (choice == 2) {
    printf("Enter Employee Name: ");
    scanf("%s", searchName);
  } else {
    printf("Invalid choice\n");
    fclose(fp);
    waitForEnter();
    return;
  }

  printf("\n%-10s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
  printDivider();

  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) == 6) {
    if ((choice == 1 && e.id == searchId) ||
        (choice == 2 && strcmp(e.name, searchName) == 0)) {
      printf("%-10d %-20s %-15s %-10.2f\n", e.id, e.name, e.department,
             e.salary);
      found = 1;
    }
  }

  if (!found) {
    printf("\nNo employee found matching the criteria.\n");
  }

  fclose(fp);
  waitForEnter();
}

void updateEmployee() {
  FILE *fp, *temp;
  struct employee e;
  int searchId, found = 0;
  int updateChoice;

  clearScreen();
  printHeader("Update Employee");

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

  printf("Enter Employee ID to update: ");
  scanf("%d", &searchId);

  while (fscanf(fp, "%d %s %s %f %f %f\n", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) == 6) {

    if (e.id == searchId) {
      found = 1;
      printf("\nEmployee Found: %s\n", e.name);
      printf("1. Update Name\n");
      printf("2. Update Department\n");
      printf("3. Update Salary Info\n");
      printf("Enter choice: ");
      scanf("%d", &updateChoice);

      switch (updateChoice) {
      case 1:
        printf("Enter New Name: ");
        scanf("%s", e.name);
        break;
      case 2:
        printf("Enter New Department: ");
        scanf("%s", e.department);
        break;
      case 3:
        printf("\nCurrent Salary: %.2f\n", e.salary);
        printf("Enter New Salary: ");
        scanf("%f", &e.salary);

        printf("Enter New Allowance: ");
        scanf("%f", &e.allowance);

        printf("Enter New Deduction: ");
        scanf("%f", &e.deduction);
        break;
      default:
        printf("Invalid choice. No changes made to this field.\n");
      }
      printSuccess("Employee updated successfully!");
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
    printSuccess("Employee Deleted Successfully");
  } else {
    remove("data/temp.dat");
    printError("Employee not found");
  }
  waitForEnter();
}

void adminGeneratePayroll() {
  FILE *empFile, *payFile;
  struct employee e;
  struct payroll p;
  char date[20];

  clearScreen();
  printHeader("Generate Payroll");

  printf("Enter Payroll Month/Year (e.g., Jan-2025): ");
  scanf("%s", date);

  empFile = fopen("data/employees.dat", "r");
  payFile = fopen("data/payroll.dat", "a");

  if (!empFile || !payFile) {
    printf("Error opening file!\n");
    if (empFile)
      fclose(empFile);
    if (payFile)
      fclose(payFile);
    waitForEnter();
    return;
  }

  while (fscanf(empFile, "%d %s %s %f %f %f", &e.id, e.name, e.department,
                &e.salary, &e.allowance, &e.deduction) != EOF) {

    p.empId = e.id;
    strcpy(p.name, e.name);
    strcpy(p.date, date);
    p.basic = e.salary;
    p.allowance = e.allowance;
    p.deduction = e.deduction;
    p.netSalary = e.salary + e.allowance - e.deduction;

    fprintf(payFile, "%d %s %s %.2f %.2f %.2f %.2f\n", p.empId, p.name, p.date,
            p.basic, p.allowance, p.deduction, p.netSalary);
  }

  fclose(empFile);
  fclose(payFile);

  fclose(payFile);

  printSuccess("Payroll generated successfully for all employees!");
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

  printf(COLOR_BOLD "%-10s %-20s %-15s %-10s %-10s %-10s %-10s\n" COLOR_RESET,
         "ID", "Name", "Date", "Basic", "Allow", "Deduct", "Net");
  printDivider();

  while (fscanf(fp, "%d %s %s %f %f %f %f\n", &p.empId, p.name, p.date,
                &p.basic, &p.allowance, &p.deduction, &p.netSalary) == 7) {
    printf("%-10d %-20s %-15s %-10.2f %-10.2f %-10.2f %-10.2f\n", p.empId,
           p.name, p.date, p.basic, p.allowance, p.deduction, p.netSalary);
  }

  fclose(fp);
  waitForEnter();
}

void searchPayrollHistory() {
  struct payroll p;
  int searchId;
  int found = 0;

  clearScreen();
  printHeader("Search Payroll History");
  printf("Enter Employee ID: ");
  scanf("%d", &searchId);

  FILE *fp = fopen("data/payroll.dat", "r");
  if (fp == NULL) {
    printf("Unable to open payroll records.\n");
    waitForEnter();
    return;
  }

  printf("\nPayroll History for Employee ID: %d\n", searchId);
  printf("\nPayroll History for Employee ID: %d\n", searchId);
  printf(COLOR_BOLD "%-15s %-10s %-10s %-10s %-10s\n" COLOR_RESET, "Date",
         "Basic", "Allow", "Deduct", "Net");
  printDivider();

  while (fscanf(fp, "%d %s %s %f %f %f %f\n", &p.empId, p.name, p.date,
                &p.basic, &p.allowance, &p.deduction, &p.netSalary) == 7) {
    if (p.empId == searchId) {
      printf("%-15s %-10.2f %-10.2f %-10.2f %-10.2f\n", p.date, p.basic,
             p.allowance, p.deduction, p.netSalary);
      found = 1;
    }
  }

  if (!found) {
    if (!found) {
      printError("No records found for this Employee ID.");
    }
  }

  fclose(fp);
  waitForEnter();
}

void adminMenu() {
  int choice;
  do {
    clearScreen();
    printHeader("Admin Menu");
    printMenuOption(1, "Add Employee");
    printMenuOption(2, "View All Employees");
    printMenuOption(3, "Search Employee");
    printMenuOption(4, "Update Employee");
    printMenuOption(5, "Delete Employee");
    printMenuOption(6, "Generate Payroll");
    printMenuOption(7, "View Payroll");
    printMenuOption(8, "Search Payroll History");
    printMenuOption(9, "Logout");
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
      searchEmployee();
      break;
    case 4:
      updateEmployee();
      break;
    case 5:
      adminDeleteEmployee();
      break;
    case 6:
      adminGeneratePayroll();
      break;
    case 7:
      adminViewPayroll();
      break;
    case 8:
      searchPayrollHistory();
      break;
    case 9:
      printSuccess("Logging out...");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
      waitForEnter();
    }
  } while (choice != 9);
}
