#pragma once

namespace app::player {
    class PostureGrind : public PlayerPosture {
    public:
        static constexpr uint32_t hash = 0x1B94974C;
        float float20;
        uint32_t dword24;
        float float28;
        float float2C;
        float float30;
        float float34;
        float float38;
        float float3C;
        uint8_t byte40;
        csl::math::Vector4 vector50;
        csl::math::Vector4 vector60;
        csl::math::Vector4 vector70;
        csl::math::Vector4 vector80;
        float float90;
        float float94;
        uint16_t word98;

        PostureGrind(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const override;
        virtual void Enter() override;
        virtual void Update(float deltaTime) override;
        virtual void UnkFunc6() override;
    };
}