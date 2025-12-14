#pragma once
#include <memory_resource>
#include <iterator>

template<typename T>
class ForwardList {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& v) : value(v), next(nullptr) {}
    };

    Node* head = nullptr;
    std::pmr::polymorphic_allocator<Node> allocator;

public:
    explicit ForwardList(std::pmr::memory_resource* mr)
        : allocator(mr) {}

    ~ForwardList() {
        clear();
    }

    void push_front(const T& value) {
        Node* node = allocator.allocate(1);
        allocator.construct(node, value);
        node->next = head;
        head = node;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        allocator.destroy(temp);
        allocator.deallocate(temp, 1);
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    class Iterator {
    private:
        Node* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;

        explicit Iterator(Node* node) : current(node) {}

        reference operator*() const { return current->value; }
        pointer operator->() const { return &current->value; }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};
