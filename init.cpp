#include <btd.hpp>

using node::NodeContext;

extern ArgsManager gArgs;

static std::optional<util::SignalInterrupt> g_shutdown;

void InitContext(NodeContext& node) {
    assert(!g_shutdown);
    g_shutdown.emplace();
    std::cout << "InitContext 执行，初始化 g_shutdown 和 node.args" << std::endl;
    node.args = &gArgs;
}