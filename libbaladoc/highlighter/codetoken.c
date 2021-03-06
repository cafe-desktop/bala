/* codetoken.c generated by balac, the Bala compiler
 * generated from codetoken.bala, do not modify */

/* codetoken.bala
 *
 * Copyright (C) 2015       Florian Brosch
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
#include <glib-object.h>

#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _BaladocHighlighterParamSpecCodeToken BaladocHighlighterParamSpecCodeToken;
#define _g_type_class_unref0(var) ((var == NULL) ? NULL : (var = (g_type_class_unref (var), NULL)))

struct _BaladocHighlighterCodeTokenPrivate {
	BaladocHighlighterCodeTokenType _token_type;
	gchar* _content;
};

struct _BaladocHighlighterParamSpecCodeToken {
	GParamSpec parent_instance;
};

static gint BaladocHighlighterCodeToken_private_offset;
static gpointer baladoc_highlighter_code_token_parent_class = NULL;

static void baladoc_highlighter_code_token_set_token_type (BaladocHighlighterCodeToken* self,
                                                    BaladocHighlighterCodeTokenType value);
static void baladoc_highlighter_code_token_set_content (BaladocHighlighterCodeToken* self,
                                                 const gchar* value);
static void baladoc_highlighter_code_token_finalize (BaladocHighlighterCodeToken * obj);
static GType baladoc_highlighter_code_token_get_type_once (void);

static inline gpointer
baladoc_highlighter_code_token_get_instance_private (BaladocHighlighterCodeToken* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocHighlighterCodeToken_private_offset);
}

BaladocHighlighterCodeTokenType
baladoc_highlighter_code_token_get_token_type (BaladocHighlighterCodeToken* self)
{
	BaladocHighlighterCodeTokenType result;
	BaladocHighlighterCodeTokenType _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_token_type;
	result = _tmp0_;
	return result;
}

static void
baladoc_highlighter_code_token_set_token_type (BaladocHighlighterCodeToken* self,
                                               BaladocHighlighterCodeTokenType value)
{
	g_return_if_fail (self != NULL);
	self->priv->_token_type = value;
}

const gchar*
baladoc_highlighter_code_token_get_content (BaladocHighlighterCodeToken* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_content;
	result = _tmp0_;
	return result;
}

static void
baladoc_highlighter_code_token_set_content (BaladocHighlighterCodeToken* self,
                                            const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_content);
	self->priv->_content = _tmp0_;
}

BaladocHighlighterCodeToken*
baladoc_highlighter_code_token_construct (GType object_type,
                                          BaladocHighlighterCodeTokenType type,
                                          const gchar* content)
{
	BaladocHighlighterCodeToken* self = NULL;
	g_return_val_if_fail (content != NULL, NULL);
	self = (BaladocHighlighterCodeToken*) g_type_create_instance (object_type);
	baladoc_highlighter_code_token_set_token_type (self, type);
	baladoc_highlighter_code_token_set_content (self, content);
	return self;
}

BaladocHighlighterCodeToken*
baladoc_highlighter_code_token_new (BaladocHighlighterCodeTokenType type,
                                    const gchar* content)
{
	return baladoc_highlighter_code_token_construct (BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN, type, content);
}

static void
baladoc_highlighter_value_code_token_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
baladoc_highlighter_value_code_token_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		baladoc_highlighter_code_token_unref (value->data[0].v_pointer);
	}
}

static void
baladoc_highlighter_value_code_token_copy_value (const GValue* src_value,
                                                 GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = baladoc_highlighter_code_token_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
baladoc_highlighter_value_code_token_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
baladoc_highlighter_value_code_token_collect_value (GValue* value,
                                                    guint n_collect_values,
                                                    GTypeCValue* collect_values,
                                                    guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		BaladocHighlighterCodeToken * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = baladoc_highlighter_code_token_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
baladoc_highlighter_value_code_token_lcopy_value (const GValue* value,
                                                  guint n_collect_values,
                                                  GTypeCValue* collect_values,
                                                  guint collect_flags)
{
	BaladocHighlighterCodeToken ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = baladoc_highlighter_code_token_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
baladoc_highlighter_param_spec_code_token (const gchar* name,
                                           const gchar* nick,
                                           const gchar* blurb,
                                           GType object_type,
                                           GParamFlags flags)
{
	BaladocHighlighterParamSpecCodeToken* spec;
	g_return_val_if_fail (g_type_is_a (object_type, BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
baladoc_highlighter_value_get_code_token (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN), NULL);
	return value->data[0].v_pointer;
}

void
baladoc_highlighter_value_set_code_token (GValue* value,
                                          gpointer v_object)
{
	BaladocHighlighterCodeToken * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		baladoc_highlighter_code_token_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		baladoc_highlighter_code_token_unref (old);
	}
}

void
baladoc_highlighter_value_take_code_token (GValue* value,
                                           gpointer v_object)
{
	BaladocHighlighterCodeToken * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		baladoc_highlighter_code_token_unref (old);
	}
}

static void
baladoc_highlighter_code_token_class_init (BaladocHighlighterCodeTokenClass * klass,
                                           gpointer klass_data)
{
	baladoc_highlighter_code_token_parent_class = g_type_class_peek_parent (klass);
	((BaladocHighlighterCodeTokenClass *) klass)->finalize = baladoc_highlighter_code_token_finalize;
	g_type_class_adjust_private_offset (klass, &BaladocHighlighterCodeToken_private_offset);
}

static void
baladoc_highlighter_code_token_instance_init (BaladocHighlighterCodeToken * self,
                                              gpointer klass)
{
	self->priv = baladoc_highlighter_code_token_get_instance_private (self);
	self->ref_count = 1;
}

static void
baladoc_highlighter_code_token_finalize (BaladocHighlighterCodeToken * obj)
{
	BaladocHighlighterCodeToken * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN, BaladocHighlighterCodeToken);
	g_signal_handlers_destroy (self);
	_g_free0 (self->priv->_content);
}

static GType
baladoc_highlighter_code_token_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { baladoc_highlighter_value_code_token_init, baladoc_highlighter_value_code_token_free_value, baladoc_highlighter_value_code_token_copy_value, baladoc_highlighter_value_code_token_peek_pointer, "p", baladoc_highlighter_value_code_token_collect_value, "p", baladoc_highlighter_value_code_token_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (BaladocHighlighterCodeTokenClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_highlighter_code_token_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocHighlighterCodeToken), 0, (GInstanceInitFunc) baladoc_highlighter_code_token_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType baladoc_highlighter_code_token_type_id;
	baladoc_highlighter_code_token_type_id = g_type_register_fundamental (g_type_fundamental_next (), "BaladocHighlighterCodeToken", &g_define_type_info, &g_define_type_fundamental_info, 0);
	BaladocHighlighterCodeToken_private_offset = g_type_add_instance_private (baladoc_highlighter_code_token_type_id, sizeof (BaladocHighlighterCodeTokenPrivate));
	return baladoc_highlighter_code_token_type_id;
}

GType
baladoc_highlighter_code_token_get_type (void)
{
	static volatile gsize baladoc_highlighter_code_token_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_highlighter_code_token_type_id__volatile)) {
		GType baladoc_highlighter_code_token_type_id;
		baladoc_highlighter_code_token_type_id = baladoc_highlighter_code_token_get_type_once ();
		g_once_init_leave (&baladoc_highlighter_code_token_type_id__volatile, baladoc_highlighter_code_token_type_id);
	}
	return baladoc_highlighter_code_token_type_id__volatile;
}

gpointer
baladoc_highlighter_code_token_ref (gpointer instance)
{
	BaladocHighlighterCodeToken * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
baladoc_highlighter_code_token_unref (gpointer instance)
{
	BaladocHighlighterCodeToken * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		BALADOC_HIGHLIGHTER_CODE_TOKEN_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

const gchar*
baladoc_highlighter_code_token_type_to_string (BaladocHighlighterCodeTokenType self)
{
	GEnumClass* enumc = NULL;
	GTypeClass* _tmp0_;
	GEnumValue* eval = NULL;
	const gchar* _tmp1_;
	const gchar* result = NULL;
	_tmp0_ = g_type_class_ref (BALADOC_HIGHLIGHTER_TYPE_CODE_TOKEN_TYPE);
	enumc = (GEnumClass*) _tmp0_;
	eval = g_enum_get_value (enumc, (gint) self);
	g_return_val_if_fail (eval != NULL, NULL);
	_tmp1_ = (*eval).value_nick;
	result = _tmp1_;
	_g_type_class_unref0 (enumc);
	return result;
}

static GType
baladoc_highlighter_code_token_type_get_type_once (void)
{
	static const GEnumValue values[] = {{BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ESCAPE, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ESCAPE", "xml-escape"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ELEMENT, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ELEMENT", "xml-element"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ATTRIBUTE, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ATTRIBUTE", "xml-attribute"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ATTRIBUTE_VALUE, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_ATTRIBUTE_VALUE", "xml-attribute-value"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_COMMENT, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_COMMENT", "xml-comment"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_CDATA, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_XML_CDATA", "xml-cdata"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_PREPROCESSOR, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_PREPROCESSOR", "preprocessor"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_COMMENT, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_COMMENT", "comment"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_KEYWORD, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_KEYWORD", "keyword"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_LITERAL, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_LITERAL", "literal"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_ESCAPE, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_ESCAPE", "escape"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_PLAIN, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_PLAIN", "plain"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_TYPE, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_TYPE", "type"}, {BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_EOF, "BALADOC_HIGHLIGHTER_CODE_TOKEN_TYPE_EOF", "eof"}, {0, NULL, NULL}};
	GType baladoc_highlighter_code_token_type_type_id;
	baladoc_highlighter_code_token_type_type_id = g_enum_register_static ("BaladocHighlighterCodeTokenType", values);
	return baladoc_highlighter_code_token_type_type_id;
}

GType
baladoc_highlighter_code_token_type_get_type (void)
{
	static volatile gsize baladoc_highlighter_code_token_type_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_highlighter_code_token_type_type_id__volatile)) {
		GType baladoc_highlighter_code_token_type_type_id;
		baladoc_highlighter_code_token_type_type_id = baladoc_highlighter_code_token_type_get_type_once ();
		g_once_init_leave (&baladoc_highlighter_code_token_type_type_id__volatile, baladoc_highlighter_code_token_type_type_id);
	}
	return baladoc_highlighter_code_token_type_type_id__volatile;
}

