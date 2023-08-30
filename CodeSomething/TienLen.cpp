#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int GetType(char k)
{
    if(k == 'B' || k == 'b')
        return 0;
    else if(k == 'T' || k == 't')
        return 1;
    else if(k == 'R' || k == 'r')
        return 2;
    else if(k == 'C' || k == 'c')
        return 3;
}

int main()
{
    int a[15][15];
    string s;

    for(int i = 0; i <= 15; i++)
        for(int j = 0; j <= 15; j++)
            a[i][j] = 0;
            
    while(true)
    {
        cout << endl << "Enter: "; // Enter 0 to end
        getline(cin, s);
        vector<string> subs;
        istringstream iss(s);
        string substring;

        while(iss >> substring)
            subs.push_back(substring);

        for(int i = 0; i < subs.size(); i++)
        {
            if(subs[i] == "0")
                return 0;

            int u, v;
            if(subs[i][0] == '1' && subs[i][1] == '0')
            {
                v = GetType(subs[i][2]);
                a[v][7] = 1;
                continue;
            }
            else if(subs[i][0] == 'J' || subs[i][0] == 'j')
                u = 8;
            else if(subs[i][0] == 'Q' || subs[i][0] == 'q')
                u = 9;
            else if(subs[i][0] == 'K' || subs[i][0] == 'k')
                u = 10;
            else if(subs[i][0] == 'A' || subs[i][0] == 'a')
                u = 11;
            else if(subs[i][0] == '2')
                u = 12;
            else
            {
                string f = "";
                f += subs[i][0];
                u = stoi(f) - 3;
            }
            
            v = GetType(subs[i][1]);
            a[v][u] = 1;
        }

        int k = 3;
        for(int i = 0; i <= 9; i++)
        {
            int l = 0;
            for(int j = 0; j <= 56; j++)
            {
                if(i == 0)
                {
                    if(j % 4 == 0 && j > 0)
                        cout << '|';
                    else if(j % 4 == 2 && j > 4)
                    {
                        if(k == 11)
                            cout << 'J';
                        else if(k == 12)
                            cout << 'Q';
                        else if(k == 13)
                            cout << 'K';
                        else if(k == 14)
                            cout << 'A';
                        else if(k == 15)
                            cout << 2;
                        else
                            cout << k;
                        k++;
                    }
                    else
                        cout << ' ';
                }
                else
                {
                    if(i % 2 != 0)
                    {
                        if(j % 4 == 1 && j != 33)
                            cout << "---";
                        else if(j % 4 == 1)
                            cout << "----";
                        else if(j % 4 == 0)
                            cout << ' '; 
                    }
                    else
                    {

                        if(j % 4 == 0 && j > 0 && j != 36)
                            cout << '|';
                        else if(j % 4 == 0 && j > 0)
                            cout << " |";
                        else
                        {
                            if(j == 2)
                            {
                                if(i/2 - 1 == 0)
                                    cout << "♠";
                                else if(i/2 - 1 == 1)
                                    cout << "♣";
                                else if(i/2 - 1 == 2)
                                    cout << "♦";
                                else if(i/2 - 1 == 3)
                                    cout << "♥";
                            }
                            else if(j % 4 == 2 && j > 2)
                            {
                                if(a[i/2 - 1][l++])
                                    cout << 'x';
                                else
                                    cout << ' ';
                            }
                            else
                                cout << ' ';
                        }
                    }
                }
                
            }
            cout << endl;
        }
    }
    return 0;
}