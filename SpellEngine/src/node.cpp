#include "pch.hpp"

namespace SpellEngine {
	Node::Node(char c) : character(c) {}

	Node::~Node() {
		for(auto child : children)
			delete child;
	}

	void Node::increment_frequency() {
		frequency++;
	}

	Node* Node::get_child(char character) const {
		for(auto child : children)
			if(child->character == character)
				return child;

		return nullptr;
	}

	Node* Node::add_child(char character) {
		auto new_node = new Node(character);
		children.push_back(new_node);

		return new_node;
	}

	std::vector<std::string> Node::get_words(const std::string& prefix) const {
		auto words = std::vector<std::string>();
		get_words_resursively(words, prefix);
		return words;
	}

	void Node::get_words_resursively(std::vector<std::string>& words, std::string current_string) const {
		if(character)
			current_string.push_back(character);

		if(frequency)
			words.push_back(current_string);

		for(auto son : children)
			son->get_words_resursively(words, current_string);
	}
}