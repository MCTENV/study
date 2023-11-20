#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class pre_Abstractclass_suf
{
public:
    pre_Abstractclass_suf(const pre_Abstractclass_suf &)            = default;
    pre_Abstractclass_suf(pre_Abstractclass_suf &&)                 = delete;
    pre_Abstractclass_suf &operator=(const pre_Abstractclass_suf &) = default;
    pre_Abstractclass_suf &operator=(pre_Abstractclass_suf &&)      = delete;
    virtual ~pre_Abstractclass_suf()                                = default;
    virtual void print(const string &str)                           = 0;
    virtual void get(vector<int> &via, vector<int> &vib)            = 0;
};

class Test
{
private:
    int a;

public:
    int &get_a() { return a; }
};

int main()
{
    using testclass = pre_Abstractclass_suf;
    unordered_map<int, string> map;
    map[0] = "mary";
    map[1] = "had";
    map[2] = "a";
    map[3] = "little";
    map[4] = "lamb";
    shared_ptr<testclass> ptr;

    auto via = vector<int>{1, 2, 3};
    auto vib = vector<int>{4, 5, 6};
    ptr->get(via, vib);
    ptr->print(map[3]);

    int n;
    cin >> n;
    auto res = map[n];

    auto vec = vector<int>{1, 2, 3, 4};

    return 0;
}
