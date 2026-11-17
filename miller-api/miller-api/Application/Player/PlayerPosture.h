#pragma once

namespace app::player {
    class Player;
    class GOCPlayerKinematicParams;
    class GOCPlayerBlackboard;
    class BlackboardStatus;
    class PlayerSpeedParam;
    class PlayerExtraParam;
    class PlayerGrindSpeedParam;

    class PlayerPostureContext : public hh::fnd::BaseObject {
    public:
        Player* playerObject;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        BlackboardStatus* blackboardStatus;
        float dword30 { 360.0f };
        uint8_t byte34;
        uint64_t unk1; // dummies i don't know what is there
        uint64_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        uint64_t unk8;
        PlayerSpeedParam speedParam;
        PlayerExtraParam extraParam;
        PlayerGrindSpeedParam grindSpeedParam;
        uint8_t byte90;

        Player* GetPlayerObject() const;
        PlayerPostureContext(csl::fnd::IAllocator* allocator, app::player::Player* playerObject);
    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {
    public:
        struct Unk1 {
            GOCPlayerKinematicParams::Unk4 unk1;
            csl::math::Vector4 vector50;
            csl::math::Vector4 vector60;
            csl::math::Vector4 vector70;
            csl::math::Vector4 vector80;
            csl::math::Vector4 vector90;
            csl::math::Vector4 vectorA0;
            csl::math::Vector4 vectorB0;
        };
    };
}