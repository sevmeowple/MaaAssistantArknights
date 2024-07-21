#pragma once

#include <memory>

#include "Task/AbstractTaskPlugin.h"
#include "Task/Roguelike/RoguelikeConfig.h"

namespace asst
{
    class AbstractRoguelikeTaskPlugin : public AbstractTaskPlugin
    {
    public:
        AbstractRoguelikeTaskPlugin(const AsstCallback& callback, Assistant* inst, std::string_view task_chain,
                                    std::shared_ptr<RoguelikeConfig> data);

        virtual std::optional<json::value> response_to_event(
            [[maybe_unused]] RoguelikeEvent event,
            [[maybe_unused]] const json::value& detail)
        {
            return std::nullopt;
        };

    protected:
        std::shared_ptr<RoguelikeConfig> m_config;
        std::optional<json::value>
            notify_sibling_plugins(RoguelikeEvent event, const json::value& detail = json::object());
    };
}
