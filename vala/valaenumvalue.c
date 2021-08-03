/* valaenumvalue.c generated by valac, the Vala compiler
 * generated from valaenumvalue.vala, do not modify */

/* valaenumvalue.vala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
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
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

struct _ValaEnumValuePrivate {
	gchar* _nick;
};

static gint ValaEnumValue_private_offset;
static gpointer vala_enum_value_parent_class = NULL;

static void vala_enum_value_real_accept (ValaCodeNode* base,
                                  ValaCodeVisitor* visitor);
static void vala_enum_value_real_accept_children (ValaCodeNode* base,
                                           ValaCodeVisitor* visitor);
static gboolean vala_enum_value_real_check (ValaCodeNode* base,
                                     ValaCodeContext* context);
static void vala_enum_value_finalize (ValaCodeNode * obj);
static GType vala_enum_value_get_type_once (void);

static inline gpointer
vala_enum_value_get_instance_private (ValaEnumValue* self)
{
	return G_STRUCT_MEMBER_P (self, ValaEnumValue_private_offset);
}

static gchar*
string_replace (const gchar* self,
                const gchar* old,
                const gchar* replacement)
{
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	GError* _inner_error0_ = NULL;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	if ((*((gchar*) self)) == '\0') {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = (*((gchar*) old)) == '\0';
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = g_strcmp0 (old, replacement) == 0;
	}
	if (_tmp0_) {
		gchar* _tmp2_;
		_tmp2_ = g_strdup (self);
		result = _tmp2_;
		return result;
	}
	{
		GRegex* regex = NULL;
		gchar* _tmp3_;
		gchar* _tmp4_;
		GRegex* _tmp5_;
		GRegex* _tmp6_;
		gchar* _tmp7_ = NULL;
		GRegex* _tmp8_;
		gchar* _tmp9_;
		gchar* _tmp10_;
		_tmp3_ = g_regex_escape_string (old, -1);
		_tmp4_ = _tmp3_;
		_tmp5_ = g_regex_new (_tmp4_, 0, 0, &_inner_error0_);
		_tmp6_ = _tmp5_;
		_g_free0 (_tmp4_);
		regex = _tmp6_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			_g_free0 (_tmp7_);
			_g_regex_unref0 (regex);
			if (_inner_error0_->domain == G_REGEX_ERROR) {
				goto __catch0_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return NULL;
		}
		_tmp8_ = regex;
		_tmp9_ = g_regex_replace_literal (_tmp8_, self, (gssize) -1, 0, replacement, 0, &_inner_error0_);
		_tmp7_ = _tmp9_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			_g_free0 (_tmp7_);
			_g_regex_unref0 (regex);
			if (_inner_error0_->domain == G_REGEX_ERROR) {
				goto __catch0_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return NULL;
		}
		_tmp10_ = _tmp7_;
		_tmp7_ = NULL;
		result = _tmp10_;
		_g_free0 (_tmp7_);
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally0;
	__catch0_g_regex_error:
	{
		g_clear_error (&_inner_error0_);
		g_assert_not_reached ();
	}
	__finally0:
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
	g_clear_error (&_inner_error0_);
	return NULL;
}

const gchar*
vala_enum_value_get_nick (ValaEnumValue* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	const gchar* _tmp8_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_nick;
	if (_tmp0_ == NULL) {
		gchar* _tmp1_;
		const gchar* _tmp2_;
		_tmp1_ = vala_code_node_get_attribute_string ((ValaCodeNode*) self, "Description", "nick", NULL);
		_g_free0 (self->priv->_nick);
		self->priv->_nick = _tmp1_;
		_tmp2_ = self->priv->_nick;
		if (_tmp2_ == NULL) {
			const gchar* _tmp3_;
			const gchar* _tmp4_;
			gchar* _tmp5_;
			gchar* _tmp6_;
			gchar* _tmp7_;
			_tmp3_ = vala_symbol_get_name ((ValaSymbol*) self);
			_tmp4_ = _tmp3_;
			_tmp5_ = g_ascii_strdown (_tmp4_, (gssize) -1);
			_tmp6_ = _tmp5_;
			_tmp7_ = string_replace (_tmp6_, "_", "-");
			_g_free0 (self->priv->_nick);
			self->priv->_nick = _tmp7_;
			_g_free0 (_tmp6_);
		}
	}
	_tmp8_ = self->priv->_nick;
	result = _tmp8_;
	return result;
}

/**
 * Creates a new enum value with the specified numerical representation.
 *
 * @param name  enum value name
 * @param value numerical representation
 * @return      newly created enum value
 */
