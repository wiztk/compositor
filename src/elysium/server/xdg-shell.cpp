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

#include "xdg-shell.hpp"
#include "display.hpp"

namespace elysium {
namespace server {

struct zxdg_shell_v6_interface XdgShell::kInterface = {
    XdgShell::Destroy,
    XdgShell::CreatePositioner,
    XdgShell::GetXdgSurface,
    XdgShell::Pong
};

struct wl_global *XdgShell::OnSetup(struct wl_display *display) {
  return wl_global_create(display, &zxdg_shell_v6_interface, 1, this, &XdgShell::Bind);
}

void XdgShell::Bind(struct wl_client *client, void *data, uint32_t version, uint32_t id) {
  printf("%s\n", __FUNCTION__);

  struct wl_resource *resource = wl_resource_create(client, &zxdg_shell_v6_interface, 1, id);
  wl_resource_set_implementation(resource, &kInterface, data, nullptr);
}

void XdgShell::Destroy(struct wl_client *client, struct wl_resource *resource) {

}

void XdgShell::CreatePositioner(struct wl_client *client, struct wl_resource *resource, uint32_t id) {

}

void XdgShell::GetXdgSurface(struct wl_client *client,
                             struct wl_resource *resource,
                             uint32_t id,
                             struct wl_resource *surface) {

}

void XdgShell::Pong(struct wl_client *client, struct wl_resource *resource, uint32_t serial) {

}

}
}