// beautification is done by gemini
// code is written by soyam bhalotia
#include "headers/admin.h"
#include "headers/auth.h"
#include "headers/employee.h"
#include "headers/utils.h"
#include <stdio.h>
#include <string.h>

int main() {
  setupWorkingDirectory();
  int n;

  while (1) {
    char role[20] = "";
    char username[50] = "";
    int attempts = 3;
    int success = 0;

    // Clear buffer if needed, though mostly handled by scanf

    clearScreen();
    printHeader("Employment Payroll Management System");
    printMenuOption(1, "Register");
    printMenuOption(2, "Login");
    printMenuOption(3, "Exit");
    printDivider();
    printf("Enter your choice: ");
    if (scanf("%d", &n) != 1) {
      // Handle non-integer input to avoid infinite loop
      while (getchar() != '\n')
        ;
      continue;
    }

    if (n == 1) {
      registerUser();
      printf("\nPress Enter to return to main menu...");
      while (getchar() != '\n')
        ;        // clear buffer
      getchar(); // wait for enter
    } else if (n == 2) {
      while (attempts > 0) {
        if (login(role, username)) {
          success = 1;
          break;
        } else {
          attempts--;
          if (attempts > 0) {
            printf("login failed! %d attempts remaining\n", attempts);
          }
        }
      }

      if (success) {
        if (strcmp(role, "ADMIN") == 0) {
          printSuccess("Welcome Admin!");
          waitForEnter();
          adminMenu();
        } else {
          printSuccess("Welcome Employee!");
          waitForEnter();
          employeeMenu(username);
        }
        // After returning from menus, the loop continues, showing the main menu
        // again
      } else {
        printError("Maximum login attempts reached.");
        waitForEnter();
      }

    } else if (n == 3) {
      printf("Exiting...\n");
      return 0;
    } else {
      printf("Invalid input. Please try again.\n");
      printf("Press Enter to continue...");
      while (getchar() != '\n')
        ;
      getchar();
    }
  }
  return 0;
}
