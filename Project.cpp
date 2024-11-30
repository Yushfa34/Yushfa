#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

bool hasSpecialCharacters(const string &str)

// check if a string of username contains any special characters
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= '0' && str[i] <= '9')))
        {
            return true;
        }
    }
    return false;
}

bool isValidPasswordLength(const string &pass)

//  check password length
{
    int length = 0;
    while (pass[length] != '\0')
    {
        length++;
    }
    return length <= 8;
}
/*
void printColored(const string &text, const string &color_code)

// Function to print colored text
{
    cout << "\033[" << color_code << "m" << text << "\033[0m" << endl;
}*/

// Function to load data into arrays

void loadData(string item[], int price[], int &count)
{
    ifstream inFile("items.txt");
    if (inFile)
    {
        count = 0;
        // Initialize count
        while (inFile >> item[count] >> price[count])
        {
            // Read item and price
            count++;
        }
    }
    else
    {
        cout << "No item found." << endl;
    }
}

// Function to store data (cart details and quantities)

void storeData(string cart[], int cartQuantity[], int &cartCount)
{
    ofstream outFile("saveitem.txt");
    if (outFile)
    {
        if (cartCount == 0)
        {
            cout << "Cart is empty!" << endl;
        }
        else
        {
            cout << "Storing Cart Data:" << endl;
            for (int i = 0; i < cartCount; i++)
            {
                cout << cart[i] << " x " << cartQuantity[i] << endl;
            }
        }
    }
    else
    {
        cout << "Can't store item." << endl;
    }
}

// Function to load user name from file

void loadUserName(string &userName)
{
    ifstream inFile("credentials.txt");
    if (inFile)
    {
        // Read the username from the file
        getline(inFile, userName);
        cout << "Welcome back, " << userName << "!" << endl;
    }
    else
    {
        cout << "No previous username found." << endl;
        cout << "Please enter your name: ";
        cin >> userName;

        // Store the username to the file
        string storeUserName(userName);
    }
}

// Function to store user name to file

