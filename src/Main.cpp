/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved.  Distributed under the terms of the GNU Public License v3.0
 * which can be found at "license.txt" or at: http://www.gnu.org/licenses/gpl.html
 * -------------------------------------------------------------------------------*/

#include "Include.h"
#include "MinLA.h"

int main() {

	graph G;

	node v1 = G.new_node();
	node v2 = G.new_node();
	node v3 = G.new_node();
	node v4 = G.new_node();
	node v5 = G.new_node();
	node v6 = G.new_node();
	node v7 = G.new_node();
	node v8 = G.new_node();
	node v9 = G.new_node();

	G.new_edge(v2, v1);
	G.new_edge(v3, v1);
	G.new_edge(v3, v4);
	G.new_edge(v2, v7);
	G.new_edge(v4, v6);
	G.new_edge(v4, v5);
	G.new_edge(v4, v9);
	G.new_edge(v5, v8);
	G.new_edge(v5, v7);
	G.new_edge(v7, v9);

	node_array<int> A(G);

	//G.sort_nodes(A);

	init_layout(G, A, 1);

	cout << A[v1] << " - " << A[v2] << " - " << A[v3] << " - ";
	cout << A[v4] << " - " << A[v5] << " - " << A[v6] << " - ";
	cout << A[v7] << " - " << A[v8] << " - " << A[v9] << endl;
	cout << "LA Score : " << la_score(G, A) << endl;

	simulated_annealing(G, A);

	cout << A[v1] << " - " << A[v2] << " - " << A[v3] << " - ";
	cout << A[v4] << " - " << A[v5] << " - " << A[v6] << " - ";
	cout << A[v7] << " - " << A[v8] << " - " << A[v9] << endl;
	cout << "LA Score : " << la_score(G, A) << endl;

}
