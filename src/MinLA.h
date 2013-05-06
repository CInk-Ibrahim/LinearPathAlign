/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/gpl.html
 *
 * Contributors:
 *     Ibrahim Suzer - initial API and implementation
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

//Applies Simulated Annealing for MinLa problem on graph with initial ordering A
void simulated_annealing(graph& G, node_array<int>& A);

class MinLA {
public:
	MinLA();
	virtual ~MinLA();

};

#endif /* MINLA_H_ */
