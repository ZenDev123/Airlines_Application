#include "airways.h"

void bubbleSort(Passenger *p, int n) {
    Passenger temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].customer_id > p[j+1].customer_id) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("\n[System] Sorting complete. Ready for Binary Search.");
}

int binarySearch(Passenger *p, int n, int search_id) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (p[mid].customer_id == search_id) return mid;
        if (p[mid].customer_id < search_id) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}