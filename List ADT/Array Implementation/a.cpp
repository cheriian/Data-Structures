#include <iostream>

using namespace std;

class list
{
    private:

        int arr[5]{};
        int size;
    public:

        list();
        void insertbeg(int);
        void insertend(int);
        void insertpos(int, int);
        void deletebeg();
        void deleteend();
        void deletepos(int);
        void search(int);
        void display();
        void rotate(int);
};

int main()
{
    list l1;
    int choice;
    int n;
    int p;
    int k;
    do
    {
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\nEnter 1, 2, 3, 4, 5, 6, 7, 8, 9 or 10: " << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:

                cout << "Enter the number to be inserted: " << endl;
                cin >> n;
                l1.insertbeg(n);
                break;
            case 2:

                cout << "Enter the number to be inserted: " << endl;
                cin >> n;
                l1.insertend(n);
                break;
            case 3:

                cout << "Enter the number to be inserted: " << endl;
                cin >> n;
                cout << "Enter the position the number is to be inserted in: " << endl;
                cin >> p;
                l1.insertpos(n, p);
                break;
            case 4:

                l1.deletebeg();
                break;
            case 5:

                l1.deleteend();
                break;
            case 6:

                cout << "Enter the position the number is to be deleted from: " << endl;
                cin >> p;
                l1.deletepos(p);
                break;
            case 7:

                cout << "Enter the number to search for: " << endl;
                cin >> n;
                l1.search(n);
                break;
            case 8:

                l1.display();
                break;
            case 9:

                cout << "Enter the number of times to rotate: " << endl;
                cin >> k;
                l1.rotate(k);
                break;
            case 10:

                break;
            default:

                cout << "Invalid Choice" << endl;
        }
    } while (choice != 10);
}

list::list()
{
    for (int i = 0; i < 5; i++)
    {
        arr[i] = 0;
    }
    size = 0;
}

void list::insertbeg(int n)
{
    if (size == 5)
    {
        cout << "List is full" << endl;
    }
    else
    {
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = n;
        size++;
    }
}

void list::insertend(int n)
{
    if (size == 5)
    {
        cout << "List is full" << endl;
    }
    else
    {
        arr[size] = n;
        size++;
    }
}

void list::insertpos(int n, int p)
{
    if (size == 5)
    {
        cout << "List is full" << endl;
    }
    else if (p > size)
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        for (int i = size; i >= p; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[p - 1] = n;
        size++;
    }
}

void list::deletebeg()
{
    if (size == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void list::deleteend()
{
    if (size == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        size--;
    }
}

void list::deletepos(int p)
{
    if (size == 0)
    {
        cout << "List is empty" << endl;
    }
    else if (p > size)
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        for (int i = p; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }
}

void list::search(int n)
{
    if (size == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == n)
            {
                cout << n << " was found at position " << i + 1 << endl;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << n << "was not found" << endl;
        }
    }
}

void list::display()
{
    if (size == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void list::rotate(int k)
{
    while (k > 0)
    {
        int temp = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
        k--;
    }
}