void storeCredentials(const string &userName, const string &password)
{
    ofstream outFile("credentials.txt");
    if (outFile)
    {
        // Write the username and password to the file
        outFile << "Username: " << userName << endl;
        outFile << "Password: " << password << endl;
        cout << "Credentials stored successfully!" << endl;
    }
    else
    {
        cout << "Error storing credentials!" << endl;
    }
}
int main()
{
    const int usize = 100;
    bool uFlag[usize] = {false};
    string username[usize]; // Array to store user id names
    string password[usize]; // Array to store id passwords
    int searchType = -10;
    int input;
    int count = 0;
    const int size = 1000;
    string item[size] = {"NV"}; // Array to store items in store
    int price[size];            // Array to store prices
    string userName;
    string passWord;
    bool userSearchFlag = false; // Flag to check if user exists
    string cart[size];           // Cart for user purchases
    int cartCount = 0;           // Cart item counter
    int cartQuantity[size];      // Array to store quantities of items in the cart

    // Program Header
    cout << "\033[1;34m                          ___                        ___              \033[0m" << endl;
    cout << "\033[1;34m                         (   )                      (   )             \033[0m" << endl;
    cout << "\033[1;32m  .--.     ___ .-.     .-.|  |    .--.     ___ .-.   | |  ___    ___  \033[0m" << endl;
    cout << "\033[1;32m /     \\ (   )   \\  /  \\  |   /   \\   (    ) \\  | | (    ) (   ) \033[0m" << endl;
    cout << "\033[1;36m|  .-.  ;  | ' .-. ;  |  .-. |  |  .-. ;  | ' .-. ;  | |  |  |   | |  \033[0m" << endl;
    cout << "\033[1;36m| |   | |  |  / (___) | |  | |  |  | | |  |  / (___) | |  |  |   | |  \033[0m" << endl;
    cout << "\033[1;31m| |   | |  | |        | |  | |  |  |/  |  | |        | |  |  '   | |  \033[0m" << endl;
    cout << "\033[1;31m| |   | |  | |        | |  | |  |  ' _.'  | |        | |  '   ` -' |  \033[0m" << endl;
    cout << "\033[1;35m| |   | |  | |        | '  | |  |  .'.-.  | |        | |   `.__.   |  \033[0m" << endl;
    cout << "\033[1;35m'  `-'  /  | |        ' `-'  /  '  `-' /  | |        | |   ___ |   |  \033[0m" << endl;
    cout << "\033[1;33m `.__ .'  (___)        `.__,'    `.__.'  (___)      (___) (   )'   |  \033[0m" << endl;
    cout << "\033[1;33m                                                          ; `-'    '  \033[0m" << endl;
    cout << "\033[1;33m                                                           . __ . '   \033[0m" << endl;
    // Load user data from file
    ifstream userFile("credentials.txt");
    if (userFile)
    {
        int i = 0;
        while (userFile >> username[i] >> password[i])
        {
            uFlag[i] = true;
            i++;
        }
        userFile.close();
    }

    // Load items data from file
    ifstream itemFile("items.txt");
    if (itemFile)
    {
        int i = 0;
        while (itemFile >> item[i] >> price[i])
        {
            i++;
        }
        count = i;
        itemFile.close();
    }
    do
    {
        cout << endl;
        cout << "\033[1;34m**************************Choose your desired option*******************************\033[0m" << endl;
        cout << "1. Management login" << endl;
        cout << "2. User login" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "\033[1;33m----Choose an option: \033[0m";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Enter the username: ";
            cin >> userName;
            cout << "Enter your password: ";
            cin >> passWord;

            if (userName == "Management" && passWord == "123shopping")
            {
                searchType = 1;
            }
            else
                searchType = -1;

            break;

        case 2:
        {
            cout << "Enter the username: ";
            cin >> userName;
            cout << "Enter your password: ";
            cin >> passWord;

            if (hasSpecialCharacters(userName))
            {
                cout << "\033[1;31mInvalid username! Username should not contain special characters.\033[0m" << endl;
                break;
            }

            if (!isValidPasswordLength(passWord))
            {
                cout << "\033[1;31mInvalid password! Password should not exceed 8 characters.\033[0m" << endl;
                break;
            }

            bool userFound = false;
            // Search for existing users
            for (int i = 0; i < usize; ++i)
            {
                if (username[i] == userName && password[i] == passWord)
                {
                    searchType = 2;
                    userFound = true;
                    break;
                }
            }
            if (!userFound)
            {
                searchType = -1;
                cout << "\033[1;31mInvalid Credentials!\033[0m" << endl;
            }
            break;
        }
        case 0:
        {
            searchType = 0;
            cout << "Thank you!";
            break;
        }
        default:
            cout << "\033[1;31mInvalid Choice!\033[0m";
            break;
        }
        if (searchType == 0)
        {
            cout << "Thank You!";
            break;
        }
        else if (searchType == 1)
        {
            do
            {
                cout << endl;
                cout << "\033[1;33m-----------Welcome to the Management menu-----------\033[0m" << endl;
                cout << "\033[1;34m**************************Choose your desired option*******************************\033[0m" << endl;

                cout << endl;
                cout << "1. Add item " << endl;
                cout << "2. Edit item" << endl;
                cout << "3. Delete item" << endl;
                cout << "4. Show List" << endl;

                cout << "5. Add User" << endl;
                cout << "6. Edit user" << endl;
                cout << "7. Delete user" << endl;
                cout << "8. Show user List" << endl;

                cout << "0. Logout" << endl;
                cout << endl;
                cout << "\033[1;33m-----Choose an option: \033[0m";
                cin >> input;
                switch (input)
                {
                case 1:
                {
                    cin.ignore(256, '\n');
                    cout << "Enter the Grocery item: ";
                    getline(cin, item[count]);
                    cout << "Enter the Price (Rs): ";
                    cin >> price[count];
                    count++;

                    ofstream outFile("items.txt");
                    if (outFile)
                    {
                        outFile << item[count - 1] << " " << price[count - 1] << endl;
                        outFile.close();
                    }
                    cout << "\033[1;32mItem added successfully.\033[0m";
                    break;
                }
                case 2:
                {
                    int updateIndex;
                    cout << "Items List: " << endl;
                    for (int i = 0; i < count; i++)
                    {
                        cout << i + 1 << ". " << item[i] << " - Rs " << price[i] << endl;
                    }
                    cout << "Choose an item to update: ";
                    cin >> updateIndex;
                    if (updateIndex > 0 && updateIndex <= count)
                    {
                        cout << "Enter updated item name: ";
                        cin >> item[updateIndex - 1];
                        cout << "Enter updated price: ";
                        cin >> price[updateIndex - 1];
                        ofstream outFile("items.txt");
                        for (int i = 0; i < count; i++)
                        {
                            outFile << item[i] << " " << price[i] << endl;
                        }
                        cout << "\033[1;32mItem updated successfully.\033[0m" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31mInvalid choice.\033[0m" << endl;
                    }
                    break;
                }
                case 3:
                {
                    int deleteIndex;
                    cout << "Items List:" << endl;
                    for (int i = 0; i < count; i++)
                    {
                        cout << i + 1 << ". " << item[i] << " - Rs " << price[i] << endl;
                    }
                    cout << "Choose an item to delete: ";
                    cin >> deleteIndex;
                    if (deleteIndex > 0 && deleteIndex <= count)
                    {
                        for (int i = deleteIndex - 1; i < count - 1; i++)
                        {
                            item[i] = item[i + 1];
                            price[i] = price[i + 1];
                        }
                        count--;
                        ofstream outFile("items.txt");
                        for (int i = 0; i < count; i++)
                        {
                            outFile << item[i] << " " << price[i] << endl;
                        }
                        cout << "\033[1;32mItem deleted successfully.\033[0m" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31mInvalid choice.\033[0m" << endl;
                    }
                    break;
                }
                case 4:
                {
                    cout << "Items List:" << endl;
                    for (int i = 0; i < count; i++)
                    {
                        cout << i + 1 << ". " << item[i] << " - Rs " << price[i] << endl;
                    }
                    break;
                }
                case 5:
                {
                    string newUsername, newPassword;

                    bool userExists = false;

                    cout << "Enter New Username: ";
                    getline(cin, newUsername);
                    cout << "Enter New Password: ";
                    getline(cin, newPassword);

                    if (hasSpecialCharacters(newUsername)) // Check if the username has special characters
                    {
                        cout << "\033[1;31mInvalid username!\033[0m" << endl;
                        cout << " Username should not contain special characters." << endl;
                        break;
                    }

                    if (!isValidPasswordLength(newPassword)) // Check if the password length is valid (8 characters)
                    {
                        cout << "\033[1;31mInvalid password!\033[0m" << endl;
                        cout << " Password should not exceed 8 characters." << endl;
                        break;
                    }

                    string userName, password;

                    storeCredentials(userName, password);

                    break;
                }
                case 6:
                {
                    string editUsername;
                    bool userFound = false;
                    cout << "Enter the username of the user to edit: ";
                    cin >> editUsername;
                    for (int i = 0; i < count; ++i)
                    {
                        if (username[i] == editUsername)
                        {
                            userFound = true;
                            cout << "User found! You can now edit their details." << endl;
                            string newUsername, newPassword;
                            cout << "Enter new username: ";
                            cin >> newUsername;
                            cout << "Enter new password: ";
                            cin >> newPassword;
                            username[i] = newUsername;
                            password[i] = newPassword;

                            cout << "\033[1;32mUser updated successfully!\033[0m" << endl;
                            break;
                            storeCredentials(userName, passWord);
                        }
                    }

                    if (!userFound)
                    {
                        cout << "\033[1;31mUser not found!\033[0m" << endl;
                    }
                    break;
                }

                case 7:
                {
                    string deleteUsername;
                    bool userFound = false;
                    cout << "Enter the username of the user to delete: ";
                    cin >> deleteUsername;
                    for (int i = 0; i < count; ++i)
                    {
                        if (username[i] == deleteUsername)
                        {
                            userFound = true;
                            for (int j = i; j < count - 1; ++j)
                            {
                                username[j] = username[j + 1];
                                password[j] = password[j + 1];
                            }
                            count--;
                            cout << "\033[1;32mUser deleted successfully!\033[0m" << endl;
                            storeCredentials(userName, passWord);
                            break;
                        }
                    }

                    if (!userFound)
                    {
                        cout << "\033[1;31mUser not found!\033[0m" << endl;
                    }
                    break;
                }

                case 8:
                {
                    cout << "Users List:" << endl;
                    for (int i = 0; i < count; i++)
                    {
                        cout << i + 1 << ". " << username[i] << endl;
                    }
                    break;
                }
                case 0:
                    searchType = -10;
                    cout << "You have logged out!!!";
                    break;
                default:
                    cout << "\033[1;31mInvalid Choice!\033[0m";
                    break;
                }
            } while (searchType == 1);
        }
        else if (searchType == 2)
        {
            do
            {
                cout << endl;
                cout << "\033[1;33m------------Welcome to the User menu------------\033[0m" << endl;
                cout << "\033[1;34m**************************Choose your desired option*******************************\033[0m" << endl;
                cout << endl;
                cout << "1. Buy item" << endl;
                cout << "2. Show Cart" << endl;
                cout << "3. Remove Item from Cart" << endl;
                cout << "4. View Cart"<< endl;

                cout << "5. Total bill" << endl;
                cout << "6. Confirm Purchase" << endl;
                cout << "0. Logout" << endl;
                cout << endl;
                cout << "\033[1;33m-----Choose an option: \033[0m";
                cin >> input;

                switch (input)
                {
                case 1:
                {
                    int buyItem;
                    cout << "Items List:" << endl;
                    for (int i = 0; i < count; i++)
                    {
                        cout << i + 1 << ". " << item[i] << " - Rs " << price[i] << endl;
                    }
                    cout << "Choose an item to buy: ";
                    cin >> buyItem;

                    if (buyItem > 0 && buyItem <= count)
                    {
                        cart[cartCount] = item[buyItem - 1];
                        cartQuantity[cartCount] = 1;
                        cartCount++;
                        cout << "Item added to cart!" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31m Invalid item number! \033[0m" << endl;
                    }
                    break;
                }
                case 2:
                {
                    loadData(cart, cartQuantity, cartCount);
                    cout << "Your Cart:" << endl;
                    for (int i = 0; i < cartCount; i++)
                    {
                        cout << cart[i] << " x " << cartQuantity[i] << endl;
                    }
                    break;
                }
                case 3:
                {
                    int removeIndex;
                    cout << "Your Cart:" << endl;
                    for (int i = 0; i < cartCount; i++)
                    {
                        cout << i + 1 << ". " << cart[i] << " x " << cartQuantity[i] << endl;
                    }
                    cout << "Choose an item to remove from cart: ";
                    cin >> removeIndex;
                    if (removeIndex > 0 && removeIndex <= cartCount)
                    {
                        for (int i = removeIndex - 1; i < cartCount - 1; i++)
                        {
                            cart[i] = cart[i + 1];
                            cartQuantity[i] = cartQuantity[i + 1];
                        }
                        cartCount--;
                        cout << "Item removed from cart!" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31mInvalid item number!\033[0m" << endl;
                    }
                    // Store updated cart data to file
                    storeData(cart, cartQuantity, cartCount);
                    break;
                }
                case 4:
                {
                    loadData(cart, cartQuantity, cartCount);
                    if (cartCount == 0)
                    {
                        cout << "\033[1;31mYour cart is empty!\033[0m" << endl;
                    }
                    else
                    {
                        cout << "Cart:" << endl;
                        for (int i = 0; i < cartCount; i++)
                        {
                            cout << cart[i] << " x" << cartQuantity[i] << endl;
                        }
                    }
                    break;
                }
                case 5:
                {
                    int totalBill = 0;
                    for (int i = 0; i < cartCount; i++)
                    {
                        for (int j = 0; j < count; j++)
                        {
                            if (cart[i] == item[j])
                            {
                                totalBill += price[j] * cartQuantity[i];
                            }
                        }
                    }
                    cout << "Total Bill (Rs): " << totalBill << endl;
                    break;
                }
                case 6:
                {
                    if (cartCount > 0)
                    {
                        cout << "\033[1;32mPurchase Confirmed!\033[0m" << endl;

                        // Clear cart after purchase
                        cartCount = 0;

                        // Update cart data in file
                        storeData(cart, cartQuantity, cartCount);
                    }
                    else
                    {
                        cout << "\033[1;31mYour cart is empty!!! Add items before confirming purchase!\033[0m" << endl;
                    }
                    break;
                }
                case 0:
                {
                    cout << "Thank you for using the user system!" << endl;
                    searchType = 0;
                    break;
                }
                default:
                    cout << "\033[1;33mInvalid choice!\033[0m" << endl;
                    break;
                }
            } while (searchType != 0);
        }
    } while (searchType != 0);

    return 0;
}
