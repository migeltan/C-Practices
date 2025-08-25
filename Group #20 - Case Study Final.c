/* 
Group #20 - BSIT 1-1
Members:
	Agojo, Aleckz V.
	Felipe, Cyrus Kishin
	Tan, MIgel H.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ORDERS 50 //used for the array parameter sa structs
#define MAX_MENU 50

struct Menu {
    char itemCode[10]; //FP #1
    char description[50]; //Fampack1
    float price;
};

struct Order {
    struct Menu item;
    int quantity;
    float amount;
};

struct Billing {
    struct Order orders[MAX_ORDERS]; //nested 
    int orderCount;
    float totalBill;
    float discount;
    float netBill;
    float tendered;
    float change;
};

//global initializations for the ff
struct Menu menuList[MAX_MENU];
int menuSize = 0;
const char *menuFile = "menu.txt"; //writing the menu sa file
const char *salesFile = "daily_sales.txt"; //sales file

// forwards declarations
void mainMenu();
void loadMenuFromFile();
void saveMenuToFile();
void displayMenu();
int findMenuIndex(char code[]);
void addMenuItem();
void updateMenuItem();
void takeOrder(struct Billing *b);
void computeBilling(struct Billing *b, char customerType[], int month);
void displayReceipt(struct Billing b, int tableNo, int month, int day, int year);
void updateSalesFile(struct Billing b);
void clearInput();
void generateDailySalesReport();

int main() {
    loadMenuFromFile(); //literally nasa loob ng function na to yung mga functions na iba
    mainMenu(); 
    return 0;
}

void mainMenu() { //main menu funct to calling other functs
    int choice;
    char again = 'Y';

    while (again == 'Y' || again == 'y') { //bakit may ganto? para sa user repetition
        printf("\n---JOLLY - JIP RESTAURANT---\n");
        printf("\nFinancial Information System");
        printf("\nInput the number on the BRACKETS for your choice.");
        printf("\nMain Menu:\n\n");

        printf("[ ] 1. Billing Sub-Module:\n");
        printf("[1] 1.1  Order and Receipt\n");
        printf("[2] 1.2. Generate Daily Total Sales\n");
        printf("[3] 2. File Maintenance\n");
        printf("[4] 3. Exit\n");
        printf("\nChoose transaction: ");

        // --- input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            clearInput(); // catches letters, symbols, etc.
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            continue;
        }
        clearInput(); // clean leftover input

        switch (choice) {
            case 1: { //nag if-else tayo kaysa case break
                struct Billing b = {0}; //eto pinakabasis ng mga struct pointers sa array
                int tableNo;
                char customerType[10];
                int month, day, year;

                // manual date input with validation
                printf("\nEnter date of transaction: (Mother's Day and Independence Day Discount)\n");
                do {
                    printf("Month (1-12): ");
                    scanf("%d", &month);
                    if (month < 1 || month > 12) printf("Invalid month. Try again.\n");
                } while (month < 1 || month > 12);

                do {
                    printf("Day (1-31): ");
                    scanf("%d", &day);
                    if (day < 1 || day > 31) printf("Invalid day. Try again.\n");
                } while (day < 1 || day > 31);

                do {
                    printf("Year (e.g. 2025): ");
                    scanf("%d", &year);
                    if (year < 1900 || year > 2100) printf("Invalid year. Try again.\n");
                } while (year < 1900 || year > 2100);
                clearInput();

                printf("\nTABLE NO: ");
                scanf("%d", &tableNo);
                clearInput();

                // customer type validation
                do {
                    printf("Enter customer type (Normal/Senior/PWD): ");
                    scanf("%s", customerType);
                    clearInput();

                    if (strcasecmp(customerType, "Normal") != 0 &&
                        strcasecmp(customerType, "Senior") != 0 &&
                        strcasecmp(customerType, "PWD") != 0) {
                        printf("Invalid customer type. Please enter either Normal, Senior, or PWD only.\n");
                    }
                } while (strcasecmp(customerType, "Normal") != 0 &&
                         strcasecmp(customerType, "Senior") != 0 &&
                         strcasecmp(customerType, "PWD") != 0);

                takeOrder(&b); //ordering and receipt
                computeBilling(&b, customerType, month);
                displayReceipt(b, tableNo, month, day, year);
                updateSalesFile(b);
                break;
            }

            case 2:
                generateDailySalesReport();
                break;

            case 3: {
                int fmChoice; //function for file maintenance
                printf("\n---FILE MAINTENANCE---\n");
                printf("[1] 2.1. Add New Menu Item\n");
                printf("[2] 2.2. Update Menu Price\n");
                printf("[3] 2.3. Display Menu Price\n");
                printf("\nChoose option: ");

                // input validation for submenu
                if (scanf("%d", &fmChoice) != 1) {
                    clearInput();
                    printf("Invalid input. Please enter a number (1-3).\n");
                    break;
                }
                clearInput();

                if (fmChoice == 1) addMenuItem();
                else if (fmChoice == 2) updateMenuItem();
                else if (fmChoice == 3) displayMenu();
                else printf("Invalid option. Please choose between 1-3.\n");

                saveMenuToFile();
                break;
            }

            case 4:
                printf("Exiting...\n");
                return;

            default:
                printf("Invalid option. Please choose a number from 1 to 4.\n");
                break;
        }

        printf("\nBack to main menu? (Y/N): ");
        scanf(" %c", &again);
        clearInput();
    }
}


