/* inlinetaglet.c generated by balac, the Bala compiler
 * generated from inlinetaglet.bala, do not modify */

/* taglet.bala
 *
 * Copyright (C) 2008-2009 Didier Villevalois
 * Copyright (C) 2008-2012 Florian Brosch
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
 * 	Didier 'Ptitjes Villevalois <ptitjes@free.fr>
 */

#include "baladoc.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>

enum  {
	BALADOC_CONTENT_INLINE_TAGLET_0_PROPERTY,
	BALADOC_CONTENT_INLINE_TAGLET_NUM_PROPERTIES
};
static GParamSpec* baladoc_content_inline_taglet_properties[BALADOC_CONTENT_INLINE_TAGLET_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _BaladocContentInlineTagletPrivate {
	BaladocContentContentElement* _content;
};

static gint BaladocContentInlineTaglet_private_offset;
static gpointer baladoc_content_inline_taglet_parent_class = NULL;
static BaladocContentTagletIface * baladoc_content_inline_taglet_baladoc_content_taglet_parent_iface = NULL;
static BaladocContentInlineIface * baladoc_content_inline_taglet_baladoc_content_inline_parent_iface = NULL;

static BaladocRule* baladoc_content_inline_taglet_real_get_parser_rule (BaladocContentInlineTaglet* self,
                                                                 BaladocRule* run_rule);
static BaladocContentContentElement* baladoc_content_inline_taglet_real_produce_content (BaladocContentInlineTaglet* self);
static BaladocContentContentElement* baladoc_content_inline_taglet_get_content (BaladocContentInlineTaglet* self);
static void baladoc_content_inline_taglet_real_configure (BaladocContentContentElement* base,
                                                   BaladocSettings* settings,
                                                   BaladocResourceLocator* locator);
static void baladoc_content_inline_taglet_real_check (BaladocContentContentElement* base,
                                               BaladocApiTree* api_root,
                                               BaladocApiNode* container,
                                               const gchar* file_path,
                                               BaladocErrorReporter* reporter,
                                               BaladocSettings* settings);
G_GNUC_INTERNAL void baladoc_content_content_element_set_parent (BaladocContentContentElement* self,
                                                 BaladocContentContentElement* value);
static void baladoc_content_inline_taglet_real_accept (BaladocContentContentElement* base,
                                                BaladocContentContentVisitor* visitor);
static gboolean baladoc_content_inline_taglet_real_is_empty (BaladocContentContentElement* base);
static void baladoc_content_inline_taglet_finalize (GObject * obj);
static GType baladoc_content_inline_taglet_get_type_once (void);

static inline gpointer
baladoc_content_inline_taglet_get_instance_private (BaladocContentInlineTaglet* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocContentInlineTaglet_private_offset);
}

BaladocContentInlineTaglet*
baladoc_content_inline_taglet_construct (GType object_type)
{
	BaladocContentInlineTaglet * self = NULL;
	self = (BaladocContentInlineTaglet*) baladoc_content_content_element_construct (object_type);
	return self;
}

static BaladocRule*
baladoc_content_inline_taglet_real_get_parser_rule (BaladocContentInlineTaglet* self,
                                                    BaladocRule* run_rule)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_content_inline_taglet_get_parser_rule'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

BaladocRule*
baladoc_content_inline_taglet_get_parser_rule (BaladocContentInlineTaglet* self,
                                               BaladocRule* run_rule)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CONTENT_INLINE_TAGLET_GET_CLASS (self)->get_parser_rule (self, run_rule);
}

static BaladocContentContentElement*
baladoc_content_inline_taglet_real_produce_content (BaladocContentInlineTaglet* self)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_content_inline_taglet_produce_content'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

