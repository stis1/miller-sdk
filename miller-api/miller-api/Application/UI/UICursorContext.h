#pragma once

namespace app::ui {
    class UICursorContext : public app_cmn::fsm::GOCTinyFsmContext {
    public:
        uint8_t byte10;
        uint8_t gap11;
        uint8_t gap12;
        uint8_t gap13;
        uint32_t dword14;
        uint32_t dword18;

        UICursorContext(csl::fnd::IAllocator* allocator)
    };
}
