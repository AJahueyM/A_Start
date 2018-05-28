#ifndef __ASTART_H_
#define __ASTART_H_
#include "Path.h"
#include "Node.h"
#include "Utils.h"
#include "Coord.h"
#include <iostream>

class AStar{
public:
    static Path getPath(Coord start, Coord end, vector<vector<Node>>& maze);
private:
    static int heuristic(Node* start, Node* end);
};
#endif