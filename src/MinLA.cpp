/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved.  Distributed under the terms of the GNU Public License v3.0
 * which can be found at "license.txt" or at: http://www.gnu.org/licenses/gpl.html
 * -------------------------------------------------------------------------------*/

#include "Include.h"
#include "MinLA.h"

int la_score(graph& G, node_array<int>& A) {
	edge e;
	int score = 0;

	forall_edges(e, G) {

		score = score + abs(A[G.source(e)] - A[G.target(e)]);
	}

	return score;
}

int la_score_flip2(graph& G, node_array<int>& A, node a, node b) {

	node_array<int> B = A;
	swap(A[a], A[b]);
	int score = 0;
	edge e;

	forall_inout_edges(e,a) {
		score = score + abs(A[G.source(e)] - A[G.target(e)]);
		//cout << A[G.source(e)] << " - " << A[G.target(e)] << " : " << score << endl;

	}
	forall_inout_edges(e,b) {
		if ((A[G.source(e)] != A[a]) && (A[G.target(e)] != A[a])) {
			score = score + abs(A[G.source(e)] - A[G.target(e)]);
			//cout << A[G.source(e)] << " - " << A[G.target(e)] << " : " << score << endl;
		}
	}

	forall_inout_edges(e,a) {
		score = score - abs(B[G.source(e)] - B[G.target(e)]);
		//cout << B[G.source(e)] << " - " << B[G.target(e)] << " : " << score << endl;
	}
	forall_inout_edges(e,b) {
		if ((B[G.source(e)] != B[a]) && (B[G.target(e)] != B[a])) {
			score = score - abs(B[G.source(e)] - B[G.target(e)]);
			//cout << B[G.source(e)] << " - " << B[G.target(e)] << " : " << score << endl;
		}
	}

	return score;

}

void flip2(graph& G, node_array<int>& A, node a, node b) {

	swap(A[a], A[b]);

}

void init_layout(graph& G, node_array<int>& A, int type) {

	/*type:
	 *1 - Normal
	 *2 - Random
	 *3 - Random BFS
	 *4 - BFS
	 *5 - DFS
	 */
	switch (type) {
	case 1:
		init_layout_normal(G, A);
		break;
	default:
		break;
	}

}

void init_layout_normal(graph& G, node_array<int>& A) {
	node v;
	int i = 1;

	forall_nodes(v, G) {
		A[v] = i;
		i++;
	}
}

void simulated_annealing(graph& G, node_array<int>& A) {

	cout << "Start SA" << endl;

	double temp = 10; //set initial temperature
	double temp_f = 0.2; //set finishing temperature
	double r = 20 * pow((double) G.number_of_nodes(), (double) 3 / 2); //set equilibrium rate (repeat times)
	double alpha = 0.95;	//cooling rate
	double E = 2.71828182845904523536; //e value

	cout << "r :" << r << endl;

	random_source S; //random number generator
	node u;
	node v;
	double z = 0; //Gain when flip2 is done

	while (temp >= temp_f) {	//While !frozen
		//cout << "Start temp loop" << endl;
		for (int i = 0; i < r; i++) {	//While !equilibrium (Repeat r times)
			//cout << "Repeat"<< i << endl;
			u = G.choose_node();	//get a random node
			v = G.choose_node();	//get a random node
			z = la_score_flip2(G, A, u, v);	//find gain of flip2 of u & v

			//cout << "G1 :" << A[u] << " - " << A[v] << " : " << z << endl;

			//find probability of flip
			double prob = pow(E, (double) z / temp);
			//cout << "prob : " <<prob << endl;
			//cout << "E : " << E << " z : " << z << " temp : " <<temp<<" z/temp : " << (z / temp) <<" prob : " <<prob <<endl;
			double x;
			prob = min((double) 1, prob);// if prob is bigger than 1 (there is - gain for flip2) do flip certainly
			S >> x;				//get a random number [0,1]
			if (x <= prob) {//if prob is smaller do with probability (based on temp and gain of flip2)
				flip2(G, A, u, v);	//flip places of u & v
			}
		}
		temp = temp * alpha; //drop temperature
	}
}

MinLA::MinLA() {
	// TODO Auto-generated constructor stub

}

MinLA::~MinLA() {
	// TODO Auto-generated destructor stub
}

