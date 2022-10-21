#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(const char* title, const char* isbn, int price)
        : price(price)
    {
        this->title=new char[strlen(title)+1];
        strcpy(this->title, title);
        this->isbn=new char[strlen(isbn)+1];
        strcpy(this->isbn, isbn);
    }
    
    char* GetTitle() { return title; }
    char* GetIsbn() { return isbn; }
    int GetPrice() { return price; }
    
    void ShowBookInfo()
    {
        cout<<"제목: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"가격: "<<price<<endl;
    }
    
    Book& operator=(Book &ref)
    {
        size_t len=strlen(ref.title)+1;
        title=new char[len];
        strcpy(title, ref.title);
        size_t len2=strlen(ref.isbn)+1;
        isbn=new char[len];
        strcpy(isbn, ref.isbn);
        price=ref.price;
        return *this;
    }
    
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book
{
private:
    char* DRMKey;
public:
    EBook(const char* title, const char* isbn, int price, const char* DRMKey)
        : Book(title, isbn, price)
    {
        this->DRMKey=new char[strlen(DRMKey)+1];
        strcpy(this->DRMKey, DRMKey);
    }
    void ShowBookInfo()
    {
        cout<<"제목: "<<GetTitle()<<endl;
        cout<<"ISBN: "<<GetIsbn()<<endl;
        cout<<"가격: "<<GetPrice()<<endl;
        cout<<"인증키: "<<DRMKey<<endl;
    }
    EBook& operator=(EBook &ref)
    {
        Book::operator=(ref);
        size_t len3=strlen(ref.DRMKey)+1;
        DRMKey=new char[len3];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }
    
    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    Book book1("좋은 C++", "555-12345-890-0", 20000);
    Book book2("멋진 C++", "888-12345-678-0", 30000);
    book1=book2;
    book1.ShowBookInfo();
    cout<<endl;
    EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2("멋진 C++ ebook", "888-12345-678-1", 5000, "qowghozei3if");
    ebook1=ebook2;
    ebook1.ShowBookInfo();
    return 0;
}


