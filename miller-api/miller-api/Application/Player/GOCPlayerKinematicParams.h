#pragma once

namespace app::player {
    class GOCPlayerKinematicParams : public hh::game::GOComponent {
    public:
        struct GroundInfo {
            enum class Flags : uint8_t {
                HAS_GROUND,
                GROUNDED,
            };
            // enum class LayerType : uint32_t {
            //     NONE = 0,
            //     SOLID = 1,
            //     LIQUID = 2,
            //     THROUGH = 3,
            //     CAMERA = 4,
            //     SOLID_ONEWAY = 5,
            //     SOLID_THROUGH = 6,
            //     SOLID_TINY = 7,
            //     SOLID_DETAIL = 8,
            //     SOLID_MESH = 9,
            //     LAND = 10,
            //     RAYBLOCK = 11,
            //     EVENT = 12,
            //     RAYBLOCK_ENEMY = 13,
            //     ENEMY_BODY = 14,
            //     PLAYER = 15,
            //     ENEMY = 16,
            //     OBJECT_BODY = 17,
            //     GIMMICK = 18,
            //     DYNAMICS = 19,
            //     RING = 20,
            //     CHARACTER_CONTROL = 21,
            //     PLAYER_ONLY = 22,
            //     DYNAMICS_THROUGH = 23,
            //     ENEMY_ONLY = 24,
            //     SENSOR_PLAYER = 25,
            //     SENSOR_RING = 26,
            //     SENSOR_GIMMICK = 27,
            //     SENSOR_LAND = 28,
            //     SENSOR_ALL = 29,
            //     SENSOR_PLAYER_ENEMY = 30,
            //     RESERVED31 = 31,
            // };
            enum class Attribute : uint32_t {
                NOT_STAND = 0,
                BREAKABLE = 1,
                SLIDER = 2,
                UNSUPPORTED = 3,
                REFLECT_LASER = 4,
                LOOP = 5,
                WALL = 6,
                SLIDE = 7,
                PARKOUR = 8,
                DECELERATE = 9,
                MOVABLE = 10,
                AMOEBA = 11,
                PRESS_DEAD = 12,
                RAYBLOCK = 13,
                WALLJUMP = 14,
                PUSH_BOX = 15,
                STRIDER_FLOOR = 16,
                GIANT_TOWER = 17,
                LOCALJUMP = 18,
                TEST_GRASS = 19,
                TEST_WATER = 20,
            };
            csl::math::Vector3 unk1;
            csl::math::Vector3 groundNormal;
            float altitude;
            uint32_t dword24; // might be layertype not sure
            csl::ut::Bitset<Attribute> attributes;
            hh::fnd::Handle<hh::physics::GOCMeshCollider> gocMeshCollider;
            uint32_t dword30;
            uint8_t byte34;
            csl::ut::Bitset<Flags> flags;

            GroundInfo();
        };
        struct Unk2 {
            uint32_t unk1;
            hh::fnd::HandleBase handle4;
            csl::math::Matrix44 unk2;
            csl::math::Vector4 unk3;
            Unk2();
        };
        struct Unk3 {
            struct Unk1 {
                uint64_t unk1;
                uint64_t unk2;
                uint64_t unk3;
                uint64_t unk4;
                uint64_t unk5;
                uint64_t unk6;
                uint64_t unk7;
                uint64_t unk8;
                csl::math::Vector4 unk9;
                Unk1();
            };

            void* unk1;
            Unk1 unk2;
            Unk3();
        };
        struct Unk4 {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;
            csl::math::Vector4 unk3;
            uint32_t unk4;
            uint32_t unk5;
            hh::fnd::HandleBase handle38;
            uint32_t unk6;
            uint8_t unk7;
            Unk4();
        };
        struct Unk5 : Unk4 {
            csl::math::Vector4 unk102;
            csl::math::Matrix44 unk103;
            csl::math::Vector4 unk104;
            csl::math::Vector4 unk105;
            Unk5();
        };
        struct Unk6 {
            csl::math::Vector4 unk1;
            csl::math::Vector4 unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint8_t unk5;
            Unk6();
        };
        struct Unk7 {
            csl::ut::MoveArray<csl::math::Vector4> unk1;
            Unk7();
        };
        struct Unk8 {
            uint32_t unk1;
            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
            Unk8();
        };
        struct HistoryBuffer {
            enum class Flag : uint8_t  {
                GROUNDED,
                UNK,
                AMOEBA_TERRAIN,
                GRIND
            };
            GroundInfo groundInfo;
            csl::math::Vector4 worldInput;
            csl::math::Vector4 worldInputNormalized; // why..?
            csl::math::Transform transform;
            csl::math::Vector4 playerCenter;
            csl::math::Vector4 velocity;
            float deltaTime;
            csl::ut::Bitset<Flag> flags;
        };

        enum class Flag : uint8_t {
            NOT_GROUNDED = 3
        };
        csl::math::Transform transform;
        hh::fnd::WorldPosition worldPosition;
        csl::math::Vector4 velocity;
        csl::math::Vector4 unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        csl::math::Vector4 unk4;
        csl::math::Vector4 unk5;
        csl::math::Vector4 worldInput;
        csl::math::Vector4 vector140;
        csl::math::Matrix44 unk7;
        float float190;
        float float194;
        GroundInfo unk9; // usually game refers to unk9
        GroundInfo unk10;
        Unk2 unk11;
        Unk2 unk12;
        Unk3 unk12a;
        Unk5 unk13;
        Unk5 unk14;
        Unk6 unk15;
        app::player::GravityController *gravityController;
        csl::math::Vector4 gravity;
        Unk7 unk16;
        uint32_t dword530;
        csl::math::Matrix44 cameraViewportMatrix;
        csl::ut::CircularBuffer<HistoryBuffer> historyBuffer;
        uint16_t unk24;
        csl::ut::Bitset<Flag> flags; // 140618C20
        uint64_t unk26;
        uint32_t unk27;
        csl::math::Vector4 vector5D0;
        csl::math::Vector4 vector5E0;


		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        const csl::math::Transform& GetTransform() const;
        csl::math::Matrix34 GetWorldMatrix() const;
        void SetPosition(const csl::math::Vector4& position);
        void SetRotation(const csl::math::Matrix34& rotation);
        const csl::math::Quaternion& GetRotation() const;
        void SetRotation(const csl::math::Quaternion& rotation);
        void SetVelocity(const csl::math::Vector4& velocity);
        void SetGravityScale(float gravityScale);
        float GetSpeed() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerKinematicParams)
    };
}
