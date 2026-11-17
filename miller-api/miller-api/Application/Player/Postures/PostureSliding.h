#pragma once

namespace app::player {
    class PostureSliding : public PlayerPosture {
    public:
        float float20; // time
        float float24;  
        uint8_t unk2;

        PostureSliding(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const override;
        virtual void Enter() override;
        virtual void Update(float deltaTime) override;
    };
}