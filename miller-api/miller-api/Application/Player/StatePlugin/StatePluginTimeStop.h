#pragma once

namespace app::player {
    class StatePluginTimeStop : public PlayerStatePlugin, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "StatePluginTimeStop";
        
        int32_t dword30;
        float gaugeFlt;
        int32_t gaugeInt;
        uint32_t dword3C;
        uint32_t dword40;
        uint32_t dword44;
        float float48;
        float float4C;
        float float50;
        float float54;
        float startMargin;
        bool gaugeStop;
        bool isTimeStop;
        bool gaugeFill;
        bool byte5F;
        bool byte60;
        uint64_t qword68;
        uint64_t qword70;
        hh::snd::SoundHandle soundHandle;
        bool gaugeLock;

        StatePluginTimeStop(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override; 
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
    };
}