#pragma once

namespace app::player {
    class PlayerPostureContext;
	class PlayerPosture;
	
	class PostureManager : public hh::fnd::BaseObject {
	public:
		csl::ut::InplaceMoveArray<int64_t, 2> postureListeners;
        PlayerPostureContext* context;
        Player* owner;
        hh::fnd::Reference<PlayerPosture> currentPosture;

        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) = 0;
        virtual void Init() = 0;
		
		void SetContext(PlayerPostureContext* context);
        void ClearPosture();
		PlayerPosture* GetPosture(unsigned int nameHash) const;
        template<typename T>
        inline T* GetPosture() const {
            return reinterpret_cast<T*>(GetPosture(T::hash));
        };
        void SetPosture(PlayerPosture* posture) const;
	};
	
	class PostureMoveManager : public PostureManager {
	public:
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void Init() override;
		
		PostureMoveManager(csl::fnd::IAllocator* allocator, Player* playerObject);
	};
	
	class PostureInputManager : public PostureManager {
	public:
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void Init() override;
		
		PostureInputManager(csl::fnd::IAllocator* allocator, Player* playerObject);
	};
    
    class GOCPlayerPosture : public hh::game::GOComponent {
    public:
        PlayerPostureContext* context;
        PostureMoveManager* moveManager;
        PostureInputManager* inputManager;
        uint8_t byte98;

        GOCPlayerPosture(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* data) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
    
        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerReplayPlayer);
    };
}