#pragma once

namespace app::player {
    class StatePluginRunning : public PlayerStatePlugin, public PostureListener {
    public:
        csl::ut::MoveArray<uint64_t> array30;    
        app::player::GOCPlayerVisual* gocPlayerVisual;
        uint64_t qword58;
        uint32_t dword60;
        float float64;
        void* qword68;
        uint64_t qword70;
        uint64_t qword78;
        uint64_t qword80;
        uint64_t qword88;
        void* qword90;
        csl::ut::MoveArray<uint64_t> array98;
        uint64_t qwordB0;
        uint8_t byteB8;
        uint8_t byteB9;
        uint8_t byteBA;
        uint8_t byteBB;
        uint16_t wordBC;

        
    };
}