/* typesymbol.c generated by valac, the Vala compiler
 * generated from typesymbol.vala, do not modify */

/* typesymbol.vala
 *
 * Copyright (C) 2008-2009 Florian Brosch, Didier Villevalois
 * Copyright (C) 2011      Florian Brosch
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

#include "valadoc.h"
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <vala.h>
#include <valacodegen.h>

enum  {
	BALADOC_API_TYPESYMBOL_0_PROPERTY,
	BALADOC_API_TYPESYMBOL_IS_BASIC_TYPE_PROPERTY,
	BALADOC_API_TYPESYMBOL_NUM_PROPERTIES
};
static GParamSpec* valadoc_api_typesymbol_properties[BALADOC_API_TYPESYMBOL_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValadocApiTypeSymbolPrivate {
	gboolean _is_basic_type;
};

static gint ValadocApiTypeSymbol_private_offset;
static gpointer valadoc_api_typesymbol_parent_class = NULL;

static void valadoc_api_typesymbol_set_is_basic_type (ValadocApiTypeSymbol* self,
                                               gboolean value);
static void valadoc_api_typesymbol_finalize (GObject * obj);
static GType valadoc_api_typesymbol_get_type_once (void);
static void _vala_valadoc_api_typesymbol_get_property (GObject * object,
                                                guint property_id,
                                                GValue * value,
                                                GParamSpec * pspec);
static void _vala_valadoc_api_typesymbol_set_property (GObject * object,
                                                guint property_id,
                                                const GValue * value,
                                                GParamSpec * pspec);

static inline gpointer
valadoc_api_typesymbol_get_instance_private (ValadocApiTypeSymbol* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocApiTypeSymbol_private_offset);
}

ValadocApiTypeSymbol*
valadoc_api_typesymbol_construct (GType object_type,
                                  ValadocApiNode* parent,
                                  ValadocApiSourceFile* file,
                                  const gchar* name,
                                  ValaSymbolAccessibility accessibility,
                                  ValadocApiSourceComment* comment,
                                  gboolean is_basic_type,
                                  ValaTypeSymbol* data)
{
	ValadocApiTypeSymbol * self = NULL;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	self = (ValadocApiTypeSymbol*) valadoc_api_symbol_construct (object_type, parent, file, name, accessibility, comment, (ValaSymbol*) data);
	valadoc_api_typesymbol_set_is_basic_type (self, is_basic_type);
	return self;
}

gboolean
valadoc_api_typesymbol_get_is_basic_type (ValadocApiTypeSymbol* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_basic_type;
	return result;
}

static void
valadoc_api_typesymbol_set_is_basic_type (ValadocApiTypeSymbol* self,
                                          gboolean value)
{
	gboolean old_value;
	g_return_if_fail (self != NULL);
	old_value = valadoc_api_typesymbol_get_is_basic_type (self);
	if (old_value != value) {
		self->priv->_is_basic_type = value;
		g_object_notify_by_pspec ((GObject *) self, valadoc_api_typesymbol_properties[BALADOC_API_TYPESYMBOL_IS_BASIC_TYPE_PROPERTY]);
	}
}

/**
 * Gets the name of the GType macro which represents the type symbol
 */
gchar*
valadoc_api_typesymbol_get_type_macro_name (ValadocApiTypeSymbol* self)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	ValaCodeNode* _tmp3_;
	ValaCodeNode* _tmp4_;
	ValaCodeNode* _tmp13_;
	ValaCodeNode* _tmp14_;
	gchar* _tmp15_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp3_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp4_ = _tmp3_;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp4_, BALA_TYPE_CLASS)) {
		ValaCodeNode* _tmp5_;
		ValaCodeNode* _tmp6_;
		gboolean _tmp7_;
		gboolean _tmp8_;
		_tmp5_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp6_ = _tmp5_;
		_tmp7_ = vala_class_get_is_compact (G_TYPE_CHECK_INSTANCE_CAST (_tmp6_, BALA_TYPE_CLASS, ValaClass));
		_tmp8_ = _tmp7_;
		_tmp2_ = _tmp8_;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		ValaCodeNode* _tmp9_;
		ValaCodeNode* _tmp10_;
		_tmp9_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp10_ = _tmp9_;
		_tmp1_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp10_, BALA_TYPE_ERROR_DOMAIN);
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		ValaCodeNode* _tmp11_;
		ValaCodeNode* _tmp12_;
		_tmp11_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp12_ = _tmp11_;
		_tmp0_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp12_, BALA_TYPE_DELEGATE);
	}
	if (_tmp0_) {
		result = NULL;
		return result;
	}
	_tmp13_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp14_ = _tmp13_;
	_tmp15_ = vala_get_ccode_type_id (_tmp14_);
	result = _tmp15_;
	return result;
}

