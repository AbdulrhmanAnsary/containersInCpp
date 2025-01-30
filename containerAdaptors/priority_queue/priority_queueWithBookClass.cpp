#include <iostream>
#include <queue>

using namespace std;

class Book
{
  public:
    string title;
    double price;

    Book(string title, double price)
    {
        this->title = title;
        this->price = price;
    }
};

class Compare
{
  public:
    bool operator()(Book b1, Book b2)
    {
        return (b1.price > b2.price);
    }
};

int main()
{
    priority_queue<Book, vector<Book>, Compare> pq;

    Book book1("C++ for beginner", 18);
    Book book2("HTML5 for dummies", 12);
    Book book3("Building Android apps", 25);

    pq.push(book1);
    pq.push(book2);
    pq.push(book3);

    cout << "Popping out stored Books:\n";

    while (!pq.empty())
    {
        cout << "- " << pq.top().title << " [" << pq.top().price << "$]\n";
        pq.pop();
    }

    return 0;
}