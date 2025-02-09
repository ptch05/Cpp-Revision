#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <memory>

using namespace std;

//1a)
void double_list(list<double> &l) {
    for (auto &x: l) {
        x+=2;
    }
}

//b)i
int count_zeroes(const list<double> &l) {
    return count(l.cbegin(), l.cend(), 0);
}

//b)ii
int count_before_one(const list<double> &l) {
    auto x = find(l.cbegin(), l.cend(), 1);
    return count(l.cbegin(), x, 0);
}

//b)iii
void change_first_one(list<double> &l) {
    auto x = find(l.begin(), l.end(), 1);
    if (x != l.end()) {
        *x = 0;  //You HAVE to use a pointer because with find, you're only getting the ITERATOR of the variable, not actually using the variable ITSELF.
    }
}

//c)i
class loggable {
public:
    virtual ~loggable(){} //This is the destructor you have to include for the base class
    virtual void log(const string &s, int n) =0;
};

//ii
vector<shared_ptr<loggable>> loggers;


//2a)
class item{
    const string _desc;
    const int _value;
public:
    item(const string &d, int v):
    _desc(d), _value(v){}

    const string &desc() const{ //I KEEP FORGETTING TO ADD CONST AFTER THE MEMBER FUNCTION BRACKETS THINGIES, STOP FORGETTING, YOU WILL NEED TO USE 2 CONSTS A LOT OF THE TIME, STOP FORGETTING THAT. IF IM NOT ALTERING THE OBJECT STATE AT ALL, THEN I USE THAT 2ND CONST
        return _desc;
    }

    int value() const {
        return _value;
    }
};

//b)
bool compare(const item &x, const item &y) {
    return x.value() > y.value();
}

void sort_items(vector<item> &v) {
    sort(v.begin(), v.end(), compare);
}

//c)
class sack :public item{
    vector<item> items;
public:
    //i)
    void add_item(const item &new_item) {
        items.push_back(new_item);
    }

    //ii)
    int total_value() const{
        int total = 0;
        for (const item &x : items) {
            total += x.value();
        }
        return total;
    }

    //iii)
    bool contain(const string &s) {
        for (const item &x : items) {
            if (x.desc() ==s) {
                return true;
            }
            return false;
        }
    }

    //d)

    int greater(int n) const {
        return count_if(items.begin(), items.end(), [n](const item &i) {
            return i.value() >n;
        });
    }
};