/**
 * Gets the name of the GType macro which casts a type instance to the given type.
 */
gchar*
valadoc_api_typesymbol_get_type_cast_macro_name (ValadocApiTypeSymbol* self)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	ValaCodeNode* _tmp2_;
	ValaCodeNode* _tmp3_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp2_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp3_ = _tmp2_;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp3_, BALA_TYPE_CLASS)) {
		ValaCodeNode* _tmp4_;
		ValaCodeNode* _tmp5_;
		gboolean _tmp6_;
		gboolean _tmp7_;
		_tmp4_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp5_ = _tmp4_;
		_tmp6_ = vala_class_get_is_compact (G_TYPE_CHECK_INSTANCE_CAST (_tmp5_, BALA_TYPE_CLASS, ValaClass));
		_tmp7_ = _tmp6_;
		_tmp1_ = !_tmp7_;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		ValaCodeNode* _tmp8_;
		ValaCodeNode* _tmp9_;
		_tmp8_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp9_ = _tmp8_;
		_tmp0_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp9_, BALA_TYPE_INTERFACE);
	}
	if (_tmp0_) {
		ValaCodeNode* _tmp10_;
		ValaCodeNode* _tmp11_;
		gchar* _tmp12_;
		_tmp10_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp11_ = _tmp10_;
		_tmp12_ = vala_get_ccode_upper_case_name ((ValaSymbol*) G_TYPE_CHECK_INSTANCE_CAST (_tmp11_, BALA_TYPE_TYPESYMBOL, ValaTypeSymbol), NULL);
		result = _tmp12_;
		return result;
	} else {
		result = NULL;
		return result;
	}
}

/**
 * Gets the name of the GType macro which determines whether a type instance is of a given type.
 */
gchar*
valadoc_api_typesymbol_get_is_type_macro_name (ValadocApiTypeSymbol* self)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	ValaCodeNode* _tmp2_;
	ValaCodeNode* _tmp3_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp2_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp3_ = _tmp2_;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp3_, BALA_TYPE_CLASS)) {
		ValaCodeNode* _tmp4_;
		ValaCodeNode* _tmp5_;
		gboolean _tmp6_;
		gboolean _tmp7_;
		_tmp4_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp5_ = _tmp4_;
		_tmp6_ = vala_class_get_is_compact (G_TYPE_CHECK_INSTANCE_CAST (_tmp5_, BALA_TYPE_CLASS, ValaClass));
		_tmp7_ = _tmp6_;
		_tmp1_ = !_tmp7_;
	} else {
		_tmp1_ = FALSE;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		ValaCodeNode* _tmp8_;
		ValaCodeNode* _tmp9_;
		_tmp8_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp9_ = _tmp8_;
		_tmp0_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp9_, BALA_TYPE_INTERFACE);
	}
	if (_tmp0_) {
		ValaCodeNode* _tmp10_;
		ValaCodeNode* _tmp11_;
		gchar* _tmp12_;
		_tmp10_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp11_ = _tmp10_;
		_tmp12_ = vala_get_ccode_type_check_function (G_TYPE_CHECK_INSTANCE_CAST (_tmp11_, BALA_TYPE_TYPESYMBOL, ValaTypeSymbol));
		result = _tmp12_;
		return result;
	} else {
		result = NULL;
		return result;
	}
}

/**
 * Gets the name of the get_type() function which represents the type symbol
 */
