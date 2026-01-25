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
  printf(COLOR_CYAN
         "====================================================================="
         "================\n" COLOR_RESET);
}

void printCentered(const char *text) {
  int width = 80; // Assuming standard width
  int len = 0;
  while (text[len] != '\0')
    len++;
  int padding = (width - len) / 2;
  if (padding < 0)
    padding = 0;

  for (int i = 0; i < padding; i++)
    printf(" ");
  printf("%s\n", text);
}

void printHeader(const char *title) {
  printf("\n");
  printDivider();
  printf(COLOR_BOLD COLOR_CYAN);
  printCentered(title);
  printf(COLOR_RESET);
  printDivider();
}

void printSuccess(const char *msg) {
  printf(COLOR_GREEN "\n[SUCCESS] %s\n" COLOR_RESET, msg);
}

void printError(const char *msg) {
  printf(COLOR_RED "\n[ERROR] %s\n" COLOR_RESET, msg);
}

void printMenuOption(int option, const char *text) {
  printf(COLOR_YELLOW "  [%d] " COLOR_RESET "%s\n", option, text);
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
