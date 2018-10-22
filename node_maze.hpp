#include <iostream>
#include <cassert>
#include <random>

#define B_SIZE 5 //size of a side of the square in pixel
#define MAZE_WIDTH 200
#define MAZE_LENGTH 200

/* ------------------------------------------------------ */

class Node{
public:
	Node(Type type = NORMAL): n_size(B_SIZE), n_type(type), n_cur_ngbs(0) {
		switch (type){
			case NORMAL:
				n_max_ngbs = N_NB;
				n_isfull = false;
				n_has_been_visited = false;
				n_ngbs = new Node[n_max_ngbs];
				break;
			case INNER_BORDER:
				n_max_ngbs = IB_NB;
				n_isfull = true;
				n_has_been_visited = false;
				n_ngbs = new Node[n_max_ngbs];
				break;
			case OUTER_BORDER: 
				n_max_ngbs = OB_NB;
				n_isfull = true;
				n_has_been_visited = false;
				n_ngbs = new Node[n_max_ngbs];
				break;
			case ENTRY:
				n_max_ngbs = IB_NB;
				n_isfull = false;
				n_has_been_visited = true;
				n_ngbs = new Node[n_max_ngbs];
				break;
			case EXIT: 
				n_max_ngbs = IB_NB;
				n_isfull = false;
				n_has_been_visited = false;
				n_ngbs = new Node[n_max_ngbs];
			}
	}

	//getters
	inline Type getNodeType() const { return n_type; }
	inline int getCurrentNbgsNb() const { return n_cur_ngbs; }
	inline bool isNodeFull() const { return n_isfull; }
	inline bool hasBeenVisited() const { return n_has_been_visited; }

	//setters
	inline void setNodeContentState(bool c_st) { n_isfull = st; }
	inline void setNodeVisitState(bool v_st) { n_has_been_visited = st; }

private:
	enum Type { NORMAL, INNER_BORDER, OUTER_BORDER, ENTRY, EXIT };
	enum Neighbours_nb { OB_NB = 0, IB_NB = 1, N_NB = 4 };

	int n_size;
	Type n_type; //0: normal; 1: border; 2: extreme border
	Neighbours_nb n_max_ngbs;
	int n_cur_ngbs;
	bool n_isfull; //true -> full; false -> empty
	bool n_has_been_visited; //true -> already visited; false -> not visited yet
	Node * n_ngbs; 
};

class Maze{
public:
	Maze(): m_width(MAZE_WIDTH), m_length(MAZE_LENGTH) { m_arr = new Node [MAZE_LENGTH * MAZE_WIDTH / B_SIZE]; } 
	Maze(int w, int l): m_width(w), m_length(l) { m_arr = new Node [w * l / B_SIZE]; }
	~Maze() { delete[] m_arr; }

	//getters
	inline int getMazeWidth() const { return m_width; }
	inline int getMazeLength() const { return m_length; }
	inline Node getNodeOfMaze(int i, int j) const { return m_arr[i*m_length+j]; }

	//printers
	void printMaze(){
		std::cout << "yes" << std::endl;
	}

	//generator ()
	void generateMaze(){ 

	}

private:
	int m_width;
	int m_length;
	Node * m_arr;
};