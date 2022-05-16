#include"structheader.h"

using namespace std;

int sum_of_3adj(Node a, Node b, Node c);             // this function will return the sum of adj values in order to find out if it satisfies the given argument to increase a certain cell. values needed to pass will be the vector with it's col i and row j
int sum_of_5adj(Node a,Node b,Node c,Node d,Node e);
int sum_of_8adj(Node a,Node b,Node c,Node d,Node e,Node f,Node g,Node h);


vector<vector<Node>> domestic_simulation(vector<vector<Node>> t);         // simulation of demestic part is going to be performed in this process
  

int workers(vector<vector<Node>> t);                    // will return number of workers in each time stamp

void print_char(vector<vector<Node>> zone);

void print_value(vector<vector<Node>> t);
