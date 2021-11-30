#include <utility>
#include <vector>
#include <functional>
#include <cstddef>


/**
 * @deprecated description
 * 
 */
template<typename key, typename value>
class CustomContainer {


public:
    CustomContainer(size_t capacity = 0) {}

    void Insert(const std::pair<key, value>& value) 
    {
        m_container.push_back(value);
    }

    size_t Size() const
    {
        return m_container.size();
    }
private:
    std::vector<std::pair<key, value>> m_container;
};