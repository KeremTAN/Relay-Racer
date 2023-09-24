#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
class MyClass {
public:
    MyClass(){};
    void MyMethod(int& i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(mutex_);
        std::cout << i <<". MyMethod is running" << std::endl;
    }
    void operator()()
    {
        for (int i = 0; i < 5; ++i)
        {
            MyMethod(i);
        }
    }
private:
std::mutex mutex_;
};

int main() {
    std::vector<MyClass> objects(3); // 2 tane MyClass nesnesi içeren bir vektör oluşturun
    std::vector<std::thread> threads;

    threads.reserve(3);
    for (int i = 0; i < objects.size(); ++i) {
        threads.emplace_back([&objects, i]() { objects[i](); }); // İş parçacığını vektöre ekleyin
    }

    // İş parçacıklarının çalışmasını bekleyin
    for (std::thread& t : threads) {
        t.join();
    }

    return 0;
}
