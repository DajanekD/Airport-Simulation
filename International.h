#ifndef AIRPORT_SIMULATION_INTERNATIONAL_H
#define AIRPORT_SIMULATION_INTERNATIONAL_H
#include"structheader.h"


int adjacentFOUR(Node a, Node b, Node c, Node d);
int adjacentTOP(Node a,Node b,Node c,Node d,Node e);
int adjacentSIX(Node a,Node b,Node c,Node d,Node e, Node f);
int adjacentEIGHT(Node a,Node b,Node c,Node d,Node e,Node f,Node g,Node h);


vector<vector<Node>> internationalSimulation(vector<vector<Node>> t);  



#endif //AIRPORT_SIMULATION_INTERNATIONAL_H
