#ifndef _CALC_H_
#define _CALC_H_


#include "SymbolTable.h"
#include "Storage.h"
#include "FunctionTable.h"

class Parser;

class Calc
{
public:
	Calc();

	bool IsFunction(unsigned int ID) 
	{
		return ID < m_functionTable.size();
	}

	funcPtr GetFunction(unsigned int ID)const
	{
		return m_functionTable.GetFunc(ID);
	}

private:
	unsigned int FindSymbol(const std::string& symbol)const
	{
		return m_symbolTable.Find(symbol);
	}

	unsigned int AddSymbol(const std::string& symbol)
	{
		return m_symbolTable.Add(symbol);
	}

	friend class Parser;
	SymbolTable m_symbolTable;	
	FunctionTable m_functionTable;    ///这三项成员有构造顺序要求
	Storage m_variableStorage;
};

#endif // !_CALC_H_



