#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        clear();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }

    void insertFront(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertBack(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    bool removeAt(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Índice fuera de rango.\n";
            return false;
        }

        Node<T>* current = head;
        if (index == 0) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete current;
        }
        else {
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }
            delete current;
        }
        size--;
        return true;
    }

    Node<T>* getHead() const {
        return head;
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

#endif