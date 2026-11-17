#pragma once

namespace app::player {
    class PostureJump : public PlayerPosture {
    public:
        static constexpr uint32_t hash = 0x158A54F6;
        enum class Mode : uint32_t {
            DEFAULT = 0,
            DOUBLE = 1,
            GRIND_DOUBLE = 3,
            BOUNCE = 4,
            SLIDER = 5,
            DWING = 6,
            DWING_DOUBLE = 7,
        };
        enum class Flags : uint8_t {
            SPECIFIED_SPEED,
            SPECIFIED_DIRECTION,
            SPECIFIED_GRAVITY_SIZE,
            LOCAL_JUMP = 5
        };
        struct Info {
            Mode mode{};
            float startSpeed{};
            csl::math::Vector4 startVelocity{};
            float gravitySize{};
            csl::ut::Bitset<Flags> flags{};
        };
        Info info;
        csl::math::Vector4 playerUp;
        csl::math::Vector4 vector60;
        csl::math::Vector4 vector70;
        csl::math::Vector4 vector80;
        float horizontalSpeed;
        float float94;
        uint32_t dword98;
        uint32_t dword9C;
        uint32_t dwordA0;
        uint8_t byteA4;
        PlayerPosture::Unk1 unkB0;

        PostureJump(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const override;
        virtual void Enter() override;
        virtual void Leave() override;
        virtual void Update(float deltaTime) override;
        virtual void UnkFunc6() override;
    };
}