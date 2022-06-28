#include "./include/FunctionTable.h"
#include <iostream>

FunctionTable::FunctionTable(SymbolTable& stbl)
	:m_functionSize(sizeof(Entrys) / sizeof(Entrys[0]))
{
	Init(stbl);
}

void FunctionTable::Init(SymbolTable& stbl)
{
	m_vecFunction.resize(m_functionSize, nullptr);
	std::cout << "Function list" << std::endl;
	for (size_t i = 0; i < m_vecFunction.size(); ++i)
	{
		m_vecFunction[i] = Entrys[i].m_func;
		unsigned int j = stbl.Add(Entrys[i].funcName);    //������������ű����ݴ棬�������Ҷ���
		assert(i == j);
		std::cout << Entrys[i].funcName << std::endl;
	}
}