#include <fstream>
#include <algorithm>
#include "pch.hpp"

namespace SpellEngine {
	void SpellEngine::add_word(const std::string& raw_word) {
		auto word = to_lower(raw_word);

		auto node = &root;
		for(auto character : word) {
			auto found = node->get_child(character);
			node = found ? found : node->add_child(character);
		}

		node->increment_frequency();
	}

	bool SpellEngine::check_word(const std::string& raw_word) const {
		auto word = to_lower(raw_word);

		auto node = get_node(word);
		return node != nullptr;
	}

	void SpellEngine::input_words(std::istream& in) {
		auto temp_string = std::string();
		while(in >> temp_string)
			add_word(temp_string);
	}

	std::vector<std::string> SpellEngine::get_prediction(const std::string& raw_word) const {
		auto word = to_lower(raw_word);

		auto node = get_node(word);
		return node->get_words(word.substr(0, word.length() - 1));
	}

	void SpellEngine::output_words(std::ostream& out) const {
		for(auto& word : root.get_words())
			out << word << '\n';
	}

	bool SpellEngine::operator()(const std::string& raw_word) const {
		return check_word(raw_word);
	}

	void SpellEngine::operator+=(const std::string& raw_word) {
		add_word(raw_word);
	}

	std::ostream& operator<<(std::ostream& out, const SpellEngine& engine) {
		engine.output_words(out);

		return out;
	}

	std::istream& operator>>(std::istream& in, SpellEngine& engine) {
		engine.input_words(in);

		return in;
	}

	const Node* SpellEngine::get_node(const std::string& word) const {
		auto current_node = &root;
		for(char character : word) {
			auto child = current_node->get_child(character);

			if(child)
				current_node = child;
			else
				return nullptr;
		}

		return current_node;
	}

	std::string SpellEngine::to_lower(const std::string& raw_word) {
		auto new_string = std::string();
		new_string.reserve(raw_word.size());

		for(auto ch: raw_word)
			new_string.push_back(std::tolower(ch));

		return new_string;
	}
}