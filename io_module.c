#include "airways.h"

static void readPassengerDetails(Passenger *p) {
    printf("Full Name: ");
    scanf(" %[^\n]s", p->name); 

    printf("Gender (M/F): ");
    scanf(" %c", &p->gender);

    printf("Age: ");
    scanf("%d", &p->age);

    printf("Baggage Weight (kg): ");
    scanf("%f", &p->baggage_weight);

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
    printf("\nDate: %02d/%02d/%d", p.travel_date.day, p.travel_date.month, p.travel_date.year);
    printf("\n------------------------------------------");
    printf("\nBase Fare:      Rs. %10.2f", p.base_fare);
    printf("\nExtra Baggage:  Rs. %10.2f", p.extra_baggage_charge);
    printf("\nDiscount:      -Rs. %10.2f", p.discount);
    printf("\nGST (10%%):      Rs. %10.2f", p.gst);
    printf("\nTOTAL FARE:     Rs. %10.2f", p.total_fare);
    printf("\n==========================================\n");
}