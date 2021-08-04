/* valatargetvalue.c generated by valac, the Vala compiler
 * generated from valatargetvalue.vala, do not modify */

/* valatargetvalue.vala
 *
 * Copyright (C) 2010  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "vala.h"
#include <glib.h>
#include <gobject/gvaluecollector.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
typedef struct _ValaParamSpecTargetValue ValaParamSpecTargetValue;

struct _ValaTargetValuePrivate {
	ValaDataType* _value_type;
	ValaDataType* _actual_value_type;
};

struct _ValaParamSpecTargetValue {
	GParamSpec parent_instance;
};

static gint ValaTargetValue_private_offset;
static gpointer vala_target_value_parent_class = NULL;

static void vala_target_value_finalize (ValaTargetValue * obj);
static GType vala_target_value_get_type_once (void);

static inline gpointer
vala_target_value_get_instance_private (ValaTargetValue* self)
{
	return G_STRUCT_MEMBER_P (self, ValaTargetValue_private_offset);
}

ValaDataType*
vala_target_value_get_value_type (ValaTargetValue* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_value_type;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_target_value_set_value_type (ValaTargetValue* self,
                                  ValaDataType* value)
{
	ValaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_value_type);
	self->priv->_value_type = _tmp0_;
}

ValaDataType*
vala_target_value_get_actual_value_type (ValaTargetValue* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_actual_value_type;
	result = _tmp0_;
	return result;
}

void
vala_target_value_set_actual_value_type (ValaTargetValue* self,
                                         ValaDataType* value)
{
	ValaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_actual_value_type);
	self->priv->_actual_value_type = _tmp0_;
}

ValaTargetValue*
vala_target_value_construct (GType object_type,
                             ValaDataType* value_type)
{
	ValaTargetValue* self = NULL;
	self = (ValaTargetValue*) g_type_create_instance (object_type);
	vala_target_value_set_value_type (self, value_type);
	return self;
}

static void
vala_value_target_value_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
vala_value_target_value_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		vala_target_value_unref (value->data[0].v_pointer);
	}
}

static void
vala_value_target_value_copy_value (const GValue* src_value,
                                    GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = vala_target_value_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
vala_value_target_value_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
vala_value_target_value_collect_value (GValue* value,
                                       guint n_collect_values,
                                       GTypeCValue* collect_values,
                                       guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		ValaTargetValue * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = vala_target_value_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
vala_value_target_value_lcopy_value (const GValue* value,
                                     guint n_collect_values,
                                     GTypeCValue* collect_values,
                                     guint collect_flags)
{
	ValaTargetValue ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = vala_target_value_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
vala_param_spec_target_value (const gchar* name,
                              const gchar* nick,
                              const gchar* blurb,
                              GType object_type,
                              GParamFlags flags)
{
	ValaParamSpecTargetValue* spec;
	g_return_val_if_fail (g_type_is_a (object_type, BALA_TYPE_TARGET_VALUE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
vala_value_get_target_value (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_TARGET_VALUE), NULL);
	return value->data[0].v_pointer;
}

void
vala_value_set_target_value (GValue* value,
                             gpointer v_object)
{
	ValaTargetValue * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_TARGET_VALUE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_TARGET_VALUE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		vala_target_value_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_target_value_unref (old);
	}
}

void
vala_value_take_target_value (GValue* value,
                              gpointer v_object)
{
	ValaTargetValue * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_TARGET_VALUE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_TARGET_VALUE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_target_value_unref (old);
	}
}

static void
vala_target_value_class_init (ValaTargetValueClass * klass,
                              gpointer klass_data)
{
	vala_target_value_parent_class = g_type_class_peek_parent (klass);
	((ValaTargetValueClass *) klass)->finalize = vala_target_value_finalize;
	g_type_class_adjust_private_offset (klass, &ValaTargetValue_private_offset);
}

static void
vala_target_value_instance_init (ValaTargetValue * self,
                                 gpointer klass)
{
	self->priv = vala_target_value_get_instance_private (self);
	self->ref_count = 1;
}

static void
vala_target_value_finalize (ValaTargetValue * obj)
{
	ValaTargetValue * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_TARGET_VALUE, ValaTargetValue);
	g_signal_handlers_destroy (self);
	_vala_code_node_unref0 (self->priv->_value_type);
	_vala_code_node_unref0 (self->priv->_actual_value_type);
}

static GType
vala_target_value_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { vala_value_target_value_init, vala_value_target_value_free_value, vala_value_target_value_copy_value, vala_value_target_value_peek_pointer, "p", vala_value_target_value_collect_value, "p", vala_value_target_value_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (ValaTargetValueClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_target_value_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaTargetValue), 0, (GInstanceInitFunc) vala_target_value_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType vala_target_value_type_id;
	vala_target_value_type_id = g_type_register_fundamental (g_type_fundamental_next (), "ValaTargetValue", &g_define_type_info, &g_define_type_fundamental_info, G_TYPE_FLAG_ABSTRACT);
	ValaTargetValue_private_offset = g_type_add_instance_private (vala_target_value_type_id, sizeof (ValaTargetValuePrivate));
	return vala_target_value_type_id;
}

GType
vala_target_value_get_type (void)
{
	static volatile gsize vala_target_value_type_id__volatile = 0;
	if (g_once_init_enter (&vala_target_value_type_id__volatile)) {
		GType vala_target_value_type_id;
		vala_target_value_type_id = vala_target_value_get_type_once ();
		g_once_init_leave (&vala_target_value_type_id__volatile, vala_target_value_type_id);
	}
	return vala_target_value_type_id__volatile;
}

gpointer
vala_target_value_ref (gpointer instance)
{
	ValaTargetValue * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
vala_target_value_unref (gpointer instance)
{
	ValaTargetValue * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		BALA_TARGET_VALUE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

