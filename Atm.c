#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"


#define MAX_USERS 3

struct User {
    char userID[20];
    char password[20];
};

struct ATM {
    char accNumber[20];
    char accHolderFirstName[25];
    char accHolderLastName[25];
    char accHolderName[50];
    int accHolderAge;
    float amount;
    char city[50];
    char accountType[20];
};

#define numberOfAccount 2
struct ATM A1[numberOfAccount];

struct User users[MAX_USERS] = {
    {"user1", "pass1"},
    {"user2", "pass2"},
    {"user3", "pass3"}
};


int authenticateUser();
void design();
void createAcc();
void dispAcc();
void depositAmt();
void withdrawBalance();
void checkBalance();
int pin();
void saveDataToFile();
void readDataFromFile();
void displayTime();

int main() {
    readDataFromFile();

    int choice;
    system("cls");


    int userIndex = authenticateUser();
    if (userIndex == -1) {
        printf(ANSI_COLOR_RED "Authentication failed. Exiting...\n" ANSI_COLOR_RESET);
        return 1;
    }

    do {
        design();
        displayTime();
        printf(ANSI_COLOR_CYAN "\nEnter your Choice: " ANSI_COLOR_RESET);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAcc();
                saveDataToFile();
                break;
            case 2:
                depositAmt();
                saveDataToFile();
                break;
            case 3:
                withdrawBalance();
                saveDataToFile();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                dispAcc();
                break;
            case 6:
                printf(ANSI_COLOR_YELLOW "\n######Thanks for using ABC ATM#####\n" ANSI_COLOR_RESET);
                saveDataToFile();
                exit(0);
            default:
                printf(ANSI_COLOR_RED "Invalid Choice\n" ANSI_COLOR_RESET);
        }
    } while (choice != 6);

    return 0;
}

int authenticateUser() {
    char userID[20];
    char password[20];

    printf("Enter User ID: ");
    scanf("%s", userID);

    printf("Enter Password: ");
    for (int i = 0; i < sizeof(password) / sizeof(password[0]) - 1; i++) {
        password[i] = getch();
        printf(ANSI_COLOR_CYAN "*");

        if (password[i] == '\r') {
            password[i] = '\0';
            break;
        }
    }


    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].userID, userID) == 0 && strcmp(users[i].password, password) == 0) {
            printf(ANSI_COLOR_GREEN "\nLogin Successful\n" ANSI_COLOR_RESET);
            return i;
        }
    }

    printf(ANSI_COLOR_RED "\nAuthentication failed\n" ANSI_COLOR_RESET);
    return -1;
}

