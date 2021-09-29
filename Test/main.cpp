#include <iostream>
#include <fstream>
#include <SpellEngine/spell_engine.hpp>

void test(const SpellEngine::SpellEngine& spell_engine, const std::string& word) {
	auto result = spell_engine(word);

	std::cout << word << ": " << (result ? "Da" : "Ne") << '\n';
}

int main() {
	auto spell_engine = SpellEngine::SpellEngine();

	auto inputFile = std::ifstream("words_alpha.txt");
	inputFile >> spell_engine;
	inputFile.close();

	test(spell_engine, "housr");
	test(spell_engine, "house");

	return 0;
}