/*-------------------------------------------------------------------------------
 * Copyright (c) 2013 Ibrahim Suzer.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/gpl.html
 *
 * Contributors:
 *     Ibrahim Suzer - initial API and implementation
 * -------------------------------------------------------------------------------*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <LEDA/graph/graph.h>
using leda::graph;
using leda::node;
using leda::edge;
using leda::node_array;

#include <LEDA/numbers/integer.h>
using leda::integer;

#include <LEDA/system/basic.h>
using leda::swap;

#include <LEDA/core/random_source.h>
using leda::random_source;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::min;

#include <cstdlib>
using std::abs;

#endif /* INCLUDE_H_ */
