#include <common/args.hpp>
#include <util/signalinterrupt.hpp>

static std::optional<util::SignalInterrupt> g_shutdown;
ArgsManager gArgs;
