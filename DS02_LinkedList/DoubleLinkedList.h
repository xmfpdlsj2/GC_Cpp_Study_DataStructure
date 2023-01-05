#pragma once
#include "MonsterList.h"

struct DLinkedList
{
	Monster_DLList* head{};
	Monster_DLList* tail{};
};

#pragma region MyCode version
// ���� �߰�
Monster_DLList* CreatMonsterD(DLinkedList& list, const char* name, const int hp)
{
	Monster_DLList* pElement = new Monster_DLList;
	strcpy_s(pElement->name, NANME_LENGTH, name);
	pElement->hp = hp;

	if (list.tail == nullptr || list.head == nullptr)
	{
		list.head = list.tail = pElement;
	}
	else
	{
		pElement->pPrev = list.tail;
		list.tail->pNext = pElement;
		list.tail = pElement;

	}

	return pElement;
}
// ����
int GetMonsterCountD(const DLinkedList& list)
{
	int count{};
	Monster_DLList* p = list.head;

	while (p != nullptr)
	{
		count++;
		p = p->pNext;
	}

	return count;
}
// ���
void PrintMosterListD(const DLinkedList& list)
{
	Monster_DLList* p = list.head;
	std::cout << "\n-----" << std::endl;
	while (p != nullptr)
	{
		std::cout << p->name << " : " << p->hp << std::endl;
		p = p->pNext;
	}
	std::cout << "-----" << std::endl;
}
//��� ��� ����
void PrintMosterListRecursiveD(const Monster_DLList* pMonster)
{

}
// �˻�
bool FindMosterD(const DLinkedList& list, const char* name)
{
	Monster_DLList* p = list.head;

	while (p != nullptr)
	{
		if (strcmp(p->name, name) == 0)
		{
			return true;
		}
		p = p->pNext;
	}
}
// ��ü ����
void DeleteMosterListD(DLinkedList& list)
{
	Monster_DLList* p = list.head;
	Monster_DLList* temp;
	while (p != nullptr)
	{
		temp = p->pNext;
		delete p;
		p = temp;
	}

	list.head = list.tail = nullptr;
}

// Ư�� ���� ���� 
bool DeleteMosterD(DLinkedList& list, const char* name)
{
	Monster_DLList* p = list.head;

	while (p != nullptr)
	{
		if (strcmp(p->name, name) == 0)
		{
			break;
		}

		p = p->pNext;
	}

	if (p == nullptr)
	{
		return false;
	}

	if (list.head == list.tail)		// ���Ұ� �ϳ��� ������
	{
		list.head = list.tail = nullptr;
	}
	else if (p->pPrev == nullptr)	// ù��° ���Ҹ� ���ﶧ
	{
		list.head = p->pNext;
		(p->pNext)->pPrev = nullptr;
	}
	else if (p == list.tail)		// ������ ���Ҹ� ���ﶧ
	{
		(p->pPrev)->pNext = nullptr;
		list.tail = p->pPrev;
	}
	else							// �߰� ���Ҹ� ���ﶧ
	{
		(p->pPrev)->pNext = p->pNext;
		(p->pNext)->pPrev = p->pPrev;
	}

	delete p;
	return true;
}
#pragma endregion

#pragma region Feedback version
// Ư�� ���� ���� 
bool DeleteMosterD_FB(DLinkedList& list, const char* name)
{
	Monster_DLList* p = list.head;

	while (p != nullptr)
	{
		if (strcmp(p->name, name) == 0)
		{
			break;
		}

		p = p->pNext;
	}

	if (p == nullptr)
	{
		return false;
	}

	if (p == list.head)
	{
		list.head = p->pNext;
	}
	else
	{
		p->pPrev->pNext = p->pNext;
	}

	if (p == list.tail)
	{
		list.tail = p->pPrev;
	}
	else
	{
		p->pNext->pPrev = p->pPrev;
	}

	delete p;
	return true;
}
#pragma endregion