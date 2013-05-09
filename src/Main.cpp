/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved.  Distributed under the terms of the GNU Public License v3.0
 * which can be found at "license.txt" or at: http://www.gnu.org/licenses/gpl.html
 * -------------------------------------------------------------------------------*/

#include "Include.h"
#include "MinLA.h"
#include "Visualization.h"
#include "Alignment.h"
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

	init_layout(G, A, 4);

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

	K.new_edge(k1, k2);
	K.new_edge(k2, k1);
	K.new_edge(k2, k3);
	K.new_edge(k3, k2);
	K.new_edge(k3, k2);
	K.new_edge(k3, k2);
	K.new_edge(k2, k4);
	K.new_edge(k4, k2);
	K.new_edge(k2, k5);
	K.new_edge(k5, k2);
	K.new_edge(k3, k6);
	K.new_edge(k6, k3);
	K.new_edge(k5, k4);
	K.new_edge(k4, k5);
	K.new_edge(k6, k5);
	K.new_edge(k6, k5);
	K.new_edge(k6, k5);
	K.new_edge(k4, k7);
	K.new_edge(k7, k4);

	node_array<int> Z(K);
	node_array<int> V(K);
	edge_array<string> E2(K);
	Z[k1] = 103;
	Z[k2] = 668;
	Z[k3] = 267;
	Z[k4] = 5345;
	Z[k5] = 1172;
	Z[k6] = 221;
	Z[k7] = 5378;

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

	graph KK;

	node kk1 = KK.new_node();
	node kk2 = KK.new_node();
	node kk3 = KK.new_node();
	node kk4 = KK.new_node();
	node kk5 = KK.new_node();
	node kk6 = KK.new_node();
	node kk7 = KK.new_node();

	KK.new_edge(kk1, kk2);
	KK.new_edge(kk2, kk1);
	KK.new_edge(kk2, kk3);
	KK.new_edge(kk3, kk2);
	KK.new_edge(kk3, kk2);
	KK.new_edge(kk3, kk2);
	KK.new_edge(kk2, kk4);
	KK.new_edge(kk4, kk2);
	KK.new_edge(kk2, kk5);
	KK.new_edge(kk5, kk2);
	KK.new_edge(kk3, kk6);
	KK.new_edge(kk6, kk3);
	KK.new_edge(kk5, kk4);
	KK.new_edge(kk4, kk5);
	KK.new_edge(kk6, kk5);
	KK.new_edge(kk6, kk5);
	KK.new_edge(kk6, kk5);
	KK.new_edge(kk4, kk7);
	KK.new_edge(kk7, kk4);

	node_array<int> ZZ(KK);
	node_array<int> VV(KK);
	edge_array<string> EE2(KK);
	ZZ[kk1] = 103;
	//ZZ[kk2] = 668;
	ZZ[kk2] = 600;
	//ZZ[kk3] = 267;
	ZZ[kk3] = 500;
	ZZ[kk4] = 5345;
	ZZ[kk5] = 1172;
	ZZ[kk6] = 221;
	ZZ[kk7] = 5378;



	/*
	 init_layout(KK, VV, 4);
	 cout << VV[kk1] << " - " << VV[kk2] << " - " << VV[kk3] << " - ";
	 cout << " - " << VV[kk5] << " - " << VV[kk6] << " - ";
	 cout << VV[kk7] << endl;
	 cout << "LA Score : " << la_score(KK, VV) << endl;

	 simulated_annealing(KK, VV);
	 cout << VV[kk1] << " - " << VV[kk2] << " - " << VV[kk3] << " - ";
	 cout <<  " - " << VV[kk5] << " - " << VV[kk6] << " - ";
	 cout << VV[kk7] << endl;
	 cout << "LA Score : " << la_score(KK, VV) << endl;
	 //draw_arr(G, A, K, V);

	 */
	align_greedy(K, V, Z, KK, VV, ZZ);
	draw_arr(K, V, Z, KK, VV, ZZ);

	//align_greedy(K, V, Z, G, A, A);
	//draw_arr(K, V, Z, G, A, A);

}
