#pragma once
#define OPER_SIZE 30
#define POP_SIZE 100
#define CANDI_SIZE 10
class Operations
{public:
	std::string feature_id;
	std::string operation_type;

	int n_tad;
	int tad_id[CANDI_SIZE];
	int n_machine;
	int machine_id[CANDI_SIZE];
	int n_tool;
	int tool_id[CANDI_SIZE];
};

class chromosome {
public:
	int oper_sequence[OPER_SIZE];
	int tad_id_sequence[OPER_SIZE];
	int machine_id_sequence[OPER_SIZE];
	int tool_id_sequence[OPER_SIZE];

	float cost;

};



Operations* input_operations(int n_opr);

int** input_precedence(int n_oper);

void gen_sequence(int precedence[OPER_SIZE][OPER_SIZE],int sequence[OPER_SIZE], int n_oper);

void generate_population(chromosome population[POP_SIZE], int n_pop, int n_oper, Operations oper_list[OPER_SIZE], int precedence[OPER_SIZE][OPER_SIZE]);
void calc_cost(chromosome population[POP_SIZE], int n_oper, int n_pop);
float mc(int machine_id);
float tc(int tool_id);
int del(int id1, int id2);
void rand_pair(int rand_pair[POP_SIZE], int n);
void crossover(chromosome population[POP_SIZE], int n_parent1, int n_parent2, int n_child1, int n_child2, int n_oper);
void mutation(chromosome population[POP_SIZE], Operations oper_list[OPER_SIZE], int n_pop, int n_oper, float pm);
void copy_pop(chromosome population[POP_SIZE], chromosome new_population[POP_SIZE], int n_copy, int n_paste, int n_oper);