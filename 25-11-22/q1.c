#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* childL;
	int data;
	struct node* childR;
}*t=NULL, *root=NULL;

void insert(int x) {
	t = root;
	struct node* r;
	
	int isRC = 0;
	int isLC = 0;
	if(root == NULL) {
		struct node* p = (struct node*)malloc(sizeof(struct node));
		printf("%X\n", p);	
		root = p;
		p->data = x;
		printf("%d inserted in root\n", x);
		p->childL = NULL;
		p->childR = NULL;
	}
	else {
		while(t != NULL) {
			r = t;
			if(x < (root->data)) {
				t = t->childL;
				printf("Moving to L subtree\n");
				isLC = 1;
			}
			else if(x > (root->data)) {
				t = t->childR;
				printf("Moving to R subtree\n");
				isRC = 1;
				
			}
			else return;
		}
		
		struct node* p = (struct node*)malloc(sizeof(struct node));
		printf("%X\n", p);
		p->data = x;
			
		if(isLC)
			printf("%d inserted in L subtree\n", x);
		else if(isRC)
			printf("%d inserted in R subtree\n", x);
			
		p->childL = NULL;
		p->childR = NULL;
		isLC = 0;
		isRC = 0;
		
		if(x < (r->data))
			r->childL = p;
		else
			r->childR = p;
	}
}

struct node* search(int x) {
	t = root;
	while(t != NULL) {
		if(x == t->data)
			return t;
		else if(x < (t->data))
			t = t->childL;
		else if(x > (t->data))
			t = t->childR;
	}
	return NULL;
}

void delete(struct node* p, int x) {
	struct node* q;
	if(p == NULL)
		printf("Tree empty");
	
	if(p->childL == NULL && p->childR == NULL)
	{
		if(p == root && p->data == x)
			root = NULL;
		int k = p->data;
		free(p);
	}
	
	if(x < (p->data))
		p->childL = delete(p->childL, x);
	else if(x > (p->data))
		p->childR = delete(p->childR, x);
	else {
		if(height(p->childL) > height(p->childR)) {
			q = InPre(p->childL);
			p->data = q->data;
			p->childL = delete(p->childL, q->data);
		}
		else if(height(p->childL) > height(p->childR)) {
			q = InSuc(p->childR);
			p->data = q->data;
			p->childR = delete(p->childR, q->data);
		}
	}
}

int main()
{
	insert(5);
	insert(7);
	insert(3);
	insert(6);
	insert(4);
	
	int key = 6;
	struct node* found = search(key); 
	
	if(found)
		printf("Element %d found at %X", key, found);
	else
		printf("Element %d not found", key);
}
