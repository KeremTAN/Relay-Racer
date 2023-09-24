#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <shared_mutex>

struct Config
{
    std::shared_mutex mutex_;
};

class MyClass {
public:
    static Config* m_config;
    
    MyClass(){};
    void MyMethod(int& i) {
        std::cout << i <<". MyMethod is running" << std::endl;
    }
    void operator()()
    {
        for (int i = 0; i < 400; ++i)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::unique_lock<std::shared_mutex> lock(m_config->mutex_); 
            MyMethod(i);
        }
    }
};

Config* MyClass::m_config = nullptr;

int main() {
    std::vector<MyClass> objects(400); 
    std::vector<std::thread> threads;
    Config c;
    MyClass::m_config = &c;

    std::cout<<sizeof(MyClass)<<std::endl;

    threads.reserve(400);
    for (int i = 0; i < objects.size(); ++i) {
        threads.emplace_back([&objects, i]() { objects[i](); }); 
    }

    for (std::thread& t : threads) {
        t.join();
    }

    return 0;
}
