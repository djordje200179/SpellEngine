#include "pch.hpp"

namespace SpellEngine {
	Node::Node(char c) : character(c) {}

	Node::~Node() {
		for(auto child : children)
			delete child;
	}

	void Node::incrementFrequency() {
		frequency++;
	}

	Node* Node::getChild(char character) const {
		for(auto child : children)
			if(child->character == character)
				return child;

		return nullptr;
	}

	Node* Node::addChild(char character) {
		auto newNode = new Node(character);
		children.push_back(newNode);

		return newNode;
	}

	std::vector<std::string> Node::getWords(const std::string& prefix) const {
		auto words = std::vector<std::string>();
		getWordsResursively(words, prefix);
		return words;
	}

	void Node::getWordsResursively(std::vector<std::string>& words, std::string currentString) const {
		if(character)
			currentString.push_back(character);

		if(frequency)
			words.push_back(currentString);

		for(auto son : children)
			son->getWordsResursively(words, currentString);
	}
}