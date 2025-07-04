#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream> // For file operations

using namespace std;

void MainMenu();
int Choice;
bool cinfall;
int Confirmation;
string Username, Password1, Password2;

void writetofile(string Username)
{
    ofstream writefile;
    string filename = Username + ".txt";
    writefile.open(filename.c_str());
    writefile << Password1 << endl;
    writefile.close();
    MainMenu();
}

void Login()
{
    cout << "WELCOME!!! You are being logged in." << endl;
}

void RegisterPassword()
{
    cout << "Please enter your password: ";
    cin >> Password1;
    cout << "Please re-enter your password: ";
    cin >> Password2;

    if (Password1 == Password2)
    {
        cout << "Password confirmed." << endl;
        writetofile(Username);
    }
    else
    {
        cout << "Passwords do not match. Please try again." << endl;
        RegisterPassword();
    }
}

void RegisterUser()
{
    cout << "Please enter your username: ";
    cin.ignore(); // Clear the input buffer before getline
    getline(cin, Username);
    cout << "\nUsername: " << Username << endl;
    cout << "If your Username is correct, please enter 1 to confirm or 0 to re-enter: ";
    cin >> Confirmation;

    if (Confirmation == 1)
    {
        RegisterPassword();
    }
    else if (Confirmation == 0)
    {
        RegisterUser();
    }
    else
    {
        cout << "Invalid input. Please try again." << endl;
        RegisterUser();
    }
}

void Exit()
{
    cout << "Exiting the program. Goodbye!" << endl;
    exit(0);
}

void MainMenu()
{
    cout << "How may I assist you Today: ";
    cout << "\n1. Login" << endl;
    cout << "\n2. Register" << endl;
    cout << "\n3. Exit\n"
         << endl;

    cin >> Choice;

    // Check for input failure
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n'); // Clear the input buffer
        cout << "Invalid input. Please try again." << endl;
        MainMenu();
        return; // Exit the function to avoid executing the switch
    }

    switch (Choice)
    {
    case 1:
        Login();
        break;
    case 2:
        RegisterUser();
        break;
    case 3:
        Exit();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        MainMenu();
        break;
    }
}

int main()
{
    cout << "\nWelcome to Login and Registration System!\n"
         << endl;
    MainMenu();
    return 0;
}
