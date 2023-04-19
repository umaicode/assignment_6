#include <stdlib.h>
#include <iostream>
/*

*/
using namespace std;
class String {
    char* data; // ���� �Ұ�

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
    friend class Stack; // �����Ұ�
    String* pname; // �����Ұ�
    int age; // �����Ұ�

public:

    Person() : pname(new String("")), age(0) {}
    Person(const char* name) : pname(new String(name)), age(0) {}
    Person(int age) : pname(new String("")), age(age) {}
    Person(const char* name, int age) : pname(new String(name)), age(age) {}

    ~Person() {
        delete pname;
    }

    friend ostream& operator<<(ostream& os, Person& p) {
        os << "NAME : " << p.pname->GetData() << ", AGE : " << p.age;
        return os;
    }

    bool operator>(const Person& other) const {
        const char* str1 = pname->GetData();
        const char* str2 = other.pname->GetData();
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0') {
            if (str1[i] > str2[i]) {
                return true;
            }
            else if (str1[i] < str2[i]) {
                return false;
            }
            i++;
        }
        return str1[i] > str2[i];
    }
};

class Stack {
    int top; // �����Ұ�
    Person* items[100]; // �����Ұ�

public:
    Stack() {
        top = 0;
    }
    ~Stack() {
        for (int i = 0; i < top; i++) {
            delete items[i];
        }
    }

    //// ���� ������
    //Stack(const Stack& other) {
    //    top = other.top;
    //    for (int i = 0; i < top; i++) {
    //        items[i] = new Person(*other.items[i]);
    //    }
    //}

    //// ���� ������
    //Stack& operator=(const Stack& other) {
    //    if (this == &other) {
    //        return *this;
    //    }
    //    for (int i = 0; i < top; i++) {
    //        delete items[i];
    //    }
    //    top = other.top;
    //    for (int i = 0; i < top; i++) {
    //        items[i] = new Person(*other.items[i]);
    //    }
    //    return *this;
    //}

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
    Person* p = items[top - 1];
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
        cout << "\n���� 1: Stack �Է�(Batch), 2: Push(ȭ�� �Է�), 3. PoP �� ��ü�� ���, 4: ���� ��� ��ü ���," << endl;
        cout << "5. ������ ��� ��ü�� pop�Ͽ� Person ��ü �迭�� ���� �� �����ϱ�, 6. ������ ġȯ(s1 = s2;), 7.quit = > ";
        cin >> select;
        switch (select)
        {
        case 1://AddBatch
        {
            cout << endl << "10�� ť�� �Է�" << endl;
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

        case 5:
        {
            Person* arry[50];
            int count = s2.GetTop();
            Person* tempArry[50]; // ���ο� �迭 ����
            for (int i = 0; i < count; i++) {
                tempArry[i] = &s2.Pop(); // ���ÿ��� ��ü�� ������ ���ο� �迭�� ����
            }
            for (int i = 0; i < count; i++) {
                arry[i] = tempArry[i]; // ���ο� �迭�� ������ ���� �迭�� ����
            }
            //arry[] ��ü�� person�� �̸����� �����ϱ� > person�� �� ������ ����
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (*arry[i] > *arry[j]) {
                        Person* temp = arry[i];
                        arry[i] = arry[j];
                        arry[j] = temp;
                    }
                }
            }
            //���ĵ� ��ü�� ����ϱ�
            for (int i = 0; i < count; i++) {
                cout << *arry[i] << endl;
            }
            break;
        }

        /*
        case 5:
        {
            Person* arry[50];
            int count = s2.GetTop();
            for (int i = 0; i < count; i++) {
                arry[i] = &s2.Pop();
            }
            //arry[] ��ü�� person�� �̸����� �����ϱ� > person�� �� ������ ����
            for (int i = 0; i <= count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (*arry[i] > *arry[j]) {
                        Person* temp = arry[i];
                        arry[i] = arry[j];
                        arry[j] = temp;
                    }
                }
            }
            //���ĵ� ��ü�� ����ϱ�
            for (int i = 0; i < count; i++) {
                cout << *arry[i] << endl;
            }
            break;
        }
        */
        case 6:
        {
            s1 = s2;
            cout << s1;
            cout << s2;
            break;
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


