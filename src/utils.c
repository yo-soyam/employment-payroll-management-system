#include "../headers/utils.h"
#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
  // ANSI escape code to clear screen and move cursor to top-left
  printf("\033[2J\033[H");
}

void printDivider() {
  printf("---------------------------------------------------------------------"
         "\n");
}

void printHeader(const char *title) {
  printDivider();
  printf("  %s\n", title);
  printDivider();
}

void waitForEnter() {
  printf("\nPress Enter to continue...");
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;        // Flush stdin
  getchar(); // Wait for Enter
}
