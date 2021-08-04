/* namespace.c generated by balac, the Bala compiler
 * generated from namespace.bala, do not modify */

/* namespace.bala
 *
 * Copyright (C) 2008-2011  Florian Brosch
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Florian Brosch <flo.brosch@gmail.com>
 */

#include "baladoc.h"
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <bala.h>

enum  {
	BALADOC_API_NAMESPACE_0_PROPERTY,
	BALADOC_API_NAMESPACE_NODE_TYPE_PROPERTY,
	BALADOC_API_NAMESPACE_NUM_PROPERTIES
};
static GParamSpec* baladoc_api_namespace_properties[BALADOC_API_NAMESPACE_NUM_PROPERTIES];
#define _baladoc_api_signature_builder_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_api_signature_builder_unref (var), NULL)))

static gpointer baladoc_api_namespace_parent_class = NULL;

static BaladocContentInline* baladoc_api_namespace_real_build_signature (BaladocApiItem* base);
static void baladoc_api_namespace_real_accept (BaladocApiNode* base,
                                        BaladocApiVisitor* visitor);
static gboolean baladoc_api_namespace_real_is_browsable (BaladocApiNode* base,
                                                  BaladocSettings* settings);
static GType baladoc_api_namespace_get_type_once (void);
static void _bala_baladoc_api_namespace_get_property (GObject * object,
                                               guint property_id,
                                               GValue * value,
                                               GParamSpec * pspec);

BaladocApiNamespace*
baladoc_api_namespace_construct (GType object_type,
                                 BaladocApiNode* parent,
                                 BaladocApiSourceFile* file,
                                 const gchar* name,
                                 BaladocApiSourceComment* comment,
                                 BalaNamespace* data)
{
	BaladocApiNamespace * self = NULL;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (BaladocApiNamespace*) baladoc_api_symbol_construct (object_type, parent, file, name, BALA_SYMBOL_ACCESSIBILITY_PUBLIC, comment, (BalaSymbol*) data);
	return self;
}

BaladocApiNamespace*
baladoc_api_namespace_new (BaladocApiNode* parent,
                           BaladocApiSourceFile* file,
                           const gchar* name,
                           BaladocApiSourceComment* comment,
                           BalaNamespace* data)
{
	return baladoc_api_namespace_construct (BALADOC_API_TYPE_NAMESPACE, parent, file, name, comment, data);
}

/**
 * {@inheritDoc}
 */
