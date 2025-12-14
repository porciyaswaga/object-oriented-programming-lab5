#include <iostream>
#include "memory/MapMemoryResource.h"
#include "container/ForwardList.h"
#include "types/TestStruct.h"

int main() {
    MapMemoryResource memory;

    std::cout << "Пример с интами\n";
    ForwardList<int> intList(&memory);
    intList.push_front(1);
    intList.push_front(2);
    intList.push_front(3);

    for (int x : intList) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "Пример со структурой\n";
    ForwardList<TestStruct> structList(&memory);
    structList.push_front({1, "Alice", 3.14});
    structList.push_front({2, "Bob", 2.71});

    for (const auto& s : structList) {
        std::cout << s.id << " " << s.name << " " << s.value << "\n";
    }

    return 0;
}
