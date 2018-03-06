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

#ifndef ELYSIUM_SERVER_XDG_SURFACE_HPP_
#define ELYSIUM_SERVER_XDG_SURFACE_HPP_

#include "xdg-shell-unstable-v6-server-protocol.h"

namespace elysium {
namespace server {

class Display;

class XdgSurface {

 public:

  explicit XdgSurface(Display *display);

  ~XdgSurface();

 private:

  static void Destroy(struct wl_client *client, struct wl_resource *resource);

  static void GetTopLevel(struct wl_client *client, struct wl_resource *resource, uint32_t id);

  static void GetPopup(struct wl_client *client, struct wl_resource *resource, uint32_t id,
                       struct wl_resource *parent, struct wl_resource *positioner);

  static void SetWindowGeometry(struct wl_client *client,
                                struct wl_resource *resource,
                                int32_t x,
                                int32_t y,
                                int32_t width,
                                int32_t height);

  static void AckConfigure(struct wl_client *client, struct wl_resource *resource, uint32_t serial);

  static struct zxdg_surface_v6_interface kInterface;

  Display *display_ = nullptr;

};

}
}

#endif //ELYSIUM_XDG_SURFACE_HPP
