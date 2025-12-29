#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Book{
    int id;
    string book_title;
    string book_author;
    string isbn;
    bool isIssued;
    int issuedDate;

};

vector<Book>Library;
int count = 0;

void add_book(){
    Book b;
    cin.ignore();

    cout<<"\nEnter the book title: ";
    getline(cin, b.book_title);
    cout<<"Enter author name: ";
    getline(cin, b.book_author);

    cout<<"Enter ISBN number: ";
    getline(cin, b.isbn);

    b.id = ++count;
    b.isIssued = false;
    b.issuedDate = 0;

    Library.push_back(b);
    cout<<"\nBook added successfully!"<<endl;
}

void view_book(){
    if(Library.empty()){
        cout<<"\nNo books available in the library!!"<<endl;
        return;
    }

    cout<<"\nLibrary book list : "<<endl;
    cout<<"-----------------------------"<<endl;

    for(auto b : Library){
        cout<<"ID: "<<b.id<<endl;
        cout<<"Title: "<<b.book_title<<endl;
        cout<<"Author: "<<b.book_author<<endl;
        cout<<"ISBN: "<<b.isbn<<endl;
        cout<<"Status: "<<(b.isIssued ? "Issued" : "Available")<<endl;
        cout<<"----------------------------------------------"<<endl;

    }

    
}

void search(){
    int choice;
    string key;
    cin.ignore();

    cout<< "\n Search by: \n1.Title \n2. Author\n3. ISBN\n 4. Choice";
    cin>>choice;
    cin.ignore();

    cout<<"Enter the search key: ";
    getline(cin, key);

    bool found = false;

    for(auto b : Library){
        if((choice == 1 && b.book_title == key) || (choice == 2 && b.book_author == key) || (choice == 3 && b.isbn == key)){
            cout<<"\nBook found!"<<endl;
            cout<<"Title: "<<b.book_title<<endl;
            cout<<"Author: "<<b.book_author<<endl;
            cout<<"ISBN Number: "<<b.isbn<<endl;
            cout<<"Status: "<<(b.isIssued ? "Issued" : "Available")<<endl;
            found = true; 
        }
    }

    if(!found){
        cout<<"\nBook is not found!"<<endl;

    }
}


void issued(){
    int i;
    cout<<"\nEnter book id to issue: ";
    cin>>i;

    for(auto &b : Library){
        if(b.id = i && !b.isIssued){
            cout<<"Enter number of days for issue: ";
            cin>>b.issuedDate;
            b.isIssued = true;
            cout<<"\nBook issued successfully!"<<endl;
            return;
        }
    }

    cout<<"\nbook not available of invalid id!"<<endl;
}


void returnBook(){
    int id;
    int late;
    cout<<"\nEnter book id to return: ";
    cin>>id;

    for(auto &b: Library){
        if(b.id = id && b.isIssued){
            cout<<"\nEnter number of overdues days: ";
            cin>>late;

            int fine = late * 5;
            cout<<"\nFine Amount: "<<fine<<endl;


            b.isIssued = false;
            b.issuedDate = 0;

            cout<<"Book returned successfully!"<<endl;
            return;

        }
    }

    cout<<"Invalid book id or book is not returned"<<endl;
}

int main(){
    int c;
    do{
        cout<<"----------------------------------"<<endl;
        cout<<"LIBRARY MANAGEMENT SYSTEM"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. View Books"<<endl;
        cout<<"3. Search Books"<<endl;
        cout<<"4. Issue Book"<<endl;
        cout<<"5. Return Book"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choices: ";
        cin>>c;


        switch(c){
            case 1: 
                add_book();
                break;
            case 2:
                view_book();
                break;
            case 3:
                search();
                break;
            case 4:
                issued();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                cout<<"terminating the system..."<<endl;
            default:
                cout<<"Invalid choice!"<<endl;

        }
    }
    while(c != 6);


    return 0;
}