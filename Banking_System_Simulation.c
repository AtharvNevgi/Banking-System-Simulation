#include<stdio.h>
#include<stdlib.h>

// Structure to represent an account
struct Account {
    int accountNumber;
    char accountHolder[50];
    double balance;
};

// Function to create a new account
void createAccount(struct Account *accounts, int *numAccounts) {
    printf("Enter account holder's name: ");
    scanf("%s", accounts[*numAccounts].accountHolder);

    accounts[*numAccounts].accountNumber = *numAccounts + 1;
    accounts[*numAccounts].balance = 0;

    (*numAccounts)++;
    printf("Account created successfully. Account number: %d\n", *numAccounts);
}

// Function to deposit amount into an account
void deposit(struct Account *accounts, int numAccounts, int accountNumber, double amount) {
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        accounts[accountNumber - 1].balance += amount;
        printf("Deposit successful. New balance: %.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to withdraw amount from an account
void withdraw(struct Account *accounts, int numAccounts, int accountNumber, double amount) {
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        if (accounts[accountNumber - 1].balance >= amount) {
            accounts[accountNumber - 1].balance -= amount;
            printf("Withdrawal successful. New balance: %.2f\n", accounts[accountNumber - 1].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to check account balance
void checkBalance(struct Account *accounts, int numAccounts, int accountNumber) {
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        printf("Account Holder: %s\n", accounts[accountNumber - 1].accountHolder);
        printf("Account Number: %d\n", accounts[accountNumber - 1].accountNumber);
        printf("Account Balance: %.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

int main() {
    struct Account accounts[10]; // Maximum 10 accounts
    int numAccounts = 0;

    int choice, accountNumber;
    double amount;

    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Select option from above: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(accounts, numAccounts, accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(accounts, numAccounts, accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                checkBalance(accounts, numAccounts, accountNumber);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                
                
        }
    }

    return 0;
}
