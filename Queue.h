
#ifndef queue_h
#define queue_h
#include "Node.h"

class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};


void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){ 
  if (size == 0) //only for first-time node - and increase size 
  {
    headPtr = new_node;
  }
  else // if no longer first-time node
  {
    tailPtr->set_next(new_node); 
  }
  tailPtr = new_node; //always change the tail
  size++;
   
   
    /* Add head and tail for me please 
   1. connect & Change tail
  2. (may be) change head  when the queue is empty
  3. increase size*/
	
 }
}

int Queue::dequeue(){
  if(headPtr != NULL)
  {
     NodePtr t = headPtr;
     headPtr = headPtr->get_next();
     int value = t->get_value();
     /* Add head and tail for me please */
     if (size == 1)
     {
        headPtr = NULL; //cuz head and tail go somewhere while t(temp) dequeue
        tailPtr = NULL;
     }
     size--;
     cout<<"dequeing-"<<value<<endl;
          
     delete t;
     return value;
  }
  cout<<" -Empty queue- "<<endl;
  return -1;
}


Queue::Queue(){
    //initialize Queue (set the values in Class)
    size = 0;
    headPtr = NULL;
    tailPtr = NULL;
    
}
Queue::~Queue(){
    //delete all remaning Queue (i.e. DQ all) 
    cout<<" -d-e-q-u-e-i-n-g-i-n-i-t-i-a-t-e-d- "<<endl;
    while (size>0)
    {
      dequeue();
      //size--;
    }
    
    
}


#endif
