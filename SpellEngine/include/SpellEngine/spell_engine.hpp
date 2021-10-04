#pragma once

#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include "node.hpp"

namespace SpellEngine {
class SpellEngine {
public:
	void addWord(const std::string& rawWord);
	bool checkWord(const std::string& rawWord) const;
	std::vector<std::string> getPrediction(const std::string& rawWord) const;

	void outputWords(std::ostream& output) const;
	void inputWords(std::istream& input);

	bool operator()(const std::string& rawWord) const;
	void operator+=(const std::string& rawWord);
	friend std::ostream& operator<<(std::ostream& output, const SpellEngine& engine);
	friend std::istream& operator>>(std::istream& input, SpellEngine& engine);

private:
	const Node* getNode(const std::string& word) const;
	static std::string toLower(const std::string& rawWord);

	Node root;
};
}