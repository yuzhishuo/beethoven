#include <iostream>
#include <string>
#include <fstream>

#include <n-gram.h>

using namespace std;
using namespace beethoven;

#ifdef NDEBUG
    constexpr auto config_path = "../example/profile.config";
#else
    constexpr auto config_path = "../example/sample.config";
#endif // NDEBUG


int main(int argc, char **argv)
{
    ifstream in(config_path);
        if (!in) {
        cout << "Could not find the file named "
            << config_path << " to open!" << endl;
        return -1;
    }

    std::string in_path, out_path, language; 
    while(in>>in_path >> out_path >> language)
    {
        NGram nGram;
        ifstream _in(in_path);
        if (!_in) {
            cout << "Could not find the file named "
                << in_path << " to open!" << endl;
            return -1;
        }

        
        std::string str((std::istreambuf_iterator<char>(_in)),  
                 std::istreambuf_iterator<char>()); 
        nGram.Gen(str, 3);
        _in.close();
    }
}
