/* errordomain.c generated by balac, the Bala compiler
 * generated from errordomain.bala, do not modify */

/* errordomain.bala
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
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <bala.h>
#include <balacodegen.h>

enum  {
	BALADOC_API_ERROR_DOMAIN_0_PROPERTY,
	BALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY,
	BALADOC_API_ERROR_DOMAIN_NUM_PROPERTIES
};
static GParamSpec* baladoc_api_error_domain_properties[BALADOC_API_ERROR_DOMAIN_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _baladoc_api_signature_builder_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_api_signature_builder_unref (var), NULL)))

struct _BaladocApiErrorDomainPrivate {
	gchar* quark_function_name;
	gchar* quark_macro_name;
	gchar* dbus_name;
	gchar* cname;
};

static gint BaladocApiErrorDomain_private_offset;
static gpointer baladoc_api_error_domain_parent_class = NULL;

static gchar* _baladoc_api_error_domain_get_quark_function_name (BaladocApiErrorDomain* self,
                                                          BalaErrorDomain* element);
static gchar* _baladoc_api_error_domain_get_quark_macro_name (BaladocApiErrorDomain* self,
                                                       BalaErrorDomain* element);
static void baladoc_api_error_domain_real_accept (BaladocApiNode* base,
                                           BaladocApiVisitor* visitor);
static BaladocContentInline* baladoc_api_error_domain_real_build_signature (BaladocApiItem* base);
static void baladoc_api_error_domain_finalize (GObject * obj);
static GType baladoc_api_error_domain_get_type_once (void);
static void _bala_baladoc_api_error_domain_get_property (GObject * object,
                                                  guint property_id,
                                                  GValue * value,
                                                  GParamSpec * pspec);

static inline gpointer
baladoc_api_error_domain_get_instance_private (BaladocApiErrorDomain* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocApiErrorDomain_private_offset);
}

BaladocApiErrorDomain*
baladoc_api_error_domain_construct (GType object_type,
                                    BaladocApiNode* parent,
                                    BaladocApiSourceFile* file,
                                    const gchar* name,
                                    BalaSymbolAccessibility accessibility,
                                    BaladocApiSourceComment* comment,
                                    BalaErrorDomain* data)
{
	BaladocApiErrorDomain * self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (BaladocApiErrorDomain*) baladoc_api_typesymbol_construct (object_type, parent, file, name, accessibility, comment, FALSE, (BalaTypeSymbol*) data);
	_tmp0_ = _baladoc_api_error_domain_get_quark_function_name (self, data);
	_g_free0 (self->priv->quark_function_name);
	self->priv->quark_function_name = _tmp0_;
	_tmp1_ = _baladoc_api_error_domain_get_quark_macro_name (self, data);
	_g_free0 (self->priv->quark_macro_name);
	self->priv->quark_macro_name = _tmp1_;
	_tmp2_ = bala_gd_bus_module_get_dbus_name ((BalaTypeSymbol*) data);
	_g_free0 (self->priv->dbus_name);
	self->priv->dbus_name = _tmp2_;
	_tmp3_ = bala_get_ccode_name ((BalaCodeNode*) data);
	_g_free0 (self->priv->cname);
	self->priv->cname = _tmp3_;
	return self;
}

BaladocApiErrorDomain*
baladoc_api_error_domain_new (BaladocApiNode* parent,
                              BaladocApiSourceFile* file,
                              const gchar* name,
                              BalaSymbolAccessibility accessibility,
                              BaladocApiSourceComment* comment,
                              BalaErrorDomain* data)
{
	return baladoc_api_error_domain_construct (BALADOC_API_TYPE_ERROR_DOMAIN, parent, file, name, accessibility, comment, data);
}

static gchar*
_baladoc_api_error_domain_get_quark_function_name (BaladocApiErrorDomain* self,
                                                   BalaErrorDomain* element)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (element != NULL, NULL);
	_tmp0_ = bala_get_ccode_lower_case_prefix ((BalaSymbol*) element);
	_tmp1_ = _tmp0_;
	_tmp2_ = g_strconcat (_tmp1_, "quark", NULL);
	_tmp3_ = _tmp2_;
	_g_free0 (_tmp1_);
	result = _tmp3_;
	return result;
}

static gchar*
_baladoc_api_error_domain_get_quark_macro_name (BaladocApiErrorDomain* self,
                                                BalaErrorDomain* element)
{
	gchar* _tmp0_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (element != NULL, NULL);
	_tmp0_ = bala_get_ccode_upper_case_name ((BalaSymbol*) element, NULL);
	result = _tmp0_;
	return result;
}

/**
 * Returns the name of this errordomain as it is used in C.
 */
