#pragma once

#include <vector>
#include <string>

namespace SpellEngine {
class Node {
public:
	Node(char c = '\0');
	~Node();

	void incrementFrequency();

	Node* getChild(char c) const;
	Node* addChild(char c);

	std::vector<std::string> getWords(const std::string& prefix = "") const;

private:
	void getWordsResursively(std::vector<std::string>& words, std::string currentString) const;

	std::vector<Node*> children;

	unsigned int frequency = 0;
	char character = '\0';
};
}