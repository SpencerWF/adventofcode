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
#define PLAYERS 486
#define MARBLES 7083300

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
	int list_length;

	LinkedList() {
		head=NULL;
		tail=NULL;
		list_length=0;
	}

	Node *create_node(unsigned long long value) {
		//Have pointer to node (node_pos), the new node must be placed so that the pointed to node has the new node as it's previous node, 
		//and it's earlier previous node has the new node as it's next node.
		Node *temp = new Node;
		temp->marble_value = value;
		temp->next = NULL;
		temp->previous = NULL;
		return temp;
	}

	Node *insert_node(Node *node_new, Node *node_pos) {
		if(head==NULL) {
			head=node_new;
			tail=node_new;
			node_new->next = node_new;
			node_new->previous = node_new;
			list_length++;
			return node_new;
		}
		else if(node_pos == head) {
			// std::cout << "put marble at tail" << std::endl;
			node_new->previous = tail;
			node_new->next = head;

			tail->next = node_new;
			tail = node_new;

			head->previous = node_new; //could also be writen node_pos->previous = node_new
			node_pos = node_new;
			list_length++;
			return tail;
		}
		else {
			node_new->next = node_pos; //Newest node points to the current node as "next" node
			node_new->previous = node_pos->previous; //Newest node points to the current nodes' previous node as newest nodes' previous node
			// std::cout << "Previous node points from " << ((node_pos->previous)->next)->marble_value;
			(node_pos->previous)->next = node_new; //current nodes' previous node now points to newest node as it's next node
			// std::cout << " to " << ((node_pos->previous)->next)->marble_value << std::endl;
			node_pos->previous = node_new; //current node points to newest node as it's new previous node
			node_pos = node_new; //newest node becomes current node
			list_length++;
			return node_pos;
		}
	}

	Node *delete_node(Node *node_pos) {
		if(head==NULL) {
			std::cout << "No nodes to delete" << std::endl;
			return node_pos;
		}
		else if(node_pos == head) {
			(head->next)->previous = tail;
			head = head->next;
			tail->next = head;
			return head;
		}
		else if(node_pos == tail) {
			(tail->previous)->next = head;
			tail = tail->previous;
			head->previous = tail;
			return tail;
		}
		else {
			(node_pos->previous)->next = node_pos->next;
			(node_pos->next)->previous = node_pos->previous;
			return node_pos->next;
		}
	}

	Node *shift_pos(Node *node_pos, bool direction, int distance) {
		if(direction) {
			for(int i=0; i<distance; i++) {
				node_pos = node_pos->next;
			}
		}
		else {
			for(int i=0; i<distance; i++) {
				node_pos = node_pos->previous;
			}
		}
		return node_pos;
	}

	Node *head_pos() {
		return head;
	}

	Node *tail_pos() {
		return tail;
	}
};

int main() {
	std::vector<int> circle;
	int player_num=0;
	unsigned long long high_score = 0;
	std::array<unsigned long long, PLAYERS> players;
	LinkedList marble_circle;
	Node *node_pos, *node_new, *circle_head;

	for(int i=0; i<players.size(); i++) {
		players[i] = 0;
	}

	std::cout << "Set players to 0" << std::endl;

	node_new = marble_circle.create_node(0);
	node_pos = marble_circle.insert_node(node_new, node_pos);
	circle_head = marble_circle.head_pos();

	std::cout << "created first marble" << std::endl;

	for(unsigned long long i=1; i<MARBLES+1; i++){
		if(i%23==0) {
			node_pos = marble_circle.shift_pos(node_pos, false, 7);
			players[player_num] += node_pos->marble_value + i;
			node_pos = marble_circle.delete_node(node_pos);
		}
		else {
			node_new = marble_circle.create_node(i);
			node_pos = marble_circle.shift_pos(node_pos, true, 2);
			node_pos = marble_circle.insert_node(node_new, node_pos);
		}
		player_num++;
		if(player_num == PLAYERS) {
			player_num = 0;
		}
	}

	std::cout << std::endl;

	for(int i=0; i<players.size(); i++) {
		// std::cout << players[i] << " ";
		if(players[i]>high_score) {
			high_score = players[i];
		}
	}
	std::cout << std::endl;
	std::cout << "Winning player has a score of: " << high_score << std::endl;
	std::cout << std::endl;
}

