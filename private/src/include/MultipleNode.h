#ifndef _MULTIPLENODE_H_
#define _MULTIPLENODE_H_

#include "Node.h"
#include <vector>

class MultipleNode:public Node
{
public:
	explicit MultipleNode(Node* pNode);
	~MultipleNode();
	void appendChildNode(Node* pNode, bool positive = true);

protected:
	std::vector<Node*> m_vecChildNode;
	std::vector<bool> m_vecPositive;
};

class SumNode :public MultipleNode {
public:
	explicit SumNode(Node* pNode);
	~SumNode() noexcept = default;
	double calculate()const final;
};

class ProductNode :public MultipleNode {
public:
	explicit ProductNode(Node* pNode);
	~ProductNode() noexcept = default;
	double calculate()const final;
};
#endif // !_MULTIPLENODE_H_
