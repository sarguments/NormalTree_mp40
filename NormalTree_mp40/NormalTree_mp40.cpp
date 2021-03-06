// NormalTree_mp40.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include  <iostream>

struct TREE_NODE
{
	struct TREE_NODE *pChild = nullptr;
	struct TREE_NODE *pSibling = nullptr;
	int iData;
};

TREE_NODE *CreateNode(int iData);  // 트리 노드를 동적 생성하고 초기화 된 노드를 리턴 합니다.
//void DeleteNode(TREE_NODE* pRoot, TREE_NODE *pNode); // 인자로 입력 받은 노드를 delete 합니다.

void AddChildNode(TREE_NODE *pParent, TREE_NODE *pChild);  // 부모 노드를 인자로 받아 해당 노드의 자식으로 붙입니다.
void PrintTree(TREE_NODE *pNode, int iDepth);

void ReleaseTree(TREE_NODE *pRoot);			   // 전체 노드를 삭제 (delete)

int main()
{
	TREE_NODE *pAddNode_R, *pAddNode_N;
	TREE_NODE *pRoot = CreateNode(0);

	pAddNode_R = CreateNode(1);
	AddChildNode(pRoot, pAddNode_R);

	pAddNode_N = CreateNode(11);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(12);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(13);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(14);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(15);
	AddChildNode(pAddNode_R, pAddNode_N);

	pAddNode_R = CreateNode(2);
	AddChildNode(pRoot, pAddNode_R);

	pAddNode_N = CreateNode(21);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(22);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(23);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(24);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(25);
	AddChildNode(pAddNode_R, pAddNode_N);

	pAddNode_R = CreateNode(3);
	AddChildNode(pRoot, pAddNode_R);

	pAddNode_N = CreateNode(31);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(32);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(33);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(34);
	AddChildNode(pAddNode_R, pAddNode_N);
	pAddNode_N = CreateNode(35);
	AddChildNode(pAddNode_R, pAddNode_N);

	PrintTree(pRoot, 0);
	ReleaseTree(pRoot);

	return 0;
}

TREE_NODE * CreateNode(int iData)
{
	TREE_NODE* newNode = new TREE_NODE;
	newNode->iData = iData;
	newNode->pChild = nullptr;
	newNode->pSibling = nullptr;

	return newNode;
}

void AddChildNode(TREE_NODE * pParent, TREE_NODE * pChild)
{
	pChild->pSibling = pParent->pChild;
	//pChild->pChild = pParent->pChild->pChild;
	pParent->pChild = pChild;
}

void PrintTree(TREE_NODE * pNode, int iDepth)
{
	int localDepth = iDepth;

	if (pNode == nullptr)
	{
		return;
	}

	for (int i = 0; i < iDepth; i++)
	{
		std::wcout << L" ";
	}

	std::wcout << pNode->iData << std::endl;

	localDepth++;

	PrintTree(pNode->pChild, localDepth);
	PrintTree(pNode->pSibling, iDepth);
}

void ReleaseTree(TREE_NODE * pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	ReleaseTree(pRoot->pChild);
	ReleaseTree(pRoot->pSibling);

	delete pRoot;
}