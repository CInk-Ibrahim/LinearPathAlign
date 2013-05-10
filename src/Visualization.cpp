/*
 * Visualization.cpp
 *
 *  Created on: 8 May 2013
 *      Author: raviel
 */

#include "Visualization.h"
#include "Include.h"

void draw_arr(graph& G, node_array<int>& A, node_array<int>& B, graph& K,
		node_array<int>& V, node_array<int>& Z, array<int> Li) {

	GraphWin gw(G, 1000, 600, "Alignment");

	gw.win_init(0, 1000, 0);

	gw.display(window::center, window::center);
	//gw.get_window().draw_int_node(50, 50, 5, grey1);

	gw.set_node_width(35);
	gw.set_node_border_thickness(3, true);
	gw.set_edge_thickness(1.5);
	gw.set_node_label_type(leda::user_label);
	gw.set_edge_label_type(leda::user_label);
	gw.set_bg_color(white);
	gw.get_window().set_bg_color(white);
	gw.get_window().set_line_width(5);

	int nodes = G.number_of_nodes();

	int po1 = 100;
	int po2 = 400;

//Position Nodes
	node v;
	node_array<point> pos(G);

	forall_nodes(v,G) {

		string st;          //The string
		string_ostream te;  //temp as in temporary
		te << B[v];

		gw.set_user_label(v, te.str());
		gw.set_border_color(v, violet);
		gw.set_label_color(v, violet);
	}

	forall_nodes(v,G) {
		point p(po1 * A[v], po2);
		pos[v] = p;

	}
	gw.set_position(pos);

//Sort edges by lenght
	edge e;
	edge_array<int> Be(G);

	forall_edges(e,G) {
		Be[e] = abs(A[G.source(e)] - A[G.target(e)]);
	}
	G.sort_edges(Be);

//Set Bends
	int counter = 0;
	int lastl = 0;
	forall_edges(e,G) {

		if (Be[e] > 1) {

			int sour = A[G.source(e)];
			int targ = A[G.target(e)];
			int change = 0;
			if (sour > targ)
				change = 10;
			else if (sour < targ)
				change = -10;
			else
				change = 0;
			if (lastl == Be[e])
				counter = counter + 10;
			list<point> L;
			point p3(po1 * sour, po2 + 20);
			L.append(p3);
			point p1(po1 * sour, (po2 + 10 + Be[e] * 10 + counter));
			L.append(p1);
			point p2(po1 * targ + change, (po2 + 10 + Be[e] * 10 + counter));
			L.append(p2);
			point p4(po1 * targ + change, po2 + 20);
			L.append(p4);
			gw.set_bends(e, L, 5);
			//gw.set_direction(e, bidirected_edge);
			lastl = Be[e];

			//gw.set_source_anchor(e, p3);
			//gw.set_target_anchor(e, p4);

		}

	}

// First graph is done

	map<node, node> M;

	po1 = 100;
	po2 = 200;

	K.sort_nodes(V);

	forall_nodes(v,K) {
		point p(po1 * V[v], po2);
		node g = gw.new_node(p);
		M[v] = g;

		string st;          //The string
		string_ostream te;  //temp as in temporary
		te << Z[v];

		gw.set_user_label(g, te.str());
		gw.set_border_color(g, blue2);
		gw.set_label_color(g, blue2);

	}

	counter = 0;
	lastl = 0;

	forall_edges(e,K) {
		edge ee = gw.new_edge(M[G.source(e)], M[G.target(e)]);

		int score = abs(V[G.source(e)] - V[G.target(e)]);
		if (score > 1) {

			int sour = V[G.source(e)];
			int targ = V[G.target(e)];

			int change = 0;
			if (sour > targ)
				change = 10;
			else if (sour < targ)
				change = -10;
			else
				change = 0;
			if (lastl == score)
				counter = counter + 10;
			lastl = score;
			list<point> L;
			point p3(po1 * sour, po2 - 20);
			L.append(p3);
			point p1(po1 * sour, (po2 - 10 - score * 10 - counter));
			L.append(p1);
			point p2(po1 * targ + change, (po2 - 10 - score * 10 - counter));
			L.append(p2);
			point p4(po1 * targ + change, po2 - 20);
			L.append(p4);
			gw.set_bends(ee, L, 5);
			//gw.set_direction(e, bidirected_edge);

			//gw.set_source_anchor(e, p3);
			//gw.set_target_anchor(e, p4);

		}
	}

	int i = 1;
	int x1 = 50;
	int x2 = 50;
	int y1 = 50;
	int y2 = 550;
	color c;

	while (i <= nodes) {
		cout << Li[i] << endl;

		if (Li[i] == 1) {
			c = blue;
			while ((i < nodes) && (Li[i] == 1)) {
				x2 = x2 + 100;
				i++;

			}
			if ((i == nodes) && (Li[i] == 1)) {
				x2 = x2 + 100;
				i++;
			}

			gw.get_window().draw_rectangle(x1, y1, x2-5, y2, c);
			x1 = x2;

		} else {
			c = red;
			while ((i < nodes) && (Li[i] != 1)) {
				x2 = x2 + 100;
				i++;
			}
			if ((i == nodes) && (Li[i] != 1)) {
				x2 = x2 + 100;
				i++;
			}

			gw.get_window().draw_rectangle(x1, y1, x2-5, y2, c);
			x1 = x2;
		}

	}

	//gw.get_window().draw_rectangle(50, 50, 400, 400, red);

	gw.edit();

	cout << "Press RETURN to continue... ";
	char cha;
	cin.get(cha);

	// here we will fill in code for algorithms on G later

}

Visualization::Visualization() {
	// TODO Auto-generated constructor stub

}

Visualization::~Visualization() {
	// TODO Auto-generated destructor stub
}

