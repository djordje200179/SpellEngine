#include <fstream>
#include <algorithm>
#include "pch.hpp"

namespace SpellEngine {
	void SpellEngine::addWord(const std::string& rawWord) {
		auto word = toLower(rawWord);

		auto node = &root;
		for(auto character : word) {
			auto found = node->getChild(character);
			node = found ? found : node->addChild(character);
		}

		node->incrementFrequency();
	}

	bool SpellEngine::checkWord(const std::string& rawWord) const {
		auto word = toLower(rawWord);

		auto node = getNode(word);
		return node != nullptr;
	}

	void SpellEngine::inputWords(std::istream& in) {
		auto tempString = std::string();
		while(in >> tempString)
			addWord(tempString);
	}

	std::vector<std::string> SpellEngine::getPrediction(const std::string& rawWord) const {
		auto word = toLower(rawWord);

		auto node = getNode(word);
		return node->getWords(word.substr(0, word.length() - 1));
	}

	void SpellEngine::outputWords(std::ostream& out) const {
		for(auto& word : root.getWords())
			out << word << '\n';
	}

	bool SpellEngine::operator()(const std::string& rawWord) const {
		return checkWord(rawWord);
	}

	void SpellEngine::operator+=(const std::string& rawWord) {
		addWord(rawWord);
	}

	std::ostream& operator<<(std::ostream& out, const SpellEngine& engine) {
		engine.outputWords(out);

		return out;
	}

	std::istream& operator>>(std::istream& in, SpellEngine& engine) {
		engine.inputWords(in);

		return in;
	}

	const Node* SpellEngine::getNode(const std::string& word) const {
		auto currentNode = &root;
		for(char character : word) {
			auto child = currentNode->getChild(character);

			if(child)
				currentNode = child;
			else
				return nullptr;
		}

		return currentNode;
	}

	std::string SpellEngine::toLower(const std::string& rawWord) {
		auto newString = std::string();
		newString.reserve(rawWord.size());

		for(auto ch: rawWord)
			newString.push_back(std::tolower(ch));

		return newString;
	}
}