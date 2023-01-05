#pragma once

const int NANME_LENGTH = 16;

struct Monster_SLList
{
	char name[NANME_LENGTH];
	int hp;
	Monster_SLList* pNext{};
};

struct Monster_DLList
{
	char name[NANME_LENGTH];
	int hp;
	Monster_DLList* pPrev{};
	Monster_DLList* pNext{};
};