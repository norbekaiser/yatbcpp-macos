//    Copyright (c) 2017 Norbert Rühl
//    
//    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//    
//    Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//    
//        1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//    
//        2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//    
//        3. This notice may not be removed or altered from any source distribution.
//
// Created by norbert on 12.08.17.
//

#ifndef YATBCPP_BOT_H
#define YATBCPP_BOT_H

#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <queue>
#include <condition_variable>

#include "../bot/Token.h"
#include "../types/InlineQuery.h"
#include "../types/MessageEntity.h"
#include "../types/Message.h"
#include "../types/Update.h"
#include "../types/User.h"

#include "../methods/sendMessage.h"

#include "../methods/telegram_methodJSON.h"
#include "../methods/telegram_methodMultipart.h"

namespace yatbcpp {
    class Bot {
    public:

        Bot(Token& T);

        void startLongPoll();

        void startLongPoll(long timeout);

        void stopLongPoll();

        void startUpdating();

        void stopUpdating();

        const User getMe() const ;

//        const Message sendSM(sendMessage sm);

        void addOnUpdateListener(std::function<void(Update)> Listener);

        void addOnMessageBotCommandListener(std::function<void(Message,MessageEntity)> Listener);

        void addOnMessageListener(std::function<void(Message)> Listener);

        void addOnMessageEditedListener(std::function<void(Message)> Listener);

        void addOnChannelPostListener(std::function<void(Message)> Listener);

        void addOnChannelPostEditedListener(std::function<void(Message)> Listener);

        void addOnInlineQueryListener(std::function<void(InlineQuery)> Listener);

        void join();

    private:

        const Token token;



        std::thread Polling;
        std::thread Updating;

        bool isPolling;
        bool isUpdating;

        void LongPolling(long timeout);
        void NotifyRegisteredListeners();

        std::mutex m;
        std::queue<Update> pendingUpdates;
        std::condition_variable pendingUpdatesAvailable;

        std::vector<std::function<void(Update)>> OnUpdateListeners;
        std::vector<std::function<void(Message,MessageEntity)>> OnMessageCommandListener;
        std::vector<std::function<void(Message)>> OnMessageListener;
        std::vector<std::function<void(Message)>> OnMessageEditedListener;
        std::vector<std::function<void(Message)>> OnChannelPostListener;
        std::vector<std::function<void(Message)>> OnChannelPostEditedListener;
        std::vector<std::function<void(InlineQuery)>> OnInlineQueryListener;


    };
}

#endif //YATBOT_BOT_H
