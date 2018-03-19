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

#include "shell.hpp"

namespace elysium {
namespace server {

struct wl_shell_interface Shell::kInstance = {
    Shell::GetShellSurface
};

struct wl_global *Shell::OnSetup(struct wl_display *display) {
  return wl_global_create(display, &wl_shell_interface, 1, this, &Shell::Bind);
}

void Shell::Bind(struct wl_client *client, void *data, uint32_t version, uint32_t id) {
  printf("%s\n", __FUNCTION__);

  struct wl_resource *resource = wl_resource_create(client, &wl_shell_interface, 1, id);
  wl_resource_set_implementation(resource, &kInstance, data, nullptr);
}

void Shell::GetShellSurface(struct wl_client *client,
                            struct wl_resource *resource,
                            uint32_t id,
                            struct wl_resource *surface) {
  
}

}
}