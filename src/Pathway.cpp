/*
 * Pathway.cpp
 *
 *  Created on: 8 May 2013
 *      Author: raviel
 */

#include "Pathway.h"
#include "Include.h"

void create_edge_ec(graph& G, edge_array<int>& EC1, edge_array<int>& EC2,
		edge_array<int>& EC3, edge_array<int>& EC4, edge k, string EC) {

	std::string word;
	stringstream stream(EC);
	getline(stream, word, '.');
	int value = atoi(word.c_str()); //value = 45
	EC1[k] = value;
	getline(stream, word, '.');
	value = atoi(word.c_str()); //value = 45
	EC2[k] = value;
	getline(stream, word, '.');
	value = atoi(word.c_str()); //value = 45
	EC3[k] = value;
	getline(stream, word, '.');
	value = atoi(word.c_str()); //value = 45
	EC4[k] = value;
}

Pathway::Pathway() {
	// TODO Auto-generated constructor stub

}

Pathway::~Pathway() {
	// TODO Auto-generated destructor stub
}

