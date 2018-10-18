#include <iostream>
#include <cassert>

#define B_SIZE 5 //size of a side of the square in pixel
#define MAZE_WIDTH 200
#define MAZE_LENGTH 200

/* -------------------------------------------------------- */

class Node{
private:
	enum Type { NORMAL, I_END, O_END };
	enum Neighbours_nb { OEND_NB = 3, IEND_NB = 5, NORM_NB = 8 };

	int n_size;
	Type n_type; //0: normal; 1: bordure; 2:extremité.
	Neighbours_nb n_max_ngbs;
	int n_cur_ngbs;
	bool n_isfull; //true -> full; false -> empty.
	Node * n_ngbs; 

public:
	Node(Type type = NORMAL): n_size(B_SIZE), n_type(type), n_cur_ngbs(0) {
		switch (type){
			case NORMAL:
				n_max_ngbs = NORM_NB;
				n_isfull = false;
				n_ngbs = new Node[NORM_NB];
				break;
			case I_END:
				n_max_ngbs = IEND_NB;
				n_isfull = true;
				n_ngbs = new Node[I_END];
				break;
			case O_END: 
				n_max_ngbs = OEND_NB;
				n_isfull = true;
				n_ngbs = new Node[O_END];
				break;
			}
	}

	//getters
	inline Type getNodeType() const { return n_type; }
	inline int getCurrentNbgsNb() const { return n_cur_ngbs; }
	inline bool isNodeFull() const { return n_isfull; }

	//setters
	inline void setNodeState(bool st) { n_isfull = st; }
};

class Maze{
public:
	Maze(): m_width(MAZE_WIDTH), m_length(MAZE_LENGTH) { m_arr = new Node [MAZE_LENGTH * MAZE_WIDTH / B_SIZE]; } 
	Maze(int w, int l): m_width(w), m_length(l) { m_arr = new Node [w * l / B_SIZE]; }
	~Maze() { delete[] m_arr; }

private:
	int m_width;
	int m_length;
	Node * m_arr;
};