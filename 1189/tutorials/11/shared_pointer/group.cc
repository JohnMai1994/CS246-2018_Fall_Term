#include "group.h"
#include <iostream>
#include <memory>
#include <vector>
#include "member.h"
using namespace std;

Group::Group(string name) : name{name} {}

Group::~Group() { cout << "Group " << name << " destroyed" << endl; }
