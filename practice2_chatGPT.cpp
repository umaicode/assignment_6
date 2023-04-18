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
    ~String() {
        delete[] data;
    }

    char* GetData() const { // data 멤버에 접근할 수 있는 함수
        return data;
    }
};
class Person {
    friend class Stack;
    String* pname;
    int age;

public:
    Person() : pname(nullptr), age(0) {}
    Person(char* name) : pname(new String(name)), age(0) {}
    Person(int age) : pname(nullptr), age(age) {}
    Person(char* name, int age) : pname(new String(name)), age(age) {}

    ~Person() {
        delete pname;
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

    void Push(Person&);
    Person& Pop();

};

void Stack::Push(Person& p) {
    items[top] = new Person(p.pname->data, p.age);
    top++;
}

Person& Stack::Pop() {
    Person* p = items[top];
    top--;
    return *p;
}


int main() {
    Stack s1;
    while (1)
    {
        Stack s2;

        int select;
        cout << "\n선택 1: Stack 입력(Batch), 2: Push(화면 입력), 3. PoP 한 객체를 출력, 4: 스택 모든 객체 출력," << endl;
        cout << "5. 스택의 모든 객체를 pop하여 Person 객체 배열에 저장 후 정렬하기, 6. 스택의 치환(s1 = s2;), 7.quit = > ";
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
                for () {
                    arry[i] = s2.Pop();
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


