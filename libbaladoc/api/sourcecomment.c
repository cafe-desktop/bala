/* sourcecomment.c generated by balac, the Bala compiler
 * generated from sourcecomment.bala, do not modify */

/* sourcecomment.bala
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
#include <gobject/gvaluecollector.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _BaladocApiParamSpecSourceComment BaladocApiParamSpecSourceComment;

struct _BaladocApiSourceCommentPrivate {
	BaladocApiSourceFile* _file;
	gchar* _content;
	gint _first_line;
	gint _first_column;
	gint _last_line;
	gint _last_column;
};

struct _BaladocApiParamSpecSourceComment {
	GParamSpec parent_instance;
};

static gint BaladocApiSourceComment_private_offset;
static gpointer baladoc_api_source_comment_parent_class = NULL;

static void baladoc_api_source_comment_set_file (BaladocApiSourceComment* self,
                                          BaladocApiSourceFile* value);
static void baladoc_api_source_comment_set_content (BaladocApiSourceComment* self,
                                             const gchar* value);
static void baladoc_api_source_comment_set_first_line (BaladocApiSourceComment* self,
                                                gint value);
static void baladoc_api_source_comment_set_first_column (BaladocApiSourceComment* self,
                                                  gint value);
static void baladoc_api_source_comment_set_last_line (BaladocApiSourceComment* self,
                                               gint value);
static void baladoc_api_source_comment_set_last_column (BaladocApiSourceComment* self,
                                                 gint value);
static void baladoc_api_source_comment_finalize (BaladocApiSourceComment * obj);
static GType baladoc_api_source_comment_get_type_once (void);

static inline gpointer
baladoc_api_source_comment_get_instance_private (BaladocApiSourceComment* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocApiSourceComment_private_offset);
}

BaladocApiSourceFile*
baladoc_api_source_comment_get_file (BaladocApiSourceComment* self)
{
	BaladocApiSourceFile* result;
	BaladocApiSourceFile* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_file;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
baladoc_api_source_comment_set_file (BaladocApiSourceComment* self,
                                     BaladocApiSourceFile* value)
{
	BaladocApiSourceFile* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _g_object_ref0 (value);
	_g_object_unref0 (self->priv->_file);
	self->priv->_file = _tmp0_;
}

const gchar*
baladoc_api_source_comment_get_content (BaladocApiSourceComment* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_content;
	result = _tmp0_;
	return result;
}

static void
baladoc_api_source_comment_set_content (BaladocApiSourceComment* self,
                                        const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_content);
	self->priv->_content = _tmp0_;
}

gint
baladoc_api_source_comment_get_first_line (BaladocApiSourceComment* self)
{
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_first_line;
	return result;
}

static void
baladoc_api_source_comment_set_first_line (BaladocApiSourceComment* self,
                                           gint value)
{
	g_return_if_fail (self != NULL);
	self->priv->_first_line = value;
}

gint
baladoc_api_source_comment_get_first_column (BaladocApiSourceComment* self)
{
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_first_column;
	return result;
}

static void
baladoc_api_source_comment_set_first_column (BaladocApiSourceComment* self,
                                             gint value)
{
	g_return_if_fail (self != NULL);
	self->priv->_first_column = value;
}

gint
baladoc_api_source_comment_get_last_line (BaladocApiSourceComment* self)
{
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_last_line;
	return result;
}

static void
baladoc_api_source_comment_set_last_line (BaladocApiSourceComment* self,
                                          gint value)
{
	g_return_if_fail (self != NULL);
	self->priv->_last_line = value;
}

gint
baladoc_api_source_comment_get_last_column (BaladocApiSourceComment* self)
{
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_last_column;
	return result;
}

static void
baladoc_api_source_comment_set_last_column (BaladocApiSourceComment* self,
                                            gint value)
{
	g_return_if_fail (self != NULL);
	self->priv->_last_column = value;
}

BaladocApiSourceComment*
baladoc_api_source_comment_construct (GType object_type,
                                      const gchar* content,
                                      BaladocApiSourceFile* file,
                                      gint first_line,
                                      gint first_column,
                                      gint last_line,
                                      gint last_column)
{
	BaladocApiSourceComment* self = NULL;
	g_return_val_if_fail (content != NULL, NULL);
	g_return_val_if_fail (file != NULL, NULL);
	self = (BaladocApiSourceComment*) g_type_create_instance (object_type);
	baladoc_api_source_comment_set_first_column (self, first_column);
	baladoc_api_source_comment_set_last_column (self, last_column);
	baladoc_api_source_comment_set_first_line (self, first_line);
	baladoc_api_source_comment_set_last_line (self, last_line);
	baladoc_api_source_comment_set_content (self, content);
	baladoc_api_source_comment_set_file (self, file);
	return self;
}

BaladocApiSourceComment*
baladoc_api_source_comment_new (const gchar* content,
                                BaladocApiSourceFile* file,
                                gint first_line,
                                gint first_column,
                                gint last_line,
                                gint last_column)
{
	return baladoc_api_source_comment_construct (BALADOC_API_TYPE_SOURCE_COMMENT, content, file, first_line, first_column, last_line, last_column);
}

static void
baladoc_api_value_source_comment_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
baladoc_api_value_source_comment_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		baladoc_api_source_comment_unref (value->data[0].v_pointer);
	}
}

static void
baladoc_api_value_source_comment_copy_value (const GValue* src_value,
                                             GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = baladoc_api_source_comment_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
baladoc_api_value_source_comment_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
baladoc_api_value_source_comment_collect_value (GValue* value,
                                                guint n_collect_values,
                                                GTypeCValue* collect_values,
                                                guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		BaladocApiSourceComment * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = baladoc_api_source_comment_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
baladoc_api_value_source_comment_lcopy_value (const GValue* value,
                                              guint n_collect_values,
                                              GTypeCValue* collect_values,
                                              guint collect_flags)
{
	BaladocApiSourceComment ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = baladoc_api_source_comment_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
baladoc_api_param_spec_source_comment (const gchar* name,
                                       const gchar* nick,
                                       const gchar* blurb,
                                       GType object_type,
                                       GParamFlags flags)
{
	BaladocApiParamSpecSourceComment* spec;
	g_return_val_if_fail (g_type_is_a (object_type, BALADOC_API_TYPE_SOURCE_COMMENT), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
baladoc_api_value_get_source_comment (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALADOC_API_TYPE_SOURCE_COMMENT), NULL);
	return value->data[0].v_pointer;
}

void
baladoc_api_value_set_source_comment (GValue* value,
                                      gpointer v_object)
{
	BaladocApiSourceComment * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALADOC_API_TYPE_SOURCE_COMMENT));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALADOC_API_TYPE_SOURCE_COMMENT));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		baladoc_api_source_comment_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		baladoc_api_source_comment_unref (old);
	}
}

void
baladoc_api_value_take_source_comment (GValue* value,
                                       gpointer v_object)
{
	BaladocApiSourceComment * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALADOC_API_TYPE_SOURCE_COMMENT));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALADOC_API_TYPE_SOURCE_COMMENT));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		baladoc_api_source_comment_unref (old);
	}
}

static void
baladoc_api_source_comment_class_init (BaladocApiSourceCommentClass * klass,
                                       gpointer klass_data)
{
	baladoc_api_source_comment_parent_class = g_type_class_peek_parent (klass);
	((BaladocApiSourceCommentClass *) klass)->finalize = baladoc_api_source_comment_finalize;
	g_type_class_adjust_private_offset (klass, &BaladocApiSourceComment_private_offset);
}

static void
baladoc_api_source_comment_instance_init (BaladocApiSourceComment * self,
                                          gpointer klass)
{
	self->priv = baladoc_api_source_comment_get_instance_private (self);
	self->ref_count = 1;
}

static void
baladoc_api_source_comment_finalize (BaladocApiSourceComment * obj)
{
	BaladocApiSourceComment * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_API_TYPE_SOURCE_COMMENT, BaladocApiSourceComment);
	g_signal_handlers_destroy (self);
	_g_object_unref0 (self->priv->_file);
	_g_free0 (self->priv->_content);
}

/**
 * A documentation comment used by baladoc
 */
