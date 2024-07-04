#include <bits/stdc++.h>

#include <windows.h>

using namespace std;

struct Product {
    string name;
    double unitPrice;
    int quantityOrdered;
    double totalSales;

    Product(string n, double price) : name(n), unitPrice(price), quantityOrdered(0), totalSales(0) {}
};

const int NUM_PRODUCTS = 15;
Product products[NUM_PRODUCTS] = {
    {"Hamburger", 25.00},
    {"Egg Sandwich", 25.00},
    {"Bacon and Cheese Burger", 35.00},
    {"Cheese Burger", 25.00},
    {"Double Cheese Burger", 30.00},
    {"Crispy Chicken Sandwich", 35.00},
    {"Spicy Chicken Sandwich", 35.00},
    {"Onion Rings", 40.00},
    {"Chicken Nuggets", 50.00},
    {"French Fries", 35.00},
    {"Royal", 13.00},
    {"Sprite", 13.00},
    {"Pineapple Juice", 30.00},
    {"Coke", 17.00},
    {"Water", 15.00}
};

void clearInputBuffer() {
    cin.clear();

}

void clearScreen() {
    system("cls");
}

void title() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 14);
    cout << "\n\n\n\n";
    cout << "\t\t    ********    **    **   ********    ******     *******   ******** \n";
    cout << "\t\t   /**    **   /**   /**  /**    **  /**    **   /**       /**    ** \n";
    cout << "\t\t   /*********  /**   /**  /********  /**   ****  /******   /******** \n";
    SetConsoleTextAttribute(h, 12);
    cout << "\t\t   /**     **  /**   /**  /**  /**   /**    **   /**       /**  /**  \n";
    cout << "\t\t   /*********  //******   /**  //**  //******    /*******  /**  //** \n";
    cout << "\t\t   /////////    //////    //    //    //////     ///////   //    //\n\n\n";

    SetConsoleTextAttribute(h, 14);
    cout << "\t\t          ------------       \n";
    cout << "\t\t        /%%%%%%%%%%%%%%\\      \n";
    cout << "\t\t       /%%%%%%%%%%%%%%%%\\     ";
    SetConsoleTextAttribute(h, 14);
    cout << "**    **   **    **   ********\n";
    SetConsoleTextAttribute(h, 12);
    cout << "\t\t       \\wwwwwwwwwwwwwwww/    ";
    SetConsoleTextAttribute(h, 14);
    cout << "/**   /**  /**   /**  /**    **          \n";
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t        <%%%%%%%%%%%%%%>     ";
    SetConsoleTextAttribute(h, 14);
    cout << "/********  /**   /**  /*********      \n";
    SetConsoleTextAttribute(h, 4);
    cout << "\t\t        (%%%%%%%%%%%%%%)     ";
    SetConsoleTextAttribute(h, 12);
    cout << "/**   /**  /**   /**  /**     **          \n";
    SetConsoleTextAttribute(h, 14);
    cout << "\t\t       /%%%%%%%%%%%%%%%%\\    ";
    SetConsoleTextAttribute(h, 12);
    cout << "/**   /**  //******   /*********    \n";
    SetConsoleTextAttribute(h, 14);
    cout << "\t\t       \\%%%%%%%%%%%%%%%%/    ";
    SetConsoleTextAttribute(h, 12);
    cout << "//    //    //////    /////////  \n";
    SetConsoleTextAttribute(h, 14);
    cout << "\t\t        \\%%%%%%%%%%%%%%/        \n";
    cout << "\t\t          ------------         \n\n";
    cout << "\t\t\t\t      ";
}

void createAccount() {
    ofstream file("accounts.txt", ios::app);

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string username, password;

    clearScreen();
    title();

    cout << "\n\t\t\t\tEnter new username: ";
    cin >> username;

    cout << "\n\t\t\t\tEnter password: ";
    cin >> password;

    file << username << " " << password << endl;

    file.close();

    cout << "\n\t\t\t\tAccount created successfully!" << endl;
    clearInputBuffer();
    cin.get();
}

