#include "./include/SymbolTable.h"
#include <iostream>
#include <algorithm>

SymbolTable::SymbolTable()
	:m_uCurID(0)
{
}

unsigned int SymbolTable::Add(const std::string& symbol)
{
	m_mapSybolTable[symbol] = m_uCurID;
	return m_uCurID++;
}
unsigned int SymbolTable::Find(const std::string& symbol)const
{
	auto it = m_mapSybolTable.find(symbol);
	if (it != m_mapSybolTable.end())
	{
		//std::cout << symbol << ": " << it->second << "\n";
		return it->second;
	}
	std::cout << "didn'n find it " << "\n";
	return -1;
}

void SymbolTable::clear()
{
	m_mapSybolTable.clear();
	m_uCurID = 0;
}

const std::string SymbolTable::getSymbolName(unsigned int curID)const 
{
	auto it = std::find_if(m_mapSybolTable.begin(),m_mapSybolTable.end(),
		[&](auto& item) {return item.second == curID; });
	return it->first;
}