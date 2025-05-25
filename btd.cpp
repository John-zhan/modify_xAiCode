#include <btd.hpp>

using node::NodeContext;

// extern void InitContext(NodeContext& node);

namespace init {
    namespace {
        class BitcoindInit : public interfaces::Init {
        public:
            BitcoindInit(NodeContext& node) : m_node(node) {
                cout << "BitcoindInit 构造完成" << endl;
                InitContext(m_node);
                m_node.init = this;
            }
            std::unique_ptr<interfaces::Node> makeNode() override {
                cout << "BitcoindInit::makeNode 被调用" << endl;
                return interfaces::MakeNode(m_node);
            }
            std::unique_ptr<interfaces::Chain> makeChain() override {
                cout << "BitcoindInit::makeChain 被调用" << endl;
                return interfaces::MakeChain(m_node);
            }
            std::unique_ptr<interfaces::Mining> makeMining() override {
                cout << "BitcoindInit::makeMining 被调用" << endl;
                return interfaces::MakeMining(m_node);
            }
            NodeContext& m_node;
        };
    }
}

namespace interfaces {
    std::unique_ptr<Init> MakeNodeInit(NodeContext& node, int argc, char* argv[], int& exit_status) {
        cout << "MakeNodeInit 创建 BitcoindInit" << endl;
        return std::make_unique<init::BitcoindInit>(node);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "开始执行 main 函数" << endl;
    NodeContext node;
    cout << "创建 NodeContext" << endl;
    auto init = std::make_unique<init::BitcoindInit>(node);
    cout << "创建 BitcoindInit" << endl;
    auto node_interface = init->makeNode();
    cout << "创建 Node 接口" << endl;
    auto chain_interface = init->makeChain();
    cout << "创建 Chain 接口" << endl;
    auto mining_interface = init->makeMining();
    cout << "创建 Mining 接口" << endl;
    cout << "Node 上下文地址: " << node_interface->context() << endl;
    cout << "Chain 上下文地址: " << chain_interface->context() << endl;
    cout << "main 函数执行完成" << endl;
    return 0;
}