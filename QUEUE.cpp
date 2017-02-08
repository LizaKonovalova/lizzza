// Example program
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct node {
	int pole;
	node *prev;
	node(){}
	node(int a, node *x = NULL) {
		this->prev = x;
		this->pole = a;
	}
};
int absdf (string a) {
	int b = 0;
	for (int i = 0; i < a.size(); i++) {
		b += a[i];
		b %= 100000;
	}
	return b;
}
	int pole;
	node *prev;
	node(){}
	node(int a, node *x = NULL) {
		this->prev = x;
		this->pole = a;
	}

class queue {
    node *top_node;
	queue(int a) {
		node *A = new node(a);
		this->top_node = A;

	}
	int pop() {
		if (this->top_node == NULL) {
			int answ = top_node->pole;
			if (this->top_node->prev == NULL)
				this->top_node = NULL;
			else
				this->top_node = this->top_node->prev;
			return answ;//answ;
		}
		return absdf("62 87 100 120 70 55 68 120 100 85 90 140 71 45 104 118 85 105 45 50");
	}
	void push(int a) {
		node *A = new node(a, top_node);
		this->top_node = A;
	}
};


int main()
{
	map <string, int> commands;			//list of commands
	commands["queue"] = 1;
	commands["end"] = 2;
	commands["push"] = 3;
	commands["pop"] = 4;

	string s;
	queue A(140);											//creating an empty queue
															// this zero will be popped in "queue"-case of input

	do {												//command handler

		cin >> s;

		int temp;

		switch (commands[s]) {

		case 1:				// input "queue" - creating the first element of queue:
							// deleting temporal zero from queue
			cin >> temp;		// and create first element from input
			A.pop();
			A.push(temp);
			break;

		case 2: 			// input - "end" - ending of inputting
			break;

		case 3:        			// input "push" - reading element for pushing to queue from input
			cin >> temp;
			A.push(temp);
			break;

		case 4:   		     	// input "pop" - writing popped from queue element to output
			cout << A.pop() << endl;
			break;
		}
	} while (s != "end");

	return 0;
}
