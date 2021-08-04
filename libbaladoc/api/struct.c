/* struct.c generated by balac, the Vala compiler
 * generated from struct.bala, do not modify */

/* struct.bala
 *
 * Copyright (C) 2011  Florian Brosch
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
#include <balagee.h>
#include <glib-object.h>
#include <bala.h>
#include <balacodegen.h>

enum  {
	BALADOC_API_STRUCT_0_PROPERTY,
	BALADOC_API_STRUCT_BASE_TYPE_PROPERTY,
	BALADOC_API_STRUCT_NODE_TYPE_PROPERTY,
	BALADOC_API_STRUCT_NUM_PROPERTIES
};
static GParamSpec* baladoc_api_struct_properties[BALADOC_API_STRUCT_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _baladoc_api_signature_builder_unref0(var) ((var == NULL) ? NULL : (var = (baladoc_api_signature_builder_unref (var), NULL)))

struct _ValadocApiStructPrivate {
	gchar* dup_function_cname;
	gchar* copy_function_cname;
	gchar* free_function_cname;
	gchar* destroy_function_cname;
	gchar* type_id;
	gchar* cname;
	ValadocApiTypeReference* _base_type;
	ValaSet* _known_child_structs;
};

static gint ValadocApiStruct_private_offset;
static gpointer baladoc_api_struct_parent_class = NULL;

static void baladoc_api_struct_real_accept (ValadocApiNode* base,
                                     ValadocApiVisitor* visitor);
static ValadocContentInline* baladoc_api_struct_real_build_signature (ValadocApiItem* base);
static void baladoc_api_struct_finalize (GObject * obj);
static GType baladoc_api_struct_get_type_once (void);
static void _bala_baladoc_api_struct_get_property (GObject * object,
                                            guint property_id,
                                            GValue * value,
                                            GParamSpec * pspec);
static void _bala_baladoc_api_struct_set_property (GObject * object,
                                            guint property_id,
                                            const GValue * value,
                                            GParamSpec * pspec);

static inline gpointer
baladoc_api_struct_get_instance_private (ValadocApiStruct* self)
{
	return G_STRUCT_MEMBER_P (self, ValadocApiStruct_private_offset);
}

ValadocApiStruct*
baladoc_api_struct_construct (GType object_type,
                              ValadocApiNode* parent,
                              ValadocApiSourceFile* file,
                              const gchar* name,
                              ValaSymbolAccessibility accessibility,
                              ValadocApiSourceComment* comment,
                              ValaStruct* data)
{
	ValadocApiStruct * self = NULL;
	gboolean _tmp0_ = FALSE;
	ValaDataType* _tmp1_;
	ValaDataType* _tmp2_;
	gboolean is_basic_type = FALSE;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	g_return_val_if_fail (parent != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (data != NULL, NULL);
	_tmp1_ = bala_struct_get_base_type (data);
	_tmp2_ = _tmp1_;
	if (_tmp2_ == NULL) {
		gboolean _tmp3_ = FALSE;
		gboolean _tmp4_ = FALSE;
		if (bala_struct_is_boolean_type (data)) {
			_tmp4_ = TRUE;
		} else {
			_tmp4_ = bala_struct_is_floating_type (data);
		}
		if (_tmp4_) {
			_tmp3_ = TRUE;
		} else {
			_tmp3_ = bala_struct_is_integer_type (data);
		}
		_tmp0_ = _tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	is_basic_type = _tmp0_;
	self = (ValadocApiStruct*) baladoc_api_typesymbol_construct (object_type, parent, file, name, accessibility, comment, is_basic_type, (ValaTypeSymbol*) data);
	_tmp5_ = bala_get_ccode_dup_function ((ValaTypeSymbol*) data);
	_g_free0 (self->priv->dup_function_cname);
	self->priv->dup_function_cname = _tmp5_;
	_tmp6_ = bala_get_ccode_copy_function ((ValaTypeSymbol*) data);
	_g_free0 (self->priv->copy_function_cname);
	self->priv->copy_function_cname = _tmp6_;
	_tmp7_ = bala_get_ccode_free_function ((ValaTypeSymbol*) data);
	_g_free0 (self->priv->free_function_cname);
	self->priv->free_function_cname = _tmp7_;
	_tmp8_ = bala_get_ccode_destroy_function ((ValaTypeSymbol*) data);
	_g_free0 (self->priv->destroy_function_cname);
	self->priv->destroy_function_cname = _tmp8_;
	_tmp9_ = bala_get_ccode_name ((ValaCodeNode*) data);
	_g_free0 (self->priv->cname);
	self->priv->cname = _tmp9_;
	_tmp10_ = bala_get_ccode_type_id ((ValaCodeNode*) data);
	_g_free0 (self->priv->type_id);
	self->priv->type_id = _tmp10_;
	return self;
}

ValadocApiStruct*
baladoc_api_struct_new (ValadocApiNode* parent,
                        ValadocApiSourceFile* file,
                        const gchar* name,
                        ValaSymbolAccessibility accessibility,
                        ValadocApiSourceComment* comment,
                        ValaStruct* data)
{
	return baladoc_api_struct_construct (BALADOC_API_TYPE_STRUCT, parent, file, name, accessibility, comment, data);
}

ValadocApiTypeReference*
baladoc_api_struct_get_base_type (ValadocApiStruct* self)
{
	ValadocApiTypeReference* result;
	ValadocApiTypeReference* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_base_type;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

void
baladoc_api_struct_set_base_type (ValadocApiStruct* self,
                                  ValadocApiTypeReference* value)
{
	ValadocApiTypeReference* old_value;
	g_return_if_fail (self != NULL);
	old_value = baladoc_api_struct_get_base_type (self);
	if (old_value != value) {
		ValadocApiTypeReference* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_base_type);
		self->priv->_base_type = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, baladoc_api_struct_properties[BALADOC_API_STRUCT_BASE_TYPE_PROPERTY]);
	}
}

/**
 * Returns the name of this struct as it is used in C.
 */
