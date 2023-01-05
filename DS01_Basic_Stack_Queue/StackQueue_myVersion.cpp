// �ڷᱸ�� ����, ť ������

#include <iostream>

enum DS_TYPE
{
	STACK,
	QUERE
};

enum PUSHPOP
{
	PUSH = 1,
	POP,
	END
};

const int MAX_NUM{ 3 };

struct DataStructure
{
	int currentIndex{ 0 };
	int array[MAX_NUM]{};
};


int InputState(bool);
void PrintState(int[], int, DS_TYPE);

void CallStack(DataStructure&, int);
void CallQueue(DataStructure&, int);


void StackQueueMyVersion()
{
	// Stack & Queue �����
	// 1.������ ����� ���ô�.
	// 1: push, 2:pop
	// > 1
	// push value? 100
	// ----
	// 100
	// ----
	// 1:push, 2:pop
	// >1
	// push value? 25
	// ----
	// 25
	// 100
	// ----
	// 1:push, 2:pop
	// >2
	// 25 pop! 
	// ----
	// 100
	// ----

	//DataStructure stack;
	//CallStack(stack, MAX_NUM - 1);

	// 2. ť�� ����� ���ô�.
	// 1:push, 2:pop
	// >1
	// push value? 100
	// ----
	// 100
	// ----
	// 1:push, 2:pop
	// >1
	// push value? 25
	// ----
	// 100 25
	// ----
	// 1:push, 2pop
	// >2
	// 100 pop!
	// ----
	// 25
	// ----

	DataStructure queue;
	CallQueue(queue, MAX_NUM - 1);
}

// ���� ó�� ���� ���
int InputState(bool isFirst)
{
	int input{};
	if (isFirst)
	{
		std::cout << " 1: push. 2: pop\n > ";
		std::cin >> input;

		if (input != PUSH && input != POP)
		{
			input = END;
		}
	}
	else
	{
		std::cout << "push value?: ";
		std::cin >> input;
	}

	return input;
}

void PrintState(int array[], int count, DS_TYPE type)
{
	int i{};
	std::cout << "\n----------" << std::endl;
	switch (type)
	{
		case STACK:
			i = count;
			while (--i >= 0)
			{
				std::cout << array[i] << std::endl;
			}
			break;

		case QUERE:
			i = 0;
			while (i < count)
			{
				std::cout << array[i] << ' ';
				i++;
			}
			std::cout << std::endl;
			break;

		default:
			break;
	}
	std::cout << "----------\n" << std::endl;

}

void CallStack(DataStructure& stack, int maxCount)
{
	std::cout << "STACK" << std::endl;
	while (true)
	{
		int input{ InputState(true) };

		if (input == PUSH)
		{
			if (stack.currentIndex > maxCount)
			{
				std::cout << "������ ���� á���ϴ�. �� �̻� 'Ǫ��'�� �� �����ϴ�." << std::endl;
				continue;
			}
			if (stack.currentIndex < 0)
			{
				stack.currentIndex = 0;
			}

			int value{ InputState(false) };
			stack.array[stack.currentIndex] = value;
			stack.currentIndex++;

			PrintState(stack.array, stack.currentIndex, STACK);
		}
		else if (input == POP)
		{
			stack.currentIndex--;

			if (stack.currentIndex < 0)
			{
				std::cout << "������ �� ������ϴ�. �� �̻� '��'�� �� �����ϴ�." << std::endl;
				continue;
			}

			int pop{ stack.array[stack.currentIndex] };
			stack.array[stack.currentIndex] = 0;

			std::cout << pop << " pop!" << std::endl;
			PrintState(stack.array, stack.currentIndex, STACK);

		}
		else
		{
			std::cout << "�Լ� ����." << std::endl;
			break;
		}
	}
}

void CallQueue(DataStructure& queue, int maxCount)
{
	std::cout << "QUEUE" << std::endl;
	while (true)
	{
		int input{ InputState(true) };

		if (input == PUSH)
		{
			if (queue.currentIndex > maxCount)
			{
				std::cout << "ť�� ���� á���ϴ�. �� �̻� 'Ǫ��'�� �� �����ϴ�." << std::endl;
				continue;
			}
			if (queue.currentIndex < 0)
			{
				queue.currentIndex = 0;
			}

			int value{ InputState(false) };
			queue.array[queue.currentIndex] = value;
			queue.currentIndex++;

			PrintState(queue.array, queue.currentIndex, QUERE);
		}
		else if (input == POP)
		{
			queue.currentIndex--;

			if (queue.currentIndex < 0)
			{
				std::cout << "ť�� �� ������ϴ�. �� �̻� '��'�� �� �����ϴ�." << std::endl;
				continue;
			}

			int pop{ queue.array[0] };
			for (int i = 0; i < queue.currentIndex; i++)
			{
				queue.array[i] = queue.array[i + 1];
			}
			queue.array[queue.currentIndex] = 0;

			std::cout << pop << " pop!" << std::endl;
			PrintState(queue.array, queue.currentIndex, QUERE);

		}
		else
		{
			std::cout << "�Լ� ����." << std::endl;
			break;
		}
	}
}



