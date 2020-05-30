#include<iostream>
#include<ctime>
#include"Header.h"

// Max operations = 70
// Max TAD Candidates = 10
// Max Machine candidates = 30
// Max Tool Candidates = 15
// Precedence matrix [column] [row]

int main()
{
	srand(time(0));
	int i,j,opti_chromosome, opti_cost;
	int n_oper = 23;

	// ------ OPERATIONS INPUT ------ //
	// TAD ID: -X = 1	+X = 2	 -Y = 3		+Y = 4  	-Z = 5		+Z = 6 //
	Operations oper_list[OPER_SIZE];
		oper_list[0].feature_id = "F1";
	oper_list[0].operation_type = "Drilling";
	oper_list[0].n_tad = 2;
	oper_list[0].tad_id[0] = 5;
	oper_list[0].tad_id[1] = 6;
	oper_list[0].n_machine = 3;
	oper_list[0].machine_id[0] = 1;
	oper_list[0].machine_id[1] = 2;
	oper_list[0].machine_id[2] = 3;
	oper_list[0].n_tool = 1;
	oper_list[0].tool_id[0] =  1 ;
	
	
	oper_list[1].feature_id = "F2";
	oper_list[1].operation_type = "Drilling";
	oper_list[1].n_tad = 2;
	oper_list[1].tad_id[0] = 5;
	oper_list[1].tad_id[1] = 6;
	oper_list[1].n_machine = 3;
	oper_list[1].machine_id[0] = 1;
	oper_list[1].machine_id[1] = 2;
	oper_list[1].machine_id[2] = 3;
	oper_list[1].n_tool = 1;
	oper_list[1].tool_id[0] =  1 ;
	

	oper_list[2].feature_id = "F3";
	oper_list[2].operation_type = "Milling";
	oper_list[2].n_tad = 2;
	oper_list[2].tad_id[0] =  6 ;
	oper_list[2].tad_id[1] =  5 ;
	oper_list[2].n_machine = 2;
	oper_list[2].machine_id[0] = 2;
	oper_list[2].machine_id[1] = 3;
	oper_list[2].n_tool = 1;
	oper_list[2].tool_id[0] =  7;

	oper_list[3].feature_id = "F4";
	oper_list[3].operation_type = "Milling";
	oper_list[3].n_tad = 2;
	oper_list[3].tad_id[0] = 4;
	oper_list[3].tad_id[1] = 5;
	oper_list[3].n_machine = 2;
	oper_list[3].machine_id[0] = 2;
	oper_list[3].machine_id[1] = 2;
	oper_list[3].machine_id[2] = 3;
	oper_list[3].n_tool = 2;
	oper_list[3].tool_id[0] = 5;
	oper_list[3].tool_id[1] = 6;

	oper_list[4].feature_id = "F5";
	oper_list[4].operation_type = "Milling";
	oper_list[4].n_tad = 1;
	oper_list[4].tad_id[0] = 4;
	oper_list[4].n_machine = 2;
	oper_list[4].machine_id[0] = 2;
	oper_list[4].machine_id[1] = 3;
	oper_list[4].n_tool = 2;
	oper_list[4].tool_id[0] = 5;
	oper_list[4].tool_id[1] = 6;

	oper_list[5].feature_id = "F6";
	oper_list[5].operation_type = "Milling";
	oper_list[5].n_tad = 1;
	oper_list[5].tad_id[0] = 4;
	oper_list[5].n_machine = 2;
	oper_list[5].machine_id[0] = 2;
	oper_list[5].machine_id[1] = 3;
	oper_list[5].n_tool = 2;
	oper_list[5].tool_id[0] = 5;
	oper_list[5].tool_id[1] = 6;

	oper_list[6].feature_id = "F7";
	oper_list[6].operation_type = "Drilling";
	oper_list[6].n_tad = 2;
	oper_list[6].tad_id[0] = 6;
	oper_list[6].tad_id[1] = 5;
	oper_list[6].n_machine = 3;
	oper_list[6].machine_id[0] = 1;
	oper_list[6].machine_id[1] = 2;
	oper_list[6].machine_id[2] = 3;
	oper_list[6].n_tool = 1;
	oper_list[6].tool_id[0] = 2;

	oper_list[7].feature_id = "F7";
	oper_list[7].operation_type = "Reaming";
	oper_list[7].n_tad = 2;
	oper_list[7].tad_id[0] = 6;
	oper_list[7].tad_id[1] = 5;
	oper_list[7].n_machine = 3;
	oper_list[7].machine_id[0] = 1;
	oper_list[7].machine_id[1] = 2;
	oper_list[7].machine_id[2] = 3;
	oper_list[7].n_tool = 1;
	oper_list[7].tool_id[0] = 3;


	oper_list[8].feature_id = "F7";
	oper_list[8].operation_type = "Boring";
	oper_list[8].n_tad = 2;
	oper_list[8].tad_id[0] = 6;
	oper_list[8].tad_id[1] = 5;
	oper_list[8].n_machine = 2;
	oper_list[8].machine_id[0] = 3;
	oper_list[8].machine_id[1] = 4;
	oper_list[8].n_tool = 1;
	oper_list[8].tool_id[0] = 4;

	oper_list[9].feature_id = "F8";
	oper_list[9].operation_type = "Drilling";
	oper_list[9].n_tad = 1;
	oper_list[9].tad_id[0] = 5;
	oper_list[9].n_machine = 3;
	oper_list[9].machine_id[0] = 1;
	oper_list[9].machine_id[1] = 2;
	oper_list[9].machine_id[2] = 3;
	oper_list[9].n_tool = 1;
	oper_list[9].tool_id[0] = 1;

	oper_list[10].feature_id = "F9";
	oper_list[10].operation_type = "Drilling";
	oper_list[10].n_tad = 2;
	oper_list[10].tad_id[0] = 6;
	oper_list[10].tad_id[1] = 5;
	oper_list[10].n_machine = 3;
	oper_list[10].machine_id[0] = 1;
	oper_list[10].machine_id[1] = 2;
	oper_list[10].machine_id[2] = 3;
	oper_list[10].n_tool = 1;
	oper_list[10].tool_id[0] = 2;

	oper_list[11].feature_id = "F9";
	oper_list[11].operation_type = "Reaming";
	oper_list[11].n_tad = 2;
	oper_list[11].tad_id[0] = 6;
	oper_list[11].tad_id[1] = 5;
	oper_list[11].n_machine = 3;
	oper_list[11].machine_id[0] = 1;
	oper_list[11].machine_id[1] = 2;
	oper_list[11].machine_id[2] = 3;
	oper_list[11].n_tool = 1;
	oper_list[11].tool_id[0] = 3;

	oper_list[12].feature_id = "F9";
	oper_list[12].operation_type = "Boring";
	oper_list[12].n_tad = 2;
	oper_list[12].tad_id[0] = 6;
	oper_list[12].tad_id[1] = 5;
	oper_list[12].n_machine = 2;
	oper_list[12].machine_id[0] = 3;
	oper_list[12].machine_id[1] = 4;
	oper_list[12].n_tool = 1;
	oper_list[12].tool_id[0] = 4;

	oper_list[13].feature_id = "F10";
	oper_list[13].operation_type = "Milling";
	oper_list[13].n_tad = 1;
	oper_list[13].tad_id[0] = 2;
	oper_list[13].n_machine = 2;
	oper_list[13].machine_id[0] = 2;
	oper_list[13].machine_id[1] = 3;
	oper_list[13].n_tool = 2;
	oper_list[13].tool_id[0] = 5;
	oper_list[13].tool_id[1] = 6;

	oper_list[14].feature_id = "F11";
	oper_list[14].operation_type = "Drilling";
	oper_list[14].n_tad = 1;
	oper_list[14].tad_id[0] = 5;
	oper_list[14].n_machine = 3;
	oper_list[14].machine_id[0] = 1;
	oper_list[14].machine_id[1] = 2;
	oper_list[14].machine_id[2] = 3;
	oper_list[14].n_tool = 1;
	oper_list[14].tool_id[0] = 1;

	oper_list[15].feature_id = "F12";
	oper_list[15].operation_type = "Drilling";
	oper_list[15].n_tad = 1;
	oper_list[15].tad_id[0] = 5;
	oper_list[15].n_machine = 3;
	oper_list[15].machine_id[0] = 1;
	oper_list[15].machine_id[1] = 2;
	oper_list[15].machine_id[2] = 3;
	oper_list[15].n_tool = 1;
	oper_list[15].tool_id[0] = 1;

	oper_list[16].feature_id = "F13";
	oper_list[16].operation_type = "Milling";
	oper_list[16].n_tad = 2;
	oper_list[16].tad_id[0] = 3;
	oper_list[16].tad_id[1] = 5;
	oper_list[16].n_machine = 2;
	oper_list[16].machine_id[0] = 2;
	oper_list[16].machine_id[1] = 3;
	oper_list[16].n_tool = 2;
	oper_list[16].tool_id[0] = 5;
	oper_list[16].tool_id[1] = 8;

	oper_list[17].feature_id = "F14";
	oper_list[17].operation_type = "Milling";
	oper_list[17].n_tad = 2;
	oper_list[17].tad_id[0] = 3;
	oper_list[17].tad_id[1] = 5;
	oper_list[17].n_machine = 2;
	oper_list[17].machine_id[0] = 2;
	oper_list[17].machine_id[1] = 3;
	oper_list[17].n_tool = 2;
	oper_list[17].tool_id[0] = 5;
	oper_list[17].tool_id[1] = 6;

	oper_list[18].feature_id = "F15";
	oper_list[18].operation_type = "Drilling";
	oper_list[18].n_tad = 2;
	oper_list[18].tad_id[0] = 5;
	oper_list[18].tad_id[1] = 6;
	oper_list[18].n_machine = 3;
	oper_list[18].machine_id[0] = 1;
	oper_list[18].machine_id[1] = 2;
	oper_list[18].machine_id[2] = 3;
	oper_list[18].n_tool = 1;
	oper_list[18].tool_id[0] = 1;

	oper_list[19].feature_id = "F16";
	oper_list[19].operation_type = "Drilling";
	oper_list[19].n_tad = 2;
	oper_list[19].tad_id[0] = 6;
	oper_list[19].tad_id[1] = 5;
	oper_list[19].n_machine = 3;
	oper_list[19].machine_id[0] = 1;
	oper_list[19].machine_id[1] = 2;
	oper_list[19].machine_id[2] = 3;
	oper_list[19].n_tool = 1;
	oper_list[19].tool_id[0] = 1;

	oper_list[20].feature_id = "F17";
	oper_list[20].operation_type = "Milling";
	oper_list[20].n_tad = 1;
	oper_list[20].tad_id[0] = 3;
	oper_list[20].n_machine = 2;
	oper_list[20].machine_id[0] = 2;
	oper_list[20].machine_id[1] = 3;
	oper_list[20].n_tool = 2;
	oper_list[20].tool_id[0] = 5;
	oper_list[20].tool_id[1] = 6;

	oper_list[21].feature_id = "F18";
	oper_list[21].operation_type = "Drilling";
	oper_list[21].n_tad = 1;
	oper_list[21].tad_id[0] = 3;
	oper_list[21].n_machine = 3;
	oper_list[21].machine_id[0] = 1;
	oper_list[21].machine_id[1] = 2;
	oper_list[21].machine_id[2] = 3;
	oper_list[21].n_tool = 1;
	oper_list[21].tool_id[0] = 1;

	oper_list[22].feature_id = "F19";
	oper_list[22].operation_type = "Drilling";
	oper_list[22].n_tad = 1;
	oper_list[22].tad_id[0] = 3;
	oper_list[22].n_machine = 3;
	oper_list[22].machine_id[0] = 1;
	oper_list[22].machine_id[1] = 2;
	oper_list[22].machine_id[2] = 3;
	oper_list[22].n_tool = 1;
	oper_list[22].tool_id[0] = 1;


	
	// ------ PRECEDENCE MATRIX ------ //
		int pm[OPER_SIZE][OPER_SIZE] = 
		 //  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23
		  { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//1
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//2
			{1, 1, 0, 1, 0, 0, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//3
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//4
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},	//5
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},	//6
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//7
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//8
			{0, 0, 0, 0, 0, 0, 1, 1, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0}, //9
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0}, //10
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//11
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//12
			{0, 0, 0, 0, 0, 0, 1, 1, 1, 0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//13
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},	//14
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},	//15
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0},	//16
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  1,  0,  0},	//17
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  1,  0,  0}, //18
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  1,  0,  0}, //19
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},	//20
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},	//21
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  1,  0,  0},	//22
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  1,  1,  0},}; //23

		chromosome population[POP_SIZE];
		chromosome new_population[POP_SIZE];
		// n_pop must be divisible by 4
		int n_pop = 100;
		int iter = 0;
		int pairs[POP_SIZE];
		generate_population(population, n_pop, n_oper, oper_list, pm);
		calc_cost(population, n_oper, n_pop);
		

		for (iter = 0; iter < 250; iter++) {
			// ---------- TOURNAMENT ---------- //
			rand_pair(pairs, n_pop);
			//std::cout << "random pairs are:" << std::endl;
			//for (i = 0; i < n_pop; i++) { std::cout << "  " << pairs[i]<<std::endl; }
			
			for (i = 0; i < n_pop / 2; i++) {
				//std::cout << " pair:" << pairs[2 * i] - 1 + 1 << " vs " << pairs[(2 * i) + 1] - 1+1<<std::endl;
				if (population[pairs[2*i]-1].cost < population[pairs[(2 * i) + 1]-1].cost) {
					copy_pop(population, new_population, pairs[(2 * i)]-1, i, n_oper);
					//std::cout << "chromosome:"<< pairs[2 * i] << " wins" << std::endl;
				}
				else {
					copy_pop(population, new_population, pairs[(2 * i)+1]-1,i, n_oper);
					//std::cout << "chromosome:" << pairs[(2 * i) + 1] << " wins" << std::endl;
				}
			}

			// ---------- CROSSOVER ----------//
			for (i = 0; i < n_pop / 4; i++) {
				crossover(new_population, (2*i)+1, (2*i)+2, (2 * i)+(n_pop/2)+1, (2 * i) + 2+(n_pop/2), n_oper);
			}
			//---------- MUTATION ----------//
			mutation(new_population, oper_list, n_pop, n_oper, 0.2); 
			// ---------- POPULATION UPDATE ---------- //
			for (i = 0; i < n_pop; i++) {
				copy_pop(new_population, population, i, i, n_oper);
			}
			calc_cost(population, n_oper, n_pop);
			// ---------- OPTIMAL CHROMOSOME ---------- //
			opti_cost = population[0].cost;
			opti_chromosome = 0;
			for (i = 1; i < n_pop; i++) {
				if (population[i].cost < opti_cost) {
					opti_cost = population[i].cost;
					opti_chromosome = i;
				}
			}
			std::cout <<"Iteration:"<<iter<< "	Least cost:" << opti_cost << std::endl;
			//std::cout << opti_cost << std::endl;
		}
		
		std::cout << "||----------- Optimal Chromosome:" << opti_chromosome + 1 << " ----------||" << "     Cost:" << population[opti_chromosome].cost << std::endl;
		for (i = 0; i < n_oper; i++) {
			std::cout << i + 1 << ": Operation: " << population[opti_chromosome].oper_sequence[i];
			std::cout << "		Machine id: " << population[opti_chromosome].machine_id_sequence[i];
			std::cout << "		Tool id: " << population[opti_chromosome].tool_id_sequence[i];
			std::cout << "		Tad id: " << population[opti_chromosome].tad_id_sequence[i] << std::endl;

		}
}