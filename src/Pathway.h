/*
 * Pathway.h
 *
 *  Created on: 8 May 2013
 *      Author: raviel
 */

#ifndef PATHWAY_H_
#define PATHWAY_H_

#include "Include.h"

//Fills EC edge arrays with required values by parsing string input
void create_edge_ec(graph& G, edge_array<int>& EC1, edge_array<int>& EC2,
		edge_array<int>& EC3, edge_array<int>& EC4, edge k, string EC);

class Pathway {
public:
	Pathway();
	virtual ~Pathway();
};

#endif /* PATHWAY_H_ */
