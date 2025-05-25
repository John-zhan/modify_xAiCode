#ifndef NODE_CONTEXT_HPP
#define NODE_CONTEXT_HPP

#include <interfaces/init.hpp>
#include <common/args.hpp>

namespace node {
    struct NodeContext {
        interfaces::Init* init{ nullptr };
        ArgsManager* args{ nullptr };
    };
}

namespace interfaces {
    std::unique_ptr<Node> MakeNode(node::NodeContext& context);
    std::unique_ptr<Chain> MakeChain(node::NodeContext& context);
    std::unique_ptr<Mining> MakeMining(node::NodeContext& context);
}

#endif