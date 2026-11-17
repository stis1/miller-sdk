#pragma once

namespace app::player {
    struct HomingTargetInfo {
        hh::fnd::Handle<hh::physics::GOCCollider> target;
        bool isChaosAttack;
        uint16_t unk2a;
        uint32_t unk2b;
        hh::fnd::WorldPosition worldPos;
        uint32_t unk3;
        float radius;
        float height;
        uint32_t unk4;
        float float40;
        float float44;
        float float48;
        float float4C;
        float dashKeepSpeedTime;
        float dashOutOfControlTime;
        uint32_t dword58;
        uint32_t dword5C;
        uint32_t dword60;
        uint32_t dword64;
        csl::math::Vector4 vector70;
        csl::math::Vector4 vector80;
        csl::math::Vector4 vector90;
        uint32_t unk9;
    };
}
