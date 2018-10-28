#pragma once
#include <unordered_map>
#include <string>
#include <utility>

#include "tokens.h"

using namespace std;
class Lexer
{
public:
	int line = 1;
	Lexer();
	virtual ~Lexer();
	void reserve(Word t);
	Token scan();

private:
	char peek = ' ';
	unordered_map<string, Word> words;
};

