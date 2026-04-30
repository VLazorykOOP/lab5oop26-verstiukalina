#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>
#include <windows.h>
#undef Ellipse
using namespace std;

class Point {
protected:
    double x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(double x1, double y1) {
        x = x1;
        y = y1;
    }

    ~Point() {
        cout << "Деструктор точки\n";
    }

    void drukuvaty() {
        cout << "Точка: x = " << x << ", y = " << y << endl;
    }

    double ploshcha() {
        return 0;
    }
};

class MyEllipse : public Point {
protected:
    double a, b;

public:
    MyEllipse() : Point() {
        a = 1;
        b = 1;
    }

    MyEllipse(double x1, double y1, double a1, double b1) : Point(x1, y1) {
        a = a1;
        b = b1;
    }

    ~MyEllipse() {
        cout << "Деструктор еліпса\n";
    }

    void drukuvaty() {
        cout << "Центр еліпса: x = " << x << ", y = " << y << endl;
        cout << "Півосі: a = " << a << ", b = " << b << endl;
        cout << "Площа = " << ploshcha() << endl;
    }

    double ploshcha() {
        return 3.14 * a * b;
    }
};

class Circle : public MyEllipse {
public:
    Circle() : MyEllipse() {}

    Circle(double x1, double y1, double r) : MyEllipse(x1, y1, r, r) {}

    ~Circle() {
        cout << "Деструктор кола\n";
    }

    void drukuvaty() {
        cout << "Центр кола: x = " << x << ", y = " << y << endl;
        cout << "Радіус: r = " << a << endl;
        cout << "Площа = " << ploshcha() << endl;
    }

    double ploshcha() {
        return 3.14 * a * a;
    }
};

void testPoint() {
    cout << "\nТест точки \n";
    Point p1;
    p1.drukuvaty();
    cout << "Площа = " << p1.ploshcha() << endl;

    Point p2(2, 5);
    p2.drukuvaty();
    cout << "Площа = " << p2.ploshcha() << endl;
}

void testEllipse() {
    cout << "\nТест еліпса \n";
    MyEllipse e1;
    e1.drukuvaty();

    MyEllipse e2(1, 2, 4, 3);
    e2.drukuvaty();
}

void testCircle() {
    cout << "\nТест кола \n";
    Circle c1;
    c1.drukuvaty();

    Circle c2(3, 4, 5);
    c2.drukuvaty();
}

void testAll() {
    testPoint();
    testEllipse();
    testCircle();
}

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    void dodaty(TreeNode*& node, int value) {
        if (node == NULL) {
            node = new TreeNode(value);
        }
        else if (value < node->value) {
            dodaty(node->left, value);
        }
        else if (value > node->value) {
            dodaty(node->right, value);
        }
        else {
            cout << "Повторне значення\n";
        }
    }

    void poslidovnyiObhid(TreeNode* node) {
        if (node != NULL) {
            poslidovnyiObhid(node->left);
            cout << node->value << " ";
            poslidovnyiObhid(node->right);
        }
    }

    void zvorotnyiObhid(TreeNode* node) {
        if (node != NULL) {
            zvorotnyiObhid(node->right);
            cout << node->value << " ";
            zvorotnyiObhid(node->left);
        }
    }

    void ochystyty(TreeNode* node) {
        if (node != NULL) {
            ochystyty(node->left);
            ochystyty(node->right);
            delete node;
        }
    }

public:
    BinaryTree() {
        root = NULL;
    }

    ~BinaryTree() {
        ochystyty(root);
    }

    void dodaty(int value) {
        dodaty(root, value);
    }

    void drukuvatyPoslidovno() {
        poslidovnyiObhid(root);
        cout << endl;
    }

    void drukuvatyZvorotno() {
        zvorotnyiObhid(root);
        cout << endl;
    }
};

void robotaZDerevom() {
    BinaryTree tree;
    int choice;
    int value;

    do {
        cout << "\n Бінарне дерево \n";
        cout << "1. Додати значення\n";
        cout << "2. Послідовний обхід\n";
        cout << "3. Зворотний обхід\n";
        cout << "0. Повернутися в головне меню\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть значення: ";
            cin >> value;
            tree.dodaty(value);
            break;
        case 2:
            tree.drukuvatyPoslidovno();
            break;
        case 3:
            tree.drukuvatyZvorotno();
            break;
        case 0:
            break;
        default:
            cout << "Неправильний вибір\n";
        }
    } while (choice != 0);
}

class MyString {
protected:
    char* str;

public:
    MyString() {
        str = new char[1];
        str[0] = '\0';
    }

    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const MyString& s) {
        out << s.str;
        return out;
    }

    friend istream& operator>>(istream& in, MyString& s) {
        char temp[100];
        in >> temp;
        delete[] s.str;
        s.str = new char[strlen(temp) + 1];
        strcpy(s.str, temp);
        return in;
    }
};

class DigitString : public MyString {
private:
    bool tilkyTsyfry(const char* s) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (!isdigit(s[i])) {
                return false;
            }
        }
        return true;
    }

    void vstanovytyZnachenia(const char* s) {
        delete[] str;
        if (tilkyTsyfry(s)) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else {
            str = new char[1];
            str[0] = '\0';
        }
    }

public:
    DigitString() : MyString() {}

    DigitString(const char* s) : MyString() {
        vstanovytyZnachenia(s);
    }

    DigitString(const DigitString& other) : MyString(other) {}

    ~DigitString() {}

    DigitString& operator=(const DigitString& other) {
        MyString::operator=(other);
        return *this;
    }

    friend ostream& operator<<(ostream& out, const DigitString& s) {
        out << s.str;
        return out;
    }

    friend istream& operator>>(istream& in, DigitString& s) {
        char temp[100];
        in >> temp;
        s.vstanovytyZnachenia(temp);
        return in;
    }
};

void testRiadkiv() {
    cout << "\n Тест рядків \n";

    MyString s1("privit");
    MyString s2 = s1;
    MyString s3;
    s3 = s1;

    cout << "s1 = " << s1 << endl;
    cout << "копія s2 = " << s2 << endl;
    cout << "присвоєний s3 = " << s3 << endl;

    DigitString d1("12345");
    DigitString d2 = d1;
    DigitString d3;
    d3 = d1;

    cout << "d1 = " << d1 << endl;
    cout << "копія d2 = " << d2 << endl;
    cout << "присвоєний d3 = " << d3 << endl;

    cout << "Введіть рядок: ";
    cin >> s1;
    cout << "Ви ввели: " << s1 << endl;

    cout << "Введіть рядок із цифр: ";
    cin >> d1;
    cout << "Рядок із цифр: " << d1 << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;

    do {
        cout << "\nМЕНЮ\n";
        cout << "1. Тести до задачі 1\n";
        cout << "2. Робота з бінарним деревом\n";
        cout << "3. Тести до задачі 3\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            testAll();
            break;
        case 2:
            robotaZDerevom();
            break;
        case 3:
            testRiadkiv();
            break;
        case 0:
            cout << "Вихід\n";
            break;
        default:
            cout << "Неправильний вибір\n";
        }
    } while (choice != 0);

    return 0;
}
