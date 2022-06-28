#ifndef _FUNCTION_TABLE_
#define _FUNCTION_TABLE_

#include <functional>
#include <vector>
#include "SymbolTable.h"
#include <cassert>
#include <cmath>

using funcPtr = double(*)(double);
//using funcPtr = std::function<double>(double);

class FunctionTable
{	
	struct FunctionEntry
	{
		funcPtr m_func;
		const char* funcName;
	};

	FunctionEntry Entrys[13] =
	{
		log,     "log",
		log10,   "log10",
		exp,     "exp",
		sqrt,    "sqrt",
		sin,     "sin",
		cos,     "cos",
		tan,     "tan",
		sinh,    "sinh",
		cosh,    "cosh",
		tanh,    "tanh",
		asin,    "asin",
		acos,    "acos",
		atan,    "atan"
	};

public:
	FunctionTable(SymbolTable& stbl);
	~FunctionTable()noexcept = default;

	unsigned int size() { return m_functionSize; }
	funcPtr GetFunc(unsigned int ID)const
	{
		return m_vecFunction[ID];
	}

	void Init(SymbolTable& stbl);

private:
	std::vector<funcPtr>   m_vecFunction;
	unsigned int           m_functionSize;
};


#endif // !_FUNCTION_TABLE_


