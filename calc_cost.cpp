#include<iostream>
#include<ctime>
#include"Header.h"

// MC - Machine operating cost 
// TC - Tool operating cost 
// MCC - Machine changing cost - 2 adjacent operation but different machine
// SCC - Setup changing cost - 2 adjacent operation, same machine but different TAD
// TCC - Tool changing cost - 2 adjacent operation, same machine but different tool


void calc_cost(chromosome population[POP_SIZE], int n_oper,int n_pop) {
                // COSTS //
    float mcc = 300;
    float scc = 90;
    float tcc = 10;
    float mc_cost, tc_cost, mcc_cost, scc_cost, tcc_cost;
    float cost;
    int i,j;
    for (j = 0; j < n_pop; j++) {
        
        cost = mc(population[j].machine_id_sequence[0]) + tc(population[j].tool_id_sequence[0]);
        for (i = 1; i < n_oper; i++) {
            
            mc_cost = mc(population[j].machine_id_sequence[i]);
            tc_cost = tc(population[j].tool_id_sequence[i]);
            mcc_cost = mcc * del(population[j].machine_id_sequence[i], population[j].machine_id_sequence[i - 1]);
            scc_cost = scc * (1 - del(population[j].machine_id_sequence[i], population[j].machine_id_sequence[i - 1])) * del(population[j].tad_id_sequence[i], population[j].tad_id_sequence[i - 1]);
            tcc_cost = tcc * (1 - del(population[j].machine_id_sequence[i], population[j].machine_id_sequence[i - 1])) * del(population[j].tool_id_sequence[i], population[j].tool_id_sequence[i - 1]);
            cost = cost + mc_cost + tc_cost + mcc_cost + scc_cost + tcc_cost;
            
        }
        population[j].cost = cost;
    }


}

float mc(int machine_id) {
    // Machine Costs = [10, 35, 60, 50]
    float mc;
    switch (machine_id) {
    case 1 :
        mc = 10;
        break;
    case 2:
        mc = 35;
        break;
    case 3:
        mc = 60;
        break;
    case 4:
        mc = 50;
        break;
    
    }
    
    return mc;
}

float tc(int tool_id) {
    // Tool Costs = { 3,3,8,15,10,15,10,10 }
    float tc;
    switch (tool_id) {
    case 1:
        tc = 3;
        break;
    case 2:
        tc = 3;
        break;
    case 3:
        tc = 8;
        break;
    case 4:
        tc = 15;
        break;
    case 5:
        tc = 10;
        break;
    case 6:
        tc = 15;
        break;
    case 7:
        tc = 10;
        break;
    case 8:
        tc = 10;
        break;
    }
    return tc;
}

int del(int id1, int id2) {
    int r;
    if (id1 == id2) { r = 0; }
    else { r = 1; }
    return r;
}