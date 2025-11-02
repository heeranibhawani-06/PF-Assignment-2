#include <stdio.h>

void updateSector(int grid[3][3]);
void querySector(int grid[3][3]);
void runDiagnostic(int grid[3][3]);

int main() {
    int grid[3][3] = {0};
    int choice;

    do {
        printf("\n--- IESCO Power Grid Menu ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            updateSector(grid);
        else if(choice == 2)
            querySector(grid);
        else if(choice == 3)
            runDiagnostic(grid);
        else if(choice == 4)
            printf("Exiting...\n");
        else
            printf("Invalid choice!\n");
    } while(choice != 4);

    return 0;
}

void updateSector(int grid[3][3]) {
    int r, c, bit, value;
    printf("Enter row and column (0-2): ");
    scanf("%d%d", &r, &c);
    printf("Enter bit (0=Power,1=Overload,2=Maintenance): ");
    scanf("%d", &bit);
    printf("Enter value (1=set,0=clear): ");
    scanf("%d", &value);

    if(value == 1)
        grid[r][c] |= (1 << bit);
    else
        grid[r][c] &= ~(1 << bit);

    printf("Sector updated.\n");
}

void querySector(int grid[3][3]) {
    int r, c, val;
    printf("Enter row and column: ");
    scanf("%d%d", &r, &c);
    val = grid[r][c];
    printf("Power: %s\n", (val & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (val & 2) ? "YES" : "NO");
    printf("Maintenance: %s\n", (val & 4) ? "REQUIRED" : "NOT REQUIRED");
}

void runDiagnostic(int grid[3][3]) {
    int i, j, overload = 0, maintenance = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(grid[i][j] & 2) overload++;
            if(grid[i][j] & 4) maintenance++;
        }
    }
    printf("Overloaded sectors: %d\n", overload);
    printf("Maintenance required sectors: %d\n", maintenance);
}
