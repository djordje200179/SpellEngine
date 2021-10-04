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

	void SpellEngine::inputWords(std::istream& input) {
		auto tempString = std::string();
		while(input >> tempString)
			addWord(tempString);
	}

	std::vector<std::string> SpellEngine::getPrediction(const std::string& rawWord) const {
		auto word = toLower(rawWord);

		auto node = getNode(word);
		return node->getWords(word.substr(0, word.length() - 1));
	}

	void SpellEngine::outputWords(std::ostream& output) const {
		for(auto& word : root.getWords())
			output << word << '\n';
	}

	bool SpellEngine::operator()(const std::string& rawWord) const {
		return checkWord(rawWord);
	}

	void SpellEngine::operator+=(const std::string& rawWord) {
		addWord(rawWord);
	}

	std::ostream& operator<<(std::ostream& output, const SpellEngine& engine) {
		engine.outputWords(output);

		return output;
	}

	std::istream& operator>>(std::istream& input, SpellEngine& engine) {
		engine.inputWords(input);

		return input;
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