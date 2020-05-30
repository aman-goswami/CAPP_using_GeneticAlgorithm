#include<iostream>
#include<ctime>
#include"Header.h"

void gen_sequence(int precedence[OPER_SIZE][OPER_SIZE], int sequence[OPER_SIZE], int n_oper) {
	// precedence_matrix = [column][row]
	// Variable Declaration
	int i, j, t, s, r, c, randi, r_oper;
	int temp[OPER_SIZE];
	int copy_precedence[OPER_SIZE][OPER_SIZE];

	//Creating copy of precedence matrix
	for (i = 0; i < n_oper; i++) {
		for (j = 0; j < n_oper; j++) {
			copy_precedence[i][j] = precedence[i][j];
		}
	}

	int c_sequence = 0;

	while (c_sequence < n_oper) {
		t = 0;
		for (r = 0; r < n_oper; r++) {
			s = 0;
			for (c = 0; c < n_oper; c++) {
				if (copy_precedence[c][r] == 1) { s = s + 1; }
			}

			if (s == 0) { temp[t] = r; t = t + 1; }
		}
		
		randi = rand() % t;
		r_oper = temp[randi];
		sequence[c_sequence] = r_oper + 1;

		for (r = 0; r < n_oper; r++) { copy_precedence[r_oper][r] = 0; }
		copy_precedence[r_oper][r_oper] = 1;
		c_sequence = c_sequence + 1;
	}




}