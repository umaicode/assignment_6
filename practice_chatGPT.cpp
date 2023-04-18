#include <stdlib.h>
#include <iostream>
/*

*/
using namespace std;
class String {
    char* data;

public:
    String(char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    ~String() {
        delete[] data;
    }
};
/*
public:
    String(char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    ~String() {
        delete[] data;
    }
};
*/

class Person {
    friend class Stack;
    String* pname;
    int age;

public:
    Person(char* n = "", int a = 0) {
        this->pname = new String(n);
        this->age = a;
    }

    ~Person() {
        delete[] pname;
    }

    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Name: " << p.pname << ", Age: " << p.age << endl;
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

    // ���� ������
    Stack(const Stack& other) {
        top = other.top;
        for (int i = 0; i < top; i++) {
            items[i] = new Person(*other.items[i]);
        }
    }

    // ���� ������
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

    ~Stack() {
        for (int i = 0; i < top; i++) {
            delete items[i];
        }
    }

    void Push(Person&);
    Person& Pop();

};

void Stack::Push(Person& p) {
    this->items[top] = new Person(new String(p.pname->data), p.age);
    top++;
}

Person& Stack::Pop() {
    top--;
    return *items[top];
}


int main() {
    Person* p[10];
    Stack s1;
    while (1)
    {
        Stack s2;
        char sname[20];
        int year;

        int select;
        cout << "\n���� 1: Stack �Է�(Batch), 2: Push(ȭ�� �Է�), 3. PoP �� ��ü�� ���, 4: ���� ��� ��ü ���," << endl;
        cout << "5. ������ ��� ��ü�� pop�Ͽ� Person ��ü �迭�� ���� �� �����ϱ�, 6. ������ ġȯ(s1 = s2;), 7.quit = > ";
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
                Person px = Person(sname, year);
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
                for () {
                    arry[i] = s2.Pop();
                }
                //arry[] ��ü�� person�� �̸����� �����ϱ� > person�� �� ������ ����
                //���ĵ� ��ü�� ����ϱ�
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


