#pragma once

namespace app::ui {
    class UICursor : public hh::game::GameObject {
    public:
        

        virtual bool ProcessMessage(hh::fnd::Message& message);
        virtual bool RecieveMessage(hh::fnd::Message& message);
        virtual void AddCallback(hh::game::GameManager* gameManager);
        GAMEOBJECT_CLASS_DECLARATION(UICursor);
    };
}