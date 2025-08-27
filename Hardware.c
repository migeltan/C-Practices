#include <stdio.h>
#include <string.h>

// Define Product structure
struct Product {
    char product_code[9];
    char description[31];
    float unit_price;
    int quantity;
    float amount;
};

// Function to input product details
void RECORD(struct Product products[]) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("Enter product code: ");
        scanf("%s", products[i].product_code);
        getchar(); // consume newline

        printf("Enter product description: ");
        scanf(" %[^\n]s", products[i].description);

        printf("Enter unit price: ");
        scanf("%f", &products[i].unit_price);

        printf("Enter number quantity: ");
        scanf("%d", &products[i].quantity);

        printf("\n");
    }
}

// Function to compute amounts and display the receipt
void KOMPUTE(struct Product products[]) {
    int i;
    float total_billing = 0;

    printf("\nABC HARDWARE\n\n");
    printf("Product code  Product Description         Unit Price  Quantity  Amount\n");

    for (i = 0; i < 3; i++) {
        products[i].amount = products[i].unit_price * products[i].quantity;
        total_billing += products[i].amount;

        printf("%-13s %-26s %-11.2f %-9d %-10.2f\n",
               products[i].product_code,
               products[i].description,
               products[i].unit_price,
               products[i].quantity,
               products[i].amount);
    }

    printf("\nTotal Billing : Php %.2f\n", total_billing);
}

// Main function
int main() {
    struct Product products[3];

    RECORD(products);
    KOMPUTE(products);

    return 0;
}