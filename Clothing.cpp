#include "Clothing.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

// Helper to detect white space 

static bool isWhitespaceOnly_C(const string& s) {
    if (s.empty()) return true;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        if (!isspace(ch)) return false;
    }
    return true;
}

// Creates case-insensitive version of string as per spec

static string toLowerCopy_C(const string& s) {
    string t;
    t.reserve(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        t.push_back(static_cast<char>(tolower(ch)));
    }
    return t;
}

Clothing::Clothing(const string& name, double price, const string& size)
    : Product(name, price), m_size(size) {
}

Clothing::~Clothing() {}

string Clothing::getCategory() const {
    return "Clothing";
}

bool Clothing::matchesKeyword(const string& keyword) const {
    if (isWhitespaceOnly_C(keyword)) return false;
    string key = toLowerCopy_C(keyword);
    string hayName = toLowerCopy_C(m_name);
    string haySize = toLowerCopy_C(m_size);
    return (hayName.find(key) != string::npos) || (haySize.find(key) != string::npos);
}

void Clothing::printInfo() const {
    cout << "Category: " << getCategory()
        << " | Name: " << m_name
        << " | Price: " << fixed << setprecision(2) << m_price
        << " | Size: " << m_size
        << endl;
}





