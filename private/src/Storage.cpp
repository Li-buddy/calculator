#include "./include/Storage.h"
#include "./include/SymbolTable.h"
#include <cassert>
#include <iostream>

Storage::Storage(SymbolTable& stbl)
{
	AddConstant(stbl);
}
void Storage::clear()
{
	m_vecCellValue.clear();
	m_vecIsInited.clear();
}

void Storage::AddConstant(SymbolTable& stbl)
{
	std::cout << "variable list : " << std::endl;
	std::cout << "e = " << exp(1.0) << std::endl;
	unsigned int id = stbl.Add("e");
	addValue(id, exp(1.0));
	id = stbl.Add("pi");

	addValue(id, 2.0 * acos(0.0));
	std::cout << "pi = " << 2.0 * acos(0.0) << std::endl;
}
bool Storage::IsInited(unsigned int curID)
{
	if (curID < m_vecIsInited.size()
		&& m_vecIsInited[curID])
		return true;
	else
		return false;
}
double Storage::getValue(unsigned int curID)
{
	assert(curID < m_vecCellValue.size());
	return m_vecCellValue[curID];
}
void Storage::setValue(unsigned int curID, double value)
{
	assert(curID <= m_vecCellValue.size());
	if (curID < m_vecCellValue.size())
	{
		m_vecCellValue[curID] = value;
		m_vecIsInited[curID] = true;
	}
	else if (curID == m_vecCellValue.size())
	{
		addValue(curID,value);
	}
	else
	{
		;
	}
}
void Storage::addValue(unsigned int curID, double value)
{
	//assert(curID == m_vecCellValue.size());
	m_vecCellValue.resize(curID+1);
	m_vecIsInited.resize(curID+1);
	m_vecCellValue[curID] = value;
	m_vecIsInited[curID] = true;
}