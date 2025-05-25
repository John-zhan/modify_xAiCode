#include <node/context.hpp>

namespace node {
    namespace {
        class NodeImpl : public interfaces::Node {
        public:
            explicit NodeImpl(NodeContext& context) : m_context(nullptr) {
                std::cout << "NodeImpl 构造完成" << std::endl;
                setContext(&context);
            }
            node::NodeContext* context() override {
                std::cout << "NodeImpl::context 被调用" << std::endl;
                return m_context;
            }
            void setContext(node::NodeContext* context) override {
                std::cout << "NodeImpl::setContext 被调用" << std::endl;
                m_context = context;
            }
            NodeContext* m_context{ nullptr };
        };

        class ChainImpl : public interfaces::Chain {
        public:
            explicit ChainImpl(NodeContext& node) : m_node(node) {
                std::cout << "ChainImpl 构造完成" << std::endl;
            }
            node::NodeContext* context() override {
                std::cout << "ChainImpl::context 被调用" << std::endl;
                return &m_node;
            }
            NodeContext& m_node;
        };

        class MinerImpl : public interfaces::Mining {
        public:
            explicit MinerImpl(NodeContext& node) : m_node(node) {
                std::cout << "MinerImpl 构造完成" << std::endl;
            }
            NodeContext& m_node;
        };
    }
}

namespace interfaces {
    std::unique_ptr<Node> MakeNode(node::NodeContext& context) {
        std::cout << "MakeNode 创建 NodeImpl" << std::endl;
        return std::make_unique<node::NodeImpl>(context);
    }
    std::unique_ptr<Chain> MakeChain(node::NodeContext& context) {
        std::cout << "MakeChain 创建 ChainImpl" << std::endl;
        return std::make_unique<node::ChainImpl>(context);
    }
    std::unique_ptr<Mining> MakeMining(node::NodeContext& context) {
        std::cout << "MakeMining 创建 MinerImpl" << std::endl;
        return std::make_unique<node::MinerImpl>(context);
    }
}