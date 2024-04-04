#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

// Define colors for better readability
#define COLOR_CYAN 11
#define COLOR_YELLOW 14
#define COLOR_GREEN 10
#define COLOR_RED 12
#define COLOR_WHITE 15

// Function prototypes
void setColor(int color);
void clearScreen();
void displayHouse(bool isDoorOpen, bool isWindowOpen);
void displayAsciiArt();
void flushInputBuffer();

int main() {
    // Initialize variables
    bool isDoorOpen = false;
    bool isWindowOpen = false;
    char choice;

    // Display welcome message
    printf("\n\t\tWelcome to My House Simulator\n\n");

    // Main game loop
    while (true) {
        clearScreen(); // Clear screen
        displayHouse(isDoorOpen, isWindowOpen); // Display house
        printf("\n");

        // Display options
        setColor(COLOR_CYAN);
        printf("-- Made by Raven :v --\n\n");
        setColor(COLOR_YELLOW);
        printf("1. %s the door\n", isDoorOpen ? "Close" : "Open");
        printf("2. %s the windows\n", isWindowOpen ? "Close" : "Open");
        printf("3. Show Instructions\n"); // Updated option
        printf("4. Quit\n");
        setColor(COLOR_WHITE);

        printf("\nEnter your choice (1, 2, 3, or 4): ");
        if (scanf(" %c", &choice) != 1 || (choice < '1' || choice > '4')) {
            setColor(COLOR_RED);
            printf("\nInvalid input. Please enter a valid option (1, 2, 3, or 4).\n");
            setColor(COLOR_WHITE);
            flushInputBuffer();
            continue;
        }

        // Process user choice
        switch (choice) {
            case '1':
                isDoorOpen = !isDoorOpen;
                break;
            case '2':
                isWindowOpen = !isWindowOpen;
                break;
            case '3':
                clearScreen();
                setColor(COLOR_CYAN);
                printf("\n\t\tInstructions:\n\n");
                setColor(COLOR_WHITE);
                printf("1. Use option 1 to toggle the door.\n");
                printf("2. Use option 2 to toggle the windows.\n");
                printf("3. Use option 4 to quit the simulator.\n");
                printf("\nPress any key to return to the main menu...");
                flushInputBuffer();
                getchar(); // Wait for key press
                break;
            case '4':
                clearScreen();    
                setColor(COLOR_GREEN);
                printf("\nThanks for playing :)\n");
                setColor(COLOR_WHITE);
                displayAsciiArt();
                system("pause");
                return 0;
            default:
                setColor(COLOR_RED);
                printf("\nInvalid choice. Please enter a valid option (1, 2, 3, or 4).\n");
                setColor(COLOR_WHITE);
        }

        system("pause"); // Pause execution to let the user see the output
    }

    return 0;
}

// Function to set text color
void setColor(int color) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, color);
}

// Function to clear the screen
void clearScreen() {
    system("cls"); // For Windows
    //system("clear"); // For Unix-like systems
}

// Function to display the house with its current state
void displayHouse(bool isDoorOpen, bool isWindowOpen) {
    printf("     __________\n");
    printf("    /          \\\n");
    printf("   /            \\\n");
    printf("  /              \\\n");
    printf(" /________________\\\n");
    printf(" |      ___       |\n");
    printf(" |     |___|      |\n");
    printf(" |                |\n");

    // Display Window state
    if (isWindowOpen) {
        setColor(COLOR_GREEN);
        printf(" |      [ ]       |\n");
    } else {
        setColor(COLOR_RED);
        printf(" |       |        |\n");
    }

    // Display Door state
    if (isDoorOpen) {
        setColor(COLOR_GREEN);
        printf(" |     ( - )      |\n");
    } else {
        setColor(COLOR_RED);
        printf(" |      ___       |\n");
    }

    setColor(COLOR_WHITE); // Reset text color to white
    printf(" |________________|\n");
}

// Function to display ASCII art
void displayAsciiArt() {
    printf("\n\t |\\/\\/|  \n");
    printf("\t |      |  \n");
    printf("\t | (o)(o)  \n");
    printf("\t C      _) \n");
    printf("\t  |  ___|  \n");
    printf("\t  |   /    \n");
    printf("\t /____\\    \n");
    printf("\t/      \\   \n");
}

// Function to flush input buffer
void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
