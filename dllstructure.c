#include<stdio.h>
#include<stdlib.h>
//1
struct Node{
	int data;
	struct Node* next;
	struct Node* previous;
};
typedef struct Node Node;

Node* create_dll_from_array(int array[], int size)
{
	int i;
	Node* stNode;
	Node* fnNode;
	Node* tempNode;
	if(size>=0){
		stNode=(Node*)malloc(sizeof(Node));
		if(stNode==NULL)exit(1);
		if(stNode!=NULL){
			stNode->previous=NULL;
			stNode->next=NULL;
			tempNode=stNode;
		}
		for(i=0;i<size;i++){
			fnNode=(Node*)malloc(sizeof(Node));
			if(fnNode==NULL)exit(1);
			if(fnNode!=NULL){
				fnNode->data=array[i];
				fnNode->previous=tempNode;
				fnNode->next=NULL;

				tempNode->next=fnNode;
				tempNode=fnNode;
			}
		}
		
	}
	return stNode;
}




//2
void print_dll(Node* head){
	Node* temp=head->next;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


//3
void insert_after(Node* head,int valueToInsertAfter,int valueToBeInserted)
{       
	


	Node* insert=(Node*)malloc(sizeof(Node));
	insert->data=valueToBeInserted;
	Node* temp=head;
	if(head->next!=NULL){
		temp=head->next;
	}else{
		head->next=insert;
		insert->previous=head;
		insert->next=NULL;
		return;
		
	}
	while(temp->next!=NULL){
		if(temp->data==valueToInsertAfter){
			insert->next=temp->next;
				temp->next->previous=insert;
			temp->next=insert;
			insert->previous=temp;
			return;
		}
		temp=temp->next;
	}
	//if the last element is the value or if there is no such valueToInsertAfter,directly add to the end of the list
        temp->next=insert;
	insert->previous=temp;
	insert->next=NULL;
}
			
//4
void delete_element(Node* head, int valueToBeDeleted)
{       
          //if deleted node is in medium
	   Node* temp=head->next;
	   if(temp==NULL){
		   return;
	   }
	   while(temp->next!=NULL){
		   
		 if(temp->data==valueToBeDeleted){
		
		           temp->previous->next=temp->next;
			   temp->next->previous=temp->previous;
			   temp->next=NULL;
			   temp->previous=NULL;
			   free(temp);
			   return;
		   }
		   temp=temp->next;
	   }
	   //if the deleted node is last node

	   if(temp->data==valueToBeDeleted){
		   temp->previous->next=NULL;
		   temp->previous=NULL;
		   free(temp);
	   }
	
}

//5

void sort_dll(Node* head){
	
        Node *temp=head->next;
	
        while(temp->next!=NULL){
             int swapped=0;
	     Node *sectemp=head->next;
	    while(sectemp->next!=NULL){
		if(sectemp->data > sectemp->next->data){
		    int da=sectemp->data;
	            sectemp->data=sectemp->next->data;
	            sectemp->next->data=da;
		    swapped=1;
		}
                sectemp=sectemp->next;
	    }
	    if(swapped==0){
		    return;
	    }
	    temp=temp->next;
	}
}

//6

void clearMemoryLeaks(Node* head){
	Node *temp=head->next, *temp2;
	while(temp!=NULL){
		temp2=temp;
		temp=temp->next;
		
		free(temp2);
	}
	head->next=NULL;
}






//main
int main()
{
	int array[5]={11,2,7,22,4};
        Node* head;
	/*Question 1*/
	head=create_dll_from_array(array,5);//size of array



	/*Question 2*/
	print_dll(head);
	
	
	/*Question 3 */

        //To insert 13 after the first occurence of 7
	insert_after(head,7,13);
	//To insert 29 after the first occurence of 21
	insert_after(head,21,29);
	print_dll(head);

	/*Question 4 */
        
	delete_element(head,22);
	print_dll(head);


	delete_element(head,11);
	print_dll(head);

	/*Question 5 */
	sort_dll(head);
	print_dll(head);

	/*Question 6 */
	clearMemoryLeaks(head);
	print_dll(head);
	
	return 0;
	
}
