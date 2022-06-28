#ifndef _BINARYNODE_H_
#define _BINARTNODE_H

#include "Node.h"
#include <iostream>
#include <cassert>

class BinaryNode :public Node {
public:
	BinaryNode(Node* pLeftNode, Node* pRightNode)
		:m_leftNode(pLeftNode), m_rightNode(pRightNode)
	{}
	
	~BinaryNode() ;
	
protected:	
	Node* const m_leftNode;
	Node* const m_rightNode;
};


class AssignNode :public BinaryNode
{
public:
	explicit AssignNode(Node* pLeftNode, Node* pRightNode)
		:BinaryNode(pLeftNode,pRightNode)
	{
		assert(pLeftNode->IsLValue());
	}
	double calculate()const final
	{
		double x = 0.0;
		x = m_rightNode->calculate();
		m_leftNode->assign(x);
		return x;
	}
};

#endif // !_BINARYNODE_H_

