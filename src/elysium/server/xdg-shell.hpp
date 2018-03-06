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

#ifndef ELYSIUM_SERVER_XDG_SHELL_HPP_
#define ELYSIUM_SERVER_XDG_SHELL_HPP_

#include "abstract-global.hpp"

#include "xdg-shell-unstable-v6-server-protocol.h"

namespace elysium {
namespace server {

class XdgShell : public AbstractGlobal {

 public:

  XdgShell() = default;

  ~XdgShell() final = default;

 protected:

  struct wl_global *OnSetup(struct wl_display *display) final;

 private:

  static void Bind(struct wl_client *client, void *data, uint32_t version, uint32_t id);

  static void Destroy(struct wl_client *client,
                      struct wl_resource *resource);

  static void CreatePositioner(struct wl_client *client,
                               struct wl_resource *resource,
                               uint32_t id);

  static void GetXdgSurface(struct wl_client *client,
                            struct wl_resource *resource,
                            uint32_t id,
                            struct wl_resource *surface);

  static void Pong(struct wl_client *client,
                   struct wl_resource *resource,
                   uint32_t serial);

  static struct zxdg_shell_v6_interface kInterface;

};

}
}

#endif // ELYSIUM_SERVER_XDG_SHELL_HPP_
