#pragma once

namespace app::player {
    class PlayerController : public hh::fnd::ReferencedObject {
    public:
        struct Unk1 {
            csl::math::Vector4 unk3;
            csl::math::Quaternion unk4;
            csl::math::Vector4 unk5;
            csl::math::Vector4 unk6;
            csl::math::Vector4 unk7;
            csl::math::Vector4 unk8;
            uint32_t unk9;
            GOCPlayerKinematicParams::GroundInfo groundInfo;
            uint32_t unk10;

            Unk1();
        };

        csl::math::Vector4 vector20;
        hh::fnd::Reference<PlayerCollision> playerCollision;
        csl::ut::MoveArray<void*> MoveCommands;
        Unk1 unk60;//60
        Unk1 unk120;//120
        uint8_t byte1E0;
        csl::ut::InplaceMoveArray<void*, 1> unk1E8;
        uint64_t qword210;
        uint64_t qword218;


        CREATE_FUNC(PlayerController, PlayerCollision* playerCollision);
    };
}
