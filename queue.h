
typedef struct node Node;
typedef struct queue Queue;

Queue* queue_create (void);
void queue_insert (Queue* queue, int v, double k);
int queue_retrieve_minimum (Queue* queue);
int queue_empty (Queue* queue);
void queue_free(Queue* queue);
int queue_hasVertex(Queue* queue, int vertex);

struct node {
	
	int vertex; 
	double key; 
	struct node* next;	

};


struct queue {
	
	Node* init;
	Node* end;
		
};