bool login() {
    ifstream file("accounts.txt");

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return false;
    }

    string username, password;
    bool found = false;

    clearScreen();
    title();

    cout << "\n\t\t\t\tEnter username: ";
    cin >> username;

    cout << "\n\t\t\t\tEnter password: ";
    cin >> password;

    string line;

    while (getline(file, line)) {
        string savedUsername, savedPassword;
        istringstream iss(line);
        iss >> savedUsername >> savedPassword;

        if (savedUsername == username && savedPassword == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "\n\t\t\t\tLogin successful!" << endl;
    } else {
        cout << "\n\t\t\t\tInvalid username or password." << endl;
    }

    clearInputBuffer();
    cin.get();

    return found;
}

string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

int main() {
    system("mode 100");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    title();

    for (int a = 1; a < 8; a++) {
        Sleep(300);
        SetConsoleTextAttribute(h, 10);
        cout << "...";
    }

    Sleep(2000);
    clearScreen();

    int choice;

    do {
        clearScreen();
        title();

        cout << "\n\t\t\t =================================================" << endl;
        cout << "\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
        cout << "\n\t\t\t\t       Welcome to Burger Hub";
        cout << "\n\t\t\t %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
        cout << "\n\t\t\t =================================================" << endl;

        cout << "\n\n\t\t\t\t      1. Login" << endl;
        cout << "\t\t\t\t      2. Create Account" << endl;
        cout << "\t\t\t\t      3. Exit" << endl;
        cout << "\n\t\t\t\t      Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (login()) {
                    string password;
                    do {
                        clearScreen();
                        title();
                        cout << "\n\t\t\t\tWelcome to Burger Hub!" << endl;
                        cout << "\n\t\t\t\t=====>>>> PICK YOUR ORDER <<<<=====\n\n";
                        cout << "\t\t==========================================================" << endl;
                        cout << "\t\t PRODUCT NUMBER\t  PRODUCT\t\tPRICE" << endl;
                        cout << "\t\t==========================================================" << endl;
                        for (int i = 0; i < NUM_PRODUCTS; ++i) {
                            cout << "\t\t     " << i + 1 << "\t\t  " << products[i].name << "\t\t\tTk " << fixed << setprecision(2) << products[i].unitPrice << endl;
                        }
                        cout << "\t\t==========================================================" << endl;

                        cout << "\n\t\t\tEnter product number: ";
                        cin >> choice;

                        if (choice < 1 || choice > NUM_PRODUCTS) {
                            cout << "\n\t\t\tInvalid product number. Please try again." << endl;
                            clearInputBuffer();
                            cin.get();
                            continue;
                        }

                        cout << "\t\t\tEnter quantity: ";
                        cin >> choice;

                        products[choice - 1].quantityOrdered += choice;
                        products[choice - 1].totalSales += products[choice - 1].unitPrice * choice;

                        cout << "\n\t\t\tDo you want to order again? (Y/N): ";
                        cin >> password;

                    } while (password == "Y" || password == "y");

                    clearScreen();
                    title();
                    cout << "\n\t\t\t\tBurger Hub - Receipt" << endl;
                    cout << "\n\t\t\t===================================================" << endl;
                    cout << "\t\t\t  PRODUCT\t\tQUANTITY\t\tAMOUNT" << endl;
                    cout << "\t\t\t===================================================" << endl;

                    for (int i = 0; i < NUM_PRODUCTS; ++i) {
                        if (products[i].quantityOrdered > 0) {
                            cout << "\t\t\t  " << products[i].name << "\t\t\t" << products[i].quantityOrdered << "\t\t\tTk " << fixed << setprecision(2) << products[i].totalSales << endl;
                        }
                    }

                    cout << "\t\t\t===================================================" << endl;
                    cout << "\n\n\t\t\t\t    THANK YOU FOR VISITING US!" << endl;
                    cout << "\t\t\t\t    " << currentDateTime() << endl;
                    cout << "\n\t\t\t\t===================================================" << endl;
                }
                break;

            case 2:
                createAccount();
                break;

            case 3:
                clearScreen();
                title();
                cout << "\n\n\n\t\t\t\t\t THANKS FOR VISITING " << endl;
                exit(0);
                break;

            default:
                cout << "\n\n\n\t\t\t\tINVALID INPUT! Please enter correct choice." << endl;
                break;
        }

        clearInputBuffer();
        cin.get();

    } while (choice != 3);

    return 0;
}
