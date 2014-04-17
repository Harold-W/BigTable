#include "Tablet.h"

using namespace bt;

Node* NodeFactory::build(std::string name, const std::string &value) {
	Node* node=nullptr;
	if (name.empty()) return node;
	size_t first_deli_pos = name.find_first_of(':');
	std::string name_prefix = name.substr(0, first_deli_pos);
	if (first_deli_pos+1>name.length()) {
		node = new Cell;
		return node;
	} else {
		name = name.substr(first_deli_pos+1);
		node = new Lookup;
		return node;
	}
}