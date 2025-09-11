#include "redblacktree.h"       // NOOR & ANAIL file
#include "myStack_Management.h" // NAUMANA file
#include "BST.h"                // FATIMA file
#include "LL.h"                 // RITAJ file

int main()
{
    versiontracker tracker;
    Red_Black_Tree treeobj;
    CommitQueue queueobj(10, tracker);
    RollbackSystem rollbackSys;
    BST bst;
    LLnode *initialCommit = new LLnode(1);
    BranchManager bm(initialCommit);

    string name;
    int com;

    while (true)
    {
        cout << "\n========== MENU ==========\n";
        cout << "Commit System:\n";
        cout << " 1.  Commit\n";
        cout << " 2.  Log History\n";
        cout << " 3.  Queue Commit\n";
        cout << " 4.  Push Queue\n";
        cout << "\nRollback System:\n";
        cout << " 5.  Rollback\n";
        cout << " 6.  View Rollback Stack\n";
        cout << "\nBranching System:\n";
        cout << " 7.  Create Branch\n";
        cout << " 8.  Checkout Branch\n";
        cout << " 9.  List Branches\n";
        cout << "10.  Delete Branch\n";
        cout << "\nVersion Tracking:\n";
        cout << "11.  View File Versions\n";
        cout << "12.  View All Version Heaps\n";
        cout << "\nMerge System:\n";
        cout << "13.  Simulate Merge Trees\n";
        cout << "14.  View Merge Conflicts\n";
        cout << "15.  Finalize Merge\n";
        cout << "\n16.  Exit\n";
        cout << "===========================\n";
        cout << "Enter choice = ";
        cin >> com;
        cin.ignore();

        if (com == 1)
        {
            string commitMessage;
            cout << "Enter commit message: ";
            getline(cin, commitMessage);
            string timestamp = getCurrentTimestamp();
            treeobj.add_Commit(commitMessage, timestamp);
            rollbackSys.onCommitAdded(commitMessage, timestamp);
            string filename = extractFileName(commitMessage);
            tracker.insertVersion(filename, commitMessage, timestamp);
            cout << "Commit added successfully!\n";
        }
        else if (com == 2)
        {
            cout << "Commit History:\n";
            treeobj.log();
        }
        else if (com == 3)
        {
            if (treeobj.treeEmpty())
            {
                cout << "No commits yet. Please commit at least once before using queue.\n";
                continue;
            }
            string commitMessage;
            cout << "Enter commit message: ";
            getline(cin, commitMessage);
            string timestamp = getCurrentTimestamp();
            queueobj.queueCommit(commitMessage, timestamp);
            cout << "Commit queued successfully\n";
        }
        else if (com == 4)
        {
            cout << "Pushing queued commits...\n";
            queueobj.pushQueue(treeobj, tracker);
            cout << "All queued commits pushed.\n";
        }
        else if (com == 5)
        {
            rollbackSys.rollback();
        }
        else if (com == 6)
        {
            rollbackSys.viewRollbackStack();
        }
        else if (com == 7)
        {
            cout << "Enter new branch name: ";
            getline(cin, name);
            bm.createBranch(name);
        }
        else if (com == 8)
        {
            cout << "Enter branch to switch to: ";
            getline(cin, name);
            bm.checkout(name);
        }
        else if (com == 9)
        {
            bm.listBranches();
        }
        else if (com == 10)
        {
            cout << "Enter branch name to delete: ";
            getline(cin, name);
            bm.deleteBranch(name);
        }
        else if (com == 11)
        {
            string filename;
            cout << "Enter filename to view versions: ";
            getline(cin, filename);
            tracker.displayFileVersions(filename);
        }
        else if (com == 12)
        {
            tracker.viewAllVersionHeaps();
        }
        else if (com == 13)
        {
            cout << "\nSimulating two trees for merge...\n";
            Node *BranchA = new Node{70, new Node{10, nullptr, nullptr}, new Node{30, nullptr, nullptr}};
            Node *BranchB = new Node{40, new Node{70, nullptr, nullptr}, new Node{50, nullptr, nullptr}};
            bst.MergeTree(BranchA, BranchB, true);
            bst.Display();
        }
        else if (com == 14)
        {
            bst.LConflicts();
        }
        else if (com == 15)
        {
            bst.finalizeMerge();
        }
        else if (com == 16)
        {
            cout << "Exiting program...\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}