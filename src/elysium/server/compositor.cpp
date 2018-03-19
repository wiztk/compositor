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

#include "compositor.hpp"

namespace elysium {
namespace server {

const struct wl_compositor_interface Compositor::kInterface = {
    &Compositor::CreateSurface,
    &Compositor::CreateRegion
};

struct wl_global *Compositor::OnSetup(struct wl_display *display) {
  return wl_global_create(display,
                          &wl_compositor_interface,
                          4,
                          this,
                          &Compositor::Bind);
}

void Compositor::Bind(struct wl_client *client, void *data, uint32_t version, uint32_t id) {
  printf("%s\n", __FUNCTION__);
  struct wl_resource *resource = wl_resource_create(client, &wl_compositor_interface, version, id);
  if (nullptr == resource) {
    wl_client_post_no_memory(client);
    return;
  }

  wl_resource_set_implementation(resource, &kInterface, data, nullptr);
}

void Compositor::CreateSurface(struct wl_client *client, struct wl_resource *resource, uint32_t id) {
  printf("%s\n", __FUNCTION__);

}

void Compositor::CreateRegion(struct wl_client *client, struct wl_resource *resource, uint32_t id) {
  printf("%s\n", __FUNCTION__);

}

} // namespace server
} // namespace elysium
