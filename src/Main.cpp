/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved.  Distributed under the terms of the GNU Public License v3.0
 * which can be found at "license.txt" or at: http://www.gnu.org/licenses/gpl.html
 * -------------------------------------------------------------------------------*/

#include "Include.h"
#include "MinLA.h"
#include "Pathway.h"

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

	init_layout(G, A, 2);

	cout << A[v1] << " - " << A[v2] << " - " << A[v3] << " - ";
	cout << A[v4] << " - " << A[v5] << " - " << A[v6] << " - ";
	cout << A[v7] << " - " << A[v8] << " - " << A[v9] << endl;
	cout << "LA Score : " << la_score(G, A) << endl;

	simulated_annealing(G, A);

	cout << A[v1] << " - " << A[v2] << " - " << A[v3] << " - ";
	cout << A[v4] << " - " << A[v5] << " - " << A[v6] << " - ";
	cout << A[v7] << " - " << A[v8] << " - " << A[v9] << endl;
	cout << "LA Score : " << la_score(G, A) << endl;

	//Glycolysis / Gluconeogenesis - Homo sapiens (human)

	graph K;

	node k1 = K.new_node();
	node k2 = K.new_node();
	node k3 = K.new_node();
	node k4 = K.new_node();
	node k5 = K.new_node();
	node k6 = K.new_node();
	node k7 = K.new_node();
	node k8 = K.new_node();
	node k9 = K.new_node();
	node k10 = K.new_node();
	node k11 = K.new_node();
	node k12 = K.new_node();
	node k13 = K.new_node();

	node_array<int> V(K);
	V[k1] = 103;
	V[k2] = 668;
	V[k3] = 267;
	V[k4] = 5345;
	V[k5] = 1172;
	V[k6] = 221;
	V[k7] = 5378;

	edge ke1 = K.new_edge(k1, k2);
	edge ke2 = K.new_edge(k2, k1);
	edge ke3 = K.new_edge(k2, k3);
	edge ke4 = K.new_edge(k3, k2);
	edge ke5 = K.new_edge(k3, k2);
	edge ke6 = K.new_edge(k3, k2);
	edge ke7 = K.new_edge(k2, k4);
	edge ke8 = K.new_edge(k4, k2);
	edge ke9 = K.new_edge(k2, k5);
	edge ke10 = K.new_edge(k5, k2);
	edge ke11 = K.new_edge(k3, k6);
	edge ke12 = K.new_edge(k6, k3);
	edge ke13 = K.new_edge(k5, k4);
	edge ke14 = K.new_edge(k4, k5);
	edge ke15 = K.new_edge(k6, k5);
	edge ke16 = K.new_edge(k6, k5);
	edge ke17 = K.new_edge(k6, k5);
	edge ke18 = K.new_edge(k4, k7);
	edge ke19 = K.new_edge(k7, k4);

	edge_array<int> EC1(K);
	edge_array<int> EC2(K);
	edge_array<int> EC3(K);
	edge_array<int> EC4(K);
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke1, "5.4.2.2");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke2, "5.4.2.2");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke3, "3.1.3.9");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke4, "2.7.1.1");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke5, "2.7.1.2");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke6, "2.7.1.147");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke7, "5.3.1.9");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke8, "5.3.1.9");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke9, "5.3.1.9");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke10, "5.3.1.9");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke11, "5.1.3.3");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke12, "5.1.3.3");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke13, "5.3.1.9");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke14, "5.3.1.9");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke15, "2.7.1.1");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke16, "2.7.1.2");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke17, "2.7.1.147");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke18, "2.7.1.11");
	create_edge_ec(K, EC1, EC2, EC3, EC4, ke19, "3.1.3.11");

	cout << EC1[ke1] << EC2[ke1] << EC3[ke1] << EC4[ke1] << endl;

	init_layout(K, V, 4);

	cout << V[k1] << " - " << V[k2] << " - " << V[k3] << " - ";
	cout << V[k4] << " - " << V[k5] << " - " << V[k6] << " - ";
	cout << V[k7] << endl;
	cout << "LA Score : " << la_score(K, V) << endl;

	simulated_annealing(K, V);

	cout << V[k1] << " - " << V[k2] << " - " << V[k3] << " - ";
	cout << V[k4] << " - " << V[k5] << " - " << V[k6] << " - ";
	cout << V[k7] << endl;
	cout << "LA Score : " << la_score(K, V) << endl;

}
