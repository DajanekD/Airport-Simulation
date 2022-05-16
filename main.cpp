#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include"structheader.h"
#include"Domestic.cpp"
#include"Cargo.cpp"
#include"International.cpp"

using namespace std;


int main()
{
        string fileName,configFile;        //for .csv filename from user
      
	int worker_available = 0;
	int goods_available = 0;
	vector<vector<Node>> zone;
        string line,word;
	
	int time_limit;
	int rate;
	int temp=0;

        cout<<"Enter the name of the configuration file: ";
        cin>>configFile;

        fstream f;
        f.open(configFile,ios::in);
        string str, str2;

        if(f.good())
        {
                getline(f,str,':');
                        getline(f,fileName,'\n');

                getline(f,str,':');
                        f>>time_limit;

                getline(f,str,':');
                        f>>rate;                
        }

	
        fstream fin;            // file pointer
        fin.open(fileName, ios::in);            // open entered .csv file

        while (fin)
        {
                if(!getline(fin,line)) break;

                istringstream ss(line);
                vector<Node> words;

                while(ss)
                {
                        string s;
			struct Node a;
                        if(!getline(ss,s,',')) break;
			{
				if(s == "D" || s == "C" || s == "I")
				{
					a.node_char = s;
					a.node_value = 0;
                        		words.push_back(Node(a));
				}
				else
				{
					a.node_char = s;
					a.node_value = 0;
					words.push_back(Node(a));
				}
			}
                }
                zone.push_back(words);
        }


	

        // -----------OUTPUT------------

        cout<<"Beginning Simulation"<<endl;
        //config file part
        cout<<endl<<endl;
        print_char(zone);

	int array[time_limit]={0};
	int arraygoods[time_limit]={0};
	int temp2;

        for(int i=1; i<=time_limit; i++)
        {
                //goods as well
                zone = domestic_simulation(zone);
		

                for(int j=0;j<1 ; j++)
                {	
                        array[j] = worker_available;
                  	arraygoods[j] = goods_available;
		  	temp += array[j];
                	temp2 += arraygoods[j];
		}
                worker_available = workers(zone);
                worker_available -= temp;
                
		goods_available = goods(zone);
		goods_available -= temp2;

		zone = cargoSimulation( zone , worker_available);
	
		//zone = internationalSimulation(zone, worker_available, goods_available);	

		//goods_available = goods(zone);
		if(i%rate == 0)
                {
                        cout<<endl<<"Time step: "<<i<<endl;
                        cout<<"Available Workers "<<worker_available<<" and Available Goods "<<goods_available<<endl;
        		        
			print_value(zone);
                }
                if(worker_available == 0)
                {
                        break;
                }
	}

	pollution_sim_init( pollution(zone) );
	
	return 0;
}
