/*
 * Copyright 2017 - 2018 The WizTK Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ELYSIUM_SERVER_CLIENT_HPP_
#define ELYSIUM_SERVER_CLIENT_HPP_

#include <wayland-server.h>

namespace elysium {
namespace server {

class Client;

namespace internal {

struct ClientTraits {

  ClientTraits() = delete;

  explicit ClientTraits(Client *c)
      : client(c), link({nullptr, nullptr}) {}

  ~ClientTraits() {
    wl_list_remove(&link);
  }

  Client *client;

  struct wl_list link;

};

} // namespace internal

/**
 * @brief A class represents a client connected to this server.
 */
class Client {

  friend class ClientList;

 public:

  Client()
      : traits_(this) {}

  ~Client() = default;

 private:

  struct wl_client *wl_client = nullptr;

  struct wl_resource *wl_pointer = nullptr;

  struct wl_resource *wl_keyboard = nullptr;

  internal::ClientTraits traits_;

};

} // namespace server
} // namespace elysium

#endif // ELYSIUM_SERVER_CLIENT_HPP_
