/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved.  Distributed under the terms of the GNU Public License v3.0
 * which can be found at "license.txt" or at: http://www.gnu.org/licenses/gpl.html
 * -------------------------------------------------------------------------------*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <LEDA/graphics/graphwin.h>
using leda::GraphWin;
using leda::gw_node_shape;
using leda::rectangle_node;
using leda::gw_edge_dir;
using leda::bidirected_edge;
using leda::gw_label_type;
using leda::user_label;
using leda::gw_position;
using leda::central_pos;
using leda::south_pos;



#include <LEDA/graphics/window.h>
using leda::window;

#include <LEDA/graphics/color.h>
using leda::color;
using leda::grey1;
using leda::grey2;
using leda::grey3;
using leda::invisible;
using leda::white;
using leda::red;
using leda::blue;
using leda::blue2;
using leda::orange;
using leda::violet;

#include <LEDA/geo/point.h>
using leda::point;

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

#include <LEDA/graph/basic_graph_alg.h>
using leda::DFS_NUM;


#include <LEDA/graph/node_list.h>
using leda::node_list;

#include <LEDA/numbers/integer.h>
using leda::integer;

#include <LEDA/system/basic.h>
using leda::swap;

#include <LEDA/core/array.h>
using leda::array;

#include <LEDA/core/string.h>
using leda::string;


#include <LEDA/system/stream.h>
using leda::string_ostream;


#include <LEDA/core/random_source.h>
using leda::random_source;

#include <LEDA/core/list.h>
using leda::list;

#include <LEDA/core/map.h>
using leda::map;


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
using std::stringstream;
using std::getline;






#endif /* INCLUDE_H_ */
