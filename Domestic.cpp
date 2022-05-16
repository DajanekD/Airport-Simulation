#include"Domestic.h"
using namespace std;

int sum_of_3adj(Node a,Node b,Node c)
{
	return a.node_value + b.node_value + c.node_value;
}

int sum_of_5adj(Node a,Node b,Node c,Node d,Node e)
{
        return a.node_value + b.node_value + c.node_value + d.node_value + e.node_value;
}

int sum_of_8adj(Node a,Node b,Node c,Node d,Node e,Node f,Node g,Node h)
{
	return a.node_value + b.node_value + c.node_value + d.node_value + e.node_value + f.node_value + g.node_value + h.node_value;
}


vector<vector<Node>> domestic_simulation(vector<vector<Node>> t)
{
	int population=0;
	for(size_t i=0; i<t.size(); i++)
        {
                for(size_t j=0; j<t[i].size(); j++)
                {
                        if(t[i][j].node_char == "D")
			{
				if(i==t.size()-1 && j==t[i].size()-1)
				{	
					//cout<<"bottom right corner"<<endl;
					if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i-1][j].node_char == "#" || t[i-1][j-1].node_char == "#" || t[i][j-1].node_char == "T" || t[i-1][j].node_char == "T" || t[i-1][j-1].node_char == "T"))
					{
						t[i][j].node_value = t[i][j].node_value + 1;
						population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_3adj(t[i][j-1], t[i-1][j], t[i-1][j-1])>=1)
	                                {
        	                                t[i][j].node_value++;
						population++;
                	                }
	
					else if(t[i][j].node_value == 1 && sum_of_3adj(t[i][j-1], t[i-1][j], t[i-1][j-1])>=2)
                	                {
                        	                t[i][j].node_value++;
						population++;
                                	}
	
					else if(t[i][j].node_value == 2 && sum_of_3adj(t[i][j-1], t[i-1][j], t[i-1][j-1])>=8)
                	                {
                        	                t[i][j].node_value++;
						population++;
                                	}

					else if(t[i][j].node_value == 3 && sum_of_3adj(t[i][j-1], t[i-1][j], t[i-1][j-1])>=18)
                                	{
                                       		t[i][j].node_value++;
                                		population++;
					}
	
					else if(t[i][j].node_value == 4 && sum_of_3adj(t[i][j-1], t[i-1][j], t[i-1][j-1])>=32)
		      			{
                      			        t[i][j].node_value++;
						population++;
                        	        }

				}
				else if(i==0 && j==t[i].size()-1)
				{
			//		cout<<"top right corner"<<endl;
					if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j-1].node_char == "#" || t[i][j-1].node_char == "T" || t[i+1][j].node_char == "T" || t[i+1][j-1].node_char == "T"))
					{
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                        	population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_3adj(t[i][j-1],t[i+1][j],t[i+1][j-1])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_3adj(t[i][j-1],t[i+1][j],t[i+1][j-1])>=2)
                	                {
                        	                t[i][j].node_value++;
                                		population++;
					}
	
					else if(t[i][j].node_value == 2 && sum_of_3adj(t[i][j-1],t[i+1][j],t[i+1][j-1])>=8)
                	                {
                        	                t[i][j].node_value++;
                                		population++;
					}
	
					else if(t[i][j].node_value == 3 && sum_of_3adj(t[i][j-1],t[i+1][j],t[i+1][j-1])>=18)
                	                {
                        	                t[i][j].node_value++;
                                		population++;
					}
	
					else if(t[i][j].node_value == 4 && sum_of_3adj(t[i][j-1],t[i+1][j],t[i+1][j-1])>=32)
                	                {
                        	                t[i][j].node_value++;
                                		population++;
					}
				}
				else if(i==t.size()-1 && j==0)
				{
			//		cout<<"bottom left corner"<<endl;
					if(t[i][j].node_value == 0 && (t[i][j+1].node_char == "#" || t[i-1][j].node_char == "#" || t[i-1][j+1].node_char == "#" || t[i][j+1].node_char == "T" || t[i-1][j].node_char == "T" || t[i-1][j+1].node_char == "T"))
					{
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                        	population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_3adj(t[i][j+1],t[i-1][j],t[i-1][j+1])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_3adj(t[i][j+1],t[i-1][j],t[i-1][j+1])>=2)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 2 && sum_of_3adj(t[i][j+1],t[i-1][j],t[i-1][j+1])>=8)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 3 && sum_of_3adj(t[i][j+1],t[i-1][j],t[i-1][j+1])>=18)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 4 && sum_of_3adj(t[i][j+1],t[i-1][j],t[i-1][j+1])>=32)
                                	{
                                        	t[i][j].node_value++;
                                		population++;
					}
				}
				else if(i==0 && j==0)
				{
			//		cout<<"top left corner"<<endl;
					if(t[i][j].node_value == 0 && (t[i][j+1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j+1].node_char == "#" || t[i][j+1].node_char == "T" || t[i+1][j].node_char == "T" || t[i+1][j+1].node_char == "T"))
					{
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                        	population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_3adj(t[i][j+1],t[i+1][j],t[i+1][j+1])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_3adj(t[i][j+1],t[i+1][j],t[i+1][j+1])>=2)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 2 && sum_of_3adj(t[i][j+1],t[i+1][j],t[i+1][j+1])>=8)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 3 && sum_of_3adj(t[i][j+1],t[i+1][j],t[i+1][j+1])>=18)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 4 && sum_of_3adj(t[i][j+1],t[i+1][j],t[i+1][j+1])>=32)
                                	{
                                        	t[i][j].node_value++;
                                		population++;
					}
				}
				else if(i!=0 && i!=t.size()-1 && j==t[i].size()-1)
				{
			//		cout<<"right"<<endl;
					if(t[i][j].node_value == 0 && (t[i-1][j].node_char == "#" || t[i-1][j-1].node_char == "#" || t[i][j-1].node_char == "#" || t[i+1][j-1].node_char == "#" || t[i+1][j].node_char == "#" || t[i-1][j].node_char == "T" || t[i-1][j-1].node_char == "T" || t[i][j-1].node_char == "T" || t[i+1][j-1].node_char == "T" || t[i+1][j].node_char == "T"))
					{
                                                t[i][j].node_value = t[i][j].node_value + 1;
                                        	population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_5adj(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_5adj(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j])>=2)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 2 && sum_of_5adj(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j])>=8)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 3 && sum_of_5adj(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j])>=18)
                        	        {
                	                        t[i][j].node_value++;
						population++;
        	                        }
	
					else if(t[i][j].node_value == 4 && sum_of_5adj(t[i-1][j], t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j])>=32)
                                	{
                                        	t[i][j].node_value++;
                                		population++;
					}
				}
				else if(i!=0 && j==0 && i!=t.size()-1)
				{
			//		cout<<"left"<<endl;
					if(t[i][j].node_value == 0 && (t[i-1][j].node_char == "#" || t[i-1][j+1].node_char == "#" || t[i][j+1].node_char == "#" || t[i+1][j+1].node_char == "#" || t[i+1][j].node_char == "#" || t[i-1][j].node_char == "T" || t[i-1][j+1].node_char == "T" || t[i][j+1].node_char == "T" || t[i+1][j+1].node_char == "T" || t[i+1][j].node_char == "T"))
					{
						t[i][j].node_value += 1;
						population++;
					}	
					else if(t[i][j].node_value == 0 && sum_of_5adj(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_5adj(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j])>=2)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 2 && sum_of_5adj(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j])>=8)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 3 && sum_of_5adj(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j])>=18)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 4 && sum_of_5adj(t[i-1][j], t[i-1][j+1], t[i][j+1], t[i+1][j+1], t[i+1][j])>=32)
                                	{
                                        	t[i][j].node_value++;
                                		population++;
					}
				}

				else if(i==0 && j!=0 && j!=t[i].size()-1)
				{
			//		cout<<"top"<<endl;
					if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i+1][j-1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j+1].node_char == "#" || t[i][j+1].node_char == "#" || t[i][j-1].node_char == "T" || t[i+1][j-1].node_char == "T" || t[i+1][j].node_char == "T" || t[i+1][j+1].node_char == "T" || t[i][j+1].node_char == "T"))
					{
						t[i][j].node_value += 1;
						population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_5adj(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_5adj(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1])>=2)
                        	        {
                	                        t[i][j].node_value++;
						population++;
        	                        }
	
					else if(t[i][j].node_value == 2 && sum_of_5adj(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1])>=8)
                        	        {
                	                        t[i][j].node_value++;
						population++;
        	                        }
	
					else if(t[i][j].node_value == 3 && sum_of_5adj(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1])>=18)
                        	        {
                	                        t[i][j].node_value++;
						population++;
        	                        }
	
					else if(t[i][j].node_value == 4 && sum_of_5adj(t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1])>=32)
                                	{
                                       		t[i][j].node_value++;
						population++;
                                	}
				}
				else if(i==t.size()-1 && j!=0 && j!=t[i].size()-1)
				{
			//		cout<<"Bottom"<<endl;
					if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "#" || t[i-1][j-1].node_char == "#" || t[i-1][j].node_char == "#" || t[i-1][j+1].node_char == "#" || t[i][j+1].node_char == "#" || t[i][j-1].node_char == "T" || t[i-1][j-1].node_char == "T" || t[i-1][j].node_char == "T" || t[i-1][j+1].node_char == "T" || t[i][j+1].node_char == "T"))
					{
						t[i][j].node_value += 1;
						population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_5adj(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_5adj(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1])>=2)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 2 && sum_of_5adj(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1])>=8)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 3 && sum_of_5adj(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1])>=18)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 4 && sum_of_5adj(t[i][j-1], t[i-1][j-1], t[i-1][j], t[i-1][j+1], t[i][j+1])>=32)
                                	{
                                        	t[i][j].node_value++;
                                		population++;
					}
				}
				else
			 	{	
			 		if(t[i][j].node_value == 0 && (t[i-1][j-1].node_char == "#" || t[i][j-1].node_char == "#" || t[i+1][j-1].node_char == "#" || t[i+1][j].node_char == "#" || t[i+1][j+1].node_char == "#" || t[i][j+1].node_char == "#" || t[i-1][j+1].node_char == "#" || t[i-1][j].node_char == "#" || t[i-1][j-1].node_char == "T" || t[i][j-1].node_char == "T" || t[i+1][j-1].node_char == "T" || t[i+1][j].node_char == "T" || t[i+1][j+1].node_char == "T" || t[i][j+1].node_char == "T" || t[i-1][j+1].node_char == "T" || t[i-1][j].node_char == "T"))
					{
						t[i][j].node_value = t[i][j].node_value + 1;
			 			population++;
					}
					else if(t[i][j].node_value == 0 && sum_of_8adj(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=1)
					{
						t[i][j].node_value++;
						population++;
					}
	
					else if(t[i][j].node_value == 1 && sum_of_8adj(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=2)
				  	{
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 2 && sum_of_8adj(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=8)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 3 && sum_of_8adj(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=18)
                        	        {
                	                        t[i][j].node_value++;
        	                        	population++;
					}
	
					else if(t[i][j].node_value == 4 && sum_of_8adj(t[i-1][j-1], t[i][j-1], t[i+1][j-1], t[i+1][j], t[i+1][j+1], t[i][j+1], t[i-1][j+1], t[i-1][j])>=32)
                                	{
                                        	t[i][j].node_value++;
						population++;
                                	}
			 	}

		
			 }
                }
     
	}
	
	
	return t;
}


int workers(vector<vector<Node>> t)
{
	int population=0;
	for(size_t i=0; i<t.size(); i++)
	{
		for(size_t j=0; j<t[i].size(); j++)
		{
			if(t[i][j].node_char == "D")
			{

				population += t[i][j].node_value;
			}
		}
	}

	return population;
}

void print_char(vector<vector<Node>> zone)
{
	for(size_t i=0; i<zone.size(); i++)
        {
                for(size_t j=0; j<zone[i].size(); j++)
                {
                        cout<<zone[i][j].node_char<<" ";
                }
                cout<<endl;
        }
}

void print_value(vector<vector<Node>> t)
{
	for(size_t i=0; i<t.size(); i++)
	{
		for(size_t j=0; j<t[i].size(); j++)
		{
			if(t[i][j].node_char != "C" && t[i][j].node_char != "D" && t[i][j].node_char != "I")
			{
				cout<<t[i][j].node_char<<" ";
			}
			else
				cout<<t[i][j].node_value<<" ";
		}
		cout<<endl;
	}

}


