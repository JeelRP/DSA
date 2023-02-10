#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    map<string, int> m;

    // insertion
    // 1
    pair<string, int> p = make_pair("Jeel", 3);
    m.insert(p);

    // 2
    pair<string, int> p2("Patel", 2);
    m.insert(p2);

    // 3
    m["Rajesh"] = 1;

    cout << m["Rajesh"] << endl;
    cout << m.at("Jeel") << endl;

    cout << m["unknown"] << endl;
    cout << m.at("unknown") << endl;

    // SIZE
    cout << m.size() << endl;

    // To check presence
    cout << m.count("bro") << endl;
    cout << m.count("Jeel") << endl;

    // erase
    // m.erase("Jeel");
    cout << m.size() << endl;

    // iterator
    map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}