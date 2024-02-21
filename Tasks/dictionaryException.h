#include <string>
#include <iostream>
#include <map>
#include <any>

template<class Key>
class not_found_exception : public std::exception
{
public:
    virtual const Key& get_key() const noexcept = 0;
};

template<class Key>
class myException : public not_found_exception<Key>
{
public:
    myException(Key keyers)
    {
        perem = keyers;
    }
    const Key& get_key() const noexcept
    {
        return perem;
    };
private:
    Key perem;
};


template<class Key, class Value>
class dictionary
{
public:
    virtual ~dictionary() = default;

    virtual const Value& get(const Key& key) const = 0;
    virtual void set(const Key& key, const Value& value) = 0;
    virtual bool is_set(const Key& key) const = 0;
};

template<class Key, class Value>
class myDictionary : public dictionary<Key,Value>
{
public:
    myDictionary() {};
    void set(const Key& key, const Value& value)
    {
        temp[key] = value;
    }
    const Value& get(const Key& key) const
    {
        try
        {
            if(temp.find(key) == temp.end())
            {
                throw myException<Key>(key);
            }
        }
        catch (const myException<Key>& ex)
        {
            std::cout << "exception with value of " << ex.get_key() << std::endl;
            throw;
        }

        return temp.at(key);
    }
    bool is_set(const Key& key) const
    {
        if(temp.find(key) == temp.end())
        {
            return false;
        }
        
        return true;
    }
private:
    // реализовывать с помощью массива долго. для простоты использую стандартный мап
    std::map<Key,Value> temp;
};


void dictionaryWithException()
{
    myDictionary<int,std::string> tempp;
    tempp.set(6,"kek");
    std::cout << tempp.get(6) << std::endl;
    std::cout << tempp.is_set(8) << std::endl;
    std::cout << tempp.get(8) << std::endl;
}