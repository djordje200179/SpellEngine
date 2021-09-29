#pragma once

#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include "node.hpp"

namespace SpellEngine {
	class SpellEngine {
	public:
		void add_word(const std::string& raw_word);
		bool check_word(const std::string& raw_word) const;
		std::vector<std::string> get_prediction(const std::string& raw_word) const;

		void output_words(std::ostream& out) const;
		void input_words(std::istream& out);

		bool operator()(const std::string& raw_word) const;
		void operator+=(const std::string& raw_word);
		friend std::ostream& operator<<(std::ostream& out, const SpellEngine& engine);
		friend std::istream& operator>>(std::istream& in, SpellEngine& engine);

	private:
		const Node* get_node(const std::string& word) const;
		static std::string to_lower(const std::string& raw_word);

		Node root;
	};
}