#ifndef _UNARYNODE_H_
#define _UNARYNODE_H_

#include "Node.h"

using funcPtr = double(*)(double);

class UnaryNode:public Node
{
public:
	explicit UnaryNode(Node* pNode);
	~UnaryNode()noexcept;
	
protected:
	Node* const m_memberNode;
};

class UMinusNode :public UnaryNode {
public:
	explicit UMinusNode(Node* pNode);
	~UMinusNode()noexcept = default;

	virtual double calculate()const final;
};

class FunctionNode :public UnaryNode {
public:
	explicit FunctionNode(Node* pNode, funcPtr func)
		:UnaryNode(pNode),m_function(func)
	{

	}
	~FunctionNode()noexcept = default;
	double calculate() const final
	{
		return m_function(m_memberNode->calculate());    //���� sqrt��4+5����Ҫ�ȵõ�4+5   �ټ��㺯��
	}
protected:
	funcPtr m_function;
};

#endif // !_UNARYNODE_H_
