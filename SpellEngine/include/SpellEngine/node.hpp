#pragma once

#include <vector>
#include <string>

namespace SpellEngine {
	class Node {
	public:
		Node(char c = '\0');
		~Node();

		void increment_frequency();

		Node* get_child(char c) const;
		Node* add_child(char c);

		std::vector<std::string> get_words(const std::string& prefix = "") const;

	private:
		void get_words_resursively(std::vector<std::string>& words, std::string current_string) const;

		std::vector<Node*> children;

		unsigned int frequency = 0;
		char character = '\0';
	};
}