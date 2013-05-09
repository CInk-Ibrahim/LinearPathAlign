/*
 * Alignment.cpp
 *
 *  Created on: 8 May 2013
 *      Author: raviel
 */

#include "Alignment.h"
#include "Include.h"
#include "MinLA.h"

void align_greedy(graph& G, node_array<int>& A, node_array<int>& B, graph& K,
		node_array<int>& V, node_array<int>& Z) {

	node_list L;
	array<int> Li(G.number_of_nodes() + 1);

	node v;
	node u;
	forall_nodes(u,K) {
		forall_nodes(v,G) {
			if (Z[u] == B[v]) {
				V[u] = A[v];
				L.append(u);
				Li[V[u]] = 1;
			}
		}
	}

	int i = 1;
	forall_nodes(u,K) {
		while (Li[i] == 1) {
			if (i >= G.number_of_nodes())
				break;
			i++;
			cout << i;

		}
		if (V[u] == 0) {
			V[u] = i;
			Li[V[u]] = 1;
		}

	}

	simulated_annealing_protected(K, V, L);
}



int same_compound_as(graph& G, node_array<int>& A, node_array<int>& B, int C) {

	node v;
	forall_nodes(v,G) {
		if (B[v] == C) {
			return A[v];
		}

	}
	return 0;

}


Alignment::Alignment() {
	// TODO Auto-generated constructor stub

}

Alignment::~Alignment() {
	// TODO Auto-generated destructor stub
}