gchar*
baladoc_api_struct_get_cname (ValadocApiStruct* self)
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
baladoc_api_struct_get_type_id (ValadocApiStruct* self)
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

/**
 * Returns the C function name that duplicates instances of this data
 * type.
 */
gchar*
baladoc_api_struct_get_dup_function_cname (ValadocApiStruct* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->dup_function_cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Returns the C function name that copies instances of this data
 * type.
 */
gchar*
baladoc_api_struct_get_copy_function_cname (ValadocApiStruct* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->copy_function_cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Returns the C function name that frees instances of this data type.
 */
gchar*
baladoc_api_struct_get_free_function_cname (ValadocApiStruct* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->free_function_cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

/**
 * Returns the C function name that destroys instances of this data type.
 */
gchar*
baladoc_api_struct_get_destroy_function_cname (ValadocApiStruct* self)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->destroy_function_cname;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

static ValadocApiNodeType
baladoc_api_struct_real_get_node_type (ValadocApiNode* base)
{
	ValadocApiNodeType result;
	ValadocApiStruct* self;
	self = (ValadocApiStruct*) base;
	result = BALADOC_API_NODE_TYPE_STRUCT;
	return result;
}

/**
 * {@inheritDoc}
 */
static void
baladoc_api_struct_real_accept (ValadocApiNode* base,
                                ValadocApiVisitor* visitor)
{
	ValadocApiStruct * self;
	self = (ValadocApiStruct*) base;
	g_return_if_fail (visitor != NULL);
	baladoc_api_visitor_visit_struct (visitor, self);
}

/**
 * Returns a list of all known structs based on this struct
 */
static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

ValaCollection*
baladoc_api_struct_get_known_child_structs (ValadocApiStruct* self)
{
	ValaSet* _tmp0_;
	ValaCollection* _tmp1_;
	ValaCollection* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_known_child_structs;
	_tmp1_ = _bala_iterable_ref0 ((ValaCollection*) _tmp0_);
	result = _tmp1_;
	return result;
}

void
baladoc_api_struct_register_child_struct (ValadocApiStruct* self,
                                          ValadocApiStruct* stru)
{
	ValadocApiTypeReference* _tmp0_;
	ValaSet* _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stru != NULL);
	_tmp0_ = self->priv->_base_type;
	if (_tmp0_ != NULL) {
		ValadocApiTypeReference* _tmp1_;
		ValadocApiItem* _tmp2_;
		ValadocApiItem* _tmp3_;
		_tmp1_ = self->priv->_base_type;
		_tmp2_ = baladoc_api_typereference_get_data_type (_tmp1_);
		_tmp3_ = _tmp2_;
		baladoc_api_struct_register_child_struct (G_TYPE_CHECK_INSTANCE_CAST (_tmp3_, BALADOC_API_TYPE_STRUCT, ValadocApiStruct), stru);
	}
	_tmp4_ = self->priv->_known_child_structs;
	bala_collection_add ((ValaCollection*) _tmp4_, stru);
}

/**
 * {@inheritDoc}
 */
static ValadocContentInline*
baladoc_api_struct_real_build_signature (ValadocApiItem* base)
{
	ValadocApiStruct * self;
	ValadocApiSignatureBuilder* signature = NULL;
	ValadocApiSignatureBuilder* _tmp0_;
	ValadocApiSignatureBuilder* _tmp1_;
	ValaSymbolAccessibility _tmp2_;
	ValaSymbolAccessibility _tmp3_;
	const gchar* _tmp4_;
	ValadocApiSignatureBuilder* _tmp5_;
	ValadocApiSignatureBuilder* _tmp6_;
	ValaList* type_parameters = NULL;
	ValaList* _tmp7_;
	ValaList* _tmp8_;
	gint _tmp9_;
	gint _tmp10_;
	ValadocApiTypeReference* _tmp27_;
	ValadocApiSignatureBuilder* _tmp33_;
	ValadocContentRun* _tmp34_;
	ValadocContentInline* result = NULL;
	self = (ValadocApiStruct*) base;
	_tmp0_ = baladoc_api_signature_builder_new ();
	signature = _tmp0_;
	_tmp1_ = signature;
	_tmp2_ = baladoc_api_symbol_get_accessibility ((ValadocApiSymbol*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = bala_symbol_accessibility_to_string (_tmp3_);
	baladoc_api_signature_builder_append_keyword (_tmp1_, _tmp4_, TRUE);
	_tmp5_ = signature;
	baladoc_api_signature_builder_append_keyword (_tmp5_, "struct", TRUE);
	_tmp6_ = signature;
	baladoc_api_signature_builder_append_symbol (_tmp6_, (ValadocApiNode*) self, TRUE);
	_tmp7_ = baladoc_api_node_get_children_by_type ((ValadocApiNode*) self, BALADOC_API_NODE_TYPE_TYPE_PARAMETER, FALSE);
	type_parameters = _tmp7_;
	_tmp8_ = type_parameters;
	_tmp9_ = bala_collection_get_size ((ValaCollection*) _tmp8_);
	_tmp10_ = _tmp9_;
	if (_tmp10_ > 0) {
		ValadocApiSignatureBuilder* _tmp11_;
		gboolean first = FALSE;
		ValadocApiSignatureBuilder* _tmp26_;
		_tmp11_ = signature;
		baladoc_api_signature_builder_append (_tmp11_, "<", FALSE);
		first = TRUE;
		{
			ValaList* _param_list = NULL;
			ValaList* _tmp12_;
			ValaList* _tmp13_;
			gint _param_size = 0;
			ValaList* _tmp14_;
			gint _tmp15_;
			gint _tmp16_;
			gint _param_index = 0;
			_tmp12_ = type_parameters;
			_tmp13_ = _bala_iterable_ref0 (_tmp12_);
			_param_list = _tmp13_;
			_tmp14_ = _param_list;
			_tmp15_ = bala_collection_get_size ((ValaCollection*) _tmp14_);
			_tmp16_ = _tmp15_;
			_param_size = _tmp16_;
			_param_index = -1;
			while (TRUE) {
				gint _tmp17_;
				gint _tmp18_;
				ValadocApiItem* param = NULL;
				ValaList* _tmp19_;
				gpointer _tmp20_;
				ValadocApiSignatureBuilder* _tmp22_;
				ValadocApiItem* _tmp23_;
				ValadocContentInline* _tmp24_;
				ValadocContentInline* _tmp25_;
				_param_index = _param_index + 1;
				_tmp17_ = _param_index;
				_tmp18_ = _param_size;
				if (!(_tmp17_ < _tmp18_)) {
					break;
				}
				_tmp19_ = _param_list;
				_tmp20_ = bala_list_get (_tmp19_, _param_index);
				param = (ValadocApiItem*) ((ValadocApiNode*) _tmp20_);
				if (!first) {
					ValadocApiSignatureBuilder* _tmp21_;
					_tmp21_ = signature;
					baladoc_api_signature_builder_append (_tmp21_, ",", FALSE);
				}
				_tmp22_ = signature;
				_tmp23_ = param;
				_tmp24_ = baladoc_api_item_get_signature (_tmp23_);
				_tmp25_ = _tmp24_;
				baladoc_api_signature_builder_append_content (_tmp22_, _tmp25_, FALSE);
				first = FALSE;
				_g_object_unref0 (param);
			}
			_bala_iterable_unref0 (_param_list);
		}
		_tmp26_ = signature;
		baladoc_api_signature_builder_append (_tmp26_, ">", FALSE);
	}
	_tmp27_ = self->priv->_base_type;
	if (_tmp27_ != NULL) {
		ValadocApiSignatureBuilder* _tmp28_;
		ValadocApiSignatureBuilder* _tmp29_;
		ValadocApiTypeReference* _tmp30_;
		ValadocContentInline* _tmp31_;
		ValadocContentInline* _tmp32_;
		_tmp28_ = signature;
		baladoc_api_signature_builder_append (_tmp28_, ":", TRUE);
		_tmp29_ = signature;
		_tmp30_ = self->priv->_base_type;
		_tmp31_ = baladoc_api_item_get_signature ((ValadocApiItem*) _tmp30_);
		_tmp32_ = _tmp31_;
		baladoc_api_signature_builder_append_content (_tmp29_, _tmp32_, TRUE);
	}
	_tmp33_ = signature;
	_tmp34_ = baladoc_api_signature_builder_get (_tmp33_);
	result = (ValadocContentInline*) _tmp34_;
	_bala_iterable_unref0 (type_parameters);
	_baladoc_api_signature_builder_unref0 (signature);
	return result;
}

static void
baladoc_api_struct_class_init (ValadocApiStructClass * klass,
                               gpointer klass_data)
{
	baladoc_api_struct_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &ValadocApiStruct_private_offset);
	((ValadocApiNodeClass *) klass)->accept = (void (*) (ValadocApiNode*, ValadocApiVisitor*)) baladoc_api_struct_real_accept;
	((ValadocApiItemClass *) klass)->build_signature = (ValadocContentInline* (*) (ValadocApiItem*)) baladoc_api_struct_real_build_signature;
	BALADOC_API_NODE_CLASS (klass)->get_node_type = baladoc_api_struct_real_get_node_type;
	G_OBJECT_CLASS (klass)->get_property = _bala_baladoc_api_struct_get_property;
	G_OBJECT_CLASS (klass)->set_property = _bala_baladoc_api_struct_set_property;
	G_OBJECT_CLASS (klass)->finalize = baladoc_api_struct_finalize;
	/**
	 * Specifies the base struct.
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_STRUCT_BASE_TYPE_PROPERTY, baladoc_api_struct_properties[BALADOC_API_STRUCT_BASE_TYPE_PROPERTY] = g_param_spec_object ("base-type", "base-type", "base-type", BALADOC_API_TYPE_TYPEREFERENCE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	/**
	 * {@inheritDoc}
	 */
	g_object_class_install_property (G_OBJECT_CLASS (klass), BALADOC_API_STRUCT_NODE_TYPE_PROPERTY, baladoc_api_struct_properties[BALADOC_API_STRUCT_NODE_TYPE_PROPERTY] = g_param_spec_enum ("node-type", "node-type", "node-type", BALADOC_API_TYPE_NODE_TYPE, 0, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static void
baladoc_api_struct_instance_init (ValadocApiStruct * self,
                                  gpointer klass)
{
	GHashFunc _tmp0_;
	GEqualFunc _tmp1_;
	ValaHashSet* _tmp2_;
	self->priv = baladoc_api_struct_get_instance_private (self);
	_tmp0_ = g_direct_hash;
	_tmp1_ = g_direct_equal;
	_tmp2_ = bala_hash_set_new (BALADOC_API_TYPE_STRUCT, (GBoxedCopyFunc) g_object_ref, (GDestroyNotify) g_object_unref, _tmp0_, _tmp1_);
	self->priv->_known_child_structs = (ValaSet*) _tmp2_;
}

static void
baladoc_api_struct_finalize (GObject * obj)
{
	ValadocApiStruct * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_STRUCT, ValadocApiStruct);
	_g_free0 (self->priv->dup_function_cname);
	_g_free0 (self->priv->copy_function_cname);
	_g_free0 (self->priv->free_function_cname);
	_g_free0 (self->priv->destroy_function_cname);
	_g_free0 (self->priv->type_id);
	_g_free0 (self->priv->cname);
	_g_object_unref0 (self->priv->_base_type);
	_bala_iterable_unref0 (self->priv->_known_child_structs);
	G_OBJECT_CLASS (baladoc_api_struct_parent_class)->finalize (obj);
}

/**
 * Represents a struct declaration.
 */
static GType
baladoc_api_struct_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocApiStructClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_struct_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValadocApiStruct), 0, (GInstanceInitFunc) baladoc_api_struct_instance_init, NULL };
	GType baladoc_api_struct_type_id;
	baladoc_api_struct_type_id = g_type_register_static (BALADOC_API_TYPE_TYPESYMBOL, "ValadocApiStruct", &g_define_type_info, 0);
	ValadocApiStruct_private_offset = g_type_add_instance_private (baladoc_api_struct_type_id, sizeof (ValadocApiStructPrivate));
	return baladoc_api_struct_type_id;
}

GType
baladoc_api_struct_get_type (void)
{
	static volatile gsize baladoc_api_struct_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_struct_type_id__volatile)) {
		GType baladoc_api_struct_type_id;
		baladoc_api_struct_type_id = baladoc_api_struct_get_type_once ();
		g_once_init_leave (&baladoc_api_struct_type_id__volatile, baladoc_api_struct_type_id);
	}
	return baladoc_api_struct_type_id__volatile;
}

static void
_bala_baladoc_api_struct_get_property (GObject * object,
                                       guint property_id,
                                       GValue * value,
                                       GParamSpec * pspec)
{
	ValadocApiStruct * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_STRUCT, ValadocApiStruct);
	switch (property_id) {
		case BALADOC_API_STRUCT_BASE_TYPE_PROPERTY:
		g_value_set_object (value, baladoc_api_struct_get_base_type (self));
		break;
		case BALADOC_API_STRUCT_NODE_TYPE_PROPERTY:
		g_value_set_enum (value, baladoc_api_node_get_node_type ((ValadocApiNode*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_bala_baladoc_api_struct_set_property (GObject * object,
                                       guint property_id,
                                       const GValue * value,
                                       GParamSpec * pspec)
{
	ValadocApiStruct * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, BALADOC_API_TYPE_STRUCT, ValadocApiStruct);
	switch (property_id) {
		case BALADOC_API_STRUCT_BASE_TYPE_PROPERTY:
		baladoc_api_struct_set_base_type (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
