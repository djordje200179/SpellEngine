#include <CppUnitTest.h>
#include <SpellEngine/spell_engine.hpp>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SpellEngine {
TEST_CLASS(Checking) {
private:
	SpellEngine spellEngine;

	TEST_METHOD_INITIALIZE(Construction) {
		std::ifstream inputFile("words_alpha.txt");
		inputFile >> spellEngine;
		inputFile.close();
	}

public:
	TEST_METHOD(SuccessfulSearch) {
		auto result = spellEngine("house");

		Assert::IsTrue(result);
	}

	TEST_METHOD(UnsuccessfulSearch) {
		auto result = spellEngine("hzuse");

		Assert::IsFalse(result);
	}
};
}