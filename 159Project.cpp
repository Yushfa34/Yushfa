#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struct definitions
struct Item
{
    string name;
    int price;
};

struct User
{
    string username;
    string password;
    bool active;
};

struct CartItem
{
    Item item;
    int quantity;

    // Function to get the total price for this CartItem
    int getTotalPrice() const
    {
        return item.price * quantity;
    }
};

bool hasSpecialCharacters(const string &str);
bool isValidPasswordLength(const string &pass);
void saveUsers(User users[], int count);
void saveItems(Item items[], int count);
void displayItems(Item items[], int count);
void addToCart(CartItem cart[], int &cartCount, Item items[], int itemIndex);
void displayCart(CartItem cart[], int cartCount);
void removeFromCart(CartItem cart[], int &cartCount, int index);
int calculateTotalBill(CartItem cart[], int cartCount);
void confirmPurchase(CartItem cart[], int &cartCount);
bool adminLogin(string &username, string &password);

int main()
{
    const int maxItems = 100;
    const int maxUsers = 100;
    const int maxCartItems = 50;
    int searchType = -10;
    Item items[maxItems];
    User users[maxUsers];
    CartItem cart[maxCartItems];

    int itemCount = 0, userCount = 0, cartCount = 0;

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

    // Read items from file
    ifstream itemFile("items.txt");
    if (itemFile)
    {
        while (itemFile >> items[itemCount].name >> items[itemCount].price)
        {
            itemCount++;
        }
        itemFile.close();
    }
    else
    {
        cout << "No items file found. Using default items." << endl;
        items[itemCount++] = {"Milk", 50};
        items[itemCount++] = {"Bread", 40};
        items[itemCount++] = {"Eggs", 120};
        items[itemCount++] = {"Rice", 90};
    }

    // Read users from file
    ifstream userFile("credentials.txt");
    if (userFile)
    {
        while (userFile >> users[userCount].username >> users[userCount].password)
        {
            users[userCount].active = true;
            userCount++;
        }
        userFile.close();
    }
    else
    {
        cout << "No users file found. Using default users." << endl;
    }

    string username, password;
    do
    {
        // Main login loop
        int input;
        cout << "\033[1;34m**************************Choose your desired option*******************************\033[0m" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. User Login" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "\033[1;33m----Choose an option: \033[0m";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Enter the username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (username == "Management" && password == "123shopping")
            {
                searchType = 1;
            }
            else
                searchType = -1;

            break;

        case 2:
        {
            cout << "Enter the username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (hasSpecialCharacters(username))
            {
                cout << "\033[1;31mInvalid username! Username should not contain special characters.\033[0m" << endl;
                break;
            }

            if (!isValidPasswordLength(password))
            {
                cout << "\033[1;31mInvalid password! Password should not exceed 8 characters.\033[0m" << endl;
                break;
            }

            bool userFound = false;
            // Search for existing users
            for (int i = 0; i < userCount; ++i)
            {
                if (users[i].username == username && users[i].password == password)
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
            cout << "Thank You!" << endl;
        }
        else if (searchType == 1)
        {

            int choice;
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
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    // Add new item
                    string itemName;
                    int itemPrice;
                    cout << "Enter item name: ";
                    cin >> itemName;
                    cout << "Enter item price: ";
                    cin >> itemPrice;
                    items[itemCount].name = itemName;
                    items[itemCount].price = itemPrice;
                    itemCount++;
                    saveItems(items, itemCount);
                    cout << "Item added successfully!" << endl;
                    break;
                }
                case 2:
                {
                    // Edit item
                    int editIndex;
                    cout << "Enter the item number to edit: ";
                    cin >> editIndex;
                    if (editIndex > 0 && editIndex <= itemCount)
                    {
                        cout << "Enter new name for the item: ";
                        cin >> items[editIndex - 1].name;
                        cout << "Enter new price for the item: ";
                        cin >> items[editIndex - 1].price;
                        saveItems(items, itemCount);
                        cout << "Item updated successfully!" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31mInvalid item number.\033[0m" << endl;
                    }
                    break;
                }
                case 3:
                {
                    // Delete item
                    int delIndex;
                    cout << "Enter item number to delete: ";
                    cin >> delIndex;
                    if (delIndex > 0 && delIndex <= itemCount)
                    {
                        for (int i = delIndex - 1; i < itemCount - 1; i++)
                        {
                            items[i] = items[i + 1];
                        }
                        itemCount--;
                        saveItems(items, itemCount);
                        cout << "Item deleted successfully!" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31mInvalid item number.\033[0m" << endl;
                    }
                    break;
                }
                case 4:
                {
                    // Show item list
                    cout << "\033[1;32mItem List:\033[0m" << endl;
                    displayItems(items, itemCount);
                    break;
                }
                case 5:
                {
                    // Add user
                    string newUsername, newPassword;
                    cout << "Enter new username: ";
                    cin >> newUsername;
                    cout << "Enter new password: ";
                    cin >> newPassword;

                    users[userCount].username = newUsername;
                    users[userCount].password = newPassword;
                    users[userCount].active = true;
                    userCount++;
                    saveUsers(users, userCount);
                    cout << "User added successfully!" << endl;
                    break;
                }
                case 6:
                {
                    // Edit user
                    string editUserName;
                    cout << "Enter username to edit: ";
                    cin >> editUserName;

                    for (int i = 0; i < userCount; ++i)
                    {
                        if (users[i].username == editUserName)
                        {
                            string newPassword;
                            cout << "Enter new password: ";
                            cin >> newPassword;
                            users[i].password = newPassword;
                            saveUsers(users, userCount);
                            cout << "User password updated successfully!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case 7:
                {
                    // Delete user
                    string delUser;
                    cout << "Enter username to delete: ";
                    cin >> delUser;
                    for (int i = 0; i < userCount; ++i)
                    {
                        if (users[i].username == delUser)
                        {
                            for (int j = i; j < userCount - 1; ++j)
                            {
                                users[j] = users[j + 1];
                            }
                            userCount--;
                            saveUsers(users, userCount);
                            cout << "User deleted successfully!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case 8:
                {
                    // Show user list
                    cout << "\033[1;32mUser List:\033[0m" << endl;
                    for (int i = 0; i < userCount; ++i)
                    {
                        cout << users[i].username << endl;
                    }
                    break;
                }
                case 0:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "\033[1;31mInvalid choice! Please try again.\033[0m" << endl;
                }
            } while (searchType == 1);
        }
        else if (searchType == 2)
        {
            // User functionality
            int userChoice;
            do
            {
                cout << "\033[1;33m-----------Welcome User-----------\033[0m" << endl;
                cout << "\033[1;34m**************************Choose your desired option*******************************\033[0m" << endl;
                cout << "1. View items" << endl;
                cout << "2. Add to cart" << endl;
                cout << "3. View cart" << endl;
                cout << "4. Remove item from cart" << endl;
                cout << "5. Total Bill" << endl;
                cout << "6. Checkout" << endl;
                cout << "0. Logout" << endl;

                cout << "\033[1;33m-----Choose an option: \033[0m";
                cin >> userChoice;

                switch (userChoice)
                {
                case 1:
                    displayItems(items, itemCount);
                    break;
                case 2:
                {
                    int itemIndex, quantity;
                    cout << "Enter item number to add to cart: ";
                    cin >> itemIndex;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    if (itemIndex > 0 && itemIndex <= itemCount)
                    {
                        addToCart(cart, cartCount, items, itemIndex - 1);
                        cout << "Item added to cart!" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31mInvalid item number.\033[0m" << endl;
                    }
                    break;
                }

                case 3:
                    displayCart(cart, cartCount);
                    break;

                case 4:
                {
                    int index;
                    cout << "Enter index of item to remove from cart: ";
                    cin >> index;
                    if (index >= 0 && index < cartCount)
                    {
                        removeFromCart(cart, cartCount, index);
                        cout << "Item removed from cart!" << endl;
                    }
                    else
                    {
                        cout << "\033[1;31mInvalid cart index.\033[0m" << endl;
                    }
                    break;
                }

                case 5:
                {

                    // Calculate and display total bill
                    int total = calculateTotalBill(cart, cartCount);

                    cout << "Total Bill: Rs." << total << endl;
                    break;
                }

                case 6:

                    confirmPurchase(cart, cartCount);
                    break;
                case 0:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "\033[1;31mInvalid choice! Please try again.\033[0m" << endl;
                }
            } while (userChoice != 0);
        }
        while (searchType != 0)
            ;
    }
    while(searchType !=0);
}

    bool hasSpecialCharacters(const string &str)
    {
        for (char ch : str)
        {
            if (!isalnum(ch))
            {
                return true;
            }
        }
        return false;
    }

    bool isValidPasswordLength(const string &pass)
    {
        return pass.length() <= 8;
    }

    void saveUsers(User users[], int count)
    {
        ofstream userFile("credentials.txt");
        for (int i = 0; i < count; i++)
        {
            userFile << users[i].username << " " << users[i].password << endl;
        }
        userFile.close();
    }

    void saveItems(Item items[], int count)
    {
        ofstream itemFile("items.txt");
        for (int i = 0; i < count; i++)
        {
            itemFile << items[i].name << " " << items[i].price << endl;
        }
        itemFile.close();
    }

    void displayItems(Item items[], int count)
    {
        cout << "\033[1;32mItem List:\033[0m" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << items[i].name << " - Rs." << items[i].price << endl;
        }
    }

    void addToCart(CartItem cart[], int &cartCount, Item items[], int itemIndex)
    {
        bool found = false;
        for (int i = 0; i < cartCount; i++)
        {
            if (cart[i].item.name == items[itemIndex].name)
            {
                cart[i].quantity++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cart[cartCount].item = items[itemIndex];
            cart[cartCount].quantity = 1;
            cartCount++;
        }
    }

    void displayCart(CartItem cart[], int cartCount)
    {
        cout << "\033[1;33mYour Cart:\033[0m" << endl;
        for (int i = 0; i < cartCount; i++)
        {
            cout << cart[i].item.name << " - Quantity: " << cart[i].quantity << endl;
        }
    }

    void removeFromCart(CartItem cart[], int &cartCount, int index)
    {
        for (int i = index; i < cartCount - 1; i++)
        {
            cart[i] = cart[i + 1];
        }
        cartCount--;
    }

    int calculateTotalBill(CartItem cart[], int cartCount)
    {
        int total = 0;
        for (int i = 0; i < cartCount; i++)
        {
            total += cart[i].getTotalPrice(); // Directly use the method in CartItem
        }
        return total;
    }

    void confirmPurchase(CartItem cart[], int &cartCount)
    {
        int total = calculateTotalBill(cart, cartCount);
        cout << "\033[1;32mTotal Bill: Rs." << total << "\033[0m" << endl;
        cout << "Thank you for shopping with us!" << endl;
        cartCount = 0; // Clear the cart after purchase
    }