BaladocContentContentElement*
baladoc_content_inline_taglet_produce_content (BaladocContentInlineTaglet* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CONTENT_INLINE_TAGLET_GET_CLASS (self)->produce_content (self);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static BaladocContentContentElement*
baladoc_content_inline_taglet_get_content (BaladocContentInlineTaglet* self)
{
	BaladocContentContentElement* _tmp0_;
	BaladocContentContentElement* _tmp2_;
	BaladocContentContentElement* _tmp3_;
	BaladocContentContentElement* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_content;
	if (_tmp0_ == NULL) {
		BaladocContentContentElement* _tmp1_;
		_tmp1_ = baladoc_content_inline_taglet_produce_content (self);
		_g_object_unref0 (self->priv->_content);
		self->priv->_content = _tmp1_;
	}
	_tmp2_ = self->priv->_content;
	_tmp3_ = _g_object_ref0 (_tmp2_);
	result = _tmp3_;
	return result;
}

static void
baladoc_content_inline_taglet_real_configure (BaladocContentContentElement* base,
                                              BaladocSettings* settings,
                                              BaladocResourceLocator* locator)
{
	BaladocContentInlineTaglet * self;
	BaladocSettings* _tmp0_;
	BaladocResourceLocator* _tmp1_;
	self = (BaladocContentInlineTaglet*) base;
	g_return_if_fail (settings != NULL);
	g_return_if_fail (locator != NULL);
	_tmp0_ = _g_object_ref0 (settings);
	_g_object_unref0 (self->settings);
	self->settings = _tmp0_;
	_tmp1_ = _g_object_ref0 (locator);
	_g_object_unref0 (self->locator);
	self->locator = _tmp1_;
}

static void
baladoc_content_inline_taglet_real_check (BaladocContentContentElement* base,
                                          BaladocApiTree* api_root,
                                          BaladocApiNode* container,
                                          const gchar* file_path,
                                          BaladocErrorReporter* reporter,
                                          BaladocSettings* settings)
{
	BaladocContentInlineTaglet * self;
	BaladocContentContentElement* element = NULL;
	BaladocContentContentElement* _tmp0_;
	self = (BaladocContentInlineTaglet*) base;
	g_return_if_fail (api_root != NULL);
	g_return_if_fail (container != NULL);
	g_return_if_fail (file_path != NULL);
	g_return_if_fail (reporter != NULL);
	g_return_if_fail (settings != NULL);
	_tmp0_ = baladoc_content_inline_taglet_get_content (self);
	element = _tmp0_;
	baladoc_content_content_element_set_parent (element, (BaladocContentContentElement*) self);
	baladoc_content_content_element_check (element, api_root, container, file_path, reporter, settings);
	_g_object_unref0 (element);
}

static void
baladoc_content_inline_taglet_real_accept (BaladocContentContentElement* base,
                                           BaladocContentContentVisitor* visitor)
{
	BaladocContentInlineTaglet * self;
	BaladocContentContentElement* element = NULL;
	BaladocContentContentElement* _tmp0_;
	self = (BaladocContentInlineTaglet*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = baladoc_content_inline_taglet_get_content (self);
	element = _tmp0_;
	baladoc_content_content_element_accept (element, visitor);
	_g_object_unref0 (element);
}

static gboolean
baladoc_content_inline_taglet_real_is_empty (BaladocContentContentElement* base)
{
	BaladocContentInlineTaglet * self;
	gboolean result = FALSE;
	self = (BaladocContentInlineTaglet*) base;
	result = FALSE;
	return result;
}

static void
baladoc_content_inline_taglet_class_init (BaladocContentInlineTagletClass * klass,
                                          gpointer klass_data)
{
	baladoc_content_inline_taglet_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &BaladocContentInlineTaglet_private_offset);
	((BaladocContentInlineTagletClass *) klass)->get_parser_rule = (BaladocRule* (*) (BaladocContentInlineTaglet*, BaladocRule*)) baladoc_content_inline_taglet_real_get_parser_rule;
	((BaladocContentInlineTagletClass *) klass)->produce_content = (BaladocContentContentElement* (*) (BaladocContentInlineTaglet*)) baladoc_content_inline_taglet_real_produce_content;
	((BaladocContentContentElementClass *) klass)->configure = (void (*) (BaladocContentContentElement*, BaladocSettings*, BaladocResourceLocator*)) baladoc_content_inline_taglet_real_configure;
	((BaladocContentContentElementClass *) klass)->check = (void (*) (BaladocContentContentElement*, BaladocApiTree*, BaladocApiNode*, const gchar*, BaladocErrorReporter*, BaladocSettings*)) baladoc_content_inline_taglet_real_check;
	((BaladocContentContentElementClass *) klass)->accept = (void (*) (BaladocContentContentElement*, BaladocContentContentVisitor*)) baladoc_content_inline_taglet_real_accept;
	((BaladocContentContentElementClass *) klass)->is_empty = (gboolean (*) (BaladocContentContentElement*)) baladoc_content_inline_taglet_real_is_empty;
	G_OBJECT_CLASS (klass)->finalize = baladoc_content_inline_taglet_finalize;
}

static void
baladoc_content_inline_taglet_baladoc_content_taglet_interface_init (BaladocContentTagletIface * iface,
                                                                     gpointer iface_data)
{
	baladoc_content_inline_taglet_baladoc_content_taglet_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_parser_rule = (BaladocRule* (*) (BaladocContentTaglet*, BaladocRule*)) baladoc_content_inline_taglet_get_parser_rule;
}

static void
baladoc_content_inline_taglet_baladoc_content_inline_interface_init (BaladocContentInlineIface * iface,
                                                                     gpointer iface_data)
{
	baladoc_content_inline_taglet_baladoc_content_inline_parent_iface = g_type_interface_peek_parent (iface);
}

static void
baladoc_content_inline_taglet_instance_init (BaladocContentInlineTaglet * self,
                                             gpointer klass)
{
	self->priv = baladoc_content_inline_taglet_get_instance_private (self);
}

static void
baladoc_content_inline_taglet_finalize (GObject * obj)
{
	BaladocContentInlineTaglet * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_CONTENT_TYPE_INLINE_TAGLET, BaladocContentInlineTaglet);
	_g_object_unref0 (self->settings);
	_g_object_unref0 (self->locator);
	_g_object_unref0 (self->priv->_content);
	G_OBJECT_CLASS (baladoc_content_inline_taglet_parent_class)->finalize (obj);
}

