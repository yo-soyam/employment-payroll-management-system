#include "../headers/utils.h"
#include <libgen.h>
#include <limits.h>
#include <mach-o/dyld.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void setupWorkingDirectory() {
  char path[PATH_MAX];
  uint32_t size = sizeof(path);
  if (_NSGetExecutablePath(path, &size) == 0) {
    char *dir = dirname(path);
    if (chdir(dir) != 0) {
      perror("Failed to set working directory");
    }
  } else {
    printf("Buffer too small; suspect path is too long\n");
  }
}
