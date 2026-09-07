#ifndef AIRWAYS_H
#define AIRWAYS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Experiment 1 & 8: Structures
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int customer_id;
    char name[100];
    char gender;
    int age;
    float baggage_weight;
    char source[50];
    char destination[50];
    Date travel_date;
    float distance;
    char club_member; 
    
    float base_fare;
    float extra_baggage_charge;
    float discount;
    float gst;
    float total_fare;
} Passenger;

// Function Prototypes (Experiment 6)
void readDetails(Passenger *p);
void readDetailsWithId(Passenger *p, int customer_id);
void calculateTicket(Passenger *p);
void displayBoardingPass(Passenger p);
void displayBalanceSheet(Passenger *p, int n);
void bubbleSort(Passenger *p, int n); 
int binarySearch(Passenger *p, int n, int search_id); 

#endif