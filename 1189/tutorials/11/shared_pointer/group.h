#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <memory>
#include <vector>

class Member;

struct Group {
    std::string name;
    // using a shared pointer; member will freed when a member
    // does not exist in any of the groups (and there is no
    // shared_ptrs to member outside this class).
    std::vector<std::shared_ptr<Member>> members;

    explicit Group(std::string name);
    ~Group();
};
#endif