//Hanggang dito lang Cyrus

void clearInput() { //input buffer lang to
    while (getchar() != '\n');
}

//following file handling is forda menu items, kung may inupdate ba ganern

void loadMenuFromFile() { //ginawa ko to para sa file reading, gets na yan
//for file reading larngs
    FILE *fp = fopen(menuFile, "r");
    if (fp == NULL) {
        printf("Menu file not found. Creating default menu.\n");
        struct Menu defaultMenu[] = { //dinefine na mga laman ng struct na 2 para printing na lang sa file
            {"FP#1", "Family Package1", 850.00},
            {"FP#2", "Family Package2", 900.00},
            {"BP#1", "Barkada Package1", 450.00},
            {"BP#2", "Barkada Package2", 500.00},
            {"SP#1", "Solo Package1", 150.00},
            {"SP#2", "Solo Package2", 180.00},
            {"Soda1", "Coke 1.5L", 80.00},
            {"Rice", "Xtra Rice", 50.00}
        };
        menuSize = sizeof(defaultMenu) / sizeof(defaultMenu[0]);
        for (int i = 0; i < menuSize; i++) {
            menuList[i] = defaultMenu[i];
        }
        saveMenuToFile();
        return;
    }

    menuSize = 0;
    while (fscanf(fp, "%s %[^,], %f\n", menuList[menuSize].itemCode,
           menuList[menuSize].description, &menuList[menuSize].price) == 3) {
        menuSize++;
    }
    fclose(fp);
}

void saveMenuToFile() { //file writing or fwrite 
    FILE *fp = fopen(menuFile, "w"); //saves menuList sa file
    if (fp == NULL) {
        printf("Failed to save menu.\n");
        return;
    }
    for (int i = 0; i < menuSize; i++) {
    fprintf(fp, "%s %s, %.2f\n", menuList[i].itemCode, menuList[i].description, menuList[i].price);
    }
    fclose(fp);
}

void displayMenu() { //function for displaying menu
    printf("\n------MENU------\n");
    for (int i = 0; i < menuSize; i++) {
    printf("%s - %s (%.2f)\n", menuList[i].itemCode, menuList[i].description, menuList[i].price);
    }
}

int findMenuIndex(char code[]) { //para lang mahanap yung product code
    for (int i = 0; i < menuSize; i++) {
        if (strcmp(menuList[i].itemCode, code) == 0)
            return i;
    }
    return -1;
}

void addMenuItem() { //sa file management ito na option, para sa papgdaggdag ng menu item
    //literally yung name niya yung function
	
	if (menuSize >= MAX_MENU) {
        printf("Menu is full.\n");
        return;
    }
    struct Menu m;
    printf("Enter item code: ");
    scanf("%s", m.itemCode);
    clearInput();
    printf("Enter description: ");
    fgets(m.description, sizeof(m.description), stdin);
    m.description[strcspn(m.description, "\n")] = '\0';
    printf("Enter price: ");
    scanf("%f", &m.price);
    clearInput();

    menuList[menuSize++] = m;
    printf("Menu item added.\n");
}

void updateMenuItem() {
	//upd lang ni user price sa existing menu, 
	//para masatisfy yung number 3, price option 
	
    char code[10];
    printf("Enter item code to update: ");
    scanf("%s", code);
    clearInput();

    int idx = findMenuIndex(code); //tinawag lang yung function panghanap ng index
    if (idx == -1) {
        printf("Item not found.\n");
        return;
    }

    printf("Old price of %s: %.2f\n", menuList[idx].description, menuList[idx].price);
    printf("Enter new price: ");
    scanf("%f", &menuList[idx].price);
    clearInput();
    printf("Price updated.\n");
}

