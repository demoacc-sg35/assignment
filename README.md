# 🏦 FNB Digital Banking System

A Console-Based Banking Application Developed in C++

Welcome to the FNB Digital Banking System, a C++ console application that simulates basic banking operations. The system allows users to securely access their accounts, manage their funds, perform transactions and view their account information.

The project was developed to demonstrate fundamental C++ programming concepts, including functions, conditional statements, loops, input validation and switch-case structures.

---

# 📌 Features

The banking system includes the following functionalities:

## 🔐 1. User Authentication

- Account number and PIN verification.
- Three predefined user accounts.
- Maximum of three login attempts.
- Access restriction after unsuccessful login attempts.

## 💰 2. Deposit Funds

- Allows users to deposit money into their accounts.
- Validates deposit amounts.
- Automatically updates the account balance.
- Prevents zero or negative deposits.

## 💸 3. Withdraw Funds

- Allows users to withdraw money from their accounts.
- Checks available account balances.
- Prevents withdrawals exceeding available funds.
- Automatically updates the remaining balance.

## 🔄 4. Transfer Funds

- Allows users to transfer money between registered accounts.
- Validates beneficiary account numbers.
- Prevents transfers to the user's own account.
- Checks available funds before processing.
- Requires transaction confirmation before completing a transfer.
- Updates both sender and recipient balances.

## 📄 5. Account Information

- Displays the account holder's name.
- Displays the account number.
- Shows the available account balance.

## 🚪 6. Secure Sign Out

- Allows users to safely end their banking session.
- Returns users to the main banking menu.

---

# 👥 Registered Test Accounts

The application currently contains three predefined accounts for testing purposes.

Account Holder| Account Number| PIN| Initial Balance
Daniel| 10000| 1111| R1,000.00
Bruno| 20000| 2222| R2,500.00
Greenwood| 30000| 3333| R5,000.00

Note: These are demonstration accounts. The application does not use a database, and account information is stored directly in the program.

---

# 🛠️ Technologies Used

- Programming Language: C++
- Compiler: Any compatible C++ compiler.
- Libraries:
  - "iostream" – Input and output operations.
  - "iomanip" – Formatting monetary values.
  - "string" – Handling account holder names.
  - "limits" – Managing invalid input.
  - "cmath" – Mathematical operations and validation.

---

# ⚙️ Programming Concepts Demonstrated

This project demonstrates the practical application of several C++ programming concepts:

Concept| Application
Functions| Separating banking operations into reusable functions.
Void Functions| Performing operations such as deposits, withdrawals and transfers.
Conditional Statements| Validating accounts, PINs and transactions.
Switch Statements| Managing the main banking menu.
Do-While Loops| Keeping the banking system running until the user exits.
While Loops| Handling login attempts and input validation.
Input Validation| Preventing invalid entries and incorrect data.
Global Variables| Storing predefined account information and balances.
Return Values| Retrieving account information and validating user credentials.

---

# ▶️ How to Run the Program

1. Download or clone this repository.
2. Open the project using a C++ compatible IDE or code editor.
3. Compile the "main.cpp" file.
4. Run the compiled program.
5. Select an option from the main menu.
6. Use one of the registered test accounts to access the banking system.

Compilation Using G++

g++ main.cpp -o banking

Run the Application

./banking

---

# ⚠️ Limitations

This project is a basic banking simulation developed for educational purposes.

- Account information is predefined in the source code.
- Account balances are not permanently stored.
- Changes to balances are lost when the program terminates.
- The application does not connect to an actual banking system.
- PINs are stored as plain integers and are not encrypted.

---

# 🚀 Future Improvements

Possible improvements for future versions include:

- Adding new user registration.
- Implementing permanent data storage.
- Introducing transaction history.
- Allowing users to change their PINs.
- Adding additional security features.
- Improving the graphical user interface.

---

# 👨‍💻 Developer

Daniel

Developed as a C++ programming project to demonstrate fundamental programming concepts through a practical banking application.

---

# 📜 Disclaimer

This application is an educational project and is not affiliated with, endorsed by, or connected to First National Bank (FNB). It is not intended for real financial transactions.
