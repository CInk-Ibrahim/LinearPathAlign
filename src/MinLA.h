/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved.  Distributed under the terms of the GNU Public License v3.0
 * which can be found at "license.txt" or at: http://www.gnu.org/licenses/gpl.html
 * -------------------------------------------------------------------------------*/

#ifndef MINLA_H_
#define MINLA_H_

#include "Include.h"

//Linear Arrangement Score of G based on arrangement A
int la_score(graph& G, node_array<int>& A);

//Return score change if node a and b changes ordering
int la_score_flip2(graph& G, node_array<int>& A, node a, node b);

//Changes ordering of node a and b
void flip2(graph& G, node_array<int>& A, node a, node b);

//Generates initial layout
void init_layout(graph& G, node_array<int>& A, int type);
//Type 1
void init_layout_normal(graph& G, node_array<int>& A);
//Type 2
void init_layout_rand(graph& G, node_array<int>& A);
//Type 3
void init_layout_rbfs(graph& G, node_array<int>& A);	//NOT IMPLEMENTED
//Type 4
void init_layout_bfs(graph& G, node_array<int>& A);
//Type 5
void init_layout_dfs(graph& G, node_array<int>& A);


//Applies Simulated Annealing for MinLa problem on graph with initial ordering A
void simulated_annealing(graph& G, node_array<int>& A);

void simulated_annealing_protected(graph& G, node_array<int>& A, node_list& L);

class MinLA {
public:
	MinLA();
	virtual ~MinLA();

};

#endif /* MINLA_H_ */
