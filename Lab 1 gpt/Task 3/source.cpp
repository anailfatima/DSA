#include <iostream>
using namespace std;


class Book{
protected:
    string t;
    string w;
    float p;

public:
Book()
{
    t = "";
    w = "";
    p = 0;
}
Book(string title,string writer,float pages)
{
    t = title;
    w = writer;
    p = pages;
}

void display()
{
    cout << "Book title : " << t << endl;
    cout << "Writer : " << w << endl;
    cout << "Price : " << p << endl;
    cout << endl;
}

int getPages()
{
    return p;
}

string getTitle()
{
    return t;
}
};




class Newspaper
{
protected:
    string t;
    string d;
    string e;

public:
Newspaper()
{
    t = "";
    d = "";
    e = "";
}
    Newspaper(string title, string date, string edition)
    {
        t = title;
        d = date;
        e = edition;
    }

    void display()
    {
        cout << "Newspaper title : " << t << endl;
        cout << "Printing date : " << d << endl;
        cout << "Edition : " << e << endl;
        cout << endl;
    }

    string getTitle()
    {
        return t;
    }

    string getEdition()
    {
        return e;
    }
};



class Library{
protected:
    Book barray[2];
    Newspaper narray[2];
    int i = 0;
    int j = 0;

public:

    void addBook(Book b)
    {
        barray[i] = b;
        i++;
    }

    void addNewspaper(Newspaper n)
    {
        narray[j] = n;
        j++;
    }

    void displayCollection()
    {
        for (int i = 0; i < 2;i++)
        {
            barray[i].display();
        }

        for (int i = 0; i < 2; i++)
        {
            narray[i].display();
        }
    }

    void sortBooksByPages()
    {
if(barray[0].getPages() > barray[1].getPages())
{
    Book temp;
    temp = barray[0];
    barray[0] = barray[1];
    barray[1] = temp;
}
    }

    void sortNewspapersByEdition()
    {
        if (narray[0].getEdition() == "Weekend Edition" && narray[1].getEdition() == "Morning Edition")
        {
            Newspaper temp;
            temp = narray[0];
            narray[0] = narray[1];
            narray[1] = temp;
        }
    }

    Book* searchBookByTitle(string s)
    {
        for (int i = 0; i < 2;i++)
        {
            if(barray[i].getTitle()==s)
            {
                return &barray[i];
            }
        }
    }

    Newspaper *searchNewspaperByName(string s)
    {
        for (int i = 0; i < 2; i++)
        {
            if (narray[i].getTitle() == s)
            {
                return &narray[i];
            }
        }
    }
};




int main()
{
    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 377);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);


    // Create newspaper objects
    Newspaper newspaper1("Washington Post", "2024-10-13", "Weekend Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Morning Edition");


    // Create a library object
    Library library;


    // Add books and newspapers to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);


    // Display the entire collection
    cout << "Before Sorting:\n";
    library.displayCollection();


    // Sort books by pages and newspapers by edition
    library.sortBooksByPages();
    library.sortNewspapersByEdition();
    cout << "\nAfter Sorting:\n";
    library.displayCollection();


    // Search for a book by title
    Book *foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook)
    {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else
    {
        cout << "\nBook not found.\n";
    }



    // Search for a newspaper by name
    Newspaper *foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper)
    {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else
    {
        cout << "\nNewspaper not found.\n";
    }
    return 0;
}