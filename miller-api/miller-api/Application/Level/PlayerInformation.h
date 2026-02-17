#pragma once

namespace app::level {
    class PlayerInformation : public hh::fnd::BaseObject {
    public:
        struct Unk2 {
            hh::fnd::Handle<hh::fnd::Messenger> unk1;
            uint8_t unk2;
            uint32_t unk2a;
            hh::fnd::WorldPosition worldPos;
            uint64_t unk3;
            uint64_t unk4;
            float unk5;
            float unk6;
            float unk7;
            float unk8;
            uint32_t unk9;
            uint32_t unk10;
            uint32_t unk11;
            uint32_t unk12;
            uint32_t unk13;
            csl::math::Vector3 unk14;
            csl::math::Vector3 unk15;
            csl::math::Vector3 unk16;
            uint32_t unk17;

            Unk2();
        };

        struct Unk4 {
            uint32_t unk1;
            uint32_t unk2;
        };
        
        //_ns = not sure
        std::optional<hh::fnd::Handle<app::player::Player>> playerObject;
        std::optional<csl::math::Vector3> position;
        std::optional<csl::math::Quaternion> rotation;
        std::optional<float> Speed;
        std::optional<csl::math::Vector3> vector470;
        std::optional<csl::math::Vector3> vector490;
        std::optional<csl::math::Vector3> vector4B0;
        std::optional<csl::math::Vector3> vector4D0;
        std::optional<csl::math::Vector3> vector4F0;
        std::optional<csl::math::Vector3> vector4110;
        std::optional<csl::math::Vector3> vector4130;
        std::optional<csl::math::Vector3> vector4150;
        std::optional<csl::math::Vector3> vector4170;
        std::optional<csl::math::Vector3> vector4190;
        std::optional<csl::math::Vector3> vector41B0;
        std::optional<csl::math::Vector3> vector41D0;
        std::optional<csl::math::Vector3> vector41F0;
        std::optional<csl::math::Vector3> vector4210;
        std::optional<csl::math::Vector3> vector4230;
        std::optional<uint8_t> byte250;
        std::optional<csl::math::Vector2> leftStickInput;
        std::optional<csl::math::Vector2> rightStickInput;
        std::optional<uint32_t> currentBoostGauge;
        std::optional<uint8_t> byte274;
        std::optional<float> stamina;
        std::optional<float> dword280;
        std::optional<uint8_t> byte288;
        std::optional<uint8_t> byte28A;
        std::optional<uint32_t> maxBoostGauge;
        std::optional<uint32_t> dword294;
        std::optional<uint32_t> dword29C;
        std::optional<uint8_t> byte2A4;
        std::optional<bool> isGrounded;
        std::optional<uint8_t> byte2A8;
        std::optional<uint8_t> byte2AA;
        std::optional<csl::math::Vector3> groundNormal;
        std::optional<float> altitude;
        std::optional<csl::math::Vector3> vector42E0;
        std::optional<uint32_t> dword300;
        std::optional<uint32_t> dword308;
        std::optional<uint8_t> isBoosting_ns;
        std::optional<uint8_t> grinding_ns; // maybe Grinding
        std::optional<uint8_t> grinding2_ns; // maybe grinding but not on rail
        std::optional<bool> homing;
        std::optional<bool> inJump;
        std::optional<bool> inDoubleJump;
        std::optional<uint8_t> falling;
        std::optional<uint8_t> byte31E;
        std::optional<uint8_t> byte320;
        std::optional<uint8_t> byte322;
        std::optional<uint8_t> byte324;
        std::optional<uint8_t> byte326;
        std::optional<uint8_t> byte328;
        std::optional<uint8_t> byte32A;
        std::optional<uint8_t> byte32C;
        std::optional<bool> airBoost; // air boosting?
        std::optional<bool> stomping; // stomping?
        std::optional<uint8_t> byte332;
        std::optional<uint8_t> byte334;
        std::optional<uint8_t> byte336;
        std::optional<bool> dAmoeba; // doom amoeba 
        std::optional<bool> dAmoeba_jump; // amoeba jump?
        std::optional<uint8_t> byte33C;
        std::optional<uint8_t> byte33E;
        std::optional<uint8_t> byte340;
        std::optional<uint8_t> byte342;
        std::optional<bool> dBlow_Aim; // doom blast aim
        std::optional<uint8_t> byte346;
        std::optional<uint8_t> byte348;
        std::optional<bool> dBlowBea; // doom blast beating up
        std::optional<uint8_t> byte34C;
        std::optional<uint8_t> byte34E;
        std::optional<bool> dBlowLaunch; // doom blast launch
        std::optional<bool> chaosSnap; // chaos snap
        std::optional<bool> dWings; // doom wings
        std::optional<bool> dWingsFly; // doom wings fly
        std::optional<uint8_t> byte358;
        std::optional<uint8_t> byte35A;
        std::optional<uint8_t> byte35C;
        std::optional<uint8_t> byte35E;
        std::optional<uint8_t> byte360;
        std::optional<uint8_t> byte362;
        std::optional<uint8_t> byte364;
        std::optional<uint8_t> byte366;
        std::optional<uint8_t> byte368;
        std::optional<bool> noInputs_afk_ns;
        std::optional<uint8_t> byte36C;
        std::optional<uint8_t> byte36E;
        std::optional<uint8_t> byte370;
        std::optional<uint8_t> byte372;
        std::optional<uint8_t> byte374;
        std::optional<bool> outOfControl_ns;
        std::optional<uint8_t> byte378;
        std::optional<uint8_t> byte37A;
        std::optional<bool> sideView_ns;
        std::optional<uint8_t> byte37E;
        std::optional<uint8_t> byte380;
        std::optional<uint32_t> currentRings;
        std::optional<uint32_t> maxRings;
        std::optional<uint8_t> byte394;
        std::optional<uint8_t> byte396;
        std::optional<uint8_t> byte398;
        std::optional<Unk2> unk3A0;
        std::optional<bool> spearCharge; // chaos spear input down
        std::optional<uint32_t> spearTargets; // chaos spear targets 
        std::optional<csl::math::Vector3> vector3470;
        std::optional<uint8_t> byte490;
        std::optional<float> float494;
        std::optional<float> float49C;
        std::optional<float> float4A4;
        std::optional<float> float4AC;
        std::optional<float> float4B4;
        std::optional<csl::math::Transform> transform44C0;
        Unk4 qword510[8];

        PlayerInformation(csl::fnd::IAllocator* allocator);
    };
}
