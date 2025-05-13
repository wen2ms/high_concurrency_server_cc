#pragma once

#include <map>
#include <mutex>
#include <queue>
#include <thread>
#include <string>

#include "channel.h"
#include "dispatcher.h"

enum class ElemType : char {
    kAdd,
    kDelete,
    kModify
};

struct ChannelElement {
    ElemType type;
    Channel* channel;
};

class EventLoop {
  public:
    EventLoop();
    EventLoop(const std::string thread_name);
    ~EventLoop();

    int run();
    int event_activate(int fd, int event);
    int add_task(Channel* channel, ElemType type);
    int process_task();
    int add(Channel* channel);
    int remove(Channel* channel);
    int modify(Channel* channel);
    int free_channel(Channel* channel);

  private:
    bool is_quit_;
    Dispatcher* dispatcher_;
    std::queue<ChannelElement*> task_queue_;
    std::map<int, Channel*> channel_map_;
    std::thread::id thread_id_;
    std::string thread_name_;
    std::mutex mutex_;
    int socket_pair[2];
};
