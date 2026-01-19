
#include "headers/auth.h"
#include <stdio.h>
#include <string.h>

int main() {
  char role[20];

  if (login(role)) {
    if (strcmp(role, "ADMIN") == 0) {
      printf("Welcome Admin!\n");
      // Admin menu here
    } else if (strcmp(role, "EMPLOYEE") == 0) {
      printf("Welcome Employee!\n");
      // Employee menu here
    }
  } else {
    printf("Access Denied.\n");
  }

  return 0;
}
