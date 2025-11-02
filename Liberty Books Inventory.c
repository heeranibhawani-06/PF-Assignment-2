#include <stdio.h>

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void processSale(int isbns[], int quantities[], int count);
void lowStock(int isbns[], char titles[][50], int quantities[], float prices[], int count);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    do {
        printf("\n--- Liberty Books Menu ---\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Generate Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            addBook(isbns, titles, prices, quantities, &count);
        else if(choice == 2)
            processSale(isbns, quantities, count);
        else if(choice == 3)
            lowStock(isbns, titles, quantities, prices, count);
        else if(choice == 4)
            printf("Exiting program...\n");
        else
            printf("Invalid choice!\n");

    } while(choice != 4);

    return 0;
}

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    int isbn, i;
    printf("Enter ISBN: ");
    scanf("%d", &isbn);

    // check duplicate
    for(i = 0; i < *count; i++) {
        if(isbns[i] == isbn) {
            printf("Book already exists!\n");
            return;
        }
    }

    isbns[*count] = isbn;
    printf("Enter Title: ");
    scanf("%s", titles[*count]);
    printf("Enter Price: ");
    scanf("%f", &prices[*count]);
    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;
    printf("Book added successfully!\n");
}

void processSale(int isbns[], int quantities[], int count) {
    int isbn, qty, i, found = 0;
    printf("Enter ISBN of book sold: ");
    scanf("%d", &isbn);

    for(i = 0; i < count; i++) {
        if(isbns[i] == isbn) {
            found = 1;
            printf("Enter quantity sold: ");
            scanf("%d", &qty);
            if(qty > quantities[i])
                printf("Not enough stock!\n");
            else {
                quantities[i] -= qty;
                printf("Sale processed!\n");
            }
            break;
        }
    }
    if(found == 0)
        printf("Book not found!\n");
}

void lowStock(int isbns[], char titles[][50], int quantities[], float prices[], int count) {
    int i, found = 0;
    printf("\nLow Stock Books (Qty < 5):\n");
    for(i = 0; i < count; i++) {
        if(quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Qty: %d\n", isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }
    if(found == 0)
        printf("No low stock books.\n");
}
