#include <stdlib.h>
#include <iostream>
/*

*/
using namespace std;
class String {
    char* data;

public:
    String(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    const char* GetData() const {
        return data;
    }
};

class Person {
    friend class Stack;
    String* pname;
    int age;

public:

    Person() : pname(new String("")), age(0){}
    Person(const char* name) : pname(new String(name)), age(0) {}
    Person(int age) : pname(new String("")), age(age){}
    Person(const char* name, int age) : pname(new String(name)), age(age) {}

    ~Person() {
        delete pname;
    }

    friend ostream& operator<<(ostream& os, Person& p) {
        os <<  ", NAME : " << p.pname->GetData() << ", AGE : " << p.age;
        return os;
    }
};

class Stack {
    int top;
    Person* items[100];

public:
    Stack() {
        top = 0;
    }
    ~Stack() {
        for (int i = 0; i < top; i++) {
            delete items[i];
        }
    }

    // 복사 생성자
    Stack(const Stack& other) {
        top = other.top;
        for (int i = 0; i < top; i++) {
            items[i] = new Person(*other.items[i]);
        }
    }

    // 대입 연산자
    Stack& operator=(const Stack& other) {
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

    friend ostream& operator<<(ostream& os, Stack& s) {
        for (int i = 0; i < s.top; i++) {
            os << *s.items[i] << endl;
        }
        return os;
    }


    void Push(Person&);
    Person& Pop();

    int GetTop() {
        return top;
    }

};

void Stack::Push(Person& p) {
    this->items[top] = new Person(p.pname->GetData(), p.age);
    cout << "Name : " << p.pname->GetData() << " age : " << p.age << endl;
    top++;
    
}

Person& Stack::Pop() {
    Person* p = items[top-1];
    top--;
    return *p;
}


int main() {
    Person* p[10];
    Stack s1;
    Stack s2;
    while (1)
    {
        char sname[20];
        int year;
        int select;
        cout << "\n선택 1: Stack 입력(Batch), 2: Push(화면 입력), 3. PoP 한 객체를 출력, 4: 스택 모든 객체 출력," << endl;
        cout << "5. 스택의 모든 객체를 pop하여 Person 객체 배열에 저장 후 정렬하기, 6. 스택의 치환(s1 = s2;), 7.quit = > ";
        cin >> select;
        switch (select) 
        {
            case 1://AddBatch
            {
                cout << endl << "10개 큐에 입력" << endl;
                Person p0;
                Person p1("kim");
                Person p2(23);
                Person p3("park", 24);
                p[0] = &p0; p[1] = &p1; p[2] = &p2; p[3] = &p3;
                for (int i = 0; i < 4; i++) {
                    s2.Push(*p[i]);
                }
                break;
            }

            case 2://AddOne
            {
                cout << endl << "1개 객체를 화면 입력받아" << endl;
                cin >> sname >> year;
                Person px = Person(sname, year);
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
                for (int i = 0; i < s2.GetTop(); i++) {
                    *arry[i] = s2.Pop();
                }
                //arry[] 객체를 person의 이름으로 정렬하기 > person의 비교 연산자 구현
                //정렬된 객체를 출력하기
            }

            case 6:
            {
                s1 = s2;
                break;
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


