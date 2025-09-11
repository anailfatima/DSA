#include <iostream>
#include <string>
#include "Red_Black_Tree.h"

using namespace std;

int main()
{
    versiontracker tracker;
    Red_Black_Tree treeobj;
    CommitQueue queueobj(10,tracker);

    int com;
    while (true)
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. commit\n";
        cout << "2. log\n";
        cout << "3. queue-commit\n";
        cout << "4. push-queue\n";
        cout << "5. priority-versions\n";
        cout << "6. version-heap-view\n";
        cout << "7. exit\n";
        cout << "===========================\n";
        cout << "Enter choice: ";
        cin >> com;
        cin.ignore();

        if (com == 1)
        {
            if (com == 1)
            {
                string commitMessage;
                cout << "Enter commit message: ";
                getline(cin, commitMessage);

                string timestamp = getCurrentTimestamp();
                treeobj.add_Commit(commitMessage, timestamp);

                string filename = extractFileName(commitMessage);
                tracker.insertVersion(filename, commitMessage, timestamp);

                cout << "Commit added successfully!\n";
            }
        }
        else if (com == 2)
        {
            cout << "\nCommit History:\n";
            treeobj.log();
        }
        else if (com == 3)
        {
            if (treeobj.treeEmpty())
            {
                cout << "No commit exists yet. Please commit at least once before queuing.\n";
                continue;
            }

            string commitMessage;
            cout << "Enter commit message: ";
            getline(cin, commitMessage);
            string timestamp = getCurrentTimestamp();

            queueobj.queueCommit(commitMessage, timestamp);
            cout << "Commit queued successfully.\n";
        }
        else if (com == 4)
        {
            cout << "Pushing all queued commits...\n";
            queueobj.pushQueue(treeobj, tracker);
            cout << "All queued commits pushed successfully.\n";
        }
        else if (com == 5)
        {
            string filename;
            cout << "Enter filename to view versions: ";
            getline(cin, filename);
            tracker.displayFileVersions(filename);
        }
        else if (com == 6)
        {
            tracker.viewAllVersionHeaps();
        }
        else if (com == 7)
        {
            cout << "Exiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
