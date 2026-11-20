#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

int accNumber1 = 10000;
int userPin1 = 1111;
string userName1 = "Daniel";
double userBalance1 = 1000;
int accNumber2 = 20000;
int userPin2 = 2222;
string userName2 = "Bruno";
double userBalance2 = 2500;
int accNumber3 = 30000;
int userPin3 = 3333;
string userName3 = "Greenwood";
double userBalance3 = 5000;


// VALIDATE INTEGER
int validInteger(string message)
{
    int number;

    while(true)
    {
        cout<<message;

        if(cin>>number)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout<<"Invalid entry! Please enter a valid number."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// VALIDATE AMOUNT
double validAmount(string message)
{
    double amount;

    while(true)
    {
        cout<<message;

        if(cin>>amount && isfinite(amount))
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }

        cout<<"Invalid amount entered. Please try again."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// USERNAME
string getUserName(int accountNumber)
{
    if(accountNumber == accNumber1)
        return userName1;

    if(accountNumber == accNumber2)
        return userName2;

    if(accountNumber == accNumber3)
        return userName3;

    return "Unknown";
}


// BALANCE
double getUserBalance(int accountNumber)
{
    if(accountNumber == accNumber1)
        return userBalance1;

    if(accountNumber == accNumber2)
        return userBalance2;

    if(accountNumber == accNumber3)
        return userBalance3;

    return 0;
}


// BALANCE
void updateBalance(int accountNumber, double newBalance)
{
    if(accountNumber == accNumber1)
        userBalance1 = newBalance;

    else if(accountNumber == accNumber2)
        userBalance2 = newBalance;

    else if(accountNumber == accNumber3)
        userBalance3 = newBalance;
}


// FUNCTION: SEARCH ACCOUNT
int searchAccount(int accountNumber)
{
    if(accountNumber == accNumber1)
        return 1;

    else if(accountNumber == accNumber2)
        return 2;

    else if(accountNumber == accNumber3)
        return 3;

    else
        return 0;
}


// FUNCTION: VERIFY PIN
bool verifyPin(int accountNumber, int pin)
{
    if(accountNumber == accNumber1 && pin == userPin1)
        return true;

    else if(accountNumber == accNumber2 && pin == userPin2)
        return true;

    else if(accountNumber == accNumber3 && pin == userPin3)
        return true;

    else
        return false;
}


// FUNCTION: BANKING MENU
int bankingMenu()
{
    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<"                    FNB BANK"<<endl;
    cout<<"                 DIGITAL BANKING"<<endl;
    cout<<"================================================"<<endl;
    cout<<"                    MAIN MENU"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"  [1]  Deposit Funds"<<endl;
    cout<<"  [2]  Withdraw Funds"<<endl;
    cout<<"  [3]  Transfer Funds"<<endl;
    cout<<"  [4]  Account Information"<<endl;
    cout<<"  [5]  Sign Out"<<endl;
    cout<<"------------------------------------------------"<<endl;

    return validInteger("Enter your selection: ");
}


// FUNCTION: LOGIN
int login()
{
    int accountNumber;
    int pin;
    int attempts = 3;

    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<"                 FNB BANK"<<endl;
    cout<<"              CUSTOMER ACCESS"<<endl;
    cout<<"================================================"<<endl;

    while(attempts > 0)
    {
        accountNumber = validInteger("Account number: ");
        pin = validInteger("Enter your PIN: ");

        if(searchAccount(accountNumber) != 0 && verifyPin(accountNumber, pin))
        {
            cout<<endl;
            cout<<"------------------------------------------------"<<endl;
            cout<<"          AUTHENTICATION SUCCESSFUL"<<endl;
            cout<<"------------------------------------------------"<<endl;
            cout<<"Good day, "<<getUserName(accountNumber)<<"!"<<endl;
            cout<<"You are now logged into your account."<<endl;
            cout<<"------------------------------------------------"<<endl;

            return accountNumber;
        }

        attempts--;

        cout<<endl;
        cout<<"Access denied! Incorrect login credentials."<<endl;

        if(attempts > 0)
            cout<<"Remaining login attempts: "<<attempts<<endl;
    }

    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<"           ACCOUNT ACCESS RESTRICTED"<<endl;
    cout<<"================================================"<<endl;
    cout<<"You have exceeded the maximum login attempts."<<endl;
    cout<<"Please try again later."<<endl;

    return 0;
}


// FUNCTION: DISPLAY BALANCE
void displayBalance(int accountNumber)
{
    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<"              ACCOUNT INFORMATION"<<endl;
    cout<<"================================================"<<endl;
    cout<<"Account holder     : "<<getUserName(accountNumber)<<endl;
    cout<<"Account number     : "<<accountNumber<<endl;
    cout<<"Available balance  : R"<<fixed<<setprecision(2)<<getUserBalance(accountNumber)<<endl;
    cout<<"================================================"<<endl;
    cout<<"          Thank you for banking with FNB."<<endl;
    cout<<"================================================"<<endl;
}


// FUNCTION: DEPOSIT MONEY
void depositMoney(int accountNumber)
{
    double amount;
    double newBalance;

    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<"                 DEPOSIT FUNDS"<<endl;
    cout<<"================================================"<<endl;

    amount = validAmount("Enter deposit amount: R");

    if(amount <= 0)
    {
        cout<<"Transaction declined. Enter an amount above R0."<<endl;
        return;
    }

    newBalance = getUserBalance(accountNumber) + amount;

    if(!isfinite(newBalance))
    {
        cout<<"Unable to process your deposit at this time."<<endl;
        return;
    }

    updateBalance(accountNumber, newBalance);

    cout<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"             DEPOSIT COMPLETED"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Amount deposited : R"<<fixed<<setprecision(2)<<amount<<endl;
    cout<<"New account balance : R"<<getUserBalance(accountNumber)<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Your funds have been successfully credited."<<endl;
}


// FUNCTION: WITHDRAW MONEY
void withdrawMoney(int accountNumber)
{
    double amount;
    double newBalance;

    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<"                WITHDRAW FUNDS"<<endl;
    cout<<"================================================"<<endl;

    amount = validAmount("Enter withdrawal amount: R");

    if(amount <= 0)
    {
        cout<<"Please enter a withdrawal amount above R0."<<endl;
        return;
    }

    if(amount > getUserBalance(accountNumber))
    {
        cout<<"Transaction declined. Insufficient account balance."<<endl;
        return;
    }

    newBalance = getUserBalance(accountNumber) - amount;

    updateBalance(accountNumber, newBalance);

    cout<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"            WITHDRAWAL SUCCESSFUL"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Amount withdrawn : R"<<fixed<<setprecision(2)<<amount<<endl;
    cout<<"Remaining balance : R"<<getUserBalance(accountNumber)<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Your withdrawal has been processed successfully."<<endl;
}


// FUNCTION: TRANSFER MONEY
void transferMoney(int accountNumber)
{
    int recipientAccount;
    double amount;
    double senderBalance;
    double recipientBalance;
    double newRecipientBalance;
    char confirmation;

    cout<<endl;
    cout<<"================================================"<<endl;
    cout<<"                 TRANSFER FUNDS"<<endl;
    cout<<"================================================"<<endl;

    recipientAccount = validInteger("Enter beneficiary account number: ");

    if(searchAccount(recipientAccount) == 0)
    {
        cout<<"Beneficiary account could not be located."<<endl;
        return;
    }

    if(recipientAccount == accountNumber)
    {
        cout<<"You cannot transfer funds to your own account."<<endl;
        return;
    }

    amount = validAmount("Enter transfer amount: R");

    if(amount <= 0)
    {
        cout<<"Please enter a transfer amount above R0."<<endl;
        return;
    }

    senderBalance = getUserBalance(accountNumber);
    recipientBalance = getUserBalance(recipientAccount);

    if(amount > senderBalance)
    {
        cout<<"Transfer unsuccessful. Insufficient available funds."<<endl;
        return;
    }

    newRecipientBalance = recipientBalance + amount;

    if(!isfinite(newRecipientBalance))
    {
        cout<<"Unable to process this transfer at the moment."<<endl;
        return;
    }

    cout<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"                PAYMENT DETAILS"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"From account : "<<getUserName(accountNumber)<<endl;
    cout<<"Beneficiary  : "<<getUserName(recipientAccount)<<endl;
    cout<<"Account no.  : "<<recipientAccount<<endl;
    cout<<"Amount       : R"<<fixed<<setprecision(2)<<amount<<endl;
    cout<<"------------------------------------------------"<<endl;

    cout<<"Would you like to proceed? (Y/N): ";
    cin>>confirmation;

    if(confirmation == 'Y' || confirmation == 'y')
    {
        updateBalance(accountNumber, senderBalance - amount);
        updateBalance(recipientAccount, newRecipientBalance);

        cout<<endl;
        cout<<"================================================"<<endl;
        cout<<"              PAYMENT SUCCESSFUL"<<endl;
        cout<<"================================================"<<endl;
        cout<<"Your transfer has been completed."<<endl;
        cout<<"Beneficiary : "<<getUserName(recipientAccount)<<endl;
        cout<<"Amount sent : R"<<fixed<<setprecision(2)<<amount<<endl;
        cout<<"New balance : R"<<getUserBalance(accountNumber)<<endl;
        cout<<"================================================"<<endl;
    }

    else
    {
        cout<<endl;
        cout<<"Payment cancelled. No funds were transferred."<<endl;
    }
}


// MAIN FUNCTION
int main()
{
    int choice;
    int accountNumber;

    do
    {
        cout<<endl;
        cout<<"================================================"<<endl;
        cout<<"                                                "<<endl;
        cout<<"                  FNB BANK                      "<<endl;
        cout<<"              FIRST NATIONAL BANK               "<<endl;
        cout<<"                                                "<<endl;
        cout<<"================================================"<<endl;
        cout<<"              WELCOME TO FNB BANKING             "<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"             Your Money. Your Future.            "<<endl;
        cout<<"                                                "<<endl;
        cout<<"             [1]  Access Your Account            "<<endl;
        cout<<"             [2]  Exit Banking                   "<<endl;
        cout<<"                                                "<<endl;
        cout<<"================================================"<<endl;

        choice = validInteger("Select an option to continue: ");

        switch(choice)
        {
            case 1:

                accountNumber = login();

                if(accountNumber != 0)
                {
                    do
                    {
                        choice = bankingMenu();

                        switch(choice)
                        {
                            case 1:
                                depositMoney(accountNumber);
                                break;

                            case 2:
                                withdrawMoney(accountNumber);
                                break;

                            case 3:
                                transferMoney(accountNumber);
                                break;

                            case 4:
                                displayBalance(accountNumber);
                                break;

                            case 5:
                                cout<<endl;
                                cout<<"================================================"<<endl;
                                cout<<"                 SESSION ENDED"<<endl;
                                cout<<"================================================"<<endl;
                                cout<<"You have safely signed out of your account."<<endl;
                                cout<<"Thank you for choosing FNB Banking."<<endl;
                                cout<<"================================================"<<endl;
                                break;

                            default:
                                cout<<"Invalid selection. Please choose an option from 1 to 5."<<endl;
                        }
                    }
                    while(choice != 5);
                }

                break;


            case 2:

                cout<<endl;
                cout<<"================================================"<<endl;
                cout<<"              THANK YOU FOR BANKING"<<endl;
                cout<<"================================================"<<endl;
                cout<<"Thank you for choosing FNB."<<endl;
                cout<<"Have a wonderful day!"<<endl;
                cout<<"================================================"<<endl;

                break;


            default:

                cout<<"Invalid selection. Please select 1 or 2."<<endl;
        }

    }
    while(choice != 2);

    return 0;
}