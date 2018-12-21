#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

struct Member {
    std::string name;

    Member(std::string name) : name{name} {std::cout << "Member " << name << " created" << std::endl;}
    ~Member() { std::cout << "Member " << name << " deleted" << std::endl; }
};

#endif
