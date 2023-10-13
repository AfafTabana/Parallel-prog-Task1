#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define USER_LENGTH 15
#define PASS_LENGTH 15

typedef struct {
    char username[USER_LENGTH];
    char password[PASS_LENGTH];
} User;

User users[];
int numUsers = 0;

void registeration() {
   

    User newUser;
    printf("Enter your username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf(" This Username already exists. Please Enter a different username.\n");
            return;
        }
    }

    printf("Enter your password: ");
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful.\n");
}

void login() {
    char username[USER_LENGTH];
    char password[PASS_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Invalid username or password. Please Check that you entered your correct username and password. \n");
}

int main() {
    int choice;

    while (1) {
        printf("a. Register\n");
        printf("b. Login\n");
        printf("c. Exit\n");
        printf("What Process will you choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registeration();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}