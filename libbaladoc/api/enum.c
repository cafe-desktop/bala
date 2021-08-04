/* enum.c generated by balac, the Vala compiler
 * generated from enum.bala, do not modify */

/* enum.bala
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
	BALADOC_API_ENUM_0_PROPERTY,
	BALADOC_API_ENUM_NODE_TYPE_PROPERTY,
	BALADOC_API_ENUM_NUM_PROPERTIES
};
static GParamSpec* baladoc_api_enum_properties[BALADOC_API_ENUM_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _baladoc_api_signature_builder_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_api_signature_builder_unref (var), NULL)))

struct _ValadocApiEnumPrivate {
	gchar* cname;
	gchar* type_id;
};

static gint ValadocApiEnum_private_offset;
static gpointer baladoc_api_enum_parent_class = NULL;

static void baladoc_api_enum_real_accept (ValadocApiNode* base,
                                   ValadocApiVisitor* visitor);
static ValadocContentInline* baladoc_api_enum_real_build_signature (ValadocApiItem* base);
static void baladoc_api_enum_finalize (GObject * obj);
static GType baladoc_api_enum_get_type_once (void);
static void _bala_baladoc_api_enum_get_property (GObject * object,
                                          guint property_id,
                                          GValue * value,
                                          GParamSpec * pspec);

static inline gpointer
baladoc_api_enum_get_instance_private (ValadocApiEnum* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocApiEnum_private_offset);
}

ValadocApiEnum*
baladoc_api_enum_construct (GType object_type,
                            ValadocApiNode* parent,
                            ValadocApiSourceFile* file,
                            const gchar* name,
                            ValaSymbolAccessibility accessibility,
                            ValadocApiSourceComment* comment,
                            ValaEnum* data)
{
	ValadocApiEnum * self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (ValadocApiEnum*) baladoc_api_typesymbol_construct (object_type, parent, file, name, accessibility, comment, FALSE, (ValaTypeSymbol*) data);
	_tmp0_ = bala_get_ccode_name ((ValaCodeNode*) data);
	_g_free0 (self->priv->cname);
	self->priv->cname = _tmp0_;
	_tmp1_ = bala_get_ccode_type_id ((ValaCodeNode*) data);
	_g_free0 (self->priv->type_id);
	self->priv->type_id = _tmp1_;
	return self;
}

ValadocApiEnum*
baladoc_api_enum_new (ValadocApiNode* parent,
                      ValadocApiSourceFile* file,
                      const gchar* name,
                      ValaSymbolAccessibility accessibility,
                      ValadocApiSourceComment* comment,
                      ValaEnum* data)
{
	return baladoc_api_enum_construct (BALADOC_API_TYPE_ENUM, parent, file, name, accessibility, comment, data);
}

/**
 * Returns the name of this enum as it is used in C.
 */
gchar*
baladoc_api_enum_get_cname (ValadocApiEnum* self)
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
 * Returns the C symbol representing the runtime type id for this data type.
 */
