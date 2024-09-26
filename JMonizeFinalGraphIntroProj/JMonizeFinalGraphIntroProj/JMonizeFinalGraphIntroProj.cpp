#include <iostream>
#include<list>
using namespace std;
	  //Jessica Monize Graph Introduction Project
	 //Making  Adjacency List
	//Making Adjacency Matrix




//Using Graph to show visual data and connections Adjacency List
class Graph {
	int V;
	list<int>* l;//making a new list

public:
	Graph(int V)
	{
		this->V = V;
		//l pointer points at array of list
		l = new list <int>[V];
	} 
	//adding edges
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	//printing out the adjacency list Vertex and it's neighbors
	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << "Vertex: " << i << "->";
			for (int lists : l[i]) { //Neighbor List
				cout << lists << ",";
			}
			cout << endl;
		}
	}

};//End of first Graph Class

//Graph 2 shows same data in Adjacency Matrix
class Graph2 {
	int V2;
	int u[7][7];
public:
	Graph2(int c) {
		V2 = c;

		for (int i = 0; i < V2; ++i) {
			for(int j=0; j<V2;++j)
			u[i][j] = 0;
		}
	}
	void showAdjMatrix() {
		cout << "Adjacency Matrix:";
		for (int i = 0; i < V2; i++) {
			cout << " "<<endl;
			for (int j = 0; j < V2; j++) {
				cout << " " << u[i][j];
			}
		}
	}
	void addingEdge(int c, int y) {
		if ((c >= V2) || (y > V2)) {
			cout << "No Vertex By This Value"<<endl;
		}
		if (c == y) {
			cout << "Vertex is the Same" << endl;
		}
		else {
			u[y][c] = 1;
			u[c][y] = 1;
		}
	}
	void addingVertex() {
		V2++;
		int i;

		for (i = 0; i < V2; i++) {
			u[i][V2 - 1] = 0;
			u[V2 - 1][i] = 0;
		}
	}
	void removingVertex(int c) {
		if (c > V2) {
			cout << "No Vertex By This Value" << endl;
			return;
		}
		else {
			int i;

			while (c < V2) {
				for (i = 0; i < V2; ++i) {
					u[c][i] = u[c + 1][i];
				}
				c++;
			}
			V2--;
		}
	}
};//end of Graph2 Class

int main() {
	//adding edges between numbers
	Graph g(5); //Nodes in Graph
	////adding edges
	g.addEdge(0,1); 
	g.addEdge(0,3);
	g.addEdge(2,3);
	g.addEdge(1,2);
	g.addEdge(3,4);

	//printing out Adj List
	g.printAdjList();
	cout << "" << endl;
	cout << "" << endl;

	Graph2 edges(5);

	edges.addingEdge(0, 1);
	edges.addingEdge(0, 3);
	edges.addingEdge(2, 3);
	edges.addingEdge(1, 2);
	edges.addingEdge(3, 4);

	edges.showAdjMatrix();
	edges.addingVertex();

	cout << " " << endl;
	cout << " " << endl;
	cout << "\tRemoving Vertex 1: " << endl;
	edges.removingVertex(1);
	edges.showAdjMatrix();

	cout << " " << endl;
	cout << " " << endl;

	cout << "\tAdding Edges, Connecting 2 and 4 and Connecting 4 and 5" << endl;
	edges.addingEdge(2, 4);
	edges.addingEdge(4, 5);
	edges.showAdjMatrix();

	return 0;
}

