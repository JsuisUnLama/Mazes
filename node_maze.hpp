#include <iostream>
#include <cassert>
#include <vector>
#include <experimental/random>

#define B_SIZE 5 //size of a side of the square in pixel
#define MAZE_WIDTH 200
#define MAZE_LENGTH 200
#define NB_NEIGHBOURS 4

/* ------------------------------------------------------ */

class Node{
public:
	Node(int index): n_size(B_SIZE), n_nb_ngbs(NB_NEIGHBOURS), n_isfull(false), n_has_been_visited(false) { n_ngbs = std::vector<Node>(n_nb_ngbs); }

	// operators
	bool operator==(Node& n) { return n.n_index == n_index; }
	bool operator==(Node&& n) { return n.n_index == n_index; }
	bool operator!=(Node& n) { return n.n_index != n_index; }
	bool operator!=(Node&& n) { return n.n_index != n_index; }
	Node operator-(Node&& n) {
		int i = 0;
		for(auto ngb : n_ngbs){
			if(n == ngb){
				n_ngbs.erase(n_ngbs.begin()+i);
				i++;
			}
		}
	}

	// getters
	static inline int getNodeIndex() { return n_index; }
	static Node getNeighbour(const int index) {
		assert(index >= 0 && index < NB_NEIGHBOURS);
		switch(index){
			case 0: return n_ngbs.at(0);
			case 1: return n_ngbs.at(1);
			case 2: return n_ngbs.at(2);
			case 3: return n_ngbs.at(3);
			default: return *this;
		} 
	}
	static inline bool isNodeFull() { return n_isfull; }
	static inline bool hasBeenVisited() { return n_has_been_visited; }
	static inline bool isDeadEnd() { return n_nb_ngbs == 0; }

	// setters
	static inline void setNodeContentState(bool c_st) { n_isfull = st; }
	static inline void setNodeVisitState(bool v_st) { n_has_been_visited = st; }

private:
	int n_index;
	int n_size;
	int n_nb_ngbs;
	bool n_isfull;
	bool n_has_been_visited;
	std::vector<Node&> n_ngbs; //order: up, down, left, right
};

class Maze{
public:
	Maze(): m_width(MAZE_WIDTH), m_length(MAZE_LENGTH) { m_arr = std::vector<Node>(MAZE_LENGTH * MAZE_WIDTH / B_SIZE); } 
	Maze(int w, int l): m_width(w), m_length(l) { m_arr = std::vector<Node>(w * l / B_SIZE); }
	~Maze() { ~m_arr; }

	// getters
	inline int getMazeWidth() { return m_width; }
	inline int getMazeLength() { return m_length; }
	inline bool isOutOfBounds(int i, int j) { return (i < 0) || (j < 0) || (i >= m_length) || (j >= m_width ); }
	Node getNodeOfMaze(int i, int j) { return m_arr.at(i*m_length+j); }
	//Node getUpNeighbour(int i, int j) { getNodeOfMaze(i+1, j) }
	//Node getDownNeighbour(int i, int j) { getNodeOfMaze(i-1, j) }
	//Node getLeftNeighbour(int i, int j) { getNodeOfMaze(i, j-1) }
	//Node getRightNeighbour(int i, int j) { getNodeOfMaze(i, j+1) }
	inline Node getRandomNode() { return getNodeOfMaze(std::experimental::randint(0,m_length),std::experimental::randint(0,m_width)); } 

	// printers
	void printMaze(){
		std::cout << "yes" << std::endl;
	}

	// initializer
	void initializeMaze(){ }

	// generator
	void generateMaze(){ 
		/* start from random, make it visited
		 * select a random unvisited neigh, make it visited
		 * continue, asserting no univisited neigh is a dead end
		 * when on a dead end, backtracks to an unvisited neigh and repeat
		 */
	}

private:
	int m_width;
	int m_length;
	std::vector<Node> m_arr;
};