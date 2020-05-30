#include<iostream>
#include<ctime>
#include"Header.h"


void generate_population(chromosome population[POP_SIZE], int n_pop, int n_oper, Operations oper_list[OPER_SIZE], int precedence[OPER_SIZE][OPER_SIZE]) {
	int c_pop, c_seq, c_oper, randi,i;
	int sequence[OPER_SIZE];
	for (c_pop = 0; c_pop < n_pop; c_pop++) {
		gen_sequence(precedence,sequence,n_oper);
		//for (i = 0; i < n_oper; i++) { std::cout << " " << sequence[i] << " " << std::endl; }
		// generation c_pop chromosome
		for (c_oper = 0; c_oper < n_oper; c_oper++) {
			// creating operation sequence
			population[c_pop].oper_sequence[c_oper] = sequence[c_oper];
			// creating tad sequence
			randi = rand() % oper_list[sequence[c_oper]-1].n_tad;
			population[c_pop].tad_id_sequence[c_oper] = oper_list[sequence[c_oper]-1].tad_id[randi];
			// creating machine sequence
			randi = rand() % oper_list[sequence[c_oper]-1].n_machine;
			population[c_pop].machine_id_sequence[c_oper] = oper_list[sequence[c_oper]-1].machine_id[randi];
			// creating tool sequence
			randi = rand() % oper_list[sequence[c_oper]-1].n_tool;
			population[c_pop].tool_id_sequence[c_oper] = oper_list[sequence[c_oper]-1].tool_id[randi];
		}

	}
	
}