#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <Windows.h>

using Tinfo = std::string;

struct NODE {
    Tinfo info;
    NODE* next;
    NODE(Tinfo info, NODE* ptr = nullptr) : info(info), next(ptr) {};
    ~NODE() { next = nullptr; }
};
using ptrNODE = NODE*;

struct StackL {
private:
    ptrNODE head;
    size_t count;
public:
    StackL() {
        count = 0;
        head = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    size_t size() {
        return count;
    }

    void push(Tinfo elem) {
        head = new NODE(elem, head);
        count++;
    }

    Tinfo top() { return head->info; }

    void pop() {
        if (!empty()) {
            ptrNODE tmp = head;
            head = head->next;
            delete tmp;
            count--;
        }
    };

    void view() {
        ptrNODE ptr{ head };
        while (ptr) {
            std::cout << ptr->info << ' ';
            ptr = ptr->next;
        }
        std::cout << '\n';
    };

    void clear() {
        while (!empty())
            pop();
    };

    ~StackL() {
        clear(); // Освобождаем память в деструкторе
    }
};

