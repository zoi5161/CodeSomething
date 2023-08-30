#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool availableAccount(char user[])
{
    char userClone[20];
    ifstream fin("account.bin", ios::binary);
    fin.seekg(0, ios::beg);
    while(!fin.eof())
    {
        fin.read(userClone, 20);
        if(strcmp(userClone, user) == 0)
            return true;
    }
    fin.close();
    return false;
}

void createAccount(char user[], char pass[])
{
    ofstream fout("account.bin", ios::binary);
    fout.seekp(0, ios::end);
    fout.write(user, 20);
    fout.write(pass, 20);
    fout.close();
}

int main()
{
    char user[20], pass[20];
    cin >> user;
    cin >> pass;
    // if(availableAccount(user))
    //     cout << "Haven !" << endl;
    // else
    // {
        cout << "Done" << endl;
        createAccount(user, pass);
    // }
    return 0;
}