#include <algorithm>
#include <list>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//1a)
/**
int f(int i, int &j) {
    i = i +j;
    j = 2*i;
    return i + j;
}

int x = 3, y = 5
cout << f(x,y) << '\n';
cout << "x = " << x << ", y = " << y << '\n';

What is printed by the snippet above is
24
3, 16

Reason it's 3 for x is because that is
its value however the & behind y makes it that
it's using its reference
*/



//b)
void print_list(list<double> &l) {
    for (auto &x :l) {
        cout << x << '\n';
    }
}

//c)
bool long_word(const string &s) {
    return s.size() >= 6;
}

int long_count(const list<string> &l) {
    return count_if(l.cbegin(), l.cend(), long_word);
}

//d)i
bool string_occur(const list<string> &l, const string &s) {
    return find(l.cbegin(), l.cend(), s) != l.cend();
    //If the iterator returned by find equals l.cend(), it means the value was not found in the list. If the iterator is not equal to l.cend(), it means the value was found.
}

//d)ii
void change_list(list<string> &l, const string &s, const string &r) {
    auto p = find(l.begin(), l.end(), s);
    if (p!= l.end()) {
        *p = r;
    }
}

//d)iii
void change_all_list(list<string> &l, const string &s, const string &r) {
    auto p = find(l.begin(), l.end(), s);
    while (p!=l.end()) {
        *p = r;
        ++p;
        p = find(p, l.end(), s);
    }
}

//2a)
class character {
    const string _name;
    const int _init_health;
    int _curr_health;

    //i
public:
    character(const string& n, int h):
    _name(n), _init_health(h), _curr_health(h){}

    //ii
    const string &name() const{
        return _name;
    }
    int health() const {
        return _curr_health;
    }

    //iii
    void reduce_one() {
        if (_curr_health >0) {
            _curr_health--;
        }
    }

    //iv
    void increase_health() {
        if (_curr_health >0 && _curr_health < _init_health) {
            _curr_health++;
        }
    }
};

//b)
class world {
    //i
    vector<character> characters;
public:
    //ii
    void increase_all_health() {
        for (auto &c : characters) {
            c.increase_health();
        }
    }

    //iii
    void decrease_named_char(const string &n) {
        for (auto &c: characters) {
            if (c.name() == n) {
                c.reduce_one();
            }
        }
    }

    //c)
    bool positive(const character &c) {
        return c.health() >0;
    }

    int number_of_positive() {
        return count_if(characters.begin(), characters.end(), positive);
    }
};

//3
class scorer {
public:
    //Combined score of a non-empty vector.
    virtual double score(const vector<double> &v) const = 0;
};

//a) Describe the effects of the two uses of const in this class

//First const is saying that usage of score() will not modify the vector passed as a parameter
//Second const is saying that score() will not modify any member variables of the scorer class. So it's literally not altering the object's variables, that's what it's saying.

//b)

class average : public scorer {
public:
    double score(const vector<double> &v) const {
        double total = 0;
        for (double x: v) {
            total += x;
        }
        return total/v.size();
    }
};

//c)
class highest : public scorer {
public:
    double score(const vector<double> &v) const{
        double max = v.front();
        for (double x: v) {
            if (x > max){
                max = x;
            }
        }
        return max;
    }
};

//d
void summary(const scorer &s, const map<string, vector<double>> &m) {
    for (const auto &p :m) {
        cout << p.first << ": " << s.score(p.second) << '\n';
    }
}
