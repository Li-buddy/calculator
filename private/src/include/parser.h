#ifndef _PARSER_H_
#define _PARSER_H_

class Calc;

//forward reference
class Scanner;
class Node;

enum EStatus
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT	
};

class Parser {
public:
	explicit Parser(Scanner& scanner, Calc& calc);
	~Parser();
	EStatus parse();            //执行解析，返回解析状态
	double calculate();

private:
	Node* Expr();
	Node* Term();
	Node* Factor();

private:
	Scanner& m_Scanner;
	Calc& m_calc;
	Node* m_treeRoot;
	EStatus m_status;
};

#endif // !_PARSER_H_
