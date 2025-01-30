#include <iostream>
#include <string>
#include <set>

using namespace std;

class Book
{
  public:
    string title;
    int id;

  public:
    Book(int id, string title)
    {
        this->id = id;
        this->title = title;
    }
};

class Compare
{
  public:
    bool operator()(Book b1, Book b2)
    {
        return b1.id < b2.id;
    }
};

int main(int argc, char *argv[])
{
    set<Book, Compare> books;

    Book book1(2, "C++ for beginner");
    Book book2(1, "HTML5 for dummies");
    Book book3(3, "Building Android apps");

    books.emplace(book1);
    books.emplace(book2);
    books.emplace(book3);

    cout << "All books:\n";

    for (auto const &book : books)
    {
        cout << book.id << " - " << book.title << endl;
    }

    return 0;
}