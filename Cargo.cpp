#include "Cargo.h"
using namespace std;

// Corners have 3 adjacent cells 'Top Left' 'Top Right' 'Bottom Left' 'Bottom Right'
int adjacentCorners3(Node a, Node b, Node c)
{
    return a.node_value + b.node_value + c.node_value;
}

// Sides have 5 adjacent cells 'Top' 'Bottom' 'Left' 'Right'
int adjacentSides5(Node a, Node b, Node c, Node d, Node e)
{
    return a.node_value + b.node_value + c.node_value + d.node_value + e.node_value;
}

// Middle has 8 adjacent cells 'Middle'
int adjacentMid8(Node a, Node b, Node c, Node d, Node e, Node f, Node g, Node h)
{
    return a.node_value + b.node_value + c.node_value + d.node_value + e.node_value + g.node_value + h.node_value;
}

// Cargo Simulation Begins
vector<vector<Node> > cargoSimulation(vector<vector<Node> > t, int workers)
{
 for(size_t i=0; i<t.size(); i++)
        {
                for(size_t j=0; j<t[i].size(); j++)
                {
                        if(t[i][j].node_char == "C" && workers>=2)
                        
			{
				if(i==t.size()-1 && j==t[i].size()-1)
				{	
				//Bottom Right
				// Cargo 1
					if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i-1][j].node_char == "#" || t[i-1][j-1].node_char == "#")) 
					{
                                
						t[i][j].node_value = t[i][j].node_value + 1;
<<<<<<< HEAD
                                                workers= workers-2;
=======
                                                workers = workers-2;
>>>>>>> 59ea3a33c2eec57fbfef4bddcd8734fcf07bad9c
					}
			        // Cargo 2i
					else if(t[i][j].node_value == 0 && adjacentCorners3(t[i][j-1], t[i-1][j], t[i-1][j-1])>=1)
	                                {
        	                                t[i][j].node_value++;
                                                workers= workers-2;
                	                }
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentCorners3(t[i][j-1], t[i-1][j], t[i-1][j-1])>=2)
                	                {
                        	                t[i][j].node_value++;
                                                workers= workers-2;
                                	}
	                        // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentCorners3(t[i][j-1], t[i-1][j], t[i-1][j-1])>=8)
                	                {
                        	                t[i][j].node_value++;
                                                workers= workers-2;
                                	}

				}
				else if(i==0 && j==t[i].size()-1)
				{
			        // Top Right 
			        // Cargo 1
		        	if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j-1].node_char == "#")) 
                                        {
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                                workers= workers-2;
                                        }
                                // Cargo 2                   
					else if(t[i][j].node_value == 0 && adjacentCorners3(t[i][j-1],t[i+1][j],t[i+1][j-1])>=1)
					{
						t[i][j].node_value++;
                                                workers= workers-2;
					}
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentCorners3(t[i][j-1],t[i+1][j],t[i+1][j-1])>=2)
                	                {
                        	                t[i][j].node_value++;
                                                workers= workers-2;
                                	}
	                        // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentCorners3(t[i][j-1],t[i+1][j],t[i+1][j-1])>=8)
                	                {
                        	                t[i][j].node_value++;
                                                workers= workers-2;
                                	}
				}
				else if(i==t.size()-1 && j==0)
				{
			        // Bottom Left
			        // Cargo 1
					if(t[i][j].node_value == 0 && (t[i][j+1].node_char == "#" || t[i-1][j].node_char == "#" || t[i-1][j+1].node_char == "#")) 
                                        {
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                                workers= workers-2;
                                        }
                                // Cargo 2
					else if(t[i][j].node_value == 0 && adjacentCorners3(t[i][j+1],t[i-1][j],t[i-1][j+1])>=1)
					{
						t[i][j].node_value++;
                                                workers = workers-2;
					}
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentCorners3(t[i][j+1],t[i-1][j],t[i-1][j+1])>=2)
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
	                        // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentCorners3(t[i][j+1],t[i-1][j],t[i-1][j+1])>=8)
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
                        	        }
				}
				else if(i==0 && j==0)
				{
			        // Top Left
			        // Cargo 1
					if(t[i][j].node_value == 0 && (t[i][j+1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j+1].node_char == "#")) 
                                        {
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                                workers= workers-2;
                                        }
                                // Cargo 2
					else if(t[i][j].node_value == 0 && adjacentCorners3(t[i][j+1],t[i+1][j],t[i+1][j+1])>=1)
					{
						t[i][j].node_value++;
                                                workers= workers-2;
					}
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentCorners3(t[i][j+1],t[i+1][j],t[i+1][j+1])>=2)
                        	        {
                	                        t[i][j].node_value++;
                                                workers = workers-2;
        	                        }
	                         // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentCorners3(t[i][j+1],t[i+1][j],t[i+1][j+1])>=8)
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
				}
				else if(i!=0 && i!=t.size()-1 && j==t[i].size()-1)
				{
			        // Right
			        // Cargo 1
					if(t[i][j].node_value == 0 && (t[i-1][j].node_char == "#" || t[i-1][j-1].node_char == "#" || t[i][j-1].node_char == "#" || t[i+1][j-1].node_char == "#" || t[i+1][j].node_char == "#"))
                                        {
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                                workers= workers-2;
                                        }
                                 // Cargo 2
					else if(t[i][j].node_value == 0 && adjacentSides5(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j]))
					{
						t[i][j].node_value++;
                                                workers= workers-2;
					}
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentSides5(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
	                        // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentSides5(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
                        	        }
				}
				else if(i!=0 && j==0 && i!=t.size()-1)
				{
			        // Left
			        // Cargo 1
					if(t[i][j].node_value == 0 && (t[i-1][j].node_char == "#" || t[i-1][j+1].node_char == "#" || t[i][j+1].node_char == "#" || t[i+1][j+1].node_char == "#" || t[i+1][j].node_char == "#"))
					{
						t[i][j].node_value += 1;
                                                workers= workers-2;
					}	
				// Cargo 2
					else if(t[i][j].node_value == 0 && adjacentSides5(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j]))
					{
						t[i][j].node_value++;
                                                workers= workers-2;
					}
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentSides5(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
	                        // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentSides5(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
				}

				else if(i==0 && j!=0 && j!=t[i].size()-1)
				{
			        // Top
			        // Cargo 1
					if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i+1][j-1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j+1].node_char == "#" || t[i][j+1].node_char == "#"))
					{
						t[i][j].node_value += 1;
                                                workers= workers-2;
					}
				// Cargo 2
					else if(t[i][j].node_value == 0 && adjacentSides5(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1]))
					{
						t[i][j].node_value++;
                                                workers= workers-2;
					}
	                        // Cargo 3 
					else if(t[i][j].node_value == 1 && adjacentSides5(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
	                        // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentSides5(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
				}
				else if(i==t.size()-1 && j!=0 && j!=t[i].size()-1)
				{
			        // Bottom
			        // Cargo 1
					if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i-1][j-1].node_char == "#" || t[i-1][j].node_char == "#" || t[i-1][j+1].node_char == "#" || t[i][j+1].node_char == "#"))
					{
						t[i][j].node_value+=1;
                                                workers= workers-2;
					}
				// Cargo 2
					else if(t[i][j].node_value == 0 && adjacentSides5(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1]))
					{
						t[i][j].node_value++;
                                                workers= workers-2;
					}
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentSides5(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
	                        // Cargo 4 
					else if(t[i][j].node_value == 2 && adjacentSides5(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1]))
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
				}
				else
			 	{	
			 	//Cargo 1
			 		if(t[i][j].node_value == 0 && (t[i-1][j-1].node_char == "#" || t[i][j-1].node_char == "#" || t[i+1][j-1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j+1].node_char == "#" || t[i][j+1].node_char == "#" || t[i-1][j+1].node_char == "#" || t[i-1][j].node_char == "#"))	
					{
						t[i][j].node_value = t[i][j].node_value + 1;
                                                workers= workers-2;
			 		}
			 	// Cargo 2
					else if(t[i][j].node_value == 0 && adjacentMid8(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=1)
					{
						t[i][j].node_value++;
                                                workers= workers-2;
					}
	                        // Cargo 3
					else if(t[i][j].node_value == 1 && adjacentMid8(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=2)
				  	{
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
	                        // Cargo 4
					else if(t[i][j].node_value == 2 && adjacentMid8(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=8 )
                        	        {
                	                        t[i][j].node_value++;
                                                workers= workers-2;
        	                        }
			 	}

		
			 }
                }
     
	}
	return t;
}


