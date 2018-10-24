#pragma once
#include <exception>

class SyntaxError
	: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Syntax error!";
	}
};