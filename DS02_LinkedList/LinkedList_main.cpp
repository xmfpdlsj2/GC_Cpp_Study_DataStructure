#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

void TestSingleLinkedList();
void TestDoubleLinkedList();

int main()
{
    //TestSingleLinkedList();
    TestDoubleLinkedList();
}

void TestSingleLinkedList()
{
    SLinkedList myList;

    CreatMonster(myList, "Demon", 100);
    CreatMonster(myList, "Wolf", 50);
    CreatMonster(myList, "Slime", 10);

    //GetMonsterCount(myList);
    //PrintMosterList(myList);
    //PrintMosterListRecursive(myList.head);

    //std::cout << FindMoster(myList, "Slime") << std::endl;
    DeleteMoster(myList, "Wolf");
    PrintMosterListRecursive(myList.head);

    DeleteMosterList(myList);
    PrintMosterListRecursive(myList.head);
}

void TestDoubleLinkedList()
{
    DLinkedList myList;

    CreatMonsterD(myList, "Demon", 100);
    CreatMonsterD(myList, "Wolf", 50);
    CreatMonsterD(myList, "Gient", 750);
    CreatMonsterD(myList, "Troll", 500);
    CreatMonsterD(myList, "Slime", 10);

    GetMonsterCountD(myList);
    PrintMosterListD(myList);
    //PrintMosterListRecursiveD(myList.head);
    //std::cout << FindMosterD(myList, "Slime") << std::endl;

    DeleteMosterD(myList, "Gient");
    PrintMosterListD(myList);

    DeleteMosterD(myList, "Demon");
    PrintMosterListD(myList);

    DeleteMosterD(myList, "Slime");
    PrintMosterListD(myList);

    DeleteMosterD(myList, "Wolf");
    PrintMosterListD(myList);

    DeleteMosterD(myList, "Troll");
    PrintMosterListD(myList);

    CreatMonsterD(myList, "Slime", 10);
    DeleteMosterD(myList, "Troll");
    PrintMosterListD(myList);


    DeleteMosterListD(myList);
    PrintMosterListD(myList);
}