<<<<<<< HEAD
// Pollution Vector    
vector<vector<int> > pollution(vector<vector<Node> > t)
=======

// Pollution simulation by Riwaj

int goods(vector<vector<Node>> t)
{
	int population=0;
	for(size_t i=0; i<t.size(); i++)
	{
		for(size_t j=0; j<t[i].size(); j++)
		{
			if(t[i][j].node_char == "C")
			{

				population += t[i][j].node_value;
			}
		}
	}

	return population;
}


vector<vector<int>> pollution(vector<vector<Node>> t)
>>>>>>> 59ea3a33c2eec57fbfef4bddcd8734fcf07bad9c
{
       
        int a;
        vector<vector<int>> z;
	vector<int> temp;
        for(size_t i=0; i<t.size(); i++)
        {
                for(size_t j=0; j<t[i].size(); j++)
                {
                        if(t[i][j].node_char == "C")
			{
                             
				a = t[i][j].node_value; 
                                temp.push_back(a);
                        }
                        else
                        {
                       
                                temp.push_back(0);
                        }
                }
        }

	z.push_back(temp);
        return z;
}


<<<<<<< HEAD
// Provides Goods to International
int goods(vector<vector<struct Node> > t)
=======
void printvec(vector<vector<int>> vec)		//pass a 2d vector and it will print the vector
>>>>>>> 59ea3a33c2eec57fbfef4bddcd8734fcf07bad9c
{
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
<<<<<<< HEAD
void pollution_sim( vector<vector<int> > vec)
{
        int i,j;
        for(i=0;i<vec.size();i++)
        {   
            for(j=0;j<vec[i].size();j++)
		{
                		if(vec[i][j]>0)
				{
=======
>>>>>>> 59ea3a33c2eec57fbfef4bddcd8734fcf07bad9c

vector<vector<int>> pollutionsim_neighbour(vector<vector<int>>vec,int i,int j){		//this will check for neighbours and update them as required
 
//there are 8 neighbours so 8 conditions
    if(i-1>0)
    {   
        if(vec[i][j]>vec[i-1][j])
        {
            vec[i-1][j]=vec[i][j]-1;
            
        }
    }
    if(i+1<vec.size())
    {
        if(vec[i][j]>vec[i+1][j])
        {
            vec[i+1][j]=vec[i][j]-1;
        }
    }
    if(j+1<vec[i].size())
    {
        if(vec[i][j]>vec[i][j+1])
        {
            vec[i][j+1]=vec[i][j]-1;
        }
    }
    if(i-1>=0 && j+1<vec[i].size())
    {
        if(vec[i][j]>vec[i-1][j+1])
        {
            vec[i-1][j+1]=vec[i][j]-1;
        }

    }
    if(i+1<vec.size() && j+1<vec[i].size())
    {
        if(vec[i][j]>vec[i+1][j+1])
        {
            vec[i+1][j+1]=vec[i][j]-1;
        }
    }
    if(i-1>=0 && j-1>=0)
    {
      if(vec[i][j]>vec[i-1][j-1])
      {
        vec[i-1][j-1]=vec[i][j]-1;
      }
    }
    if(i+1<vec.size() && j-1>=0)
    {
        if(vec[i][j]>vec[i+1][j-1])
        {
            vec[i+1][j-1]=vec[i][j]-1;
        }
    }
    if(j-1>=0)
    {
        if(vec[i][j]>vec[i][j-1])
        {
            vec[i][j-1]=vec[i][j]-1;
        }
    }
    return vec;


}

<<<<<<< HEAD
void printPollution(std::vector<vector<int> >vec){
	
        for(int i=0;i<vec.size();i++){
                for(int j=0;j<vec[i].size();j++){
                        cout<<vec[i][j]<<" ";
=======
vector<vector<int>> pollution_sim_second( vector<vector<int>> vec){
    
    printvec(vec);

    int i,j;
    int n=0;
    vector<vector<int>> vec2;

    for(i=0;i<vec.size();i++)
    {   
        for(j=0;j<vec[i].size();j++)
        {   
            
                if(vec[i][j]>0)		//find the cells to change its neighbours
                {   
                    
                    vec=pollutionsim_neighbour(vec,i,j);
                    
                    
>>>>>>> 59ea3a33c2eec57fbfef4bddcd8734fcf07bad9c
                }
            
        }
    }

    return vec;
}
void pollution_sim_init(vector<vector<int>> vec){		//this will recurse through pollution sim till the final stage is reached by comparing previous vector to current one
	    vector<vector<int>> compvec;
    compvec=vec;
    vec=pollution_sim_second(vec);
    while(vec!=compvec)
    {
        compvec=vec;
        vec=pollution_sim_second(vec);
    }
    printvec(vec);		//this will print the pollution
	vector<vector<int>> vec2;
	vec2=vecstore(vec);

}








