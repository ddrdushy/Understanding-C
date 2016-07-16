/*
 ============================================================================
 Name        : LinkedList2.c
 Author      : Dushyanth
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*include String Library*/
#include <string.h>
/*create a node structure to store data*/
struct student{
	int id;
	char name[10];
	char gender[10];
	struct student *link;
};

/*declare functions*/
/* function for add node to linked list*/
void append(struct student**,struct student);

/*function to display linked list*/
void display(struct student *);

/*function for add node at the beginning*/
void addAtBeginning(struct student**,struct student);

/* main function */
int main(void) {

	struct student *p;															//pointer for head node
	struct student s;															//structure for get values
	p=NULL;																		//assign Head to NULL
	char ch[10];
	int choice=0;
	do{																			//loop for receive data from users
		printf("Enter the id\n");												//get id from user
		scanf("%d",&s.id);														//assign to structure id
		printf("Enter the name\n");												//get name from user
		scanf("%s",s.name);														//assign to structure name
		printf("Enter the gender\n");											//get gender from user
		scanf("%s",s.gender);													//assign to structure gender
		s.link=NULL;															//assign structure link to NULL

		printf("choose the position for node\n 1.Add at the end\n 2.Add at the Beginning\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			append(&p,s);														//call append() to add the node to list
			break;
		case 2:
			addAtBeginning(&p,s);												//call addAtBeginning() to add the node at the beginning
			break;
		default:
			append(&p,s);														//call append() to add the node to list
		}

		printf("Do you want to add details of another student? Type Yes/No\n"); //request user to give the input information
		scanf("%s",ch);															//get the input from user
	}while(!strcmp(ch,"Yes"));													//compare the input with "Yes"
	printf("The Details of the students are\n");								//Display heading
	printf("%4s %10s %6s\n","ID","Name","Gender");								//display caption
	display(p);																	//call display function to display data
	getch();																	//wait for user input to exit
	return 0;
}

void append(struct student **q,struct student s){
	struct student *n;															//variable struct student
	struct student *temp=*q;													//temp struct variable holding user given values

	n=(struct student*)malloc(sizeof(struct student));							//allocate memory for new node
	*n=s;																		//assign received struct values to created node

	if(temp==NULL){																//condition for check the head node
		*q=n;																	//if head does not exist assign received node to head
	}else{
		while(temp->link!=NULL){												//else traverse through the list to get the end node
			temp=temp->link;													//change the temp to linked node
		}
		temp->link=n;															//link the new node to the list
	}
}


void display(struct student *q){
	int count=0;																//count variable
	struct student *temp=q;														//temp struct variable holding head node
	while(temp!=NULL){															//else traverse through the list to get the end node
			printf("%4d %10s %6s\n",temp->id,temp->name,temp->gender);			//print the current node values
			temp=temp->link;													//change the temp to linked node
			count++;															//count the items in the list
		}
	printf("The number of students in the list is %d",count);					//display the count
}

void addAtBeginning(struct student **q,struct student s){
	struct student *n;															//variable for hold new value
	n=(struct student*)malloc(sizeof(struct student));							//memory allocation for new node
	*n=s;																		//assign received node to variable

	n->link=*q;																	//link the created node to head
	*q=n;																		//change the head node pointer as created node
}