static GType
baladoc_api_source_comment_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { baladoc_api_value_source_comment_init, baladoc_api_value_source_comment_free_value, baladoc_api_value_source_comment_copy_value, baladoc_api_value_source_comment_peek_pointer, "p", baladoc_api_value_source_comment_collect_value, "p", baladoc_api_value_source_comment_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (BaladocApiSourceCommentClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_api_source_comment_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocApiSourceComment), 0, (GInstanceInitFunc) baladoc_api_source_comment_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType baladoc_api_source_comment_type_id;
	baladoc_api_source_comment_type_id = g_type_register_fundamental (g_type_fundamental_next (), "BaladocApiSourceComment", &g_define_type_info, &g_define_type_fundamental_info, 0);
	BaladocApiSourceComment_private_offset = g_type_add_instance_private (baladoc_api_source_comment_type_id, sizeof (BaladocApiSourceCommentPrivate));
	return baladoc_api_source_comment_type_id;
}

GType
baladoc_api_source_comment_get_type (void)
{
	static volatile gsize baladoc_api_source_comment_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_api_source_comment_type_id__volatile)) {
		GType baladoc_api_source_comment_type_id;
		baladoc_api_source_comment_type_id = baladoc_api_source_comment_get_type_once ();
		g_once_init_leave (&baladoc_api_source_comment_type_id__volatile, baladoc_api_source_comment_type_id);
	}
	return baladoc_api_source_comment_type_id__volatile;
}

gpointer
baladoc_api_source_comment_ref (gpointer instance)
{
	BaladocApiSourceComment * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
baladoc_api_source_comment_unref (gpointer instance)
{
	BaladocApiSourceComment * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		BALADOC_API_SOURCE_COMMENT_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

