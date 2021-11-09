#include <CppUnitTest.h>
#include <SpellEngine/spell_engine.hpp>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpellEngine {
TEST_CLASS(Construction) {
public:
	TEST_METHOD(FileLoading) {
		SpellEngine spellEngine;

		std::ifstream inputFile("words_alpha.txt");
		inputFile >> spellEngine;
		inputFile.close();
	}
};
}