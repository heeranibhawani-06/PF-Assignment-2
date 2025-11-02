#include <stdio.h>
#include <string.h>

void encodeMessage(char msg[]);
void decodeMessage(char msg[]);

int main() {
    char msg[100];
    int choice;

    do {
        printf("\n--- TCS Message Encoder ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // to clear newline

        if(choice == 1) {
            printf("Enter message: ");
            gets(msg);
            encodeMessage(msg);
        } else if(choice == 2) {
            printf("Enter encoded message: ");
            gets(msg);
            decodeMessage(msg);
        } else if(choice == 3) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice!\n");
        }

    } while(choice != 3);

    return 0;
}

void encodeMessage(char msg[]) {
    int len = strlen(msg);
    char temp;
    int i;

    // Reverse string
    for(i = 0; i < len/2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }

    // Toggle 2nd and 5th bits
    for(i = 0; i < len; i++) {
        msg[i] ^= (1 << 1); // toggle 2nd bit
        msg[i] ^= (1 << 4); // toggle 5th bit
    }

    printf("Encoded Message: %s\n", msg);
}

void decodeMessage(char msg[]) {
    int len = strlen(msg);
    char temp;
    int i;

    // Untoggle bits
    for(i = 0; i < len; i++) {
        msg[i] ^= (1 << 1);
        msg[i] ^= (1 << 4);
    }

    // Reverse again
    for(i = 0; i < len/2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }

    printf("Decoded Message: %s\n", msg);
}
