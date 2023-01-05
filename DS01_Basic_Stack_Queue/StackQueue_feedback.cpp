// 자료구조 스택, 큐. 쌤 피드벡

#include <iostream>

#pragma region STACK functions decaler
const int STACK_SIZE = 10;

enum Command
{
    PUSH = 1,
    POP,
    EXIT
};

struct Stack
{
    int container[STACK_SIZE]{};
    int top = -1;
};

void PrintInfo();
void ProcessUserInput(Stack& stack);
void Push(Stack& stack, int value);
void Pop(Stack& stack);
void PrintStack(Stack& stack);
#pragma endregion

#pragma region QUEUE functions decaler
const int QUEUE_SIZE = 10;

enum CommandQueue
{
    ENQUEUE = 1,
    DEQUEUE
};

struct Queue
{
    int container[QUEUE_SIZE]{};
    int head = 0;
    int tail = 0;
};

void PrintInfoQueue();
void ProcessUserInputQueue(Queue& queue);
void PrintQueue(Queue& queue);
void Enqueue(Queue& queue, int value);
void Dequeue(Queue& queue);
#pragma endregion

void StackQueueFeedback()
{
    //// Stack
    //Stack myStack;

    //while (true)
    //{
    //    PrintInfo();
    //    ProcessUserInput(myStack);
    //    PrintStack(myStack);
    //}

    // Queue
    Queue myQueue;

    while (true)
    {
        PrintInfo();
        ProcessUserInputQueue(myQueue);
        PrintQueue(myQueue);
    }
}

#pragma region STACK functions
void PrintInfo()
{
    std::cout << " 1: push. 2: pop\n > " << std::endl;
    std::cout << "---------------------" << std::endl;
}
void ProcessUserInput(Stack& stack)
{
    int command;
    std::cin >> command;
    switch (command)
    {
        case PUSH:
        {
            int value{};
            std::cout << " push value ? ";
            std::cin >> value;
            Push(stack, value);
            break;
        }
        case POP:
            Pop(stack);
            break;
        default:
            std::cout << "Invalid Command!" << std::endl;
            break;
    }

}
void Push(Stack& stack, int value)
{
    if (stack.top >= STACK_SIZE - 1)
    {
        std::cout << "STACK is full!" << std::endl;
        return;
    }
    stack.container[++stack.top] = value;
}
void Pop(Stack& stack)
{
    if (stack.top < 0)
    {
        std::cout << "STACK is empty!" << std::endl;
        return;
    }
    std::cout << stack.container[stack.top--] << " pop!" << std::endl;
}
void PrintStack(Stack& stack)
{
    std::cout << "---- stack ----" << std::endl;

    if (stack.top < 0)
    {
        std::cout << "STACK is empty!" << std::endl;
        return;
    }

    for (int i = stack.top; i >= 0; --i)
    {
        std::cout << stack.container[i] << std::endl;
    }
    std::cout << "---- stack ----" << std::endl;
}
#pragma endregion

#pragma region QUEUE functions
void PrintInfoQueue()
{
    std::cout << "1. enqueue. 2. dequeue" << std::endl;
    std::cout << "----------------------" << std::endl;
}
void ProcessUserInputQueue(Queue& queue)
{
    int command;
    std::cin >> command;

    switch (command)
    {
        case ENQUEUE:
        {
            int value{};
            std::cout << "    value ? ";
            std::cin >> value;
            Enqueue(queue, value);
            break;
        }

        case DEQUEUE:
            Dequeue(queue);
            break;

        default:
            std::cout << "Invalid command!" << std::endl;
            break;
    }
}
void PrintQueue(Queue& queue)
{
    std::cout << "---- queue ----" << std::endl;

    int i = queue.head;

    if (queue.head == queue.tail)
    {
        std::cout << "Emtpty" << std::endl;
        return;
    }

    while (i != queue.tail)
    {
        i++;
        i = i % QUEUE_SIZE;
        std::cout << queue.container[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "----" << std::endl;
}
void Enqueue(Queue& queue, int value)
{
    if ((queue.tail + 1) % QUEUE_SIZE == queue.head)
    {
        std::cout << "Queue is full!" << std::endl;
        return;
    }
    queue.tail = (queue.tail + 1) % QUEUE_SIZE;
    queue.container[queue.tail] = value;
}
void Dequeue(Queue& queue)
{
    if (queue.head == queue.tail)
    {
        return;
    }
    queue.head = (queue.head + 1) % QUEUE_SIZE;
    std::cout << queue.container[queue.head] << "is dequeue!" << std::endl;
}
#pragma endregion