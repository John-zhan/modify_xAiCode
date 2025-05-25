#ifndef UTIL_SIGNALINTERRUPT_HPP
#define UTIL_SIGNALINTERRUPT_HPP

#include <iostream>
#include <mutex>

namespace util {
    class SignalInterrupt {
    public:
        SignalInterrupt() : m_flag(false) {
            std::cout << "SignalInterrupt 构造完成" << std::endl;
        }
        explicit operator bool() const {
            std::cout << "SignalInterrupt::operator bool 被调用" << std::endl;
            return m_flag.load();
        }
        bool operator()() {
            std::cout << "SignalInterrupt::operator() 被调用" << std::endl;
            return m_flag.exchange(true);
        }
        bool reset() {
            std::cout << "SignalInterrupt::reset 被调用" << std::endl;
            return m_flag.exchange(false);
        }
        bool wait() {
            std::cout << "SignalInterrupt::wait 被调用" << std::endl;
            std::unique_lock<std::mutex> lock(m_mutex);
            m_cv.wait(lock, [this] { return m_flag.load(); });
            return true;
        }
    private:
        std::atomic<bool> m_flag;
        std::mutex m_mutex;
        std::condition_variable m_cv;
    };
}

#endif