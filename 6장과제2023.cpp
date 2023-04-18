#include <stdlib.h>
#include <iostream>
/*

*/
using namespace std;
class String {
    char* data;

public:
    String(const char* str) {
        size_t length = strlen(str) + 1;
        data = new char[length];
        strcpy_s(data, length, str);
    }

    String(const String& other) {
        size_t length = strlen(other.data) + 1;
        data = new char[length];
        strcpy_s(data, length, other.data);
    }

    ~String() {
        delete[] data;
    }

    const char* getData() const {
        return data;
    }
};

class Person {
    friend class Queue;
    String *pname;
    int age;

public:
    Person(const String& p, int a) : pname(new String(p)), age(a) {}
    Person(const char* p) : pname(new String(p)), age(0) {}
    Person(int a) : pname(new String("")), age(a) {}
    Person() : pname(new String("")), age(0) {}


    ~Person() {
        delete pname;
    }

    String* getName() const {
        return pname;
    }

    int getAge() const {
        return age;
    }

    friend ostream& operator<<(ostream& os, Person& p) {
        os << "ID : " << p.pname->getData() << ", AGE : " << p.age;
        return os;
    }

    bool operator<(const Person& other) const {
        return *pname->getData() < *other.pname->getData();
    }
};

class Stack {
private:
    int top;
    Person* items[100];

public:
    Stack() {
        top = 0;
    }

    Stack(const Stack& other) {
        top = other.top;
        for (int i = 0; i < top; i++) {
            items[i] = new Person(*other.items[i]);
        }
    }

    ~Stack() {
        for (int i = 0; i < top; i++) {
            delete items[i];
        }
    }

    Stack& Stack::operator=(const Stack& other) {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < top; i++) {
            delete items[i];
        }
        top = other.top;
        for (int i = 0; i < top; i++) {
            items[i] = new Person(*other.items[i]);
        }
        return *this;
    }

    void Push(const String&, int);
    Person& Pop();

};

void Stack::Push(const String& pname, int age) {
    if (top >= 100) {
        cout << "Stack이 다 찼습니다." << endl;
        return;
    }

    Person* p = new Person(pname, age);
    items[top++] = p;
}

Person& Stack::Pop() {
    if (top == 0) {
        cout << "Stack이 비어있습니다." << endl;
        exit(1);
    }
    
    Person* p = items[top--];
    return *p;
}


int main() {
    Stack s1;
    while (1)
    {
        Stack s2;
        char sname[20];
        int year;
        int select;
        cout << "\n선택 1: Stack 입력(Batch), 2: Push(화면 입력), 3. PoP 한 객체를 출력, 4: 스택 모든 객체 출력," << endl;
        cout <<"5. 스택의 모든 객체를 pop하여 Person 객체 배열에 저장 후 정렬하기, 6. 스택의 치환(s1 = s2;), 7.quit = > ";
        cin >> select;
        switch (select) {
            case 1://AddBatch
            {
                cout << endl << "10개 큐에 입력" << endl;
                Person p0();
                Person p1("kim");
                Person p2(23);
                Person p3("park", 24);

                for (int i = 0; i < 4; i++) {
                    s2.Push(p[i]);
                }
                break;
            }

            case 2://AddOne
            {
                cout << endl << "1개 객체를 화면 입력받아" << endl;
                cin >> sname >> year;
                Person* px = new Person(sname, year);
                s2.Push(px);
                break;
            }

            case 3://Delete
            {
                cout << endl << "Delete" << endl;
                Person result = s2.Pop();
                cout << "삭제된 객체:";
                cout << result;
                break;
            }

            case 4://Stack에 있는 모든 객체를 출력
            {
                cout << s2;
                break;
            }

            case 5: // stack에 있는 모든 객체를 pop하여 정렬하기
            {
                Person* arry[50];
                for (int i = 0; i < 50; i++) {
                    arry[i] = s2.Pop();
                }
                //arry[] 객체를 person의 이름으로 정렬하기 > person의 비교 연산자 구현
                //정렬된 객체를 출력하기
                break;
            }

            case 6:
            {
                s1 = s2;
            }

            default:
                exit(0);
                break;
        }
    }
    system("pause");
    return 1;
    //프로그램 종료시에 run-time이 없도록 소멸자 구현과 delete 호출 사용
}


