#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

// Function prototypes
void displayHouse(bool isDoorOpen, bool isWindowOpen);
void setColor(int color);
void clearScreen();

int main() {
    // Initialize variables
    bool isDoorOpen = false;
    bool isWindowOpen = false;
    char choice;

    // Main game loop 
    while (true) {
        clearScreen(); // Clear screen
        printf("Welcome to My House Simulator\n\n");
        displayHouse(isDoorOpen, isWindowOpen); // Display house

        // Display options
        setColor(11); // Change text color to light cyan
        printf("\n-- Made by Raven :v --\n");
        setColor(14); // Change text color to yellow
        printf("\nWhat would you like to do?\n");
        printf("1. %s the door\n", isDoorOpen ? "Close" : "Open");
        printf("2. %s the windows\n", isWindowOpen ? "Close" : "Open");
        printf("3. Quit\n");
        printf("\n");
        setColor(15); // Reset text color to white
        printf("Enter your choice (1, 2, or 3): ");
        scanf(" %c", &choice);

        // Process user choice
        switch (choice) {
            case '1':
                isDoorOpen = !isDoorOpen;
                break;
            case '2':
                isWindowOpen = !isWindowOpen;
                break;
            case '3':
                setColor(10); // Change text color to green
                printf("\nThanks for playing :)\n");
                setColor(15); // Reset text color to white
                return 0;
            default:
                setColor(12); // Change text color to red
                printf("\nInvalid choice. Please enter 1, 2, or 3.\n");
                setColor(15); // Reset text color to white
        }
        printf("\n");
        system("pause"); // Pause execution to let the user see the output
    }

    return 0;
}

// Function to display the house with its current state
void displayHouse(bool isDoorOpen, bool isWindowOpen) {
    printf("\n     __________\n");
    printf("    /          \\\n");
    printf("   /            \\\n");
    printf("  /              \\\n");
    printf(" /________________\\\n");
    printf(" |      ___       |\n");
    printf(" |     |___|      |\n");
    printf(" |                |\n");

    // Display Window state
    if (isWindowOpen) {
        setColor(10); // Change text color to green
        printf(" |      [ ]       |\n");
    } else {
        setColor(12); // Change text color to red
        printf(" |       |        |\n");
    }

    // Display Door state
    if (isDoorOpen) {
        setColor(10); // Change text color to green
        printf(" |     ( - )      |\n");
    } else {
        setColor(12); // Change text color to red
        printf(" |      ___       |\n");
    }

    setColor(15); // Reset text color to white
    printf(" |________________|\n");
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
