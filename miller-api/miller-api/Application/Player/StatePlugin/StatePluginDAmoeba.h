#pragma once 

namespace app::player {
    class StatePluginDAmoeba : public app::player::PlayerStatePlugin, hh::animeff::ParticleLocatorListener {
    public:
        hh::eff::EffectHandle effectHandle;
        hh::snd::SoundHandle soundHandle;
        uint64_t qword48;
        csl::math::Vector4 vector50;
        csl::math::Vector4 vector60;
        csl::math::Vector4 vector70;
        csl::math::Vector4 vector80;
        csl::math::Vector4 vector90;
        uint8_t byteA0;
        uint32_t dwordA4;
        float dashKeepSpeedTime;
        float dashOutOfControlTime;
        uint32_t dwordB0;
        uint32_t dwordB4;
        uint32_t dwordB8;
        uint32_t dwordBC;
        uint32_t dwordC0;
        uint32_t dwordC4;
        float dashInterval;
        uint32_t dwordCC;
        uint32_t dwordD0;
        uint32_t dwordD4;
        uint32_t dwordD8;
        uint32_t dwordDC;
        uint32_t dwordE0;
        uint32_t dwordE4;
        uint32_t dwordE8;
    };
}