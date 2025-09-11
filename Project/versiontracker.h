#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class versiontracker
{
private:
    unordered_map<string, vector<string>> versionMap; // filename -> versions (latest at back)

public:
    // Direct add (if formatted already)
    void addVersion(const string &filename, const string &versionInfo)
    {
        versionMap[filename].push_back(versionInfo);
    }

    // Insert with commit message and timestamp
    void insertVersion(const string &filename, const string &commitMessage, const string &timestamp)
    {
        string formatted = commitMessage + " [" + timestamp + "]";
        versionMap[filename].push_back(formatted);
    }

    void displayFileVersions(const string &filename)
    {
        if (versionMap.find(filename) == versionMap.end())
        {
            cout << "No versions found for: " << filename << endl;
            return;
        }

        cout << "\nVersions of file '" << filename << "':" << endl;
        const vector<string> &versions = versionMap[filename];
        for (int i = versions.size() - 1; i >= 0; --i)
        {
            cout << "- " << versions[i] << endl;
        }
    }

    void viewAllVersionHeaps()
    {
        cout << "\n===== File Version Heaps =====" << endl;
        for (auto &pair : versionMap)
        {
            cout << pair.first << " -> [ ";
            for (int i = pair.second.size() - 1; i >= 0; --i)
            {
                cout << pair.second[i];
                if (i > 0)
                    cout << ", ";
            }
            cout << " ]" << endl;
        }
    }
};
