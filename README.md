# Atm-project
This C program is an ATM (Automated Teller Machine) simulation that allows users to perform various banking operations such as account creation, deposit, withdrawal, balance check, and account display. Here's a breakdown of the key functionalities and components:

1. **Header Files:**
   - The program includes several standard C header files such as `stdio.h`, `stdlib.h`, `conio.h`, and `windows.h` for input/output operations, memory allocation, console input/output, and Windows-specific functions, respectively.

2. **Color Constants:**
   - ANSI escape codes are used to define color constants for styling output messages in the console. These constants are used to print messages in different colors such as red, green, yellow, blue, magenta, and cyan for better user interface.

3. **User and ATM Structs:**
   - The program defines two structs: `User` and `ATM`.
   - The `User` struct stores user credentials (userID and password).
   - The `ATM` struct represents ATM account details (account number, account holder name, age, amount, city, and account type).

4. **Global Constants and Arrays:**
   - Global constants and arrays are defined to set the maximum number of users (`MAX_USERS`) and the number of accounts (`numberOfAccount`).
   - Arrays of `User` and `ATM` structs are declared to store user and account information, respectively.

5. **Function Prototypes:**
   - Function prototypes are declared for functions used in the program such as `authenticateUser`, `design`, `createAcc`, `dispAcc`, `depositAmt`, `withdrawBalance`, `checkBalance`, `pin`, `saveDataToFile`, `readDataFromFile`, and `displayTime`.

6. **Main Function:**
   - The `main` function is the entry point of the program.
   - It reads data from a file using `readDataFromFile` function and authenticates users using `authenticateUser` function.
   - It displays the ATM menu using the `design` function and performs operations based on user input.

7. **Functions:**
   - Various functions are defined to perform specific tasks:
     - `authenticateUser`: Authenticates users by verifying their credentials.
     - `design`: Displays the ATM menu design.
     - `createAcc`: Allows users to create ATM accounts.
     - `dispAcc`: Displays account details for a given account number.
     - `depositAmt`: Allows users to deposit money into their accounts.
     - `withdrawBalance`: Allows users to withdraw money from their accounts.
     - `checkBalance`: Allows users to check the balance of their accounts.
     - `pin`: Allows users to enter their PIN securely.
     - `saveDataToFile`: Saves account data to a file.
     - `readDataFromFile`: Reads account data from a file.
     - `displayTime`: Displays the current system time.

8. **File Handling:**
   - The program uses file handling functions (`fopen`, `fprintf`, `fscanf`, and `fclose`) to read account data from a file (`account_data.txt`) and save account data to the file.

Overall, this C program provides basic ATM functionalities and demonstrates concepts such as user authentication, file handling, and console output styling. However, there are areas for improvement such as error handling, input validation, and more robust security measures for user authentication. Additionally, some functions like `pin` and `displayTime` seem to have syntax errors and may need to be reviewed for correctness.
