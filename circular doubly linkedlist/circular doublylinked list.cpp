#include <iostream>

  void insert_beg(int x);
  void insert_end(int x);
  void insert_atspec(int x, int y);
  void delete_beg();
  void delet_end();
  void delete_atspec(int position);
  void display();
  
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
  Node* head= NULL;
void insert_beg(int x) {
  Node* newNode = new Node();
  newNode->data = x;
  newNode->next = NULL;
  newNode->prev = NULL; 
   
  if( head == NULL) {
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
  } else {
    
    Node* temp = head;
    while(temp->next != head)
      temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }    
};

void insert_end(int x) {
  Node* newNode = new Node();
  newNode->data = x;
  newNode->next = NULL;
  newNode->prev = NULL; 
   
  if(head == NULL) {
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
  } else {
    
    Node* temp = head;
    while(temp->next != head)
      temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    newNode->prev = temp;
    head->prev = newNode;
  }    
};

void insert_atspec(int x, int y){
	Node* newNode =new Node();
	newNode->data = x;
	newNode->next =NULL;
	Node* temp = head;
	int NoOfElements =0;
	if(temp !=NULL){
		NoOfElements++;
		temp = temp->next;
	}
	while(temp != head){
		NoOfElements++;
		temp = temp->next;
	}
	if(y<1 || y> (NoOfElements+1)){
     cout<<"\nInvalid Position.";
	 	
	}else if (y==1){
		
		if(head==NULL){
			head = newNode;
			head->next= head;
			head->prev = head;
			
		}else{
			while(temp->next !=head){
				temp =temp->next;
				
			}
			temp->next = newNode;
			newNode->prev =temp;
			newNode->next =head;
			head->prev =newNode;
			head = newNode;	
		}
	}else{
		temp = head;
		for(int i =1;i < y-1; i++)
		  temp = temp->next;
		  newNode->next = temp->next;
		  newNode->next->prev = newNode;
		  newNode->prev = temp;
		  temp->next = newNode;	
	}	
};

void delete_beg() {
  if(head != NULL) {
    if(head->next == head) {
      head = NULL;
    } else {
      
     Node* temp = head;
      while(temp->next->next != head)
        temp = temp->next;
      
      Node* lastNode = temp->next;
      temp->next = head;
      head->prev = temp;
      delete(lastNode); 
    }
  }
}

void deletat_end() {
  if(head != NULL) {
    
    if(head->next == head) {
      head = NULL;
    } else {
      
      
      Node* temp = head;
      Node* firstNode = head;
      
      while(temp->next != head) {
        temp = temp->next;
      }
      
      head = head->next;
      head->prev = temp;
      temp->next = head; 
      delete(firstNode); 
    }
  }
}

void delete_atspec(int pos) {
  Node* newnode = head; 
  Node* temp = head;
  int NoOfElements = 0;

  if(temp != NULL) {
    NoOfElements++;
    temp = temp->next;
  }
  while(temp != head) {
    NoOfElements++;
    temp = temp->next;
  }
  
  if(pos < 1 || pos > NoOfElements) {
    cout<<"\nInavalid position.";
  } else if (pos == 1) {
  
    if(head->next == head) {
      head = NULL;
    } else {     
      while(temp->next != head)
        temp = temp->next;
      head = head->next;
      temp->next = head; 
      head->prev = temp;
      delete(newnode); 
    }
  } else {

    temp = head;
    for(int i = 1; i < pos-1; i++)
      temp = temp->next;
    newnode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete(newnode); 
  }
};
    void display() {
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The values is = ";
        while(true) {
          cout<<temp->data<<" ";
          temp = temp->next;
		       if(temp == head) 
            break;
        }
        cout<<endl;
      } else {
        cout<<"Empity";
      }
    }
int main() {

	     insert_beg(1);
         insert_beg(2);
         insert_beg(3);
         insert_beg(4);
         delete_beg();   
     display();
         
	     insert_end(6);
	     insert_end(7);
	     insert_end(8);
	     insert_end(9);
      display();	
         insert_atspec(3,6);
      display();
         delete_atspec(4);
      display();   
return 0;
}















