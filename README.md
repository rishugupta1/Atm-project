# Atm-project

This C program simulates an ATM system with basic banking functionalities like creating accounts, depositing money, withdrawing money, checking balance, and displaying account details. Let's break down the key components and functionalities of the program:

Authentication Function (authenticateUser()):
This function prompts the user to enter a user ID and password.
It compares the entered credentials with the predefined user IDs and passwords stored in the users array.
If the entered credentials match, it returns the index of the authenticated user in the users array; otherwise, it returns -1.
Main Function:
The main() function serves as the entry point of the program.
It first authenticates the user using the authenticateUser() function.
Upon successful authentication, it presents a menu to the user and prompts for their choice.
Based on the user's choice, it calls corresponding functions to perform the desired banking operations.
Menu Design (design() Function):
This function displays the menu options available to the user.
Account Management Functions:
createAcc(): Allows users to create new accounts by entering account details such as account number, holder's name, age, amount, city, and account type.
dispAcc(): Displays account details based on the provided account number.
depositAmt(): Allows users to deposit money into their accounts.
withdrawBalance(): Allows users to withdraw money from their accounts.
checkBalance(): Allows users to check the balance of their accounts.
File Handling Functions (saveDataToFile() and readDataFromFile()):
saveDataToFile(): Writes account data to a file named "account_data.txt" for persistent storage.
readDataFromFile(): Reads account data from the "account_data.txt" file during program initialization.
Time Display Function (displayTime()):
This function retrieves the current system time and displays it to the user.
Overall, this program provides a basic framework for managing ATM operations using C programming language. It demonstrates fundamental concepts such as user authentication, menu-driven interface, file handling, and basic banking functionalities. However, it's important to note that this program is a simplified simulation and may require further enhancements for real-world use, such as improved error handling, security measures, and additional features
