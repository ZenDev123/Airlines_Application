#include "airways.h"

void calculateTicket(Passenger *p) {
    p->base_fare = p->distance * 150;
    
    p->extra_baggage_charge = (p->baggage_weight > 15) ? (p->baggage_weight - 15) * 20 : 0;

    // Experiment 2: Decision making using else-if ladder
    if (p->age >= 60 && (p->club_member == 'Y' || p->club_member == 'y')) {
        p->discount = 0.45 * p->base_fare; // Stacked discount
    } else if (p->age >= 60) {
        p->discount = 0.40 * p->base_fare;
    } else if (p->club_member == 'Y' || p->club_member == 'y') {
        p->discount = 0.05 * p->base_fare;
    } else {
        p->discount = 0;
    }

    float subtotal = (p->base_fare + p->extra_baggage_charge) - p->discount;
    p->gst = subtotal * 0.10; 
    p->total_fare = subtotal + p->gst;
}