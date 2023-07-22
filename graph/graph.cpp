#include <iostream>
#include <fstream>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;



class Node {
private:
    int value;
    std::unordered_set<Edge*> edges; // Список ребер
    std::unordered_map<Node*, Edge*> parents; // Список родителей

public:
    Node(int value) : value(value) {}

    void addEdge(Edge* edge) {
        edges.insert(edge);
    }

    void addParent(Node* parent, Edge* edge) {
        parents[parent] = edge;
    }

    int getValue() const {
        return value;
    }

    const std::unordered_set<Edge*>& getEdges() const {
        return edges;
    }

    const std::unordered_map<Node*, Edge*>& getParents() const {
        return parents;
    }
};

class Edge {
private:
    Node* adjacentNode;
    int weight;

public:
    Edge(Node* adjacentNode = nullptr, int weight = 0)
        : adjacentNode(adjacentNode), weight(weight) {}

    Node* getAdjacentNode() const {
        return adjacentNode;
    }

    int getWeight() const {
        return weight;
    }
};

int main()
{

}

//class Node
//{
//	int value;
//	LinkedHaskSet<Edge> edges = new LinkedHaskSet<>(); // список ребер
//	LinkedHaskMap<Node, Edge> parents = LinkedHaskMap<>(); // список родителей;
//	Node(int value)
//	{
//		this->value = value;
//	}
//};
//
//class Edge
//{
//	Node* adjacentNode;
//	int weight;
//
//	Edge(Node* adjacentNode = nullptr, int weight = int())
//	{
//		this->adjacentNode = adjacentNode;
//		this->weight = weight;
//	}
//};

//Node addOrGet(Hashmap<int, Node*> graph, int value)
//{
//	if (value == -1) return null;
//	if (graph.containsKey(value)) return graph.get(value);
//	Node* node = new Node(value);
//	graph.put(value, node);
//	retuen node;
//}
//HashMap<int, Node> CreateGraph(vector<vector<inr>> graphData)
//{
//	HashMap<int, Node*> graph = new HashMap<>();
//	for (vector<int> row : graphData)
//	{
//		Node* node = addOrGEt(graph, row[0]);
//		Node* adjacentNode = addOrGet(graph, row[1]);
//		if (adjacentNode == null) continue;
//		Edge edge = new Edge(adjacentNode, row[2]);
//		node.edges.add(edge);
//		adjacentNode->parents->put(node, edge);
//	}
//	return graph;
//}