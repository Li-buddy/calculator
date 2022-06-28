#include "./include/UnaryNode.h"

UnaryNode::UnaryNode(Node* pNode)
	:m_memberNode(pNode)
{
}
UnaryNode::~UnaryNode()noexcept
{
	if (m_memberNode)
	{
		delete m_memberNode;
	}
}

UMinusNode::UMinusNode(Node* pNode)
	:UnaryNode(pNode)
{
}

double UMinusNode::calculate()const
{
	return 0 - m_memberNode->calculate();
}