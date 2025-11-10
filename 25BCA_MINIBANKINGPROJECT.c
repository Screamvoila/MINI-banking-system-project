#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int acc_no;
    char name[50];
    float balance;
};

struct account acc[100];
int count = 0;

void create_account() {
    printf("\n--- Create Account ---\n");

    printf("Enter account number: ");
    scanf("%d", &acc[count].acc_no);
    getchar();  // clear leftover newline

    printf("Enter name: ");
    fgets(acc[count].name, sizeof(acc[count].name), stdin);
    acc[count].name[strcspn(acc[count].name, "\n")] = '\0';

    printf("Enter initial balance: ");
    scanf("%f", &acc[count].balance);

    count++;
    printf("Account created successfully!\n");
}

void deposit() {
    int num, i;
    float amt;
    printf("\nEnter account number: ");
    scanf("%d", &num);

    for(i = 0; i < count; i++) {
        if(acc[i].acc_no == num) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amt);
            acc[i].balance += amt;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int num, i;
    float amt;

    printf("\nEnter account number: ");
    scanf("%d", &num);

    for(i = 0; i < count; i++) {
        if(acc[i].acc_no == num) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amt);

            if(amt <= acc[i].balance) {
                acc[i].balance -= amt;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void display_account() {
    int num, i;
    printf("\nEnter account number: ");
    scanf("%d", &num);

    for(i = 0; i < count; i++) {
        if(acc[i].acc_no == num) {
            printf("\n--- Account Details ---\n");
            printf("Account Number: %d\n", acc[i].acc_no);
            printf("Name: %s\n", acc[i].name);
            printf("Balance: %.2f\n", acc[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void display_all() {
    int i;
    printf("\n--- All Accounts ---\n");

    if(count == 0) {
        printf("No accounts available.\n");
        return;
    }

    for(i = 0; i < count; i++) {
        printf("\nAccount Number: %d", acc[i].acc_no);
        printf("\nName: %s", acc[i].name);
        printf("\nBalance: %.2f\n", acc[i].balance);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n===== MINI BANKING SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create_account(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: display_account(); break;
            case 5: display_all(); break;
            case 6: 
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
