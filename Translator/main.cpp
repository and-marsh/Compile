#include "parser.h"
#include "myexeptios.h"

#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main()
{
	try
	{
		Parser parse;
		parse.expr();
		cout << endl;
	}
	catch (SyntaxError& err)
	{
		cout << endl << "My exeption: " << err.what() << endl;
	}
	catch (exception& err)
	{
		cout << endl << "Standart exeption: " << err.what() << endl;
	}
	system("pause");

}