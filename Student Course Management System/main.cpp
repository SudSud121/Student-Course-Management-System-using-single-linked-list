int main()
{
    LinkedList courses;

    courses.InsertAt(CreateCourse(103, "Programming"), 0);
    courses.InsertAt(CreateCourse(101, "Mathematics"), 1);
    courses.InsertAt(CreateCourse(102, "Physics"), 2);

    cout << "STUDENT COURSE LIST\n";
    courses.Print();

    courses.InsertAt(CreateCourse(104, "English"), 1);
    cout << "\nAfter adding a course:\n";
    courses.Print();

    Course* removed = courses.RemoveAt(2);
    if (removed != NULL)
    {
        cout << "\nRemoved: " << removed->name << endl;
        delete removed;
    }

    courses.Swap(0, 1);
    courses.Sort();

    cout << "\nAfter swapping and sorting:\n";
    courses.Print();

    courses.Reverse();
    cout << "\nAfter reversing:\n";
    courses.Print();

    return 0;
}