void takeOrder(struct Billing *b) { //taking the order from the user using codes
   
   
    char code[10];
    int quantity;
    char again = 'Y';

    while (again == 'Y' || again == 'y') {
        displayMenu();
        printf("\nEnter item code: ");
        scanf("%s", code);
        clearInput();

        int index = findMenuIndex(code);
        if (index == -1) {
            printf("Invalid item code. Try again.\n");
            continue;
        }

        do {
            printf("Enter quantity: ");
            if (scanf("%d", &quantity) != 1 || quantity <= 0) {
            printf("Invalid quantity. Try again.\n");
            clearInput();
            quantity = 0;
            }
        } while (quantity == 0);
        clearInput();

        struct Order order;
        order.item = menuList[index];
        order.quantity = quantity;
        order.amount = quantity * order.item.price;

        b->orders[b->orderCount] = order;
        b->orderCount++;

        printf("Add another item? (Y/N): ");
        scanf(" %c", &again);
        clearInput();
    }
}

//2% sa month of may and june discount handling, 20% sa senior, 5% sa pwd
void computeBilling(struct Billing *b, char customerType[], int month) {
	
	//satisfies number 3 sa document
    float total = 0;
    for (int i = 0; i < b->orderCount; i++) {
        total += b->orders[i].amount; //letter a.
    }
    b->totalBill = total; //sum of indiv amt
	
	//basic computation ng discount
    float discount = 0;
    
    //since between 500 pesos to 2k lang ang may discount sa month na ito
    if ((month == 5 || month == 6) && total >= 500 && total <= 2000) {
        discount += total * 0.02;
    }
    if (strcasecmp(customerType, "Senior") == 0) {
        discount += total * 0.20;
    } else if (strcasecmp(customerType, "PWD") == 0) {
        discount += total * 0.05;
    }

    b->discount = discount;
    b->netBill = total - discount; //letter d.

    do {
        printf("\nAmount tendered: ");
        scanf("%f", &b->tendered);
        clearInput();
        if (b->tendered < b->netBill) {
            printf("Insufficient Fund or Invalid Input.\nPlease enter again (Integer Only!).\n");
        }
    } while (b->tendered < b->netBill);

    b->change = b->tendered - b->netBill; //letter e.
}

//Pinakaresibo ng whole stuff
void displayReceipt(struct Billing b, int tableNo, int month, int day, int year) {
	
    char *months[] = {
        "Invalid", "January", "February", "March", "April",
        "May", "June", "July", "August", "September", "October", "November", "December"
    };

    printf("\n---JOLLY - JIP RESTAURANT---\n");
    printf("DATE: %s %d, %d\n", months[month], day, year);
    printf("TABLE NO: %d\n", tableNo);
    printf("\n%-10s %-20s %-10s %-10s %-10s\n", "ITEM", "DESCRIPTION", "QTY", "PRICE", "AMOUNT");
    for (int i = 0; i < b.orderCount; i++) {
        printf("%-10s %-20s %-10d %-10.2f %-10.2f\n",
               b.orders[i].item.itemCode, b.orders[i].item.description,
               b.orders[i].quantity, b.orders[i].item.price, b.orders[i].amount);
    }
    printf("\nTOTAL BILL: %.2f\n", b.totalBill);
    printf("DISCOUNT: %.2f\n", b.discount);
    printf("NET BILL: %.2f\n", b.netBill);
    printf("AMOUNT TENDERED: %.2f\n", b.tendered);
    printf("CHANGE: %.2f\n", b.change);
}

//following file handling is for the sales per user

void updateSalesFile(struct Billing b) { //append file pag may dinagdagan si user
    FILE *fp = fopen(salesFile, "a");
    if (fp == NULL) {
        printf("Error updating sales file.\n");
        return;
    }
    fprintf(fp, "%.2f %.2f %.2f\n", b.totalBill, b.discount, b.netBill);
    fclose(fp);
}

void generateDailySalesReport() { //file reading
    FILE *fp = fopen(salesFile, "r");
    float tBill = 0, tDiscount = 0, tNet = 0;
    float bill, discount, net;

    if (fp == NULL) {
        printf("No sales record found.\n");
        return;
    }

    while (fscanf(fp, "%f %f %f", &bill, &discount, &net) != EOF) {
        tBill += bill;
        tDiscount += discount;
        tNet += net;
    }
    fclose(fp);

    printf("\n--- DAILY TOTAL SALES REPORT ---\n");
    printf("Total billing: %.2f\n", tBill);
    printf("Total discount: %.2f\n", tDiscount);
    printf("Total net billing: %.2f\n", tNet);
}