ValaEnumValue*
vala_enum_value_construct (GType object_type,
                           const gchar* name,
                           ValaExpression* value,
                           ValaSourceReference* source_reference,
                           ValaComment* comment)
{
	ValaEnumValue* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (ValaEnumValue*) vala_constant_construct (object_type, name, NULL, value, source_reference, comment);
	return self;
}

ValaEnumValue*
vala_enum_value_new (const gchar* name,
                     ValaExpression* value,
                     ValaSourceReference* source_reference,
                     ValaComment* comment)
{
	return vala_enum_value_construct (VALA_TYPE_ENUM_VALUE, name, value, source_reference, comment);
}

static void
vala_enum_value_real_accept (ValaCodeNode* base,
                             ValaCodeVisitor* visitor)
{
	ValaEnumValue * self;
	self = (ValaEnumValue*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_enum_value (visitor, self);
}

static void
vala_enum_value_real_accept_children (ValaCodeNode* base,
                                      ValaCodeVisitor* visitor)
{
	ValaEnumValue * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaEnumValue*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_constant_get_value ((ValaConstant*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ != NULL) {
		ValaExpression* _tmp2_;
		ValaExpression* _tmp3_;
		_tmp2_ = vala_constant_get_value ((ValaConstant*) self);
		_tmp3_ = _tmp2_;
		vala_code_node_accept ((ValaCodeNode*) _tmp3_, visitor);
	}
}

static gboolean
vala_enum_value_real_check (ValaCodeNode* base,
                            ValaCodeContext* context)
{
	ValaEnumValue * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	gboolean _tmp8_;
	gboolean _tmp9_;
	gboolean result = FALSE;
	self = (ValaEnumValue*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = vala_constant_get_value ((ValaConstant*) self);
	_tmp5_ = _tmp4_;
	if (_tmp5_ != NULL) {
		ValaExpression* _tmp6_;
		ValaExpression* _tmp7_;
		_tmp6_ = vala_constant_get_value ((ValaConstant*) self);
		_tmp7_ = _tmp6_;
		vala_code_node_check ((ValaCodeNode*) _tmp7_, context);
	}
	_tmp8_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp9_ = _tmp8_;
	result = !_tmp9_;
	return result;
}

static void
vala_enum_value_class_init (ValaEnumValueClass * klass,
                            gpointer klass_data)
{
	vala_enum_value_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_enum_value_finalize;
	g_type_class_adjust_private_offset (klass, &ValaEnumValue_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_enum_value_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_enum_value_real_accept_children;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_enum_value_real_check;
}

static void
vala_enum_value_instance_init (ValaEnumValue * self,
                               gpointer klass)
{
	self->priv = vala_enum_value_get_instance_private (self);
	self->priv->_nick = NULL;
}

static void
vala_enum_value_finalize (ValaCodeNode * obj)
{
	ValaEnumValue * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_ENUM_VALUE, ValaEnumValue);
	_g_free0 (self->priv->_nick);
	VALA_CODE_NODE_CLASS (vala_enum_value_parent_class)->finalize (obj);
}

/**
 * Represents an enum value member in the source code.
 */
static GType
vala_enum_value_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaEnumValueClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_enum_value_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaEnumValue), 0, (GInstanceInitFunc) vala_enum_value_instance_init, NULL };
	GType vala_enum_value_type_id;
	vala_enum_value_type_id = g_type_register_static (VALA_TYPE_CONSTANT, "ValaEnumValue", &g_define_type_info, 0);
	ValaEnumValue_private_offset = g_type_add_instance_private (vala_enum_value_type_id, sizeof (ValaEnumValuePrivate));
	return vala_enum_value_type_id;
}

GType
vala_enum_value_get_type (void)
{
	static volatile gsize vala_enum_value_type_id__volatile = 0;
	if (g_once_init_enter (&vala_enum_value_type_id__volatile)) {
		GType vala_enum_value_type_id;
		vala_enum_value_type_id = vala_enum_value_get_type_once ();
		g_once_init_leave (&vala_enum_value_type_id__volatile, vala_enum_value_type_id);
	}
	return vala_enum_value_type_id__volatile;
}

