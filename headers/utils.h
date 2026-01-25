#ifndef UTILS_H
#define UTILS_H

// Color Macros
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_BOLD "\033[1m"

void clearScreen();
void printHeader(const char *title);
void printDivider();
void waitForEnter();
void setupWorkingDirectory();

// New UI Utils
void printSuccess(const char *msg);
void printError(const char *msg);
void printCentered(const char *text);
void printMenuOption(int option, const char *text);

#endif
