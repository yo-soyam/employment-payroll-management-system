#ifndef MODELS_H
#define MODELS_H

struct user {
  char username[50];
  char password[30];
  int role; // 1=>admin 2=>user
};

struct employee {
  int id;
  char name[50];
  char department[50];
  float salary;
};

struct payroll {
    int id;
    float allowance;
    float deductions;
    float net_salary;
};

#endif
