#pragma once

#include <string>

class Tag
{
public:
	const static int NUM = 256;
	const static int ID = 257;
	const static int TRUE = 258;
	const static int FALSE = 259;
};

class Token
{
public:
	const int tag;
	Token()
		:tag(-1) {}

	Token(int t)
		:tag(t) {}

	virtual ~Token() = default;
};

class Num :public Token
{
public:
	const int value;

	Num(int v)
		:Token(Tag::NUM),
		value(v) {}

	virtual ~Num() = default;
};

class Word :public Token
{
public:
	const std::string lexeme;

	Word() {};

	Word(const int t, std::string s)
		:Token(t),
		lexeme(s) {}

	virtual ~Word() = default;
};