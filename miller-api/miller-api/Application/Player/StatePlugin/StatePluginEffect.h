#pragma once

namespace app::player {
    class StatePluginEffect : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginEffect";
        
        uint64_t qword28;
        uint64_t qword30;
        uint64_t qword38;
        csl::fnd::IAllocator* allocator; // something interesting
        uint8_t byte48;

        StatePluginEffect(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
    };
}
