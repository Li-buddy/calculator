#ifndef _NODE_H_
#define _NODE_H_

#include "Storage.h"
#include <iostream>

class Node {
public:
	explicit Node() = default;
	virtual ~Node() {};
	//noncopyable
	Node(const Node&) = delete;
	const Node& operator=(const Node&) = delete;
	virtual bool IsLValue()const
	{
		return false;
	}
	virtual void assign(double)
	{
		return;
	}
public:
	virtual double calculate() const = 0;//使用 const修饰，不会修改数据成员
};

class NumberNode:public Node {
public:
	explicit NumberNode(double value)
		:m_value(value)
	{
	}
	~NumberNode() noexcept = default;
	double calculate()const final
	{
		return m_value;
	}
private:
	double m_value;
};

class VariableNode :public Node
{
public:
	explicit VariableNode(unsigned int ID, Storage& storage)
		:m_curID(ID),m_variableStorage(storage)
	{
	}
	~VariableNode()noexcept = default;

	double calculate()const final
	{
		double variable = 0.0;
		if (m_variableStorage.IsInited(m_curID))
		{
			variable = m_variableStorage.getValue(m_curID);
		}
		else
		{
			std::cout << "variable not init" << std::endl;
		}
		return variable;
	}

	bool IsLValue()const
	{
		return true;
	}

	void assign(double value)final 
	{
		m_variableStorage.setValue(m_curID,value);
	}

private:
	const unsigned int m_curID;
	Storage&      m_variableStorage;
};

#endif // !_NODE_H_
