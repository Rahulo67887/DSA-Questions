#include <stdio.h>

// Sample user account data (in-memory database)
struct User {
    int accountNumber;
    int pin;
    double balance;
};

// Function to authenticate a user
int authenticateUser(struct User users[], int numUsers, int accountNumber, int pin) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber && users[i].pin == pin) {
            return i; // Return the index of the authenticated user
        }
    }
    return -1; // Return -1 if authentication fails
}

// Function to perform a withdrawal
void withdraw(struct User users[], int userIndex, double amount) {
    if(amount>users[userIndex].balance){
        printf("insufficient balance.\n");
    }
    else if (amount > 0 && users[userIndex].balance >= amount) {
        users[userIndex].balance -= amount;
        printf("Withdrawal successful.\n New balance: %.2f\n", users[userIndex].balance);
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

// Function to perform a deposit
void deposit(struct User users[], int userIndex, double amount) {
    if (amount > 0) {
        users[userIndex].balance += amount;
        printf("Deposit successful. New balance: %.2f\n", users[userIndex].balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

// Function to check the balance
double checkBalance(struct User users[], int userIndex) {
    return users[userIndex].balance;
}

int main() {
    // Sample user data
    struct User users[] = {
        {12345, 1111, 1000.0},
        {54321, 2222, 500.0},
    };
    
    int numUsers = sizeof(users) / sizeof(users[0]);

    int accountNumber, pin;
    int userIndex;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    userIndex = authenticateUser(users, numUsers, accountNumber, pin);

    if (userIndex != -1) {
        printf("Authentication successful!\n");
        int choice;
        double amount;

        while (1) {
            printf("\n1. Withdraw\n2. Deposit\n3. Check Balance\n4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter withdrawal amount: ");
                    scanf("%lf", &amount);
                    withdraw(users, userIndex, amount);
                    break;
                case 2:
                    printf("Enter deposit amount: ");
                    scanf("%lf", &amount);
                    deposit(users, userIndex, amount);
                    break;
                case 3:
                    printf("Your balance: %.2f\n", checkBalance(users, userIndex));
                    break;
                case 4:
                    printf("Goodbye!\n");
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    } else {
        printf("Authentication failed. Please check your account number and PIN.\n");
    }

    return 0;
}
