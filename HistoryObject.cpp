#include "HistoryObject.h"
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <mutex>
using namespace std;

SearchEntry::SearchEntry(const  string& t, time_t ts)
    : term(t), timestamp(ts) {}

HistoryObject::HistoryObject(const  string& filename)
    : filename(filename)
{
    loadFromFile();
}

HistoryObject::~HistoryObject()
{
    saveToFile();
}

void HistoryObject::addSearchTerm(const  string& term)
{
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    searchHistory.emplace_front(term, now);
    searchCount[term]++;
}



vector<string> HistoryObject::getTop5Searches() const
{
    // Create a vector of pairs sorted by search count in descending order
    vector<pair<string, int>> countVector(searchCount.begin(), searchCount.end());
    sort(countVector.begin(), countVector.end(), [](const auto& a, const auto& b) {
        return b.second > a.second;
        });

    vector<string> top5;

    // Extract the top 5 searched terms
    size_t count = 0;
    for (const auto& pair : countVector)
    {
        // Add the search term to the top5 vector
        top5.push_back(pair.first);

        // Increment the count of added search terms
        ++count;

        // Break loop if we've added top 5 items
        if (count >= 5)
        {
            break;
        }
    }

    return top5;
}




void HistoryObject::printSearchHistory() const
{
    static mutex timeMutex; // Define a static mutex

    for (const auto& entry : searchHistory)
    {
        lock_guard<mutex> lock(timeMutex); // Lock the mutex for this scope
        tm localTime;
        localtime_s(&localTime, &entry.timestamp);
        char buffer[80]; // Buffer to store formatted time
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
        cout << entry.term << " at " << buffer << endl;
    }
}

void HistoryObject::saveToFile() const
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cerr << "Failed to open file for writing: " << filename << endl;
        return;
    }

    for (const auto& entry : searchHistory)
    {
        tm localTime;
        localtime_s(&localTime, &entry.timestamp);
        char buffer[80]; // Buffer to store formatted time
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
        outFile << entry.term << "," << buffer << endl; // Write term, time, and date
    }
}






void HistoryObject::loadFromFile()
{
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        cerr << "Failed to open file for reading: " << filename << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        istringstream iss(line);
        string term;
        time_t timestamp;

        if (getline(iss, term, ',') && (iss >> timestamp))
        {
            searchHistory.emplace_back(term, timestamp);
            searchCount[term]++;
        }
    }
}

