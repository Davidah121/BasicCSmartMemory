#pragma once
#include <stdio.h>
#include <stdlib.h>


struct MemNode
{
    struct MemNode* next;
    void* pointer;
};

struct MemNode root;
struct MemNode* end;

void* SmartMalloc(size_t size)
{
    void* p = malloc(size);
    struct MemNode* newNode = (struct MemNode*)malloc(sizeof(struct MemNode));
    newNode->next = NULL;
    newNode->pointer = p;
    if(end != NULL)
    {
        end->next = newNode;
        end = newNode;
    }
    else
    {
        root.next = newNode;
        end = newNode;
    }

    return p;
}

void SmartFree(void* p)
{
    struct MemNode* currNode = &root;
    struct MemNode* previousNode = NULL;
    while(currNode != NULL)
    {
        if(currNode->pointer == p)
        {
            //remove node and pointer
            free(p);
            previousNode->next = currNode->next;
            free(currNode);
            break;
        }
        previousNode = currNode;
        currNode = currNode->next;
    }
}

int SmartMemoryIsValid(void* p)
{
    struct MemNode* currNode = &root;
    while(currNode != NULL)
    {
        if(currNode->pointer == p)
        {
            return 1;
        }
        currNode = currNode->next;
    }
    return 0;
}