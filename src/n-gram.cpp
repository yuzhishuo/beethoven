#include <string>
#include <cctype>
#include <vector>
#include <iostream>
#include <cstddef>
#include <map>
#include <utility>

#include <n-gram.h>

using namespace std;
using namespace beethoven;

vector<string> generateNGrams (const string& in, 
    size_t n, 
    std::function<void (const std::string&)> callback)
{
    string new_in;

    // replace all non-alphanumeric characters with _
    // if exits series of non-alphanumeric, replace with one _
    bool is_alphanumeric = true;
    for (size_t i = 0; i < in.size(); i++)
    {
        if ( isspace(in[i]) )
        {
            if(!is_alphanumeric) continue;

            new_in += '_';
            is_alphanumeric = false;
            continue;
        }

        new_in += in[i];
        is_alphanumeric = true;
    }
    
    // generate N-Grams
    vector<string> out;
    for (size_t i = 0; i < new_in.size() - n + 1; i++)
    {
        callback(new_in.substr(i, n));
        out.push_back(new_in.substr(i, n));
    }
    return out;
}

void NGram::Gen(const std::string& in, int n)
{
        using namespace std;
        for(int i = 1; i <= n; i++)
        {
            generateNGrams(in, i, [this](const std::string & str){
                if(generates.count(str) == 0)
                {
                    generates.insert(std::make_pair(str, (size_t) 1));
                    return;
                }
                generates.at(str)++;
            });
        }
        
        std::vector<std::pair<std::string, size_t>> res;
        res.reserve(generates.size());

        for(auto& gen: generates)
        {
           res.push_back(gen);
        }

        std::sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
            if(a.second == b.second)
                return a.first < b.first;
            return  a.second > b.second;;
        });

        for(auto& gen: res)
        {
            std::cout << gen.first << " " << gen.second << std::endl;
        }
        m_res.swap(res);
    }

int N_gram(string x, string y, int n)
{
    int num_x = x.length();
    int num_y = y.length();

    int num_s = 0;
    for(int i=0; i < num_x; i++)
    {
        string sub_str = x.substr(i, n);
        if(y.find(sub_str) != string::npos)
        {
            num_s++;
        }
    }
    return num_x + num_y - 2 * num_s;
}