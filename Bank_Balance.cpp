#include <bits/stdc++.h>
using namespace std;
class Bank 
{
    unordered_map<int, long long> users;

public:
    bool CREATE(int X, long long Y) 
    {
        if (users.find(X) != users.end()) 
        {
            users[X] += Y;
            return false;
        }
        users[X] = Y;
        return true;
    }
    bool DEBIT(int X, long long Y) 
    {
        if (users.find(X) == users.end())
            return false;
        if (users[X] < Y)
            return false;

        users[X] -= Y;
        return true;
    }
    bool CREDIT(int X, long long Y) 
    {
        if (users.find(X) == users.end())
            return false;
        users[X] += Y;
        return true;
    }
    long long BALANCE(int X) 
    {
        if (users.find(X) == users.end())
            return -1;

        return users[X];
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bank;
    while (Q--) 
    {
        string query;
        cin >> query;
        if (query == "CREATE") 
        {
            int X;
            long long Y;
            cin >> X >> Y;
            if (bank.CREATE(X, Y))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (query == "DEBIT") 
        {
            int X;
            long long Y;
            cin >> X >> Y;
            if (bank.DEBIT(X, Y))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (query == "CREDIT") 
        {
            int X;
            long long Y;
            cin >> X >> Y;
            if (bank.CREDIT(X, Y))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (query == "BALANCE") 
        {
            int X;
            cin >> X;
            cout << bank.BALANCE(X) << "\n";
        }
    }

    return 0;
}