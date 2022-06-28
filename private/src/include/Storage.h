#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <vector>

class SymbolTable;

class Storage
{
public:
	explicit Storage(SymbolTable& stbl);
	~Storage()noexcept = default;
	void clear();
	void AddConstant(SymbolTable& stbl);
	bool IsInited(unsigned int curID);
	double getValue(unsigned int curID);
	void setValue(unsigned int curID, double value);
	void addValue(unsigned int curID, double value);

private:
	std::vector<double>  m_vecCellValue;
	std::vector<bool> m_vecIsInited;
};


#endif // !_STORAGE_H_



