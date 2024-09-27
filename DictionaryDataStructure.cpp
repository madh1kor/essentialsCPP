#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// Template class for Dictionary
template<typename K, typename V>
class Dictionary {
private:
    vector<pair<K, V>> entries;

public:


 
    // Method to add key-value pairs to the dictionary
    void add(const K& key, const V& value) {
        entries.push_back(make_pair(key, value));
    }

    // Method to get the value for a given key
    V getValue(const K& key) const {
        for (const auto& entry : entries) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        throw runtime_error("Key not found");
    }
    // Overload the << operator to print the entire dictionary
    friend ostream& operator<<(ostream& os, const Dictionary& dict) {
        for (const auto& entry : dict.entries) {
            os << entry.first << " => " << entry.second << endl;
        }
        return os;
    }

};


    

int main() {
    Dictionary<string,string> mapObj;
    mapObj.add("blr","Bangaluru");
    mapObj.add("chn","Chennai");
    mapObj.add("hyd","Hyderabad");
    std::cout<<mapObj.getValue("blr")<<std::endl;
    std::cout<<mapObj; 
/*
Expected Output
blr => Bangaluru
chn => Chennai
hyd => Hyderabad
*/

    return 0;
}
