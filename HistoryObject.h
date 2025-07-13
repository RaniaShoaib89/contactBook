#pragma once
using namespace std;
#ifndef HISTORYOBHECT_H
#define HISTORYOBHECT_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <string>
#include <ctime>

struct SearchEntry
{
    string term;
    time_t timestamp;

    SearchEntry(const  string& t, time_t ts);
};

class HistoryObject {
public:
    HistoryObject() {}
    HistoryObject(const  string& filename);
    ~HistoryObject();

    void addSearchTerm(const  string& term);
    vector< string> getTop5Searches() const;
    void printSearchHistory() const;

private:
    list<SearchEntry> searchHistory;
    unordered_map< string, int> searchCount;
    string filename;

    void saveToFile() const;
    void loadFromFile();
};

#endif // HISTORYOBJECT_H


