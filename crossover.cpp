#include<iostream>
#include<ctime>
#include"Header.h"

void crossover(chromosome population[POP_SIZE],int n_parent1,int n_parent2, int n_child1, int n_child2, int n_oper) {
	int i, cut, s, j, k;
	cut = (rand() % (n_oper-2)) + 1;
	//std::cout << " The cut position is " << cut << std::endl;
	// ------ CHILD1 ------ //
	for (i = 0; i < cut; i++) {
		population[n_child1-1].machine_id_sequence[i] = population[n_parent1-1].machine_id_sequence[i];
		population[n_child1-1].oper_sequence[i] = population[n_parent1-1].oper_sequence[i];
		population[n_child1-1].tool_id_sequence[i] = population[n_parent1-1].tool_id_sequence[i];
		population[n_child1-1].tad_id_sequence[i] = population[n_parent1-1].tad_id_sequence[i];
	}
	k = 0;
	for (i = 0; i < n_oper; i++) {
		s = 0;
		for (j = 0; j < cut; j++) {
			if (population[n_parent2-1].oper_sequence[i] == population[n_child1-1].oper_sequence[j]) { s = 1; }
		}
		if (s == 0) {
			population[n_child1-1].machine_id_sequence[cut+k] = population[n_parent2-1].machine_id_sequence[i];
			population[n_child1-1].oper_sequence[cut+k] = population[n_parent2-1].oper_sequence[i];
			population[n_child1-1].tool_id_sequence[cut+k] = population[n_parent2-1].tool_id_sequence[i];
			population[n_child1-1].tad_id_sequence[cut+k] = population[n_parent2-1].tad_id_sequence[i];
			k = k + 1;
		}
	}
	// ------ CHILD 2 ------ //
	for (i = 0; i < cut; i++) {
		population[n_child2-1].machine_id_sequence[i] = population[n_parent2-1].machine_id_sequence[i];
		population[n_child2-1].oper_sequence[i] = population[n_parent2-1].oper_sequence[i];
		population[n_child2-1].tool_id_sequence[i] = population[n_parent2-1].tool_id_sequence[i];
		population[n_child2-1].tad_id_sequence[i] = population[n_parent2-1].tad_id_sequence[i];
	}
	k = 0;
	for (i = 0; i < n_oper; i++) {
		s = 0;
		for (j = 0; j < cut; j++) {
			if (population[n_parent1-1].oper_sequence[i] == population[n_child2-1].oper_sequence[j]) { s = 1; }
		}
		if (s == 0) {
			population[n_child2-1].machine_id_sequence[cut + k] = population[n_parent1-1].machine_id_sequence[i];
			population[n_child2-1].oper_sequence[cut + k] = population[n_parent1-1].oper_sequence[i];
			population[n_child2-1].tool_id_sequence[cut + k] = population[n_parent1-1].tool_id_sequence[i];
			population[n_child2-1].tad_id_sequence[cut + k] = population[n_parent1-1].tad_id_sequence[i];
			k = k + 1;
		}
	}
	
}