#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;


//1a)
double sum_list(list<double> &l) {
    double total = 0;
    for (auto &x : l) {
        total +=x;
    }
    return total;
}

//b)
double replace_zero(list<double> &l) {
    for (auto &x :l) {
        if (x==0) {
            x =1;
        }
    }
}

//c)i
int count_int(const list<int> &l, int n) {
    return count(l.cbegin(), l.cend(), n);
}

//c)ii
bool is_positive(int n) {
    return n < 0;
}
int contain_zeroes(const list<int> &l) {
    auto start = find_if(l.cbegin(), l.cend(), is_positive);
    if (start == l.cend()) {
        return 0;
    }
    const auto finish = find_if(++start, l.cend(), is_positive);
    return count(start,finish,0);
}


//2a)
class song {
    const string _title;
    const string _singer;
    const int _length;
public:
    //a)i
    song(const string &t, const string &s, int l):
    _title(t), _singer(s), _length(l) {};

    //a)ii
    const string &title() const {
        return _title;
    }

    const string &singer() const {
        return _singer;
    }

    int length() const {
        return _length;
    } //Don't need to say const int length() cuz its a primitive data type

};

//b)
class playlist {
    vector<song> songs;
public:
    //b)i
    void add_song(const song &b) {
        songs.push_back(b);
    }

    //b)ii
    int num_songs() const {
        return songs.size();
    }

    //b)iii
    int total_length() const {
        int total = 0;
        for (const song &s :songs) {
            total += s.length();
        }
        return total;
    }

    //b)iv
    int count_singer(const string &singer) const {
        return count_if(songs.cbegin(), songs.cend(), [&singer](const song &s) {
            return s.singer() == singer;
        });
    }

};

//3


class event {
    const string desc;
public:
    event(const string &d) : desc(d) {}
    const string & description() const { return desc; }
    // returns true if the event falls on the given date
    virtual bool on_day(int day, int month,
    int year) const = 0;
};

/**
a) Why can’t we declare a variable of type event?

The usage of on_day which is a pure virtual method indicates that event is an abstract class.
**/

//b)
class daily_event : public event{
public:
    daily_event(const string &d): event(d){}

    bool on_day(int day, int month, int year) const {
        return true;
    }
};

//c)
class annual_event : public event {
    int _day, _month;
public:
    annual_event(const string&d): event(d){}

    bool on_day(int day, int month, int year) const {
        return day == _day && month == _month;
    };
};


//d)
vector<shared_ptr<event>> v;
/**for (const auto &x :v) {
    if (x->on_day(d,m,y)) {
        cout << x->desc() << '\n';
    }
}*/

