/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved.  Distributed under the terms of the GNU Public License v3.0
 * which can be found at "license.txt" or at: http://www.gnu.org/licenses/gpl.html
 * -------------------------------------------------------------------------------*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <LEDA/graph/graph.h>
using leda::graph;
using leda::node;
using leda::edge;

#include <LEDA/graph/node_array.h>
using leda::node_array;

#include <LEDA/graph/edge_array.h>
using leda::edge_array;

#include <LEDA/graph/graph_iterator.h>
using leda::DFS_It;
using leda::BFS_It;

#include <LEDA/numbers/integer.h>
using leda::integer;

#include <LEDA/system/basic.h>
using leda::swap;


#include <LEDA/core/array.h>
using leda::array;

#include <LEDA/core/random_source.h>
using leda::random_source;


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::iostream;

#include <algorithm>
using std::min;
using std::random_shuffle;

#include <cstdlib>
using std::abs;
using std::srand;
using std::atoi;

#include <string>
using std::string;
using std::getline;
using std::stringstream;

#endif /* INCLUDE_H_ */
