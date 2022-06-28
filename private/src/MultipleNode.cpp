#include "./include/MultipleNode.h"
#include <iostream>

MultipleNode::MultipleNode(Node* pNode)
{
	appendChildNode(pNode);
}

MultipleNode::~MultipleNode()
{
	for (Node* it : m_vecChildNode)
		delete it;
	m_vecPositive.clear();
}

void MultipleNode::appendChildNode(Node* pNode, bool bPositive)
{
	m_vecChildNode.push_back(pNode);
	m_vecPositive.push_back(bPositive);
}

SumNode::SumNode(Node* pNode)
	:MultipleNode(pNode)
{
}

double SumNode::calculate()const
{
	double result = 0.0;
	auto itPositive = m_vecPositive.begin();
	for (auto itNode = m_vecChildNode.begin(); itNode != m_vecChildNode.end(); ++itNode, ++itPositive)
	{
		double value = (*itNode)->calculate();
		if (*itPositive)
			result += value;
		else
			result -= value;
	}
	return result;
}

ProductNode::ProductNode(Node* pNode)
	:MultipleNode(pNode)
{
}

double ProductNode::calculate()const
{
	double result = 1.0;
	auto itPositive = m_vecPositive.begin();
	auto itNode = m_vecChildNode.begin();
	for (itNode; itNode != m_vecChildNode.end(); ++itNode, ++itPositive)
	{
		double value = (*itNode)->calculate();
		if (*itPositive)
			result *= value;
		else
		{
			if (value == 0)
			{
				std::cout << "devided by zero!" << std::endl;
			}
			result /= value;
		}
	}
	return result;
}