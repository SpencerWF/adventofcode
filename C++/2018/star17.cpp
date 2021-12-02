#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <map>

// define character size
#define CHAR_SIZE 128
#define PLAYERS 9
#define MARBLES 

struct Node{
	int marble_value;
	Node *next;
	Node *previous;	
};

class LinkedList{
private:
	Node *head;
	Node *tail;
public:
	list() {
		head=NULL;
		tail=NULL;
	}

	Node *create_node(int value) {
		//Have pointer to node (node_pos), the new node must be placed so that the pointed to node has the new node as it's previous node, 
		//and it's earlier previous node has the new node as it's next node.
		node *temp = new node;
		temp->marble_value = value;
		temp->next = NULL;
		temp->previous = NULL;
		return temp;
	}

	Node *insert_node(Node *node_new, Node *node_pos) {
		if(head==NULL) {
			head=node_new;
			tail=node_new;
		}
		else if(node_pos == head) {
			node_new->previous = tail;
			node_new->next = head;

			tail->next = node_new;
			tail = node_new;

			head->previous = node_new;
			node_pos = node_new;
		}
		else {
			node_new->next = node_pos;
			node_new->previous = node_pos->previous;
			*(node_pos->previous).next = node_pos;
			node_pos->previous = node_new;
			node_pos = node_new;
		}
		return node_pos;
	}
};



Node * insert(int marble){

}

int main() {
	std::vector<int> circle;
	int player_num=2, high_score = 0;
	std::array<int, PLAYERS> players;
	std::vector<int>::iterator circle_pos;

	for(int i=0; i<players.size(); i++) {
		players[i] = 0;
	}

	circle.push_back(0);
	circle.push_back(1);
	circle_pos = circle.begin()+1;
	circle_pos = circle.insert(circle_pos, 2);

	for(int i=3; i<MARBLES+1; i++) {
		if(i%23==0) {
			if(circle_pos-7 < circle.begin()) {
				circle_pos = circle.end() - (circle.begin() - circle_pos);
			}
			players[player_num] += i + *(circle_pos-7);
			circle_pos = circle.erase(circle_pos-7);
		}
		else {
		
			if(circle_pos == circle.end()-1) {
				circle_pos = circle.begin()+1;
				circle_pos = circle.insert(circle_pos, i);
			}
			else if (circle_pos == circle.end()) {
				// std::cout << "yep" << std::endl;
				
			}
			else {
				//std::cout << "nope" << std::endl;
				circle_pos += 2;
				circle_pos = circle.insert(circle_pos, i);
			}
		}
		// for (std::vector<int>::iterator it = circle.begin() ; it != circle.end(); ++it)
		// 	std::cout << ' ' << *it;
		// std::cout << " : " << player_num+1 << '\n';
		player_num++;
		if(player_num == PLAYERS) {
			player_num = 0;
		}
		
	}

	for(int i=0; i<players.size(); i++) {
		std::cout << players[i] << " ";
		if(players[i]>high_score) {
			high_score = players[i];
		}
	}
	std::cout << std::endl;
	std::cout << "Winning player has a score of: " << high_score << std::endl;
	std::cout << std::endl;
}

