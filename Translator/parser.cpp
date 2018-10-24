#include "parser.h"
#include "myexeptios.h"

#include <iostream>
#include <locale>


Parser::Parser()
{
	lookahead = getchar();
}

void Parser::expr()
{
	term();
	while (true)
	{
		switch (lookahead)
		{
		case '+':
		{
			match('+');
			term();
			std::cout << '+';
			break;
		}
		case '-':
		{
			match('-');
			term();
			std::cout << '-';
			break;
		}
		default:
			return;
		}
	}
}

void Parser::term()
{
	if (isdigit(lookahead))
	{
		std::cout << static_cast<char>(lookahead);
		match(lookahead);
	}
	else
		throw SyntaxError();
}

void Parser::match(const int t)
{
	if (lookahead == t)
		lookahead = getchar();
	else
		throw SyntaxError();
}