void design() {
    printf("\n" ANSI_COLOR_BLUE "*****Welcome To ABC ATM****\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "----------------------------------------------\n");
    printf("\t 1. Create Account\n");
    printf("\t 2. Deposit Amount\n");
    printf("\t 3. Withdrawal\n");
    printf("\t 4. Check Balance\n");
    printf("\t 5. Display Account Details\n");
    printf("\t 6. Exit\n");
    printf(ANSI_COLOR_MAGENTA "==============================================\n" ANSI_COLOR_RESET);
}




void createAcc() {
    for (int i = 0; i < numberOfAccount; i++) {
        printf("\nEnter Account Number: ");
        scanf("%s", A1[i].accNumber);

        printf("\nEnter Your First Name: ");
        scanf("%s", A1[i].accHolderFirstName);

        printf("\nEnter Your Last Name: ");
        scanf("%s", A1[i].accHolderLastName);

        snprintf(A1[i].accHolderName, sizeof(A1[i].accHolderName), "%s %s", A1[i].accHolderFirstName, A1[i].accHolderLastName);

        printf("\nEnter Your Age: ");
        scanf("%d", &A1[i].accHolderAge);

        printf("\nEnter Your Amount: ");
        scanf("%f", &A1[i].amount);

        printf("\nEnter Your City: ");
        scanf("%s", A1[i].city);

        printf("\nEnter Your Account Type: ");
        scanf("%s", A1[i].accountType);

        printf("\nDo you want to create another account? (1 for Yes, 0 for No): ");
        int createAnother;
        scanf("%d", &createAnother);

        if (createAnother != 1) {
            break;
        }
    }
}

void dispAcc() {
    int found = 0;
    char accountNumber[20];
    printf("Enter Account Number: ");
    scanf("%s", accountNumber);
    printf("\n%-20s%-30s%-10s%-15s%-20s%-20s", "Account Number", "Name", "Age", "Amount", "City", "Account Type");
    for (int i = 0; i < numberOfAccount; i++) {
        if (strcmp(A1[i].accNumber, accountNumber) == 0) {
            printf("\n%-20s%-30s%-10d%-15.2f%-20s%-20s", A1[i].accNumber, A1[i].accHolderName, A1[i].accHolderAge, A1[i].amount, A1[i].city, A1[i].accountType);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n Account not found for the provided Account Number.\n");
    }
}

void depositAmt() {
    char acNo[20];
    int f = 0;
    float depositAmount;

    printf("Enter an Account Number : ");
    scanf("%s", acNo);

    for (int i = 0; i < numberOfAccount; i++) {
        if (strcmp(A1[i].accNumber, acNo) == 0) {
            f = 1;

            printf("Name : %s", A1[i].accHolderName);
            printf("\nEnter an Amount for Deposit :");
            scanf("%f", &depositAmount);
            if (depositAmount <= 0) {
                printf("\nInvalid Amount");
                printf("\nPlease Enter Valid Amount");
            } else {
                A1[i].amount = A1[i].amount + depositAmount;
                printf("\nAmount Deposited Successfully");
                break;
            }
        }
    }

    if (f == 0) {
        printf("\n Invalid Account Number Please Check");
    }
}

void withdrawBalance() {
    char acNo[20];
    int f = 0;
    float withdrawAmount;

    printf("Enter an Account Number : ");
    scanf("%s", acNo);

    for (int i = 0; i < numberOfAccount; i++) {
        if (strcmp(A1[i].accNumber, acNo) == 0) {
            f = 1;

            printf("Name : %s", A1[i].accHolderName);
            printf("\nEnter an Amount for Withdrawal :");
            scanf("%f", &withdrawAmount);
            if (withdrawAmount <= 0) {
                printf("\nInvalid Amount");
                printf("\nPlease Enter Valid Amount");
            } else if (A1[i].amount < withdrawAmount) {
                printf("\nInsufficient Balance");
            } else {
                A1[i].amount = A1[i].amount - withdrawAmount;
                printf("Take Your Cash");
                printf("\nAmount Withdrawn Successfully");
                break;
            }
        }
    }

    if (f == 0) {
        printf("\n Invalid Account Number Please Check");
    }
}

void checkBalance() {
    char acNo[20];
    int f = 0;

    printf("Enter an Account Number : ");
    scanf("%s", acNo);

    for (int i = 0; i < numberOfAccount; i++) {
        if (strcmp(A1[i].accNumber, acNo) == 0) {
            f = 1;

            printf("\nAccount Number: %s", A1[i].accNumber);
            printf("\nAccount Holder Name: %s", A1[i].accHolderName);
            printf("\nBalance : %.2f", A1[i].amount);
        }
    }
    if (f == 0) {
        printf("\n Invalid Account Number Please Check");
    }
}

void saveDataToFile() {
    FILE *file = fopen("account_data.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numberOfAccount; i++) {
            fprintf(file, "%s %s %s %d %.2f %s %s\n", A1[i].accNumber, A1[i].accHolderFirstName, A1[i].accHolderLastName, A1[i].accHolderAge, A1[i].amount, A1[i].city, A1[i].accountType);
        }
        fclose(file);
    } else {
        printf("Error opening file for writing");
    }
}

void readDataFromFile() {
    FILE *file = fopen("account_data.txt", "r");
    if (file != NULL) {
        for (int i = 0; i < numberOfAccount; i++) {
            fscanf(file, "%s %s %s %d %f %s %s", A1[i].accNumber, A1[i].accHolderFirstName, A1[i].accHolderLastName, &A1[i].accHolderAge, &A1[i].amount, A1[i].city, A1[i].accountType);
            snprintf(A1[i].accHolderName, sizeof(A1[i].accHolderName), "%s %s", A1[i].accHolderFirstName, A1[i].accHolderLastName);
        }
        fclose(file);
    }
}

void displayTime() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    printf("\nCurrent Time: %02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
}
