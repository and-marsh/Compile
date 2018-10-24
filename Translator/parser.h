#pragma once
class Parser
{
public:
	Parser();
	virtual ~Parser() = default;
	void expr();

private:
	void term();
	void match(const int t);

	int lookahead;
};

