using namespace std;

struct Course
{
    int id;
    string name;
    Course* next;
};

class LinkedList
{
    Course* head;
    int count;

public:
    LinkedList()
    {
        head = NULL;
        count = 0;
    }

    bool IsEmpty()
    {
        return head == NULL;
    }

    bool IsNotEmpty()
    {
        return head != NULL;
    }

    void Insert(Course* c)
    {
        c->next = head;
        head = c;
        count++;
    }

    Course* Remove()
    {
        if (IsEmpty()) return NULL;

        Course* temp = head;
        head = head->next;
        temp->next = NULL;
        count--;
        return temp;
    }

    Course* GetNodeAt(int index)
    {
        Course* p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        return p;
    }

    void InsertAt(Course* c, int index)
    {
        if (index < 0) index = 0;
        if (index > count) index = count;

        if (index == 0)
        {
            Insert(c);
            return;
        }

        Course* p = GetNodeAt(index - 1);
        c->next = p->next;
        p->next = c;
        count++;
    }

    Course* RemoveAt(int index)
    {
        if (index < 0 || index >= count)
            return NULL;

        if (index == 0) return Remove();

        Course* p = GetNodeAt(index - 1);
        Course* temp = p->next;
        p->next = temp->next;
        temp->next = NULL;
        count--;
        return temp;
    }

    void Swap(int a, int b)
    {
        if (a < 0 || b < 0 || a >= count || b >= count)
            return;

        Course* x = GetNodeAt(a);
        Course* y = GetNodeAt(b);

        swap(x->id, y->id);
        swap(x->name, y->name);
    }

    void Sort()
    {
        for (Course* i = head; i != NULL; i = i->next)
            for (Course* j = i->next; j != NULL; j = j->next)
                if (i->id > j->id)
                {
                    swap(i->id, j->id);
                    swap(i->name, j->name);
                }
    }

    void Reverse()
    {
        Course* prev = NULL;
        Course* curr = head;

        while (curr != NULL)
        {
            Course* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void Print()
    {
        Course* p = head;
        int i = 0;

        while (p != NULL)
        {
            cout << i++ << "  " << p->id
                 << "  " << p->name << endl;
            p = p->next;
        }

        cout << "Total courses: " << count << endl;
    }

    ~LinkedList()
    {
        while (IsNotEmpty())
            delete Remove();
    }
};

Course* CreateCourse(int id, string name)
{
    Course* c = new Course;
    c->id = id;
    c->name = name;
    c->next = NULL;
    return c;
}
