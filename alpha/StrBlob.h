/***************************
12.1
define a class to test samrt pointer.
***************************/

#include <memory>
#include <vector>
#include <string>

class StrBlob; // forward declaration

/************************************
class StrBlobPtr
************************************/
class StrBlobPtr
{
public:
    StrBlobPtr() :curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0);
    std::string& deref() const;
    StrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
}; 

/************************************
class StrBlob
************************************/
class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    const std::string &front() const;
    std::string &front();
    const std::string &back() const;
    std::string &back();

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

/************************************
StrBlob inline functions.
************************************/
inline StrBlobPtr StrBlob::begin() 
{ 
    return StrBlobPtr(*this); 
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}