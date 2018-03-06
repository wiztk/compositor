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

#include "xdg-surface.hpp"

namespace elysium {
namespace server {

struct zxdg_surface_v6_interface XdgSurface::kInterface = {
    XdgSurface::Destroy,
    XdgSurface::GetTopLevel,
    XdgSurface::GetPopup,
    XdgSurface::SetWindowGeometry,
    XdgSurface::AckConfigure
};

XdgSurface::XdgSurface(Display *display)
    : display_(display) {

}

XdgSurface::~XdgSurface() {

}

void XdgSurface::Destroy(struct wl_client *client, struct wl_resource *resource) {

}

void XdgSurface::GetTopLevel(struct wl_client *client, struct wl_resource *resource, uint32_t id) {

}

void XdgSurface::GetPopup(struct wl_client *client,
                          struct wl_resource *resource,
                          uint32_t id,
                          struct wl_resource *parent,
                          struct wl_resource *positioner) {

}

void XdgSurface::SetWindowGeometry(struct wl_client *client,
                                   struct wl_resource *resource,
                                   int32_t x,
                                   int32_t y,
                                   int32_t width,
                                   int32_t height) {

}

void XdgSurface::AckConfigure(struct wl_client *client, struct wl_resource *resource, uint32_t serial) {

}

}
}