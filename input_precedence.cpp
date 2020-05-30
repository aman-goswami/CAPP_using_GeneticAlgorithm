#include<iostream>
#include<ctime>
#include"Header.h"

int** input_precedence(int n_oper)
{
    int** precedence = 0;
    precedence = new int* [n_oper];
    std::cout << "Enter the Precedence Matrix" << std::endl;
    for (int h = 0; h < n_oper; h++)
    {
        precedence[h] = new int[n_oper];
        std::cout << "Enter the " << h + 1 << " row" << std::endl;
        for (int w = 0; w < n_oper; w++)
        {
             std::cin >> precedence[h][w];
        }
    }

    return precedence;
}