gchar*
valadoc_api_typesymbol_get_type_function_name (ValadocApiTypeSymbol* self)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	ValaCodeNode* _tmp3_;
	ValaCodeNode* _tmp4_;
	ValaCodeNode* _tmp13_;
	ValaCodeNode* _tmp14_;
	gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	gchar* _tmp18_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp3_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp4_ = _tmp3_;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp4_, BALA_TYPE_CLASS)) {
		ValaCodeNode* _tmp5_;
		ValaCodeNode* _tmp6_;
		gboolean _tmp7_;
		gboolean _tmp8_;
		_tmp5_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp6_ = _tmp5_;
		_tmp7_ = vala_class_get_is_compact (G_TYPE_CHECK_INSTANCE_CAST (_tmp6_, BALA_TYPE_CLASS, ValaClass));
		_tmp8_ = _tmp7_;
		_tmp2_ = _tmp8_;
	} else {
		_tmp2_ = FALSE;
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		ValaCodeNode* _tmp9_;
		ValaCodeNode* _tmp10_;
		_tmp9_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp10_ = _tmp9_;
		_tmp1_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp10_, BALA_TYPE_ERROR_DOMAIN);
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		ValaCodeNode* _tmp11_;
		ValaCodeNode* _tmp12_;
		_tmp11_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
		_tmp12_ = _tmp11_;
		_tmp0_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp12_, BALA_TYPE_DELEGATE);
	}
	if (_tmp0_) {
		result = NULL;
		return result;
	}
	_tmp13_ = valadoc_api_item_get_data ((ValadocApiItem*) self);
	_tmp14_ = _tmp13_;
	_tmp15_ = vala_get_ccode_lower_case_name (_tmp14_, NULL);
	_tmp16_ = _tmp15_;
	_tmp17_ = g_strdup_printf ("%s_get_type", _tmp16_);
	_tmp18_ = _tmp17_;
	_g_free0 (_tmp16_);
	result = _tmp18_;
	return result;
}

static void
valadoc_api_typesymbol_class_init (ValadocApiTypeSymbolClass * klass,
                                   gpointer klass_data)
{
	valadoc_api_typesymbol_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocApiTypeSymbol_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_valadoc_api_typesymbol_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_valadoc_api_typesymbol_set_property;
	G_OBJECT_CLASS (klass)->finalize = valadoc_api_typesymbol_finalize;
	/**
	 * Specifies whether this symbol is a basic type (string, int, char, etc)
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_TYPESYMBOL_IS_BASIC_TYPE_PROPERTY, valadoc_api_typesymbol_properties[BALADOC_API_TYPESYMBOL_IS_BASIC_TYPE_PROPERTY] = g_param_spec_boolean ("is-basic-type", "is-basic-type", "is-basic-type", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
valadoc_api_typesymbol_instance_init (ValadocApiTypeSymbol * self,
                                      gpointer klass)
{
	self->priv = valadoc_api_typesymbol_get_instance_private (self);
}

static void
valadoc_api_typesymbol_finalize (GObject * obj)
{
	ValadocApiTypeSymbol * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_TYPESYMBOL, ValadocApiTypeSymbol);
	G_OBJECT_CLASS (valadoc_api_typesymbol_parent_class)->finalize (obj);
}

/**
 * Represents a runtime data type.
 */
static GType
valadoc_api_typesymbol_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocApiTypeSymbolClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_api_typesymbol_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocApiTypeSymbol), 0, (GInstanceInitFunc) valadoc_api_typesymbol_instance_init, NULL };
	GType valadoc_api_typesymbol_type_id;
	valadoc_api_typesymbol_type_id = g_type_register_static (BALADOC_API_TYPE_SYMBOL, "ValadocApiTypeSymbol", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	ValadocApiTypeSymbol_private_offset = g_type_add_instance_private (valadoc_api_typesymbol_type_id, sizeof (ValadocApiTypeSymbolPrivate));
	return valadoc_api_typesymbol_type_id;
}

GType
valadoc_api_typesymbol_get_type (void)
{
	static volatile gsize valadoc_api_typesymbol_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_api_typesymbol_type_id__volatile)) {
		GType valadoc_api_typesymbol_type_id;
		valadoc_api_typesymbol_type_id = valadoc_api_typesymbol_get_type_once ();
		g_once_init_leave (&valadoc_api_typesymbol_type_id__volatile, valadoc_api_typesymbol_type_id);
	}
	return valadoc_api_typesymbol_type_id__volatile;
}

static void
_vala_valadoc_api_typesymbol_get_property (GObject * object,
                                           guint property_id,
                                           GValue * value,
                                           GParamSpec * pspec)
{
	ValadocApiTypeSymbol * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_TYPESYMBOL, ValadocApiTypeSymbol);
	switch (property_id) {
		case BALADOC_API_TYPESYMBOL_IS_BASIC_TYPE_PROPERTY:
		g_value_set_boolean (value, valadoc_api_typesymbol_get_is_basic_type (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_valadoc_api_typesymbol_set_property (GObject * object,
                                           guint property_id,
                                           const GValue * value,
                                           GParamSpec * pspec)
{
	ValadocApiTypeSymbol * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_TYPESYMBOL, ValadocApiTypeSymbol);
	switch (property_id) {
		case BALADOC_API_TYPESYMBOL_IS_BASIC_TYPE_PROPERTY:
		valadoc_api_typesymbol_set_is_basic_type (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

