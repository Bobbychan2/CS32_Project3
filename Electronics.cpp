#include "Electronics.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

// Helper to detect white space

static bool isWhitespaceOnly_E(const string& s) {
    if (s.empty()) return true;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        if (!isspace(ch)) return false;
    }
    return true;
}

// Creates case-insensitive version of string as per spec

static string toLowerCopy_E(const string& s) {
    string t;
    t.reserve(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        t.push_back(static_cast<char>(tolower(ch)));
    }
    return t;
}

Electronics::Electronics(const string& name, double price, int warrantyMonths)
    : Product(name, price), m_warrantyMonths(warrantyMonths) {
}

Electronics::~Electronics() {}

string Electronics::getCategory() const {
    return "Electronics";
}

bool Electronics::matchesKeyword(const string& keyword) const {
    if (isWhitespaceOnly_E(keyword)) return false;
    string key = toLowerCopy_E(keyword);
    string hayName = toLowerCopy_E(m_name);
    string warrantyStr = to_string(m_warrantyMonths) + " months";
    string hayWarranty = toLowerCopy_E(warrantyStr);
    return (hayName.find(key) != string::npos) || (hayWarranty.find(key) != string::npos);
}

void Electronics::printInfo() const {
    cout << "Category: " << getCategory()
        << " | Name: " << m_name
        << " | Price: " << fixed << setprecision(2) << m_price
        << " | Warranty: " << m_warrantyMonths << " months"
        << endl;
}



