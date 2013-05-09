/*
 * Visualization.h
 *
 *  Created on: 8 May 2013
 *      Author: raviel
 */

#ifndef VISUALIZATION_H_
#define VISUALIZATION_H_

#include "Include.h"

void draw_arr(graph& G, node_array<int>& A, node_array<int>& B, graph& K,
		node_array<int>& V, node_array<int>& Z);

class Visualization {
public:
	Visualization();
	virtual ~Visualization();
};

#endif /* VISUALIZATION_H_ */
