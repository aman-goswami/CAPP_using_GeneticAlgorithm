#include<iostream>
#include<ctime>
#include"Header.h"

void mutation(chromosome population[POP_SIZE],Operations oper_list[OPER_SIZE], int n_pop, int n_oper, float pm) {
	// n-machines,n_tad,n_tools = total no of machines/tads/tools
	int i,j,s,randi, rseq_n1, id1,oper_id1,id2,n_candi;
	for (i = 0; i < n_pop; i++) {
	if (((rand() % 100) + 1) < pm * 100) {
		//First Mutation
		rseq_n1 = rand() % n_oper;
		//std::cout << "Chromosome:" << i + 1 << "  machine mutations at:" << rseq_n1 + 1 << std::endl;
		id1 = population[i].machine_id_sequence[rseq_n1];
		oper_id1 = population[i].oper_sequence[rseq_n1];
		n_candi = oper_list[oper_id1-1].n_machine;
		id2 = oper_list[oper_id1-1].machine_id[rand()%n_candi];
		population[i].machine_id_sequence[rseq_n1] = id2;

		//Second Mutation
		rseq_n1 = rand() % n_oper;
		//std::cout << "Chromosome:" << i + 1 << "  machine mutations at:" << rseq_n1 + 1 << std::endl;
		id1 = population[i].machine_id_sequence[rseq_n1];
		oper_id1 = population[i].oper_sequence[rseq_n1];
		n_candi = oper_list[oper_id1 - 1].n_machine;
		id2 = oper_list[oper_id1 - 1].machine_id[rand() % n_candi];
		population[i].machine_id_sequence[rseq_n1] = id2;

	}

	}


	for (i = 0; i < n_pop; i++) {
		if (((rand() % 100) + 1) < pm * 100) {
			//First Mutation
			rseq_n1 = rand() % n_oper;
			//std::cout << "Chromosome:" << i + 1 << "  tool mutations at:" << rseq_n1 + 1 << std::endl;
			id1 = population[i].tool_id_sequence[rseq_n1];
			oper_id1 = population[i].oper_sequence[rseq_n1];

			n_candi = oper_list[oper_id1-1].n_tool;
			id2 = oper_list[oper_id1-1].tool_id[rand() % n_candi];
			population[i].tool_id_sequence[rseq_n1] = id2;

			//Second Mutation
			rseq_n1 = rand() % n_oper;
			//std::cout << "Chromosome:" << i + 1 << "  tool mutations at:" << rseq_n1 + 1 << std::endl;
			id1 = population[i].machine_id_sequence[rseq_n1];
			oper_id1 = population[i].oper_sequence[rseq_n1];
			n_candi = oper_list[oper_id1 - 1].n_machine;
			id2 = oper_list[oper_id1 - 1].machine_id[rand() % n_candi];
			population[i].machine_id_sequence[rseq_n1] = id2;
			}

		}

	



	for (i = 0; i < n_pop; i++) {
		if (((rand() % 100) + 1) < pm * 100) {
			// First Mutation
			rseq_n1 = rand() % n_oper;
			//std::cout << "Chromosome:" << i + 1 << "  tad mutations at:" << rseq_n1 + 1 << std::endl;
			id1 = population[i].tad_id_sequence[rseq_n1];
			oper_id1 = population[i].oper_sequence[rseq_n1];
			n_candi = oper_list[oper_id1-1].n_tad;
			id2 = oper_list[oper_id1-1].tad_id[rand() % n_candi];
			population[i].tad_id_sequence[rseq_n1] = id2;

			//Second Mutation
			rseq_n1 = rand() % n_oper;
			//std::cout << "Chromosome:" << i + 1 << "  tad mutations at:" << rseq_n1 + 1 << std::endl;
			id1 = population[i].machine_id_sequence[rseq_n1];
			oper_id1 = population[i].oper_sequence[rseq_n1];
			n_candi = oper_list[oper_id1 - 1].n_machine;
			id2 = oper_list[oper_id1 - 1].machine_id[rand() % n_candi];
			population[i].machine_id_sequence[rseq_n1] = id2;

		}

	}

	}
	
