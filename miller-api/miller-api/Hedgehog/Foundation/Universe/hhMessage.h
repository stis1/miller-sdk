#pragma once

namespace hh::fnd
{
	enum class MessageID : uint32_t {
		TRIGGER_ENTER = 512,
		TRIGGER_LEAVE = 513,
		TRIGGER_STAY = 514,
		UPDATE_SET_EDITOR = 768,
		UPDATE_ACTIVE_OBJECT_IN_EDITOR = 769,
		START_ACTIVE_OBJECT_IN_EDITOR = 770,
		FINISH_ACTIVE_OBJECT_IN_EDITOR = 771,
		PARAM_CHANGED_IN_EDITOR = 772,
		GET_DEBUG_COMMENT_IN_EDITOR = 773,
		PUSH_CAMERA_CONTROLLER = 4097,
		POP_CAMERA_CONTROLLER = 4098,
		ADJUST_PATH = 8196,
		ADD_NOTIFY_PRE_DEAD_LISTENER = 8201,
		BEGIN_BALL_MOVE = 8210,
		BEGIN_BATTLE = 8211,
		BEGIN_DIMENSION = 8215,
		BEGIN_DSURF_ON_GROUND = 8216,
		BEGIN_QUICKSTEP = 8230,
		BEGIN_SKATING_MOTION = 8232,
		BEGIN_STEERING_ASSIST = 8233,
		BEGIN_WATER_FLOW = 8239,
		CHANGE_AURA_LUMINANCE = 8333,
		CHANGE_DAMAGE_STATE = 8336,
		CHANGE_SLIDER_PATH = 8346,
		CAMERA_OFF = 8353,
		CAMERA_ON = 8354,
		COLLECTION_ROOM_ACTION_BEGIN = 8357,
		COLLECTION_ROOM_ACTION_IS_ENABLE = 8360,
		COLLIDER_QUERY_ENTER = 8361,
		COLLIDER_QUERY_STAY = 8363,
		CAMERA_ZOOM_END = 8366,
		DAMAGE = 8370,
		DEAD = 8374,
		CHANGE_GLOBAL_TIME_SCALE = 8387,
		CHANGE_LAYER_TIME_SCALE = 8388,
		DWING_CONSUMPTION_SET_BAN = 8398,
		DWING_CONSUMPTION_RESET_BAN = 8399,
		DWING_SET_BAN = 8400,
		DWING_RESET_BAN = 8401,
		END_BATTLE = 8407,
		END_DSURF_ON_GROUD = 8413,
		END_DRIFT = 8414,
		END_EXTERNAL_CONTROL = 8418,
		END_SKATING_MOTION = 8429,
		END_STEERING_ASSIST = 8430,
		END_TIME_STOP = 8434,
		END_WARP = 8436,
		END_WATER_FALL = 8437,
		ENTER_DIVING_VOLUME = 8440,
		ENTER_LOOP = 8441,
		FORCED_ACTIVATION_DWING = 8459,
		FOUND_PLAYER = 8460,
		GLIDING_SET_BAN = 8487,
		GLIDING_RESET_BAN = 8488,
		GRAVITY_CHANGED = 8491,
		HIT_DAMAGE = 8497,
		END_FREE_CAMERA = 8499,
		NOTIFY_ACTION = 8541,
		PLAYER_INPUT_ENABLED = 8577,
		RAISE_RINGS = 8594,
		REPLAY_COMMAND = 8598,
		RESUME_WORLD = 8616,
		SET_ABILITY_ENABLED = 8632,
		SET_DWING_VISIBLE = 8648,
		SPRING_ROUTE = 8673,
		IS_TAKE_RED_RING = 8676,
		TIME_STOP = 8689,
		TIME_STOP_SET_BAN = 8690,
		TIME_STOP_RESET_BAN = 8691,
		TIME_STOP_LOCK = 8692,
		TIME_STOP_UNLOCK = 8693,
		TIME_STOP_GAUGE_STOP = 8694,
		TIME_STOP_GAUGE_RESTART = 8695,
		TIME_STOP_OPERATION = 8696,
		TRANSIT_GUARDED_FLIPBACK = 8698,
		UI_BOOST_GAUGE_BUTTON_ENABLE_VIEW = 8704,
		UI_CENTER_CURSOR_ENABLE_VIEW = 8711,
		UI_LIGHT_GAUGE_LOCK = 8737,
		UI_LIGHT_GAUGE_UNLOCK = 8738,
		UI_MISSION_SET_TIMER = 8748,
		UI_SET_GAME_COCKPIT_ENABLE_RENDER = 8757,
		UI_SET_GAME_COCKPIT_VISIBILITY = 8758,
		UI_TARGET_NAVI_ENABLE_RENDER = 8759,
		NOTIFY_END_FALL_CYBERSPACE = 8765,
		WARP_TO_POINT = 8775,
		NOTIFY_LEVEL_STATUS = 8779,
		WHITE_SPACE_RESET_LARGE_CREST = 8780,
		NOTIFY_RETRY = 8788,
		PASS_POINT_MARKER = 8823,
		REVERT_GLOBAL_TIME_SCALE = 8915,
		REVERT_LAYER_TIME_SCALE = 8916,
		SET_MENU_ENABLED = 8947,
		START_FREE_CAMERA = 9001,
		UI_CAMERA_INFO = 9117,
		UI_CHANGE_PLAYER_CHARACTER = 9120,
		UI_NOTIFY_CAMERA_CONTROL = 9186,
		UI_PAUSE_RESULT = 9198,
	};

	class Messenger;
	class MessageAsyncHandler;
	class Message
	{
	public:
		MessageID ID{};
		Handle<Messenger> Sender{};
		Handle<Messenger> Receiver{};
		char Handled{};
		bool Broadcasted{};
		uint32_t Mask{ (uint32_t)-1 };

		Message(MessageID in_id);

		virtual MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator);
		virtual ~Message() = default;

		inline static void* operator new(size_t count) {
			return AllocateObjectGlobalMemory(count);
		}
		
		inline static void operator delete(void* ptr) noexcept {
			FreeObjectGlobalMemory(ptr);
		}
	};

	class MessageAsyncHandler : public ReferencedObject
	{
		Message& message;
		uint8_t unk1{};

	public:
		MessageAsyncHandler(csl::fnd::IAllocator* allocator, Message& message) : ReferencedObject{ allocator, true }, message{ message } {}

		inline Message& GetMessage() const {
			return message;
		}

		template<typename T>
		T& GetMessage() const {
			return static_cast<T&>(GetMessage());
		}
	};

	template <typename T>
	class MessageAsyncHandlerInplace : public MessageAsyncHandler
	{
		T messageInPlace;

	public:
		inline MessageAsyncHandlerInplace(csl::fnd::IAllocator* allocator, const T& message) : messageInPlace{ message }, MessageAsyncHandler { allocator, messageInPlace } {}
	};
}
