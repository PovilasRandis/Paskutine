#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    vector<string> url;
    map<string, int> zodziukiekis;        // skaiciuoja zodzius
    map<string, vector<int>> zodziuvieta; // zodziu vieta

    ifstream input("text.txt");

    string txt;

    bool singleWord = false;
    bool isInserted = false;
    string wordBuild = "";
    int lineID = 1;
    while (!input.eof())
    {
        txt = "";
        getline(input, txt);

        for (int i = 0; i < txt.length(); i++) // iesko zodzius
        {
            singleWord = false;
            if ((txt[i] >= 'A' && txt[i] <= 'Z') || (txt[i] >= 'a' && txt[i] <= 'z'))
            {
                singleWord = true;
                isInserted = false;
            }

            if (singleWord)
            {
                wordBuild += txt[i];
            }
            else if (!isInserted)
            {
                zodziukiekis[wordBuild] += 1;
                zodziuvieta[wordBuild].push_back(lineID);
                isInserted = true;
                wordBuild = "";
            }
            if ((i == txt.length() - 1) && !isInserted && singleWord)
            {
                zodziukiekis[wordBuild] += 1;
                zodziuvieta[wordBuild].push_back(lineID);
            }
        }

        for (int i = 0; i < txt.length(); i++) // randa URL
        {
            string temp;
            if (txt[i] == '.')
            {
                temp = ".";
                int forward = i + 1;
                int backward = i - 1;
                bool islink = false;
                while (forward < txt.length() && txt[forward] > 32)
                {
                    islink = true;
                    temp += txt[forward];
                    forward++;
                }
                if (islink)
                {
                    while (backward >= 0 && txt[backward] > 32)
                    {
                        temp = txt[backward] + temp;
                        backward--;
                    }
                    url.push_back(temp);
                    i = forward;
                }
            }
        }
        lineID++;
    }
    input.close();
    ofstream output1("WordsCount.txt");
    for (const auto &[key, value] : zodziukiekis)
    {
        if (value > 1)
            output1 << setw(19) << left << key << " " << value << "\n";
    }
    output1.close();

    ofstream output3("Urls.txt");
    for (const auto link : url)
    {

        output3 << link << "\n";
    }
    output3.close();

    ofstream output2("Table.txt");
    output2 << setw(19) << left << "Word:"
            << "|  ";
    for (int i = 1; i < lineID; i++)
    {
        output2 << setw(3) << left << i << "|  ";
    }
    output2 << "\n";
    for (const auto &[key, value] : zodziuvieta)
    {
        if (value.size() > 1)
        {
            output2 << setw(19) << left << key << "|";
            for (int i = 1; i < lineID; i++)
            {
                bool exist = false;
                for (int a = 0; a < value.size(); a++)
                {
                    if (value[a] == i)
                    {
                        exist = true;
                        break;
                    }
                }
                output2 << (exist ? "  *  |" : "     |");
            }
            output2 << "\n";
        }
    }
    output2.close();

    return 0;
}