#include <stdio.h>
#include<stdlib.h>
#include "queue.h"


Queue* queue_create (void)
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue -> init = queue -> end = NULL;
	
	return queue;
}

void queue_insert (Queue* queue, int v, double k) {
	
	Node* node = (Node*) malloc(sizeof(Node));
	node -> vertex = v;
	node -> key = k;
	node -> next = NULL;
	
	if (queue -> end != NULL)
		queue -> end -> next = node;
	
	else 
		queue -> init = node;
		
	queue -> end = node;
	
}

int queue_retrieve_minimum (Queue* queue) {
	
	Node* node;
	Node* temp;
	int vertex;
	double key = 99999;
	
	if(queue_empty(queue)) {
		
		printf("Empty Queue.\n");
		exit(1);		
	}
	
	node = queue -> init;
	
	for (temp = queue -> init; temp != NULL; temp = temp -> next)
		if (temp -> key < key) {
			
			key = temp -> key;
			vertex = temp -> vertex;		
		}
	
	queue -> init = node -> next;
	
	if (queue -> init == NULL)
		queue -> end = NULL;
	
	free(node);
	return vertex;
		
}


int queue_hasVertex(Queue* queue, int vertex) {
	
	Node* node;
	
	for (node = queue -> init; node != NULL; node = node -> next)
		if (node -> vertex == vertex)
			return 1;
	
	return 0;
		
}

int queue_empty (Queue* queue) {
	
	return (queue->init == NULL);	
}


void queue_free(Queue* queue){
	
	Node* node = queue -> init;
	
	while(node != NULL) {
		
		Node* temp = node -> next;
		free(node);
		node = temp;	
	}
	
	free(queue);
	
}
