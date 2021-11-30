#include <vector>
#include <cctype>
#include <string>
#include <functional>
#include <algorithm>
#include <memory>
#include <map>

namespace beethoven{

constexpr int __n = 3;

class NGram {

public:

    NGram(): generates(){}
    void Gen(const std::string& in, int n);

private:
    std::map<std::string, std::size_t,  std::greater<std::string>> generates; 
    std::vector<std::pair<std::string, size_t> > m_res;
};

} // ns beethoven