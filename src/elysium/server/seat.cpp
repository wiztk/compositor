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

#include "seat.hpp"

namespace elysium {
namespace server {

struct wl_seat_interface Seat::kInterface = {
    Seat::GetPointer,
    Seat::GetKeyboard,
    Seat::GetTouch,
    Seat::Release
};

struct wl_global *Seat::OnSetup(struct wl_display *display) {
  return wl_global_create(display, &wl_seat_interface, 1, this, &Seat::Bind);

}

void Seat::Bind(struct wl_client *client, void *data, uint32_t version, uint32_t id) {
  struct wl_resource *seat = wl_resource_create(client, &wl_seat_interface, 1, id);
  wl_resource_set_implementation(seat, &kInterface, data, NULL);
  wl_seat_send_capabilities(seat, WL_SEAT_CAPABILITY_POINTER | WL_SEAT_CAPABILITY_KEYBOARD);
}

void Seat::GetPointer(struct wl_client *client, struct wl_resource *resource, uint32_t id) {

}

void Seat::GetKeyboard(struct wl_client *client, struct wl_resource *resource, uint32_t id) {

}

void Seat::GetTouch(struct wl_client *client, struct wl_resource *resource, uint32_t id) {

}

void Seat::Release(struct wl_client *client, struct wl_resource *resource) {

}

}
}