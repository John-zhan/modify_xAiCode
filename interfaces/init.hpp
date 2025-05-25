#ifndef INTERFACES_INIT_HPP
#define INTERFACES_INIT_HPP

#include <memory>
#include <iostream>
#include <common/args.hpp>

namespace node {
    struct NodeContext;
}

// 定义 interfaces 命名空间
namespace interfaces {
    class Node {
    public:
        virtual ~Node() = default;
        virtual node::NodeContext* context() { return nullptr; }
        virtual void setContext(node::NodeContext* context) {}
    };

    class Chain {
    public:
        virtual ~Chain() = default;
        virtual node::NodeContext* context() { return nullptr; }
    };

    class Mining {
    public:
        virtual ~Mining() = default;
    };

    class Init {
    public:
        virtual ~Init() = default;
        virtual std::unique_ptr<Node> makeNode() { return nullptr; }
        virtual std::unique_ptr<Chain> makeChain() { return nullptr; }
        virtual std::unique_ptr<Mining> makeMining() { return nullptr; }
    };
}

#endif