static GType
baladoc_content_inline_taglet_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocContentInlineTagletClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_content_inline_taglet_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocContentInlineTaglet), 0, (GInstanceInitFunc) baladoc_content_inline_taglet_instance_init, NULL };
	static const GInterfaceInfo baladoc_content_taglet_info = { (GInterfaceInitFunc) baladoc_content_inline_taglet_baladoc_content_taglet_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	static const GInterfaceInfo baladoc_content_inline_info = { (GInterfaceInitFunc) baladoc_content_inline_taglet_baladoc_content_inline_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType baladoc_content_inline_taglet_type_id;
	baladoc_content_inline_taglet_type_id = g_type_register_static (BALADOC_CONTENT_TYPE_CONTENT_ELEMENT, "BaladocContentInlineTaglet", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	g_type_add_interface_static (baladoc_content_inline_taglet_type_id, BALADOC_CONTENT_TYPE_TAGLET, &baladoc_content_taglet_info);
	g_type_add_interface_static (baladoc_content_inline_taglet_type_id, BALADOC_CONTENT_TYPE_INLINE, &baladoc_content_inline_info);
	BaladocContentInlineTaglet_private_offset = g_type_add_instance_private (baladoc_content_inline_taglet_type_id, sizeof (BaladocContentInlineTagletPrivate));
	return baladoc_content_inline_taglet_type_id;
}

GType
baladoc_content_inline_taglet_get_type (void)
{
	static volatile gsize baladoc_content_inline_taglet_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_content_inline_taglet_type_id__volatile)) {
		GType baladoc_content_inline_taglet_type_id;
		baladoc_content_inline_taglet_type_id = baladoc_content_inline_taglet_get_type_once ();
		g_once_init_leave (&baladoc_content_inline_taglet_type_id__volatile, baladoc_content_inline_taglet_type_id);
	}
	return baladoc_content_inline_taglet_type_id__volatile;
}

