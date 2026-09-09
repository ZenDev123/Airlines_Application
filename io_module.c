#include "airways.h"

static void clearInputLine(void) {
    int character;
    while((character = getchar()) != '\n' && character != EOF) {
    }
}

static void readPassengerDetails(Passenger *p) {
    printf("Full Name: ");
    scanf(" %[^\n]s", p->name); 

    printf("Gender (M/F): ");
    scanf(" %c", &p->gender);

    while (p->gender != 'M' && p->gender != 'F') {
        printf("Invalid gender. Enter M or F: ");
        scanf(" %c", &p->gender);
    }

    printf("Age: ");
    scanf("%d", &p->age);

    do {
        printf("Note: Extra charges apply for baggage over 15 kg.\n");
        printf("Baggage Weight (kg, maximum 50): ");
        if(scanf("%f", &p->baggage_weight) != 1) {
            clearInputLine();
            p->baggage_weight = -1;
        }
        if(p->baggage_weight < 0 || p->baggage_weight > 50) {
            printf("Invalid baggage weight. Enter a value from 0 to 50 kg.\n");
        }
    } while(p->baggage_weight < 0 || p->baggage_weight > 50);

    printf("Source (e.g., Cochin): ");
    scanf(" %[^\n]s", p->source);

    printf("Destination (e.g., Delhi): ");
    scanf(" %[^\n]s", p->destination);

    printf("Date of Travel (DD MM YYYY): ");
    scanf("%d %d %d", &p->travel_date.day, &p->travel_date.month, &p->travel_date.year);

    printf("Distance (km): ");
    scanf("%f", &p->distance);

    printf("Club Membership (Y/N): ");
    scanf(" %c", &p->club_member);
    
    while (p->club_member != 'Y' && p->club_member != 'N') {
        printf("Invalid choice. Enter Y or N: ");
        scanf(" %c", &p->club_member);
    }
}

void readDetails(Passenger *p) {
    printf("Customer ID: ");
    scanf("%d", &p->customer_id);
    readPassengerDetails(p);
}

void readDetailsWithId(Passenger *p, int customer_id) {
    p->customer_id = customer_id;
    readPassengerDetails(p);
}

void displayBoardingPass(Passenger p) {
    printf("\n==========================================");
    printf("\n            BOARDING PASS                 ");
    printf("\n==========================================");
    printf("\nID: %-5d   Name: %s", p.customer_id, p.name);
    printf("\nFrom: %-10s To: %s", p.source, p.destination);
    printf("\nDistance: %.2f km", p.distance);
    printf("\nDate: %02d/%02d/%d", p.travel_date.day, p.travel_date.month, p.travel_date.year);
    printf("\n------------------------------------------");
    printf("\nBase Fare:      Rs. %10.2f", p.base_fare);
    printf("\nExtra Baggage:  Rs. %10.2f", p.extra_baggage_charge);
    printf("\nDiscount:      -Rs. %10.2f", p.discount);
    printf("\nGST (10%%):      Rs. %10.2f", p.gst);
    printf("\nTOTAL FARE:     Rs. %10.2f", p.total_fare);
    printf("\n==========================================\n");
}