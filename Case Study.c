#include <stdio.h>
#include <string.h>

// Struct for one menu item
struct Item {
    char code[10];
    char description[30];
    int quantity;
    float unit_price;
    float amount;
};

// Struct for the full bill
struct Bill {
    struct Item items[10];
    int itemCount;
    float total;
    float discount;
    float net_bill;
    float tendered;
    float change;
};

void computeAmounts(struct Bill *bill) {
    bill->total = 0;
    for (int i = 0; i < bill->itemCount; i++) {
        bill->items[i].amount = bill->items[i].quantity * bill->items[i].unit_price;
        bill->total += bill->items[i].amount;
    }
}

void applyDiscounts(struct Bill *bill) {
    float disc = 0;

    // 2% for May + 20% Senior
    float mayOccasion = 0.02 * bill->total;
    float senior = 0.20 * bill->total;

    disc = mayOccasion + senior;
    bill->discount = disc;
    bill->net_bill = bill->total - bill->discount;
    bill->change = bill->tendered - bill->net_bill;
}

void printReceipt(struct Bill bill) {
    printf("JOLLY - JIP RESTAURANT\nBILLING STATEMENT\n");
    printf("DATE : April 29, 2025\nTABLE NO.: 4\n\n");

    printf("%-10s %-20s %-10s %-10s %-10s\n", "ITEM CODE", "DESCRIPTION", "QUANTITY", "UNIT PRICE", "AMOUNT");
    for (int i = 0; i < bill.itemCount; i++) {
        struct Item item = bill.items[i];
        printf("%-10s %-20s %-10d %-10.2f %-10.2f\n", item.code, item.description, item.quantity, item.unit_price, item.amount);
    }

    printf("\nTOTAL BILL     : %.2f", bill.total);
    printf("\nDISCOUNT       : %.2f", bill.discount);
    printf("\nNET BILL       : %.2f", bill.net_bill);
    printf("\nAMOUNT TENDERED: %.2f", bill.tendered);
    printf("\nCHANGE         : %.2f\n", bill.change);
}

int main() {
    struct Bill bill;
    bill.itemCount = 4;
    bill.tendered = 2500.00;

    // Add the items like in the picture
    strcpy(bill.items[0].code, "FP#1");
    strcpy(bill.items[0].description, "Family Package1");
    bill.items[0].quantity = 2;
    bill.items[0].unit_price = 850.00;

    strcpy(bill.items[1].code, "BP#2");
    strcpy(bill.items[1].description, "Barkada Package2");
    bill.items[1].quantity = 1;
    bill.items[1].unit_price = 1000.00;

    strcpy(bill.items[2].code, "Soda1");
    strcpy(bill.items[2].description, "Coke 1.5L");
    bill.items[2].quantity = 3;
    bill.items[2].unit_price = 80.00;

    strcpy(bill.items[3].code, "Rice");
    strcpy(bill.items[3].description, "Xtra Rice");
    bill.items[3].quantity = 3;
    bill.items[3].unit_price = 50.00;

    computeAmounts(&bill);
    applyDiscounts(&bill);
    printReceipt(bill);

    return 0;
}
