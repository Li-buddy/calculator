#include "./include/parser.h"
#include "./include/scanner.h"
#include "./include/Node.h"
#include "./include/UnaryNode.h"
#include "./include/BinaryNode.h"
#include "./include/MultipleNode.h"
#include <iostream>
#include "./include/Calc.h"

Parser::Parser(Scanner& scanner, Calc& calc)
	:m_Scanner(scanner), m_calc(calc), m_treeRoot(nullptr), m_status(EStatus::STATUS_OK)
{
}

Parser::~Parser()
{

}

EStatus Parser::parse()
{
	m_treeRoot = Expr();
	if (!m_Scanner.IsDone())
	{
		m_status = STATUS_ERROR;
	}
	return m_status;
}

Node* Parser::Expr()
{
	//表达式 = 项
	Node* pNode = Term(); //得到项
	EToken Token = m_Scanner.getToken();
	if (EToken::TOKEN_PLUS == Token || EToken::TOKEN_SUBSTRACT == Token)
	{
		MultipleNode* pSumNode = new SumNode(pNode);
		while (EToken::TOKEN_PLUS == Token || EToken::TOKEN_SUBSTRACT == Token)
		{
			m_Scanner.accept();
			Node* pNextNode = Term();
			pSumNode->appendChildNode(pNextNode, EToken::TOKEN_PLUS == Token);
			Token = m_Scanner.getToken();
		}
		pNode = pSumNode;
	}//表达式 = 项 = 表达式
	else if (EToken::TOKEN_ASSIGN == Token)
	{
		m_Scanner.accept();
		Node* pRightNode = Expr();
		if (pNode->IsLValue())
		{
			pNode = new AssignNode(pNode, pRightNode);
		}
		else
		{
			m_status = EStatus::STATUS_ERROR;
			std::cout << "the left hand side must be a variable" << std::endl;
		}

	}
	return pNode;
}

Node* Parser::Term()
{
	//项 = 因式*项
	//项 = 因式/项
	//项 = 因式
	Node* pNode = Factor(); //得到项
	EToken Token = m_Scanner.getToken();
	if (EToken::TOKEN_MULTIPLY == Token || EToken::TOKEN_DEVIDE == Token)
	{
		MultipleNode* pMultiNode = new ProductNode(pNode);
		while (EToken::TOKEN_MULTIPLY == Token || EToken::TOKEN_DEVIDE == Token)
		{
			m_Scanner.accept();
			Node* pNextNode = Factor();
			pMultiNode->appendChildNode(pNextNode, EToken::TOKEN_MULTIPLY == Token);
			Token = m_Scanner.getToken();
		}
		pNode = pMultiNode;
	}
	return pNode;
}
Node* Parser::Factor()
{
	// 因式 = （ 表达式 ）
	// 因式 = -因式
	//

	Node* pNode = nullptr;
	EToken tempToken = m_Scanner.getToken();
	if (EToken::TOKEN_LEFTBRACKET == tempToken)
	{
		m_Scanner.accept();
		pNode = Expr();
		if (EToken::TOKEN_RIGHTBRACKET == m_Scanner.getToken())
		{
			m_Scanner.accept();
		}
		else
		{
			m_status = EStatus::STATUS_ERROR;
			std::cout << "not a valid expression!" << std::endl;
			pNode = nullptr;
		}
	}
	else if (EToken::TOKEN_NUMBER == tempToken)
	{
		pNode = new NumberNode(m_Scanner.getNumber());
		m_Scanner.accept();
	}
	else if (EToken::TOKEN_IDENTIFIER == tempToken)
	{
		std::string symbol = m_Scanner.getSymbol();
		unsigned int ID = m_calc.FindSymbol(symbol);
		m_Scanner.accept();

		if (m_Scanner.getToken() == TOKEN_LEFTBRACKET)//函数
		{
			m_Scanner.accept();
			pNode = Expr();
			if (m_Scanner.getToken() == TOKEN_RIGHTBRACKET)
			{
				m_Scanner.accept();
				if (ID != -1 && m_calc.IsFunction(ID))//找到函数
				{
					pNode = new FunctionNode(pNode, m_calc.GetFunction(ID));
				}
				else
				{
					m_status = EStatus::STATUS_ERROR;
					std::cout << "Uknown function : " << symbol << std::endl;
				}

			}
			else
			{
				std::cout << "Missing right bracket" << std::endl;
			}
		}
		else//变量
		{
			//未找到则新增一个
			if (-1 == ID)
			{
				ID = m_calc.AddSymbol(symbol);
			}
			pNode = new VariableNode(ID, m_calc.m_variableStorage);

		}
	}
	else if (EToken::TOKEN_SUBSTRACT == tempToken)
	{
		m_Scanner.accept();
		pNode = Factor();
		pNode = new UMinusNode(pNode);
	}
	else
	{
		m_status = EStatus::STATUS_ERROR;
		std::cout << "not a valid factor!" << std::endl;
		pNode = nullptr;
	}

	return pNode;
}

double Parser::calculate()
{
	return m_treeRoot->calculate();
}