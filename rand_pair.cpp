#include<iostream>
#include<ctime>
#include"Header.h"

void rand_pair(int rand_pair[POP_SIZE],int n) {
	int c, i,r,temp;
	for (i = 0; i < n; i++) {
		rand_pair[i] = i + 1;
	}
	for (i = 0; i < n-1; i++) {
		c = n-1 - i;
		r = rand() % c;
		temp = rand_pair[c];
		rand_pair[c] = rand_pair[r];
		rand_pair[r] = temp;
	}
}