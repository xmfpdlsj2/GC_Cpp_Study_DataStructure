#pragma once
#include "MonsterList.h"

struct SLinkedList
{
    Monster_SLList* head{};
    Monster_SLList* tail{};
};

// 원소 추가
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
// 개수
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
// 출력
void PrintMosterList(const SLinkedList& list)
{
    Monster_SLList* p = list.head;

    while (p != nullptr)
    {
        std::cout << p->name << " : " << p->hp << std::endl;
        p = p->pNext;
    }
}
//출력 재귀 버전
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
// 검색
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
// 전체 삭제
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

// 특정 원소 삭제 
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

    if (list.head == list.tail) // 원소가 하나만 있을때
    {
        list.head = list.tail = nullptr;
        //delete p;
    }
    else if (pPrev == nullptr)  // 첫번째 원소를 지울때
    {
        list.head = p->pNext;
        //delete p;
    }
    else if (p == list.tail)    // 마지막 원소를 지울때
    {
        pPrev->pNext = nullptr;
        list.tail = pPrev;
        //delete p;
    }
    else    // 중간 원소를 지월 때
    {
        pPrev->pNext = p->pNext;
        //delete p;
    }
    delete p;

    return true;
}