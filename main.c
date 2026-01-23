// beautification is done by gemini
// code is written by soyam bhalotia
#include "headers/admin.h"
#include "headers/auth.h"
#include "headers/employee.h"
#include "headers/utils.h"
#include <stdio.h>
#include <string.h>

int main() {
  char role[20];
  char username[50];
  int attempts = 3;
  int success = 0;
  int n;

  clearScreen();
  printHeader("Employment Payroll Management System");
  printf("1. Register\n");
  printf("2. Login\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &n);

  if (n == 1) {
    registerUser();
    printf("Please restart the application to login.\n");
    return 0;
  }

  if (n == 2) {
    while (attempts > 0) {
      if (login(role, username)) {
        success = 1;
        break;
      } else {
        attempts--;
        if (attempts > 0) {
          printf("login failed! %d attempts remaining\n", attempts);
        } else {
          // yaha par agar attempt 0 hua toh exit  ho jayega
        }
      }
    }

    if (success) {
      if (strcmp(role, "ADMIN") == 0) {
        printf("Welcome Admin!\n");
        // Admin menu here
        adminMenu();
      } else {
        printf("Welcome Employee!\n");
        // Employee menu here
        employeeMenu(username);
      }
    } else {
      printf("Maximum login attempts reached. Exiting...\n");
      return 1;
    }

  } else if (n == 3) {
    printf("Exiting...\n");
    return 0;
  } else {
    printf("Invalid input. Please try again.\n");
    return 1;
  }
  return 0;
}
