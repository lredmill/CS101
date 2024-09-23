#include <iostream>

using namespace std;

class Person {
private:
    string first, last;
    int cwid;
public:
    enum class CompareType {
        LessCwid,
        LessLastFirstCwid
    };

    Person(string first, string last, int cwid) {
        this->first = first;
        this->last = last;
        this->cwid = cwid;
    }

    string getFirst() {
        return first;
    }

    string getLast() {
        return last;
    }

    int getCwid() {
        return cwid;
    }

    void print() {
        cout << first << "\t" << last << "\t" << cwid;
    }

    bool compare(Person &rhs, Person::CompareType t) {
        switch (t) {
            case Person::CompareType::LessCwid:
                return this->getCwid() < rhs.getCwid();
            case Person::CompareType::LessLastFirstCwid:
                if (this->getLast() < rhs.getLast()) return true;
                if (this->getLast() > rhs.getLast()) return false;
                if (this->getFirst() < rhs.getFirst()) return true;
                if (this->getFirst() > rhs.getFirst()) return false;
                return this->getCwid() < rhs.getCwid();
            default:
                return false;
        }
    }
};

void print(string s, Person people[], int len) {
    cout << s << endl;
    cout << "\tFirst\tLast\tCWID" << endl;
    for (int i = 0; i < len; i++) {
        cout << "\t";
        people[i].print();
        cout << endl;
    }
    cout << endl;
}

void bubbleSortInPlace(Person people[], int len, Person::CompareType t) {
    for(int j = 1; j < len; j++) {
        bool madeChange = false;
        for (int i = 0; i < len - j; i++) {
            if (people[i + 1].compare(people[i], t)) {
                swap(people[i], people[i + 1]);
                madeChange = true;
            }
        }
        if (!madeChange) break;
    }
}

int main() {
    Person people[15] = {
        Person("John", "Smith", 99999999),
        Person("Jane", "Roe", 77777777),
        Person("Richard", "Miles", 55555555),
        Person("John", "Doe", 33333333),
        Person("Joe", "Public", 11111111),
        Person("Richard", "Roe", 88888888),
        Person("Jane", "Doe", 66666666),
        Person("John", "Roe", 44444444),
        Person("Mary", "Major", 22222222),
        Person("John", "Public", 12345678),
        Person("Mary", "Smith", 98765432),
        Person("John", "Doe", 90000000),
        Person("Joe", "Bloggs", 87654321),
        Person("Jane", "Public", 23456789),
        Person("John", "Stiles", 10000000)
    };
    int len = 15;

    print("People unsorted", people, len);

    bubbleSortInPlace(people, len, Person::CompareType::LessCwid);
    print("People sorted by cwid asc", people, len);

    bubbleSortInPlace(people, len, Person::CompareType::LessLastFirstCwid);
    print("People sorted by last name then first name then cwid asc", people, len);

    return 0;
}
