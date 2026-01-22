#include "../headers/auth.h"
#include <stdio.h>
#include <string.h>

#define MAX 50

void registerUser() {
  struct User u;
  printf("Enter username: ");
  scanf("%s", u.username);
  printf("Enter password: ");
  scanf("%s", u.password);

  FILE *fp = fopen("data/users.dat", "a");
  if (fp == NULL) {
    printf("Error opening user database.\n");
    return;
  }

  fprintf(fp, "%s %s %s\n", u.username, u.password, u.role);
  fclose(fp);
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
    printf("Error opening user database.\n");
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
    printf("\nLogin Successful!\n");
    return 1;
  } else {
    printf("\nInvalid username or password.\n");
    return 0;
  }
}