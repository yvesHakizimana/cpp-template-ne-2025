#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace csv {
    using Record = vector<string>;
    using Table  = vector<Record>;

    // Read the CSV from the moemory
    
    inline Table read(const string& fileName, char delimiter = ','){
        Table data;
        ifstream file(fileName);
        if(!file.is_open()) return {};

        string line;
        while(getline(file, line)){
            Record row;
            istringstream ss(line);
            string field;
            while(getline(ss, field, delimiter)){
                row.push_back(field);
            }
            data.push_back(move(row));
        }
        return data;
    }


    inline bool write(const string& fileName, const Table& data, char delimiter = ','){
        ofstream file(fileName);
        if(!file.is_open()) return false;

        for (const auto& row: data){
            for(size_t i = 0; i < row.size(); ++i){
                file << row[i];
                if (i < row.size() - 1) file << delimiter;
            }
            file << "\n";
        }
        return true;
    }


    inline bool append(const string& fileName, const Record& record, char delimiter = ','){
        ofstream file(fileName);
        if(!file.is_open()) return false;

        for (size_t i = 0; i < record.size(); ++i){
            file << record[i];
            if (i < record.size() - 1) file << delimiter;
        }
        file << "\n";
        return true;
    }
}
