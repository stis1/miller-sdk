#pragma once

namespace app::player
{
    class PostureDriftDash : public PlayerPosture {
    public:
        static constexpr uint32_t hash = 0x3C2DDB13;
        bool outOfControl;

        PostureDriftDash(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const override;
        virtual void Enter() override;
        virtual void Update(float deltaTime) override;
        virtual void UnkFunc6() override;
    };
}