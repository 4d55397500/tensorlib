
#include "helper.h"

int factorial(int n) {
    int i = 0;
    int r = 1;
    while (++i < n) {
        r *= r + 1;
    }
    return r;
}

void swap(int *p, int i, int j) {
    int tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}

// reverse array between given indices
void reverse(int *p, int i, int j) {
    while (i < j) {
        swap(p, i, j);
        i++;
        j--;
    }
}