gchar*
baladoc_api_error_domain_get_cname (BaladocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Returns the dbus-name.
 */
gchar*
baladoc_api_error_domain_get_dbus_name (BaladocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->dbus_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Gets the name of the quark() function which represents the error domain
 */
gchar*
baladoc_api_error_domain_get_quark_function_name (BaladocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->quark_function_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Gets the name of the quark macro which represents the error domain
 */
gchar*
baladoc_api_error_domain_get_quark_macro_name (BaladocApiErrorDomain* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->quark_macro_name;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

static BaladocApiNodeType
baladoc_api_error_domain_real_get_node_type (BaladocApiNode* base)
{
	BaladocApiNodeType result;
	BaladocApiErrorDomain* self;
	self = (BaladocApiErrorDomain*) base;
	result = BALADOC_API_NODE_TYPE_ERROR_DOMAIN;
	return result;
}

/**
 * {@inheritDoc}
 */
static void
baladoc_api_error_domain_real_accept (BaladocApiNode* base,
                                      BaladocApiVisitor* visitor)
{
	BaladocApiErrorDomain * self;
	self = (BaladocApiErrorDomain*) base;
	g_return_if_fail (visitor != NULL);
	baladoc_api_visitor_visit_error_domain (visitor, self);
}

/**
 * {@inheritDoc}
 */
static BaladocContentInline*
baladoc_api_error_domain_real_build_signature (BaladocApiItem* base)
{
	BaladocApiErrorDomain * self;
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
	self = (BaladocApiErrorDomain*) base;
	_tmp0_ = baladoc_api_signature_builder_new ();
	_tmp1_ = _tmp0_;
	_tmp2_ = baladoc_api_symbol_get_accessibility ((BaladocApiSymbol*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = bala_symbol_accessibility_to_string (_tmp3_);
	_tmp5_ = baladoc_api_signature_builder_append_keyword (_tmp1_, _tmp4_, TRUE);
	_tmp6_ = baladoc_api_signature_builder_append_keyword (_tmp5_, "errordomain", TRUE);
	_tmp7_ = baladoc_api_signature_builder_append_symbol (_tmp6_, (BaladocApiNode*) self, TRUE);
	_tmp8_ = baladoc_api_signature_builder_get (_tmp7_);
	_tmp9_ = (BaladocContentInline*) _tmp8_;
	_baladoc_api_signature_builder_unref0 (_tmp1_);
	result = _tmp9_;
	return result;
}

static void
baladoc_api_error_domain_class_init (BaladocApiErrorDomainClass * klass,
                                     gpointer klass_data)
{
	baladoc_api_error_domain_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &BaladocApiErrorDomain_private_offset);
	((BaladocApiNodeClass *) klass)->accept = (void (*) (BaladocApiNode*, BaladocApiVisitor*)) baladoc_api_error_domain_real_accept;
	((BaladocApiItemClass *) klass)->build_signature = (BaladocContentInline* (*) (BaladocApiItem*)) baladoc_api_error_domain_real_build_signature;
	BALADOC_API_NODE_CLASS (klass)->get_node_type = baladoc_api_error_domain_real_get_node_type;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_api_error_domain_get_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_api_error_domain_finalize;
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY, baladoc_api_error_domain_properties[BALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY] = g_param_spec_enum ("node-type", "node-type", "node-type", BALADOC_API_TYPE_NODE_TYPE, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
baladoc_api_error_domain_instance_init (BaladocApiErrorDomain * self,
                                        gpointer klass)
{
	self->priv = baladoc_api_error_domain_get_instance_private (self);
}

static void
baladoc_api_error_domain_finalize (GObject * obj)
{
	BaladocApiErrorDomain * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_ERROR_DOMAIN, BaladocApiErrorDomain);
	_g_free0 (self->priv->quark_function_name);
	_g_free0 (self->priv->quark_macro_name);
	_g_free0 (self->priv->dbus_name);
	_g_free0 (self->priv->cname);
	G_OBJECT_CLASS (baladoc_api_error_domain_parent_class)->finalize (obj);
}

/**
 * Represents an error domain declaration.
 */
static GType
baladoc_api_error_domain_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocApiErrorDomainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_error_domain_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocApiErrorDomain), 0, (GInstanceInitFunc) baladoc_api_error_domain_instance_init, NULL };
	GType baladoc_api_error_domain_type_id;
	baladoc_api_error_domain_type_id = g_type_register_static (BALADOC_API_TYPE_TYPESYMBOL, "BaladocApiErrorDomain", &g_define_type_info, 0);
	BaladocApiErrorDomain_private_offset = g_type_add_instance_private (baladoc_api_error_domain_type_id, sizeof (BaladocApiErrorDomainPrivate));
	return baladoc_api_error_domain_type_id;
}

GType
baladoc_api_error_domain_get_type (void)
{
	static volatile gsize baladoc_api_error_domain_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_error_domain_type_id__volatile)) {
		GType baladoc_api_error_domain_type_id;
		baladoc_api_error_domain_type_id = baladoc_api_error_domain_get_type_once ();
		g_once_init_leave (&baladoc_api_error_domain_type_id__volatile, baladoc_api_error_domain_type_id);
	}
	return baladoc_api_error_domain_type_id__volatile;
}

static void
_bala_baladoc_api_error_domain_get_property (GObject * object,
                                             guint property_id,
                                             GValue * value,
                                             GParamSpec * pspec)
{
	BaladocApiErrorDomain * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_ERROR_DOMAIN, BaladocApiErrorDomain);
	switch (property_id) {
		case BALADOC_API_ERROR_DOMAIN_NODE_TYPE_PROPERTY:
		g_value_set_enum (value, baladoc_api_node_get_node_type ((BaladocApiNode*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

