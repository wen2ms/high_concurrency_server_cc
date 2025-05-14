#pragma once

class Buffer {
  public:
    Buffer(int size);
    ~Buffer();

    void extend_room(int size);

    inline int readable_size() {
        return write_pos_ - read_pos_;
    }

    inline int writable_size() {
        return capacity_ - write_pos_;
    }

    int append_string(const char* data, int size);
    int append_string(const char* data);

    int socket_read(int fd);
    char* find_crlf();
    int send_data(int socket);

  private:
    char* data_;
    int capacity_;
    int read_pos_;
    int write_pos_;
};