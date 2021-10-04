#include <iostream>
#include <fstream>
#include <SpellEngine/spell_engine.hpp>

void test(const SpellEngine::SpellEngine& spellEngine, const std::string& word) {
	auto result = spellEngine(word);

	std::cout << word << ": " << (result ? "Da" : "Ne") << '\n';
}

int main() {
	auto spellEngine = SpellEngine::SpellEngine();

	auto inputFile = std::ifstream("words_alpha.txt");
	inputFile >> spellEngine;
	inputFile.close();

	test(spellEngine, "housr");
	test(spellEngine, "house");

	return 0;
}