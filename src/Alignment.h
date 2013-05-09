/*
 * Alignment.h
 *
 *  Created on: 8 May 2013
 *      Author: raviel
 */

#ifndef ALIGNMENT_H_
#define ALIGNMENT_H_

#include "Include.h"
//Aligns graph K to graph G using a greedy algorithm
void align_greedy(graph& G, node_array<int>& A, node_array<int>& B, graph& K,
		node_array<int>& V, node_array<int>& Z);

int same_compound_as(graph& G, node_array<int>& A, node_array<int>& B, int C);

int EC(string s, int n);

class Alignment {
public:
	Alignment();
	virtual ~Alignment();
};

#endif /* ALIGNMENT_H_ */
