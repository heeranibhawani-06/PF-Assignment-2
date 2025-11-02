#include <stdio.h>
#include <string.h>

void displayInventory(int code[], int qty[], int price[], int n);
void updateInventory(int code[], int qty[], int n, int c, int q);
float addToCart(int code[], int price[], int n);
void showInvoice(char name[], char cnic[], float total);

int main() {
    int code[4] = {1,2,3,4};
    int qty[4] = {50,10,20,8};
    int price[4] = {100,200,300,150};
    char name[30], cnic[20];
    float total = 0;
    int choice;

    printf("Enter customer name: ");
    scanf("%s", name);
    printf("Enter CNIC: ");
    scanf("%s", cnic);

    do {
        printf("\n--- Supermarket Menu ---\n");
        printf("1. Display Inventory\n");
        printf("2. Add Item to Cart\n");
        printf("3. Show Invoice\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            displayInventory(code, qty, price, 4);
        else if(choice == 2)
            total += addToCart(code, price, 4);
        else if(choice == 3)
            showInvoice(name, cnic, total);
        else if(choice == 4)
            printf("Thank you for shopping!\n");
        else
            printf("Invalid choice!\n");

    } while(choice != 4);

    return 0;
}

void displayInventory(int code[], int qty[], int price[], int n) {
    int i;
    printf("\nCode\tQty\tPrice\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", code[i], qty[i], price[i]);
    }
}

float addToCart(int code[], int price[], int n) {
    int c, q, i;
    float total = 0;
    printf("Enter product code: ");
    scanf("%d", &c);
    printf("Enter quantity: ");
    scanf("%d", &q);

    for(i = 0; i < n; i++) {
        if(code[i] == c) {
            total = q * price[i];
            printf("Item added. Total so far: %.2f\n", total);
            break;
        }
    }
    return total;
}

void showInvoice(char name[], char cnic[], float total) {
    char promo[10];
    float discount = 0;
    printf("\nDo you have promocode? (type Eid2025 if yes): ");
    scanf("%s", promo);
    if(strcmp(promo, "Eid2025") == 0) {
        discount = total * 0.25;
        total = total - discount;
        printf("\nDiscount applied!\n");
    }

    printf("\n--- INVOICE ---\n");
    printf("Customer: %s\nCNIC: %s\n", name, cnic);
    printf("Final Bill: %.2f\n", total);
}
