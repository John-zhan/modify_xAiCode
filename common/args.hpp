#ifndef COMMON_ARGS_HPP
#define COMMON_ARGS_HPP

#include <optional>
#include <string>

class ArgsManager {
public:
protected:
    struct Arg {
        std::string m_help_param;
        std::string m_help_text;
        unsigned int m_flags;
    };
};

#endif