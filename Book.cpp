#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

// Helper to detect white space 

static bool isWhitespaceOnly_B(const string& s) {
    if (s.empty()) return true;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        if (!isspace(ch)) return false;
    }
    return true;
}

// Creates case-insensitive version of string as per spec

static string toLowerCopy_B(const string& s) {
    string t;
    t.reserve(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        t.push_back(static_cast<char>(tolower(ch)));
    }
    return t;
}

Book::Book(const string& name, double price, const string& author)
    : Product(name, price), m_author(author) {
}

Book::~Book() {}

string Book::getCategory() const {
    return "Book";
}

bool Book::matchesKeyword(const string& keyword) const {
    if (isWhitespaceOnly_B(keyword)) return false;
    string key = toLowerCopy_B(keyword);
    string hayName = toLowerCopy_B(m_name);
    string hayAuthor = toLowerCopy_B(m_author);
    return (hayName.find(key) != string::npos) || (hayAuthor.find(key) != string::npos);
}

void Book::printInfo() const {
    cout << "Category: " << getCategory()
        << " | Name: " << m_name
        << " | Price: " << fixed << setprecision(2) << m_price
        << " | Author: " << m_author
        << endl;
}




