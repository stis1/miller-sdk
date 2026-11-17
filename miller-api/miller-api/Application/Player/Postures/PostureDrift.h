#pragma once

namespace app::player {
    class PostureDrift : public PlayerPosture {
    public:
        static constexpr uint32_t hash = 0x1B6A4FE1;
        float speed;
        float float24;
        float float28;
        float float2C;
        uint8_t byte30;
        uint8_t byte31;
        uint8_t byte32;
        bool isBoosting;
        uint8_t byte34;

        PostureDrift(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const override;
        virtual void Enter() override;
        virtual void Update(float deltaTime) override;
        virtual void UnkFunc6() override;
    };
}