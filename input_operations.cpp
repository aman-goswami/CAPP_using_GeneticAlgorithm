#include<iostream>
#include<ctime>
#include"Header.h"

Operations* input_operations(int n_opr)
{
	 Operations operation[OPER_SIZE];

	for (int i = 0; i < n_opr; i++) {
		std::cout << "Operation " << i + 1 << std::endl;
		std::cout << "Feature Id of Operation " << i + 1 << std::endl;
		std::cin >> operation[i].feature_id;
		std::cout << "Operation type of Operation " << i + 1 << std::endl;
		std::cin >> operation[i].operation_type;


		std::string input;
		int j = 0;

		std::cout << "Enter no of TAD candidates :  ";
		std::cin >> operation[i].n_tad;
		std::cout << "Enter all TAD candidates one by one" << std::endl;
		for (j = 0; j < operation[i].n_tad; j++) {
			std::cin >> operation[i].tad_id[j];
			
		}

		std::cout << "Enter no of Machine candidates :  ";
		std::cin >> operation[i].n_machine;
		std::cout << "Enter all Machine candidates one by one" << std::endl;
		for (j = 0; j < operation[i].n_machine; j++) {
			std::cin >> operation[i].machine_id[j];
			
		}

		std::cout << "Enter no of Tool candidates :  ";
		std::cin >> operation[i].n_tool;
		std::cout << "Enter all Tool candidates one by one" << std::endl;
		for (j = 0; j < operation[i].n_tool; j++) {
			std::cin >> operation[i].tool_id[j];
		}
		
		std::cout << std::endl;
	}
	return operation;
}