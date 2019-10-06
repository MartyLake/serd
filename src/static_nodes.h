/*
  Copyright 2019 David Robillard <http://drobilla.net>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THIS SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef SERD_STATIC_NODES_H
#define SERD_STATIC_NODES_H

#include "namespaces.h"
#include "node.h"

typedef struct StaticNode {
	SerdNode node;
	char     buf[sizeof(NS_XSD "base64Binary") + sizeof(SerdNode)];
} StaticNode;

#define DEFINE_XSD_NODE(name)                   \
	static const StaticNode serd_xsd_##name = { \
	        {sizeof(NS_XSD #name) - 1, 0, SERD_URI}, NS_XSD #name};

DEFINE_XSD_NODE(base64Binary)
DEFINE_XSD_NODE(boolean)
DEFINE_XSD_NODE(decimal)
DEFINE_XSD_NODE(double)
DEFINE_XSD_NODE(float)
DEFINE_XSD_NODE(integer)

#endif // SERD_STATIC_NODES_H