gchar*
baladoc_api_enum_get_type_id (ValadocApiEnum* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->type_id;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

static ValadocApiNodeType
baladoc_api_enum_real_get_node_type (ValadocApiNode* base)
{
	ValadocApiNodeType result;
	ValadocApiEnum* self;
	self = (ValadocApiEnum*) base;
	result = BALADOC_API_NODE_TYPE_ENUM;
	return result;
}

/**
 * {@inheritDoc}
 */
static void
baladoc_api_enum_real_accept (ValadocApiNode* base,
                              ValadocApiVisitor* visitor)
{
	ValadocApiEnum * self;
	self = (ValadocApiEnum*) base;
	g_return_if_fail (visitor != NULL);
	baladoc_api_visitor_visit_enum (visitor, self);
}

/**
 * {@inheritDoc}
 */
static ValadocContentInline*
baladoc_api_enum_real_build_signature (ValadocApiItem* base)
{
	ValadocApiEnum * self;
	ValadocApiSignatureBuilder* _tmp0_;
	ValadocApiSignatureBuilder* _tmp1_;
	ValaSymbolAccessibility _tmp2_;
	ValaSymbolAccessibility _tmp3_;
	const gchar* _tmp4_;
	ValadocApiSignatureBuilder* _tmp5_;
	ValadocApiSignatureBuilder* _tmp6_;
	ValadocApiSignatureBuilder* _tmp7_;
	ValadocContentRun* _tmp8_;
	ValadocContentInline* _tmp9_;
	ValadocContentInline* result = NULL;
	self = (ValadocApiEnum*) base;
	_tmp0_ = baladoc_api_signature_builder_new ();
	_tmp1_ = _tmp0_;
	_tmp2_ = baladoc_api_symbol_get_accessibility ((ValadocApiSymbol*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = bala_symbol_accessibility_to_string (_tmp3_);
	_tmp5_ = baladoc_api_signature_builder_append_keyword (_tmp1_, _tmp4_, TRUE);
	_tmp6_ = baladoc_api_signature_builder_append_keyword (_tmp5_, "enum", TRUE);
	_tmp7_ = baladoc_api_signature_builder_append_symbol (_tmp6_, (ValadocApiNode*) self, TRUE);
	_tmp8_ = baladoc_api_signature_builder_get (_tmp7_);
	_tmp9_ = (ValadocContentInline*) _tmp8_;
	_baladoc_api_signature_builder_unref0 (_tmp1_);
	result = _tmp9_;
	return result;
}

static void
baladoc_api_enum_class_init (ValadocApiEnumClass * klass,
                             gpointer klass_data)
{
	baladoc_api_enum_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocApiEnum_private_offset);
	((ValadocApiNodeClass *) klass)->accept = (void (*) (ValadocApiNode*, ValadocApiVisitor*)) baladoc_api_enum_real_accept;
	((ValadocApiItemClass *) klass)->build_signature = (ValadocContentInline* (*) (ValadocApiItem*)) baladoc_api_enum_real_build_signature;
	BALADOC_API_NODE_CLASS (klass)->get_node_type = baladoc_api_enum_real_get_node_type;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_api_enum_get_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_api_enum_finalize;
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_ENUM_NODE_TYPE_PROPERTY, baladoc_api_enum_properties[BALADOC_API_ENUM_NODE_TYPE_PROPERTY] = g_param_spec_enum ("node-type", "node-type", "node-type", BALADOC_API_TYPE_NODE_TYPE, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
baladoc_api_enum_instance_init (ValadocApiEnum * self,
                                gpointer klass)
{
	self->priv = baladoc_api_enum_get_instance_private (self);
}

static void
baladoc_api_enum_finalize (GObject * obj)
{
	ValadocApiEnum * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_ENUM, ValadocApiEnum);
	_g_free0 (self->priv->cname);
	_g_free0 (self->priv->type_id);
	G_OBJECT_CLASS (baladoc_api_enum_parent_class)->finalize (obj);
}

/**
 * Represents an enum declaration.
 */
static GType
baladoc_api_enum_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocApiEnumClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_enum_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocApiEnum), 0, (GInstanceInitFunc) baladoc_api_enum_instance_init, NULL };
	GType baladoc_api_enum_type_id;
	baladoc_api_enum_type_id = g_type_register_static (BALADOC_API_TYPE_TYPESYMBOL, "ValadocApiEnum", &g_define_type_info, 0);
	ValadocApiEnum_private_offset = g_type_add_instance_private (baladoc_api_enum_type_id, sizeof (ValadocApiEnumPrivate));
	return baladoc_api_enum_type_id;
}

GType
baladoc_api_enum_get_type (void)
{
	static volatile gsize baladoc_api_enum_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_enum_type_id__volatile)) {
		GType baladoc_api_enum_type_id;
		baladoc_api_enum_type_id = baladoc_api_enum_get_type_once ();
		g_once_init_leave (&baladoc_api_enum_type_id__volatile, baladoc_api_enum_type_id);
	}
	return baladoc_api_enum_type_id__volatile;
}

static void
_bala_baladoc_api_enum_get_property (GObject * object,
                                     guint property_id,
                                     GValue * value,
                                     GParamSpec * pspec)
{
	ValadocApiEnum * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_ENUM, ValadocApiEnum);
	switch (property_id) {
		case BALADOC_API_ENUM_NODE_TYPE_PROPERTY:
		g_value_set_enum (value, baladoc_api_node_get_node_type ((ValadocApiNode*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
