#include "./include/BinaryNode.h"

BinaryNode::~BinaryNode()
{
	if (m_leftNode)
	{
		delete m_leftNode;
		//m_leftNode = nullptr;
	}

	if (m_rightNode)
	{
		delete m_rightNode;
		//m_rightNode = nullptr;
	}
}

//double AddNode::calculate()const
//{
//	if (!m_leftNode && !m_rightNode)
//	{
//		return 0.0;
//	}
//	if (!m_leftNode)
//	{
//		return m_rightNode->calculate();
//	}
//	if (!m_rightNode)
//	{
//		return m_leftNode->calculate();
//	}
//	return m_leftNode->calculate() + m_rightNode->calculate();
//}
//
//double SubNode::calculate()const
//{
//	if (!m_leftNode && !m_rightNode)
//	{
//		return 0.0;
//	}
//	if (!m_leftNode)
//	{
//		return 0 - m_rightNode->calculate();
//	}
//	if (!m_rightNode)
//	{
//		return m_leftNode->calculate();
//	}
//	return m_leftNode->calculate() - m_rightNode->calculate();
//}
//
//double MultiplyNode::calculate()const
//{
//	if (!m_leftNode || !m_rightNode)
//	{
//		return 0.0;
//	}
//	return m_leftNode->calculate() * m_rightNode->calculate();
//}
//
//double DevideNode::calculate()const
//{
//	if (!m_leftNode && !m_rightNode)
//	{
//		return 0.0;
//	}
//	if (!m_leftNode)
//	{
//		return 0;
//	}
//	if (!m_rightNode)
//	{
//		std::cout << "devide by zero" << std::endl;
//		return HUGE_VAL;
//	}
//	return m_leftNode->calculate() / m_rightNode->calculate();
//}
