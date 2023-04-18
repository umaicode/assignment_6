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
        cout << "Stack�� �� á���ϴ�." << endl;
        return;
    }

    Person* p = new Person(pname, age);
    items[top++] = p;
}

Person& Stack::Pop() {
    if (top == 0) {
        cout << "Stack�� ����ֽ��ϴ�." << endl;
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
        cout << "\n���� 1: Stack �Է�(Batch), 2: Push(ȭ�� �Է�), 3. PoP �� ��ü�� ���, 4: ���� ��� ��ü ���," << endl;
        cout <<"5. ������ ��� ��ü�� pop�Ͽ� Person ��ü �迭�� ���� �� �����ϱ�, 6. ������ ġȯ(s1 = s2;), 7.quit = > ";
        cin >> select;
        switch (select) {
            case 1://AddBatch
            {
                cout << endl << "10�� ť�� �Է�" << endl;
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
                cout << endl << "1�� ��ü�� ȭ�� �Է¹޾�" << endl;
                cin >> sname >> year;
                Person* px = new Person(sname, year);
                s2.Push(px);
                break;
            }

            case 3://Delete
            {
                cout << endl << "Delete" << endl;
                Person result = s2.Pop();
                cout << "������ ��ü:";
                cout << result;
                break;
            }

            case 4://Stack�� �ִ� ��� ��ü�� ���
            {
                cout << s2;
                break;
            }

            case 5: // stack�� �ִ� ��� ��ü�� pop�Ͽ� �����ϱ�
            {
                Person* arry[50];
                for (int i = 0; i < 50; i++) {
                    arry[i] = s2.Pop();
                }
                //arry[] ��ü�� person�� �̸����� �����ϱ� > person�� �� ������ ����
                //���ĵ� ��ü�� ����ϱ�
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
    //���α׷� ����ÿ� run-time�� ������ �Ҹ��� ������ delete ȣ�� ���
}


