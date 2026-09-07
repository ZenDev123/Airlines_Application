#include "airways.h"

int main() {
    int n = 0, choice, search_id, found_index;
    Passenger list[100]; 

    printf("--- Welcome to Airway Management System ---\n");
    printf("--- BETA Version 1.2 ---\n");
    printf("Enter number of passengers to register: ");
    if (scanf("%d", &n) != 1) return 0;

    for(int i = 0; i < n; i++) {
        printf("\n--- Entering details for Passenger %d ---\n", i + 1);
        readDetails(&list[i]);
        calculateTicket(&list[i]);
    }

    do {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Passenger Profiles (View All)\n");
        printf("2. Airfare Calculation Details\n");
        printf("3. Generate E-Ticket / Boarding Pass\n");
        printf("4. Sort & Search (Binary Search)\n");
        printf("5. Airways Accounts Balance Sheet (Pointers)\n");
        printf("6. Add Passenger\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n%-10s %-25s %-20s", "ID", "Name", "Route");
                for(int i = 0; i < n; i++) {
                    printf("\n%-10d %-25s %s to %s", 
                           list[i].customer_id, list[i].name, list[i].source, list[i].destination);
                }
                printf("\n");
                break;
            case 2:
                printf("\n%-10s %-10s %-10s %-10s %-10s", "ID", "Base", "GST","Baggage", "Total");
                for(int i = 0; i < n; i++) {
                    printf("\n%-10d %-10.2f %-10.2f %-10.2f %-10.2f", 
                           list[i].customer_id, list[i].base_fare, list[i].gst, list[i].baggage_weight, list[i].total_fare);
                }
                printf("\n");
                break;
            case 3:
                printf("\nEnter Passenger ID for Boarding Pass: ");
                scanf("%d", &search_id);
                found_index = -1;
                for(int i=0; i<n; i++) {
                    if(list[i].customer_id == search_id) found_index = i;
                }
                if(found_index != -1) displayBoardingPass(list[found_index]);
                else printf("Passenger ID not found!\n");
                break;
            case 4:
                bubbleSort(list, n);
                printf("\nEnter ID to Search: ");
                scanf("%d", &search_id);
                found_index = binarySearch(list, n, search_id);
                if(found_index != -1) {
                    printf("\n[Result] Found: %s | Age: %d | Destination: %s\n", 
                           list[found_index].name, list[found_index].age, list[found_index].destination);
                } else {
                    printf("ID not found.\n");
                }
                break;
            case 5:
                displayBalanceSheet(list, n);
                break;
            case 6:
                if(n >= 100) {
                    printf("Passenger list is full!\n");
                    break;
                }
                printf("\nEnter Customer ID for the new passenger: ");
                scanf("%d", &search_id);
                if(n > 0) {
                    bubbleSort(list, n);
                    found_index = binarySearch(list, n, search_id);
                    if(found_index != -1) {
                        printf("\nCustomer ID already exists. Please use another ID.\n");
                        break;
                    }
                }
                printf("\n--- Entering details for Passenger %d ---\n", n + 1);
                readDetails(&list[n]);
                list[n].customer_id = search_id;
                calculateTicket(&list[n]);
                n++;
                printf("Passenger added successfully.\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 7); 

    return 0;
}