static BaladocContentInline*
baladoc_api_namespace_real_build_signature (BaladocApiItem* base)
{
	BaladocApiNamespace * self;
	BaladocApiSignatureBuilder* _tmp0_;
	BaladocApiSignatureBuilder* _tmp1_;
	BalaSymbolAccessibility _tmp2_;
	BalaSymbolAccessibility _tmp3_;
	const gchar* _tmp4_;
	BaladocApiSignatureBuilder* _tmp5_;
	BaladocApiSignatureBuilder* _tmp6_;
	BaladocApiSignatureBuilder* _tmp7_;
	BaladocContentRun* _tmp8_;
	BaladocContentInline* _tmp9_;
	BaladocContentInline* result = NULL;
	self = (BaladocApiNamespace*) base;
	_tmp0_ = baladoc_api_signature_builder_new ();
	_tmp1_ = _tmp0_;
	_tmp2_ = baladoc_api_symbol_get_accessibility ((BaladocApiSymbol*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = bala_symbol_accessibility_to_string (_tmp3_);
	_tmp5_ = baladoc_api_signature_builder_append_keyword (_tmp1_, _tmp4_, TRUE);
	_tmp6_ = baladoc_api_signature_builder_append_keyword (_tmp5_, "namespace", TRUE);
	_tmp7_ = baladoc_api_signature_builder_append_symbol (_tmp6_, (BaladocApiNode*) self, TRUE);
	_tmp8_ = baladoc_api_signature_builder_get (_tmp7_);
	_tmp9_ = (BaladocContentInline*) _tmp8_;
	_baladoc_api_signature_builder_unref0 (_tmp1_);
	result = _tmp9_;
	return result;
}

static BaladocApiNodeType
baladoc_api_namespace_real_get_node_type (BaladocApiNode* base)
{
	BaladocApiNodeType result;
	BaladocApiNamespace* self;
	self = (BaladocApiNamespace*) base;
	result = BALADOC_API_NODE_TYPE_NAMESPACE;
	return result;
}

/**
 * {@inheritDoc}
 */
static void
baladoc_api_namespace_real_accept (BaladocApiNode* base,
                                   BaladocApiVisitor* visitor)
{
	BaladocApiNamespace * self;
	self = (BaladocApiNamespace*) base;
	g_return_if_fail (visitor != NULL);
	baladoc_api_visitor_visit_namespace (visitor, self);
}

/**
 * {@inheritDoc}
 */
static gboolean
baladoc_api_namespace_real_is_browsable (BaladocApiNode* base,
                                         BaladocSettings* settings)
{
	BaladocApiNamespace * self;
	gboolean result = FALSE;
	self = (BaladocApiNamespace*) base;
	g_return_val_if_fail (settings != NULL, FALSE);
	result = baladoc_api_node_has_visible_children ((BaladocApiNode*) self, settings);
	return result;
}

static void
baladoc_api_namespace_class_init (BaladocApiNamespaceClass * klass,
                                  gpointer klass_data)
{
	baladoc_api_namespace_parent_class = g_type_class_peek_parent (klass);
	((BaladocApiItemClass *) klass)->build_signature = (BaladocContentInline* (*) (BaladocApiItem*)) baladoc_api_namespace_real_build_signature;
	((BaladocApiNodeClass *) klass)->accept = (void (*) (BaladocApiNode*, BaladocApiVisitor*)) baladoc_api_namespace_real_accept;
	((BaladocApiNodeClass *) klass)->is_browsable = (gboolean (*) (BaladocApiNode*, BaladocSettings*)) baladoc_api_namespace_real_is_browsable;
	BALADOC_API_NODE_CLASS (klass)->get_node_type = baladoc_api_namespace_real_get_node_type;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_api_namespace_get_property;
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_NAMESPACE_NODE_TYPE_PROPERTY, baladoc_api_namespace_properties[BALADOC_API_NAMESPACE_NODE_TYPE_PROPERTY] = g_param_spec_enum ("node-type", "node-type", "node-type", BALADOC_API_TYPE_NODE_TYPE, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
baladoc_api_namespace_instance_init (BaladocApiNamespace * self,
                                     gpointer klass)
{
}

/**
 * Represents a namespace declaration.
 */
static GType
baladoc_api_namespace_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocApiNamespaceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_namespace_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocApiNamespace), 0, (GInstanceInitFunc) baladoc_api_namespace_instance_init, NULL };
	GType baladoc_api_namespace_type_id;
	baladoc_api_namespace_type_id = g_type_register_static (BALADOC_API_TYPE_SYMBOL, "BaladocApiNamespace", &g_define_type_info, 0);
	return baladoc_api_namespace_type_id;
}

GType
baladoc_api_namespace_get_type (void)
{
	static volatile gsize baladoc_api_namespace_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_namespace_type_id__volatile)) {
		GType baladoc_api_namespace_type_id;
		baladoc_api_namespace_type_id = baladoc_api_namespace_get_type_once ();
		g_once_init_leave (&baladoc_api_namespace_type_id__volatile, baladoc_api_namespace_type_id);
	}
	return baladoc_api_namespace_type_id__volatile;
}

static void
_bala_baladoc_api_namespace_get_property (GObject * object,
                                          guint property_id,
                                          GValue * value,
                                          GParamSpec * pspec)
{
	BaladocApiNamespace * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_NAMESPACE, BaladocApiNamespace);
	switch (property_id) {
		case BALADOC_API_NAMESPACE_NODE_TYPE_PROPERTY:
		g_value_set_enum (value, baladoc_api_node_get_node_type ((BaladocApiNode*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

