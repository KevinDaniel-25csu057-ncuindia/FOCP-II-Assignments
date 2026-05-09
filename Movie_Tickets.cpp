#include <bits/stdc++.h>
using namespace std;
class MovieTicket 
{
    unordered_map<int, unordered_set<int>> bookings;

public:
    bool BOOK(int X, int Y) 
    {
        if (bookings[Y].find(X) != bookings[Y].end())

            return false;

        if (bookings[Y].size() >= 100)
            return false;
        bookings[Y].insert(X);
        
        return true;
    }
    bool CANCEL(int X, int Y) 
    {
        if (bookings[Y].find(X) == bookings[Y].end())
            return false;
        bookings[Y].erase(X);
        return true;
    }
    bool IS_BOOKED(int X, int Y) 
    {
        if (bookings[Y].find(X) != bookings[Y].end())
            return true;
        return false;
    }
    int AVAILABLE_TICKETS(int Y) 
    {
        return 100 - bookings[Y].size();
    }
};

int main() 
{
    int Q;
    cin >> Q;
    MovieTicket mt;
    while (Q--) 
    {
        string query;
        cin >> query;
        if (query == "BOOK") 
        {
            int X, Y;
            cin >> X >> Y;
            if (mt.BOOK(X, Y))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (query == "CANCEL") 
        {
            int X, Y;
            cin >> X >> Y;
            if (mt.CANCEL(X, Y))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (query == "IS_BOOKED") 
        {
            int X, Y;
            cin >> X >> Y;
            if (mt.IS_BOOKED(X, Y))
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (query == "AVAILABLE_TICKETS") 
        {
            int Y;
            cin >> Y;
            cout << mt.AVAILABLE_TICKETS(Y) << "\n";
        }
    }
    return 0;
}