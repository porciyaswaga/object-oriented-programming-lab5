#pragma once
#include <string>

struct TestStruct {
    int id;
    std::string name;
    double value;

    TestStruct(int i, std::string n, double v)
        : id(i), name(std::move(n)), value(v) {}
};
