#include "../headers/auth.h"
#include <stdio.h>
#include <string.h>

#define MAX 50

int login(char role[]) {
  char username[MAX], password[MAX];
  char fileUser[MAX], filePass[MAX], fileRole[MAX];
  int found = 0;

  printf("\nUsername: ");
  scanf("%s", username);

  printf("Password: ");
  scanf("%s", password); // for simplicity

  FILE *fp = fopen("data/users.dat", "r");
  if (fp == NULL) {
    printf("Error opening user database.\n");
    return 0;
  }

  while (fscanf(fp, "%s %s %s", fileUser, filePass, fileRole) != EOF) {
    if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
      strcpy(role, fileRole);
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