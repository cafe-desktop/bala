/* balacomment.c generated by balac, the Vala compiler
 * generated from balacomment.bala, do not modify */

/* balacomment.bala
 *
 * Copyright (C) 2008-2009  Florian Brosch
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

#include "bala.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gobject/gvaluecollector.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_source_reference_unref0(var) ((var == NULL) ? NULL : (var = (bala_source_reference_unref (var), NULL)))
typedef struct _ValaParamSpecComment ValaParamSpecComment;

struct _ValaCommentPrivate {
	gchar* _content;
	ValaSourceReference* _source_reference;
};

struct _ValaParamSpecComment {
	GParamSpec parent_instance;
};

static gint ValaComment_private_offset;
static gpointer bala_comment_parent_class = NULL;

static void bala_comment_finalize (ValaComment * obj);
static GType bala_comment_get_type_once (void);

static inline gpointer
bala_comment_get_instance_private (ValaComment* self)
{
	return G_STRUCT_MEMBER_P (self, ValaComment_private_offset);
}

ValaComment*
bala_comment_construct (GType object_type,
                        const gchar* comment,
                        ValaSourceReference* _source_reference)
{
	ValaComment* self = NULL;
	g_return_val_if_fail (comment != NULL, NULL);
	g_return_val_if_fail (_source_reference != NULL, NULL);
	self = (ValaComment*) g_type_create_instance (object_type);
	bala_comment_set_source_reference (self, _source_reference);
	bala_comment_set_content (self, comment);
	return self;
}

ValaComment*
bala_comment_new (const gchar* comment,
                  ValaSourceReference* _source_reference)
{
	return bala_comment_construct (BALA_TYPE_COMMENT, comment, _source_reference);
}

const gchar*
bala_comment_get_content (ValaComment* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_content;
	result = _tmp0_;
	return result;
}

void
bala_comment_set_content (ValaComment* self,
                          const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_content);
	self->priv->_content = _tmp0_;
}

ValaSourceReference*
bala_comment_get_source_reference (ValaComment* self)
{
	ValaSourceReference* result;
	ValaSourceReference* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_source_reference;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_source_reference_ref0 (gpointer self)
{
	return self ? bala_source_reference_ref (self) : NULL;
}

void
bala_comment_set_source_reference (ValaComment* self,
                                   ValaSourceReference* value)
{
	ValaSourceReference* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_source_reference_ref0 (value);
	_bala_source_reference_unref0 (self->priv->_source_reference);
	self->priv->_source_reference = _tmp0_;
}

static void
bala_value_comment_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
bala_value_comment_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		bala_comment_unref (value->data[0].v_pointer);
	}
}

static void
bala_value_comment_copy_value (const GValue* src_value,
                               GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = bala_comment_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
bala_value_comment_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
bala_value_comment_collect_value (GValue* value,
                                  guint n_collect_values,
                                  GTypeCValue* collect_values,
                                  guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		ValaComment * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = bala_comment_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
bala_value_comment_lcopy_value (const GValue* value,
                                guint n_collect_values,
                                GTypeCValue* collect_values,
                                guint collect_flags)
{
	ValaComment ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = bala_comment_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
bala_param_spec_comment (const gchar* name,
                         const gchar* nick,
                         const gchar* blurb,
                         GType object_type,
                         GParamFlags flags)
{
	ValaParamSpecComment* spec;
	g_return_val_if_fail (g_type_is_a (object_type, BALA_TYPE_COMMENT), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
bala_value_get_comment (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_COMMENT), NULL);
	return value->data[0].v_pointer;
}

void
bala_value_set_comment (GValue* value,
                        gpointer v_object)
{
	ValaComment * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_COMMENT));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_COMMENT));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		bala_comment_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		bala_comment_unref (old);
	}
}

void
bala_value_take_comment (GValue* value,
                         gpointer v_object)
{
	ValaComment * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_COMMENT));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_COMMENT));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		bala_comment_unref (old);
	}
}

static void
bala_comment_class_init (ValaCommentClass * klass,
                         gpointer klass_data)
{
	bala_comment_parent_class = g_type_class_peek_parent (klass);
	((ValaCommentClass *) klass)->finalize = bala_comment_finalize;
	g_type_class_adjust_private_offset (klass, &ValaComment_private_offset);
}

static void
bala_comment_instance_init (ValaComment * self,
                            gpointer klass)
{
	self->priv = bala_comment_get_instance_private (self);
	self->ref_count = 1;
}

static void
bala_comment_finalize (ValaComment * obj)
{
	ValaComment * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_COMMENT, ValaComment);
	g_signal_handlers_destroy (self);
	_g_free0 (self->priv->_content);
	_bala_source_reference_unref0 (self->priv->_source_reference);
}

/**
 * A documentation comment used by baladoc
 */
static GType
bala_comment_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { bala_value_comment_init, bala_value_comment_free_value, bala_value_comment_copy_value, bala_value_comment_peek_pointer, "p", bala_value_comment_collect_value, "p", bala_value_comment_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (ValaCommentClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_comment_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaComment), 0, (GInstanceInitFunc) bala_comment_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType bala_comment_type_id;
	bala_comment_type_id = g_type_register_fundamental (g_type_fundamental_next (), "ValaComment", &g_define_type_info, &g_define_type_fundamental_info, 0);
	ValaComment_private_offset = g_type_add_instance_private (bala_comment_type_id, sizeof (ValaCommentPrivate));
	return bala_comment_type_id;
}

GType
bala_comment_get_type (void)
{
	static volatile gsize bala_comment_type_id__volatile = 0;
	if (g_once_init_enter (&bala_comment_type_id__volatile)) {
		GType bala_comment_type_id;
		bala_comment_type_id = bala_comment_get_type_once ();
		g_once_init_leave (&bala_comment_type_id__volatile, bala_comment_type_id);
	}
	return bala_comment_type_id__volatile;
}

gpointer
bala_comment_ref (gpointer instance)
{
	ValaComment * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
bala_comment_unref (gpointer instance)
{
	ValaComment * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		BALA_COMMENT_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}
