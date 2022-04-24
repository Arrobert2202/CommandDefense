#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

class Compare
{
  public:
    bool operator()(std::pair<std::string, int> const& a, std::pair<std::string, int> const& b)
    {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};

int main()
{
    std::ifstream input("input.txt");
    std::string prop;
    std::getline(input, prop);
    std::string sep(" ,.?!");
    int foundfirst = prop.find_first_of(sep);
    int lastfound  = 0;
    std::map<std::string, int> count;
    while (foundfirst!=std::string::npos)
    {
        if (foundfirst!=lastfound)
        {
            std::string word = prop.substr(lastfound, foundfirst - lastfound);
            for (auto& i :word)
            {
                if (i >= 'A' && i <= 'Z')
                {
                    i = i - ('A' - 'a');  
                }
            }
            count[word]++;
        }
        lastfound = foundfirst + 1;
        foundfirst = prop.find_first_of(sep,lastfound);
    }
    /*for (auto const &pair:count)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }*/

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> finalqueue;
    for (auto const& x : count)
    {
        finalqueue.push(make_pair(x.first,x.second));
    }
    while (finalqueue.size())
    {
        std::pair<std::string, int> aux = finalqueue.top();
        std::cout << aux.first << "=>" << aux.second << std::endl;
        finalqueue.pop();
    }

    return 0;
}