#ifndef INIT_HPP
#define INIT_HPP

#include <node/context.hpp>

namespace node {
    struct NodeContext;
}

using node::NodeContext;

void InitContext(NodeContext& node);

#endif