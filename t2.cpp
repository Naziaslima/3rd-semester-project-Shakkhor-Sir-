
#include <bits/stdc++.h>
#include<conio.h>
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
    {"Cheese Burger", 35.00},
    {"Cheese Burger", 25.00},
    {"Double Cheese Burger", 30.00},
    {"Crispy Chicken ", 35.00},
    {"Spicy Sandwich", 35.00},
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clearScreen() {
    system("cls");
}

void title() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 14);
   cout<<"\n\n\n\n";
	cout<<"\t\t    ********    **    **   ********    ******     *******   ******** \n";
 	cout<<"\t\t   /**    **   /**   /**  /**    **  /**    **   /**       /**    ** \n";
 	cout<<"\t\t   /*********  /**   /**  /********  /**   ****  /******   /******** \n";
 	SetConsoleTextAttribute(h,12);
 	cout<<"\t\t   /**     **  /**   /**  /**  /**   /**    **   /**       /**  /**  \n";
 	cout<<"\t\t   /*********  //******   /**  //**  //******    /*******  /**  //** \n";
 	cout<<"\t\t   /////////    //////    //    //    //////     ///////   //    //\n\n\n";

	SetConsoleTextAttribute(h,14);
	cout<<"\t\t          ------------       \n";
	cout<<"\t\t        /%%%%%%%%%%%%%%\\      \n";
	cout<<"\t\t       /%%%%%%%%%%%%%%%%\\     ";
	SetConsoleTextAttribute(h,14);
	cout<<"**    **   **    **   ********\n";
	SetConsoleTextAttribute(h,12);
	cout<<"\t\t       \\wwwwwwwwwwwwwwww/    ";
	SetConsoleTextAttribute(h,14);
	cout<<"/**   /**  /**   /**  /**    **          \n";
	SetConsoleTextAttribute(h,10);
	cout<<"\t\t        <%%%%%%%%%%%%%%>     ";
	SetConsoleTextAttribute(h, 14);
	cout<<"/********  /**   /**  /*********      \n";
	SetConsoleTextAttribute(h,4);
	cout<<"\t\t        (%%%%%%%%%%%%%%)     ";
	SetConsoleTextAttribute(h,12);
	cout<<"/**   /**  /**   /**  /**     **          \n";
	SetConsoleTextAttribute(h,14);
	cout<<"\t\t       /%%%%%%%%%%%%%%%%\\    ";
	SetConsoleTextAttribute(h, 12);
	cout<<"/**   /**  //******   /*********    \n";
	SetConsoleTextAttribute(h, 14);
	cout<<"\t\t       \\%%%%%%%%%%%%%%%%/    ";
	SetConsoleTextAttribute(h, 12);
	cout<<"//    //    //////    /////////  \n";
	SetConsoleTextAttribute(h, 14);
	cout<<"\t\t        \\%%%%%%%%%%%%%%/        \n";
	cout<<"\t\t          ------------         \n\n";
	cout<<"\t\t\t\t      ";
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
    char ch;
    password = "";
    while ((ch = _getch()) != 13) {
        password.push_back(ch);
        cout << '*';
    }

    cout << endl;

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

void displayMenu() {
    cout << "\n\t\t\t\t=====>>>> PICK YOUR ORDER <<<<=====\n\n";
    cout << "\t\t==========================================================" << endl;
    cout << "\t\t PRODUCT NUMBER\t  PRODUCT\t\t  PRICE" << endl; // Adjusted spacing
    cout << "\t\t==========================================================" << endl;
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        cout << "\t\t     " << i + 1 << "\t\t  " << setw(20) << left << products[i].name
             << "\tTk " << fixed << setprecision(2) << products[i].unitPrice << endl;
    }
    cout << "\t\t==========================================================" << endl;
}

double calculateTotalAmount() {
    double totalAmount = 0.0;
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        totalAmount += products[i].totalSales;
    }
    return totalAmount;
}

void displayOrderSummary() {
    clearScreen();
    title();
    cout << "\n\t\t\t\tOrder Summary" << endl;
    cout << "\t\t===================================================" << endl;
    cout << "\t\t\t  PRODUCT\t\tQUANTITY\t\tAMOUNT" << endl;
    cout << "\t\t===================================================" << endl;

    double totalAmount = 0.0;
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        if (products[i].quantityOrdered > 0) {
            cout << "\t\t\t  " << setw(20) << left << products[i].name
                 << "\t\t" << products[i].quantityOrdered
                 << "\t\tTk " << fixed << setprecision(2) << products[i].totalSales << endl;
            totalAmount += products[i].totalSales;
        }
    }

    cout << "\t\t===================================================" << endl;
    cout << "\t\t\tTotal Amount: Tk " << fixed << setprecision(2) << totalAmount << endl;
    cout << "\t\t===================================================" << endl;
}

