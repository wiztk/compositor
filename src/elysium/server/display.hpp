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

#ifndef ELYSIUM_SERVER_DISPLAY_HPP_
#define ELYSIUM_SERVER_DISPLAY_HPP_

#include <memory>

#include <wayland-server.h>

namespace elysium {
namespace server {

class Compositor;
class Shell;
class XdgShell;
class Seat;

class ClientList;
class SurfaceList;

/**
 * @ingroup elysium_server
 * @brief The server-side display.
 */
class Display {

  friend class Session;
  friend class MainLoop;
  friend class AbstractGlobal;

 public:

  Display();

  ~Display();

  void Run();

  void FlushClients() {
    wl_display_flush_clients(wl_display_);
  }

  ClientList *GetClientList() const {
    return clients_.get();
  }

  SurfaceList *GetSurfaces() const {
    return surfaces_.get();
  }

 private:

  struct wl_display *wl_display_ = nullptr;

//  struct wl_event_loop *wl_event_loop_ = nullptr;

  std::unique_ptr<Compositor> compositor_;
  std::unique_ptr<Shell> shell_;
  std::unique_ptr<XdgShell> xdg_shell_;
  std::unique_ptr<Seat> seat_;

  std::unique_ptr<ClientList> clients_;
  std::unique_ptr<SurfaceList> surfaces_;

//  int fd_ = -1;

};

}
}

#endif // ELYSIUM_SERVER_DISPLAY_HPP_
