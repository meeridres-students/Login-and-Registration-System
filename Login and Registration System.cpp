
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool registerUser()
{
    string username, password;
    string savedUser, savedPass;

    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (username.length() < 3 || password.length() < 6)
    {
        cout << "Username must have 3 characters "
             << "and password 6 characters minimum.\n";
        return false;
    }

    ifstream readFile("users.txt");

    while (readFile >> savedUser >> savedPass)
    {
        if (savedUser == username)
        {
            cout << "Username already exists!\n";
            readFile.close();
            return false;
        }
    }

    readFile.close();

    ofstream writeFile("users.txt", ios::app);

    if (!writeFile)
    {
        cout << "File could not be opened!\n";
        return false;
    }

    writeFile << username << " " << password << endl;

    writeFile.close();

    cout << "Registration successful!\n";

    return true;
}

bool loginUser()
{
    string username, password;
    string savedUser, savedPass;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream readFile("users.txt");

    while (readFile >> savedUser >> savedPass)
    {
        if (savedUser == username && savedPass == password)
        {
            readFile.close();

            cout << "\nLogin successful!\n";
            cout << "Welcome, " << username << "!\n";

            return true;
        }
    }

    readFile.close();

    cout << "\nInvalid username or password!\n";

    return false;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
