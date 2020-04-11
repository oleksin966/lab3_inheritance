
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Variable 
{
protected:
    map<string, vector<int>> marks;
    map<string, vector<int>>::iterator it;
    const vector<string>phones = { "Samsung", "Xiomi", "Huawei","Meizu" };
    vector<string>::iterator its;
    vector<int> total = { 0,0,0,0 };
};
class Phone : public Variable
{
public:
    Phone()
    {
        marks["Ivan"] = { 5,6,3,9};
        marks["Nazar"] = { 8,2,7,4};
        marks["Oleg"] = {4,5,1,3};
        marks["Natali"] = { 10,3,4,7 };
        total_print();
        title();
        print();
    }
    void title()
    {
        cout << "Poll: best smartphone." << endl;
        cout << "\tshow -> show table" << endl;
        cout << "\tadd  -> add new respondent" << endl;
        cout << "\tmark -> add new marks" << endl;
        cout << endl;
    }
    void print()
    {
        total_print();
        cout << "\t\t";
        for (auto its = phones.begin(); its != phones.end(); ++its)
        {
            cout << *its << "\t\t";
        }
        cout << endl;
        int i = 0;
        for (auto it = marks.begin(); it != marks.end(); ++it) 
        {
            i++;
            cout << i << ". " << it->first << " ";
            for (auto its = it->second.begin(); its != it->second.end(); ++its)
            {
                cout << "\t" << *its << "\t";
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "TOTAL:\t\t";
        for (size_t i = 0; i < total.size(); ++i) 
        {
            cout<<total[i]<< "\t\t";
        }
        cout << endl;
        cout << "BEST PHONE:\t"<<phones[best_phone()]<<endl;
    }

    void add_respondent()
    {
        string name;
        cout << "name of new respondent: ";
        cin >> name;
        marks.insert(pair<string, vector<int>>(name, { 0,0,0,0}));
        cout << "the name was successfully added to the database "<<endl;
    }

    int best_phone()
    {
        int max = total[0],imax = 0;
        for (size_t i = 1; i < total.size(); ++i) 
        {
            if (max < total[i])
            {
                imax = i;
            }
        }
        return imax;
    }

    void add_marks()
    {
        int id, news, pos;
        int i = 0;
        for (auto it = marks.begin(); it != marks.end(); ++it) 
        {
            i++;
            cout <<i<<". " <<it->first << endl;
        }
        i = 0;
        cout << "Select name: ";
        cin >> id;
        for (auto it = phones.begin(); it != phones.end(); ++it)
        {
            i++;
            cout <<i<<". " <<*it<< endl;
        }
        i = 0;
        cout << "Select phone brand: ";
        cin >> pos;
        cout << "New mark(more than 0 and less than 10): ";
        cin >> news;
        if (news > 10 || news < 0)
        {
            cout<<"the mark should be greater than 0 and less than 10!!!"<<endl;
        }
        else
        {
            for (auto& pair : marks)
            {
                i++;
                if (i == id) {
                    for (size_t i = 0; i < pair.second.size(); ++i) {
                        pair.second[pos - 1] = news;
                    }
                }
            }
            cout << "the mark was successfully added to the database " << endl;
        }
    }
    void total_print()
    {
        for (auto& pair : marks)
        {
            for (size_t i = 0; i < pair.second.size(); ++i) {
                total[i] = 0;
            }
        }
        for (auto& pair : marks)
        {
            for (size_t i = 0; i < pair.second.size(); ++i) {
                total[i] = total[i] += pair.second[i];
            }
        }

    }
};
int main()
{
    Phone p;
    string cmd;
    while (true)
    {
        cout << "cmd>";
        cin >> cmd;
        if (cmd == "show")
        {
            p.print();
        }
        if (cmd == "add")
        {
            p.add_respondent();
        }
        if (cmd == "mark")
        {
            p.add_marks();
        }
        if (cmd == "clear")
        {
            system("cls");
        }
    };

    return 0;
}