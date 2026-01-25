#include "../headers/auth.h"
#include "../headers/utils.h"
#include <stdio.h>
#include <string.h>

#define MAX 50

void registerUser() {
  struct User u;
  int choice;
  clearScreen();
  printHeader("Register New User");
  printf("Enter username: ");
  scanf("%s", u.username);
  printf("Enter password: ");
  scanf("%s", u.password);

  printf("\nSelect user role:\n");
  printMenuOption(1, "Admin");
  printMenuOption(2, "Employee");
  printf("Enter choice: ");
  scanf("%d", &choice);

  if (choice == 1) {
    strcpy(u.role, "ADMIN");
  } else {
    strcpy(u.role, "EMPLOYEE");
  }

  FILE *fp = fopen("data/users.dat", "a");
  if (fp == NULL) {
    printError("Error opening user database.");
    return;
  }

  fprintf(fp, "%s %s %s\n", u.username, u.password, u.role);
  fclose(fp);
  printSuccess("Registration Successful! Please login.");
}

int login(char *role, char *username) {
  char fileUser[MAX], filePass[MAX], fileRole[MAX];
  char inputUsername[MAX], inputPassword[MAX];
  int found = 0;

  printf("\nUsername: ");
  scanf("%s", inputUsername);

  printf("Password: ");
  scanf("%s", inputPassword);

  FILE *fp = fopen("data/users.dat", "r");
  if (fp == NULL) {
    printError("Error opening user database.");
    return 0;
  }

  while (fscanf(fp, "%s %s %s", fileUser, filePass, fileRole) != EOF) {
    if (strcmp(inputUsername, fileUser) == 0 &&
        strcmp(inputPassword, filePass) == 0) {
      strcpy(role, fileRole);
      if (username != NULL) {
        strcpy(username, fileUser);
      }
      found = 1;
      break;
    }
  }

  fclose(fp);

  if (found) {
    printSuccess("Login Successful!");
    return 1;
  } else {
    printError("Invalid username or password.");
    return 0;
  }
}