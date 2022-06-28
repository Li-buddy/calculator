#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_

#include <map>
#include <string>

class SymbolTable
{
public:
	explicit SymbolTable();
	~SymbolTable()noexcept = default;

	unsigned int Add(const std::string& symbol);
	unsigned int Find(const std::string& symbol) const; 
	void clear();
	const std::string getSymbolName(unsigned int curID) const;

private:
	std::map<const std::string, unsigned int>  m_mapSybolTable;
	unsigned int                               m_uCurID;
};


#endif // !_SYMBOLTABLE_H_




