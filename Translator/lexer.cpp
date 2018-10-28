#include "lexer.h"



Lexer::Lexer()
{
	reserve(Word(Tag::TRUE, "true"s));
	reserve(Word(Tag::FALSE, "false"s));
}


Lexer::~Lexer()
{
}

void Lexer::reserve(Word t)
{
	words.insert(make_pair(t.lexeme, t));
}

Token Lexer::scan()
{
	for (;; peek = getchar())
	{
		if (peek == ' ' || peek == '\t') continue;
		else if (peek == '\n') ++line;
		else break;
	}
	if (isdigit(peek))
	{
		int v = 0;
		do {
			v = 10 * v + int(peek) - '0';
			peek = getchar();
		} while (isdigit(peek));

		return Num(v);
	}
	if (isalpha(peek))
	{
		string buffer = "";
		do
		{
			buffer += peek;
			peek = getchar();
		} while (isalnum(peek));
		auto it = words.find(buffer);
		if (it != words.end())
			return words[buffer];
		Word w(Tag::ID, buffer);
		words.insert(make_pair(buffer, w));
		return w;
	}
	Token t(peek);
	peek = ' ';
	return t;
}
