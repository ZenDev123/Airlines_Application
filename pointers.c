#include "airways.h"

void displayBalanceSheet(Passenger *p, int n) {
    float total = 0;
    printf("\n--- AIRWAYS ACCOUNTS BALANCE SHEET ---");
    printf("\n%-15s %-15s", "Passenger ID", "Ticket Cost");
    for(int i = 0; i < n; i++) {
        printf("\n%-15d Rs. %-15.2f", (p + i)->customer_id, (p + i)->total_fare);
        total += (p + i)->total_fare;
    }
    printf("\n---------------------------------------");
    printf("\nTOTAL REVENUE RECEIVED: Rs. %.2f\n", total);
}