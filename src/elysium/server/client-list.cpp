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

#include "client-list.hpp"

#include "client.hpp"
#include "display.hpp"
#include "session.hpp"

namespace elysium {
namespace server {

Client *ClientList::GetClient(struct wl_client *client) {
  Client *ret = nullptr;

  ClientList *clients = Session::GetInstance()->GetDisplay()->GetClientList();
  internal::ClientTraits *e = nullptr;
  wl_list_for_each(e, &clients->clients_, link) {
    if (e->client->wl_client == client) break;
  }

  // TODO: create new Client

  return ret;
}

ClientList::ClientList() {
  wl_list_init(&clients_);
}

ClientList::~ClientList() {
  while (!wl_list_empty(&clients_)) {
    internal::ClientTraits *e = nullptr;
    e = wl_container_of(clients_.next, e, link);
    Client *client = e->client;
    delete client;
  }
}

}
}