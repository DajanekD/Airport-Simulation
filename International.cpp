#include "International.h"

int goods(vector<vector<Node>> t); 
int workers(vector<vector<Node>> t);
  
  
  
 
 int adjacentFOUR(Node a, Node b, Node c, Node d){

    return a.node_value + b.node_value + c.node_value + d.node_value;
}



int adjacentTOP(Node a, Node b, Node c, Node d, Node e){

    return a.node_value + b.node_value + c.node_value + d.node_value + e.node_value;
}


int adjacentSIX(Node a, Node b, Node c, Node d, Node e, Node f){

    return a.node_value + b.node_value + c.node_value + d.node_value + e.node_value + f.node_value;
}


int adjacentEIGHT(Node a, Node b, Node c, Node d, Node e, Node f, Node g, Node h){

    return a.node_value + b.node_value + c.node_value + d.node_value + e.node_value + g.node_value + h.node_value;
}



vector<vector<Node>> internationalSimulation(vector<vector<Node>> t, int workers, int goods){
  
  for(size_t i=0; i<t.size(); i++){
    
    
    for(size_t j=0; j<t[i].size(); j++){
      
      if(t[i][j].node_char == "T" && workers>=1 && goods>=1){
       		//for cells with char T
        
        	//top
        	//checking for power lines
          if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "-" || t[i-1][j].node_char == "-" || t[i-1][j-1].node_char == "-" || t[i+1][j-1].node_char == "-" || t[i+1][j].node_char == "-"))
          {
       
           t[i][j].node_value = t[i][j].node_value + 1;
            workers= workers-1;
            goods= goods-1;       //get number of remaining workers
            
            
          } 
        //right side
        //checking for power lines
         else if(i!=0 && i!=t.size()-1 && j==t[i].size()-1){
          
           if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "-" || t[i-1][j].node_char == "-" || t[i-1][j-1].node_char == "-" || t[i+1][j-1].node_char == "-" || t[i+1][j].node_char == "-")){
             
            t[i][j].node_value = t[i][j].node_value + 1;
            workers= workers-1;
            goods= goods-1; 
           }
          
        }
        
        //bottom right terminal
        //checking for power lines
        else if(i==t.size()-1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 0 && (t[i][j+1].node_char == "-" || t[i-1][j].node_char == "-" || t[i+1][j+1].node_char == "-" || t[i+1][j-1].node_char == "-" || t[i+1][j].node_char == "-")){
            
           t[i][j].node_value = t[i][j].node_value + 1;
           workers= workers-1;
           goods= goods-1; 
        }
        }
        
       //top
        //checking for adjacent terminal with value >=1
        else if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "T" && t[i][j-1].node_value >=1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1) || (t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1)){
          
          t[i][j].node_value = t[i][j].node_value + 1;
          workers = workers -1;
          goods = goods -1;
        }
        
        //right side
        //checking for adjacent terminal with value >=1
        else if(i!=0 && i!=t.size()-1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "T" && t[i][j-1].node_value >=1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1) || (t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1)){
            
         	 t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
            
          }
        }
          //bottom right terminal
          //checking for adjacent terminal with value >=1
        else if(i==t.size()-1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "T" && t[i][j-1].node_value >=1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1) || (t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1)){
            
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
      
          }
          }
         
        //top
        //terminal cell has value of 1 and checking for at least 2 adjacent terminals with value >=1
        else if(t[i][j].node_value == 1 && (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >= 1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >= 1) && (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1 && t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >=1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >=1 && t[i+1][j-1].node_char =="T" && t[i+1][j-1].node_value >= 1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >= 1) || (t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1))
        {
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
        }
        
        //right side 
        //terminal cell has value of 1 and checking for at least 2 adjacent terminals with value >=1
        else if(i!=0 && i!=t.size()-1 && j==t[i].size()-1){
          if(t[i][j].node_value == 1 && (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >= 1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >= 1) && (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1 && t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >=1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >=1 && t[i+1][j-1].node_char =="T" && t[i+1][j-1].node_value >= 1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >= 1) || (t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1))
          {
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
          }
        }
        
        //bottom right terminal
        //terminal cell has value of 1 and checking for at least 2 adjacent terminals with value >=1
        else if(i==t.size()-1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 1 && (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1) || (t[i][j-1].node_char == "T" && t[i][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >= 1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >= 1) && (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >=1 && t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >=1) || (t[i-1][j].node_char == "T" && t[i-1][j].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >=1 && t[i+1][j-1].node_char =="T" && t[i+1][j-1].node_value >= 1) || (t[i-1][j-1].node_char == "T" && t[i-1][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >= 1) || (t[i+1][j-1].node_char == "T" && t[i+1][j-1].node_value >= 1 && t[i+1][j].node_char == "T" && t[i+1][j].node_value >=1))
          {
            
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
            
          }
          
          }
        
      }
       
   
   }
  
  }
  
  
  for(size_t i=0; i<t.size(); i++){
    
    for(size_t j=0; j<t[i].size(); j++){
      if(t[i][j].node_char == "I" && workers>=1 && goods>=1){
       		//for cells with char I
        
        	//top
        	//checking for power lines
          if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "-" || t[i-1][j].node_char == "-" || t[i-1][j-1].node_char == "-" || t[i+1][j-1].node_char == "-" || t[i+1][j].node_char == "-"))
          {
       
           t[i][j].node_value = t[i][j].node_value + 1;
            workers= workers-1;
            goods= goods-1;       //get number of remaining workers
            
            
          } 
        //left side
        //checking for power lines
         else if(i!=0 && i!=t.size()+1 && j==t[i].size()+1){
          
           if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "-" || t[i-1][j].node_char == "-" || t[i-1][j-1].node_char == "-" || t[i+1][j-1].node_char == "-" || t[i+1][j].node_char == "-")){
             
            t[i][j].node_value = t[i][j].node_value + 1;
            workers= workers-1;
            goods= goods-1; 
           }
          
        }
        
        //left
        //checking for power lines
        else if(i==t.size()+1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 0 && (t[i][j+1].node_char == "-" || t[i-1][j].node_char == "-" || t[i+1][j+1].node_char == "-" || t[i+1][j-1].node_char == "-" || t[i+1][j].node_char == "-")){
            
           t[i][j].node_value = t[i][j].node_value + 1;
           workers= workers-1;
           goods= goods-1; 
        }
        }
        
       //top
        //checking for adjacent terminal with value >=1
        else if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "I" && t[i][j-1].node_value >=1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1) || (t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1)){
          
          t[i][j].node_value = t[i][j].node_value + 1;
          workers = workers -1;
          goods = goods -1;
        }
        
        //left side
        //checking for adjacent terminal with value >=1
        else if(i!=0 && i!=t.size()-1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "I" && t[i][j-1].node_value >=1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1) || (t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1)){
            
         	 t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
            
          }
        }
          //bottom right terminal
          //checking for adjacent terminal with value >=1
        else if(i==t.size()-1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 0 && (t[i][j-1].node_char == "I" && t[i][j-1].node_value >=1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1) || (t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1)){
            
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
      
          }
          }
         
        //top
        //terminal cell has value of 1 and checking for at least 2 adjacent terminals with value >=1
        else if(t[i][j].node_value == 1 && (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >= 1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >= 1) && (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1 && t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >=1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >=1 && t[i+1][j-1].node_char =="I" && t[i+1][j-1].node_value >= 1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >= 1) || (t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1))
        {
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
        }
        
        //right side 
        //terminal cell has value of 1 and checking for at least 2 adjacent terminals with value >=1
        else if(i!=0 && i!=t.size()+1 && j==t[i].size()+1){
          if(t[i][j].node_value == 1 && (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >= 1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >= 1) && (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1 && t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >=1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >=1 && t[i+1][j-1].node_char =="I" && t[i+1][j-1].node_value >= 1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >= 1) || (t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1))
          {
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
          }
        }
        
        //bottom right terminal
        //terminal cell has value of 1 and checking for at least 2 adjacent terminals with value >=1
        else if(i==t.size()-1 && j==t[i].size()-1){
          
          if(t[i][j].node_value == 1 && (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1) || (t[i][j-1].node_char == "I" && t[i][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >= 1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >= 1) && (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >=1 && t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >=1) || (t[i-1][j].node_char == "I" && t[i-1][j].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >=1 && t[i+1][j-1].node_char =="I" && t[i+1][j-1].node_value >= 1) || (t[i-1][j-1].node_char == "I" && t[i-1][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >= 1) || (t[i+1][j-1].node_char == "I" && t[i+1][j-1].node_value >= 1 && t[i+1][j].node_char == "I" && t[i+1][j].node_value >=1))
          {
            
             t[i][j].node_value = t[i][j].node_value + 1;
          	 workers = workers -1;
         	 goods = goods -1;
            
          }
          
          }
        
      }
        
      }
     }

    }
      
      
