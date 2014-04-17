#ifndef BT_TABLET
#define BT_TABLET
#include <string>
#include <vector>
#include <list>

namespace bt {

struct Data {
	int timestamp;
	std::string value;
};

struct Filter {
	std::pair<int, int> time;
	std::string name;
}; 

class Tablet {
public:
	Tablet(const std::string &index);
	~Tablet();
	int update(std::string name, const std::string &value);
	const std::vector<Data>& retrieve(const Filter& filter);
private:
	std::string index;
	Node * node;
};

class NodeFactory {
public:
	static Node* build(std::string name, const std::string &value);
private:
	NodeFactory();
};

class Node {
public:
	virtual int update(std::string name, const std::string &value) = 0;
	virtual const std::vector<Data>& retrieve(const Filter&);
private:
	std::string name;
};

class Lookup : public Node {
public:
private:
	virtual Node* look(const Filter&);
};

class Cell : public Node {
public:
private:
	std::list<Data> data;
};

};

#endif