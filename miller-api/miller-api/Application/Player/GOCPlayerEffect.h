#pragma once

namespace app::player {
    class GOCPlayerEffect : public hh::game::GOComponent, public PlayerVisualListener {
    public:
        struct SetupInfo {
            int unk205;
            int effectListCount;
            int defaultEffectCount;
            int unk1;
        };

        hh::fnd::Reference<EffectList> defaultEffectList;
        csl::ut::MoveArray<hh::fnd::Reference<EffectList>> effectLists;
        csl::ut::StringMap<void*> unk203;
        uint64_t unk204;
        uint32_t unk205;
        uint8_t unk206;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void PVL_UnkFunc1(void* unkParam1, void* unkParam2) override;
        virtual void PVL_UnkFunc2(void* unkParam1, void* unkParam2) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerEffect);
        // only place where i found bool being (conditionally) true 1406391AB
        // usually is false, layer is from playercommon/effect_database.rfl
        bool LayerEnable(int layer, bool unk);
        void LayerDisable(int layer);
        void Setup(const SetupInfo& setupInfo);
        void AddEffectList(const hh::fnd::Reference<EffectList>& effectList);
    };
}
