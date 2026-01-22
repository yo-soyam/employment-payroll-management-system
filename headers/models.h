#ifndef MODELS_H
#define MODELS_H

struct User {
  char username[50];
  char password[30];
  char role[20]; // ADMIN or EMPLOYEE
};

struct employee {
  int id;
  char name[50];
  char department[50];
  float salary;
  float allowance;
  float deduction;
};

struct payroll {
  int id;
  float allowance;
  float deductions;
  float net_salary;
};

#endif