void updateOrder() {
    int productChoice, quantity;

    displayOrderSummary();
    cout << "\n\t\t\tEnter the product number to update: ";
    cin >> productChoice;

    if (productChoice < 1 || productChoice > NUM_PRODUCTS) {
        cout << "\n\t\t\tInvalid product number." << endl;
        return;
    }

    cout << "\t\t\tEnter new quantity: ";
    cin >> quantity;

    if (quantity < 0) {
        cout << "\n\t\t\tQuantity cannot be negative." << endl;
        return;
    }


    products[productChoice - 1].totalSales = products[productChoice - 1].unitPrice * quantity;

    products[productChoice - 1].quantityOrdered = quantity;
    cout << "\n\t\t\tOrder updated successfully!" << endl;
}

void deleteOrder() {
    int productChoice;

    displayOrderSummary();
    cout << "\n\t\t\tEnter the product number to delete: ";
    cin >> productChoice;

    if (productChoice < 1 || productChoice > NUM_PRODUCTS) {
        cout << "\n\t\t\tInvalid product number." << endl;
        return;
    }


    products[productChoice - 1].totalSales = 0;
    products[productChoice - 1].quantityOrdered = 0;

    cout << "\n\t\t\tOrder deleted successfully!" << endl;
}

void orderMultipleItems() {
    int productChoice, quantity;
    char moreItems;

    do {
        displayMenu();
        cout << "\t\t\tEnter product number to order: ";
        cin >> productChoice;

        if (productChoice < 1 || productChoice > NUM_PRODUCTS) {
            cout << "\n\t\t\tInvalid product number." << endl;
            continue;
        }

        cout << "\t\t\tEnter quantity: ";
        cin >> quantity;


        products[productChoice - 1].quantityOrdered += quantity;
        products[productChoice - 1].totalSales += products[productChoice - 1].unitPrice * quantity;

        cout << "\n\t\t\tOrder added successfully!" << endl;

        cout << "\n\t\t\tDo you want to order more items? (y/n): ";
        cin >> moreItems;

    } while (moreItems == 'y' || moreItems == 'Y');
}

void payment() {
    double totalAmount = calculateTotalAmount();
    double amountPaid;

    cout << "\n\t\t\tTotal Amount Due: Tk " << fixed << setprecision(2) << totalAmount << endl;
    cout << "\t\t\tEnter amount paid: Tk ";
    cin >> amountPaid;

    if (amountPaid < totalAmount) {
        cout << "\n\t\t\tInsufficient payment. You need to pay Tk " << fixed << setprecision(2) << (totalAmount - amountPaid) << " more." << endl;
    } else {
        double change = amountPaid - totalAmount;
        cout << "\n\t\t\tPayment successful! Your change: Tk " << fixed << setprecision(2) << change << endl;
    }

    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        products[i].quantityOrdered = 0;
        products[i].totalSales = 0;
    }
}

int main() {
    system("cls");
    title();

    int choice;
    bool isLoggedIn = false;

    do {
        cout << "\n\t\t\t1. Create Account\n";
        cout << "\t\t\t2. Login\n";
        cout << "\t\t\t3. Exit\n";
        cout << "\t\t\tChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                isLoggedIn = login();
                break;
            case 3:
                exit(0);
            default:
                cout << "\n\t\t\tInvalid choice! Please try again." << endl;
        }
    } while (!isLoggedIn);

    do {
        clearScreen();
        title();
        cout << "\n\t\t\t1. Display Menu\n";
        cout << "\t\t\t2. Order Products\n";
        cout << "\t\t\t3. Update Order\n";
        cout << "\t\t\t4. Delete Order\n";
        cout << "\t\t\t5. View Order Summary\n";
        cout << "\t\t\t6. Make Payment\n";
        cout << "\t\t\t7. Exit\n";
        cout << "\t\t\tChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMenu();
                clearInputBuffer();
                cin.get();
                break;
            case 2:
                orderMultipleItems();
                clearInputBuffer();
                cin.get();
                break;
            case 3:
                updateOrder();
                clearInputBuffer();
                cin.get();
                break;
            case 4:
                deleteOrder();
                clearInputBuffer();
                cin.get();
                break;
            case 5:
                displayOrderSummary();
                clearInputBuffer();
                cin.get();
                break;
            case 6:
                payment();
                clearInputBuffer();
                cin.get();
                break;
            case 7:
                cout << "\n\t\t\tThank you for using Burger Hub!" << endl;
                exit(0);
            default:
                cout << "\n\t\t\tInvalid choice! Please try again." << endl;
        }
    } while (true);

    return 0;
}
