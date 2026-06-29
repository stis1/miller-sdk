#pragma once

namespace app::player {
    class StatePluginTimeStop : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginTimeStop";

        virtual unsigned int GetNameHash();
        virtual void AddCallback(); // infected
        virtual void RemoveCallback();
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime);
        virtual bool ProcessMessage(hh::fnd::Message& message);

        void DoSmth(unsigned char type, float radius);
    };
}
