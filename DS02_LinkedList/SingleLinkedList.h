#pragma once
#include "MonsterList.h"

struct SLinkedList
{
    Monster_SLList* head{};
    Monster_SLList* tail{};
};

// ���� �߰�
Monster_SLList* CreatMonster(SLinkedList& list, const char* name, const int hp)
{
    Monster_SLList* pElement = new Monster_SLList;
    strcpy_s(pElement->name, NANME_LENGTH, name);
    pElement->hp = hp;

    if (list.tail == nullptr || list.head == nullptr)
    {
        list.head = list.tail = pElement;
    }
    else
    {
        list.tail->pNext = pElement;
        list.tail = pElement;
    }

    return pElement;
}
// ����
int GetMonsterCount(const SLinkedList& list)
{
    int count{};
    Monster_SLList* p = list.head;

    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }

    return count;
}
// ���
void PrintMosterList(const SLinkedList& list)
{
    Monster_SLList* p = list.head;

    while (p != nullptr)
    {
        std::cout << p->name << " : " << p->hp << std::endl;
        p = p->pNext;
    }
}
//��� ��� ����
void PrintMosterListRecursive(const Monster_SLList* pMonster)
{
    // base case
    if (pMonster == nullptr)
    {
        return;
    }

    std::cout << pMonster->name << " : " << pMonster->hp << std::endl;

    // recursive case
    PrintMosterListRecursive(pMonster->pNext);
}
// �˻�
bool FindMoster(const SLinkedList& list, const char* name)
{
    Monster_SLList* p = list.head;

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
void DeleteMosterList(SLinkedList& list)
{
    Monster_SLList* p = list.head;
    Monster_SLList* temp;
    while (p != nullptr)
    {
        temp = p->pNext;
        delete p;
        p = temp;
    }

    list.head = list.tail = nullptr;
}

// Ư�� ���� ���� 
bool DeleteMoster(SLinkedList& list, const char* name)
{
    Monster_SLList* p = list.head;
    Monster_SLList* pPrev{};

    while (p != nullptr)
    {
        if (strcmp(p->name, name) == 0)
        {
            break;
        }
        pPrev = p;
        p = p->pNext;
    }

    if (p == nullptr)
    {
        return false;
    }

    if (list.head == list.tail) // ���Ұ� �ϳ��� ������
    {
        list.head = list.tail = nullptr;
        //delete p;
    }
    else if (pPrev == nullptr)  // ù��° ���Ҹ� ���ﶧ
    {
        list.head = p->pNext;
        //delete p;
    }
    else if (p == list.tail)    // ������ ���Ҹ� ���ﶧ
    {
        pPrev->pNext = nullptr;
        list.tail = pPrev;
        //delete p;
    }
    else    // �߰� ���Ҹ� ���� ��
    {
        pPrev->pNext = p->pNext;
        //delete p;
    }
    delete p;

    return true;
}