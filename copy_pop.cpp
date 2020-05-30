#include<iostream>
#include<ctime>
#include"Header.h"

void copy_pop(chromosome population[POP_SIZE], chromosome new_population[POP_SIZE], int n_copy, int n_paste,int n_oper) {
	int j;

	new_population[n_paste].cost = population[n_copy].cost;
		for (j = 0; j < n_oper; j++) {
			new_population[n_paste].oper_sequence[j] = population[n_copy].oper_sequence[j];
			new_population[n_paste].machine_id_sequence[j] = population[n_copy].machine_id_sequence[j];
			new_population[n_paste].tad_id_sequence[j] = population[n_copy].tad_id_sequence[j];
			new_population[n_paste].tool_id_sequence[j] = population[n_copy].tool_id_sequence[j];
			
		}
	
}