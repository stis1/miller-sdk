#pragma once

namespace app::physics {
    class GOCMoveSphereColliderQuery;
}

namespace app::player {
    class StatePluginCollision : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginCollision";

        virtual unsigned int GetNameHash();
        virtual void AddCallback();
        virtual void RemoveCallback();
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime);
        virtual bool ProcessMessage(hh::fnd::Message& message);

        void SetTypeAndRadius(unsigned char type, float radius);
    };
}
