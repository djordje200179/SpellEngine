#include <iostream>
#include <fstream>
#include <SpellEngine/spell-engine.hpp>

void test(const SpellEngine::SpellEngine& spellEngine, const std::string& word) {
	auto result = spellEngine(word);

	std::cout << word << ": " << (result ? "Da" : "Ne") << '\n';
}

int main() {
	auto spellEngine = SpellEngine::SpellEngine();

	auto inputFile = std::ifstream("words-alpha.txt");
	inputFile >> spellEngine;
	inputFile.close();

	test(spellEngine, "housr");
	test(spellEngine, "house");

	return 0;
}