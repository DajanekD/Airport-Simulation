#include"structheader.h"
using namespace std;

// Corners = 3 Adjacent (Top Right, Bottom Right, Bottom Left, Bottom Right)
int adjacentCorners3(Node a, Node b, Node c);
// Sides = 5 Adjacents (Top, Bottom, Left, Right)            
int adjacentSides5(Node a,Node b,Node c,Node d,Node e);
// Middle = 8 Adjacents 
int adjacentMid8(Node a,Node b,Node c,Node d,Node e,Node f,Node g,Node h);

// Cargo Simulation
vector<vector<Node>> cargoSimulation(vector<vector<Node>> t, int workers);  

// Pollution Noise 
int pollutionNoise(vector<vector<struct Node>> t);

// For Pollution Noise 
vector<vector<int>> pollution(vector<vector<Node>> t);
  
// Good Provided for Internationall
int goods(vector<vector<Node>> t);                   

void printPollution(std::vector<vector<int>>vec);

void pollution_sim( vector<vector<int>> vec);
class polution{
    public: vector<vector<int>> vec;
}
