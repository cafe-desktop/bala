/* valastringliteral.c generated by valac, the Vala compiler
 * generated from valastringliteral.vala, do not modify */

/* valastringliteral.vala
 *
 * Copyright (C) 2006-2011  Jürg Billeter
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
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

struct _ValaStringLiteralPrivate {
	gchar* _value;
	gboolean _translate;
};

static gint ValaStringLiteral_private_offset;
static gpointer vala_string_literal_parent_class = NULL;

static void vala_string_literal_real_accept (ValaCodeNode* base,
                                      ValaCodeVisitor* visitor);
static gboolean vala_string_literal_real_is_pure (ValaExpression* base);
static gboolean vala_string_literal_real_is_non_null (ValaExpression* base);
static gchar* vala_string_literal_real_to_string (ValaCodeNode* base);
static gboolean vala_string_literal_real_check (ValaCodeNode* base,
                                         ValaCodeContext* context);
static void vala_string_literal_real_emit (ValaCodeNode* base,
                                    ValaCodeGenerator* codegen);
static void vala_string_literal_finalize (ValaCodeNode * obj);
static GType vala_string_literal_get_type_once (void);

static inline gpointer
vala_string_literal_get_instance_private (ValaStringLiteral* self)
{
	return G_STRUCT_MEMBER_P (self, ValaStringLiteral_private_offset);
}

const gchar*
vala_string_literal_get_value (ValaStringLiteral* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_value;
	result = _tmp0_;
	return result;
}

void
vala_string_literal_set_value (ValaStringLiteral* self,
                               const gchar* value)
{
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_value);
	self->priv->_value = _tmp0_;
}

gboolean
vala_string_literal_get_translate (ValaStringLiteral* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_translate;
	return result;
}

void
vala_string_literal_set_translate (ValaStringLiteral* self,
                                   gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_translate = value;
}

/**
 * Creates a new string literal.
 *
 * @param value             the literal value
 * @param source_reference  reference to source code
 * @return                  newly created string literal
 */
ValaStringLiteral*
vala_string_literal_construct (GType object_type,
                               const gchar* value,
                               ValaSourceReference* source_reference)
{
	ValaStringLiteral* self = NULL;
	g_return_val_if_fail (value != NULL, NULL);
	self = (ValaStringLiteral*) vala_literal_construct (object_type);
	vala_string_literal_set_value (self, value);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaStringLiteral*
vala_string_literal_new (const gchar* value,
                         ValaSourceReference* source_reference)
{
	return vala_string_literal_construct (BALA_TYPE_STRING_LITERAL, value, source_reference);
}

/**
 * Evaluates the literal string value.
 *
 * @return the unescaped string
 */
static glong
string_strnlen (gchar* str,
                glong maxlen)
{
	gchar* end = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	glong result = 0L;
	_tmp0_ = memchr (str, 0, (gsize) maxlen);
	end = _tmp0_;
	_tmp1_ = end;
	if (_tmp1_ == NULL) {
		result = maxlen;
		return result;
	} else {
		gchar* _tmp2_;
		_tmp2_ = end;
		result = (glong) (_tmp2_ - str);
		return result;
	}
}

static gchar*
string_substring (const gchar* self,
                  glong offset,
                  glong len)
{
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	gchar* _tmp3_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	if (offset >= ((glong) 0)) {
		_tmp0_ = len >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		string_length = string_strnlen ((gchar*) self, offset + len);
	} else {
		gint _tmp1_;
		gint _tmp2_;
		_tmp1_ = strlen (self);
		_tmp2_ = _tmp1_;
		string_length = (glong) _tmp2_;
	}
	if (offset < ((glong) 0)) {
		offset = string_length + offset;
		g_return_val_if_fail (offset >= ((glong) 0), NULL);
	} else {
		g_return_val_if_fail (offset <= string_length, NULL);
	}
	if (len < ((glong) 0)) {
		len = string_length - offset;
	}
	g_return_val_if_fail ((offset + len) <= string_length, NULL);
	_tmp3_ = g_strndup (((gchar*) self) + offset, (gsize) len);
	result = _tmp3_;
	return result;
}

gchar*
vala_string_literal_eval (ValaStringLiteral* self)
{
	const gchar* _tmp0_;
	gchar* noquotes = NULL;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_value;
	if (_tmp0_ == NULL) {
		result = NULL;
		return result;
	}
	_tmp1_ = self->priv->_value;
	_tmp2_ = self->priv->_value;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = string_substring (_tmp1_, (glong) 1, (glong) ((guint) (_tmp4_ - 2)));
	noquotes = _tmp5_;
	_tmp6_ = noquotes;
	_tmp7_ = g_strcompress (_tmp6_);
	result = _tmp7_;
	_g_free0 (noquotes);
	return result;
}

static void
vala_string_literal_real_accept (ValaCodeNode* base,
                                 ValaCodeVisitor* visitor)
{
	ValaStringLiteral * self;
	self = (ValaStringLiteral*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_string_literal (visitor, self);
	vala_code_visitor_visit_expression (visitor, (ValaExpression*) self);
}

static gboolean
vala_string_literal_real_is_pure (ValaExpression* base)
{
	ValaStringLiteral * self;
	gboolean result = FALSE;
	self = (ValaStringLiteral*) base;
	result = TRUE;
	return result;
}

static gboolean
vala_string_literal_real_is_non_null (ValaExpression* base)
{
	ValaStringLiteral * self;
	gboolean result = FALSE;
	self = (ValaStringLiteral*) base;
	result = TRUE;
	return result;
}

static gchar*
vala_string_literal_real_to_string (ValaCodeNode* base)
{
	ValaStringLiteral * self;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
	self = (ValaStringLiteral*) base;
	_tmp0_ = self->priv->_value;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}

static gboolean
vala_string_literal_real_check (ValaCodeNode* base,
                                ValaCodeContext* context)
{
	ValaStringLiteral * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaSemanticAnalyzer* _tmp4_;
	ValaSemanticAnalyzer* _tmp5_;
	ValaDataType* _tmp6_;
	ValaDataType* _tmp7_;
	ValaDataType* _tmp8_;
	gboolean _tmp9_;
	gboolean _tmp10_;
	gboolean result = FALSE;
	self = (ValaStringLiteral*) base;
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
	_tmp4_ = vala_code_context_get_analyzer (context);
	_tmp5_ = _tmp4_;
	_tmp6_ = _tmp5_->string_type;
	_tmp7_ = vala_data_type_copy (_tmp6_);
	_tmp8_ = _tmp7_;
	vala_expression_set_value_type ((ValaExpression*) self, _tmp8_);
	_vala_code_node_unref0 (_tmp8_);
	_tmp9_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp10_ = _tmp9_;
	result = !_tmp10_;
	return result;
}

static void
vala_string_literal_real_emit (ValaCodeNode* base,
                               ValaCodeGenerator* codegen)
{
	ValaStringLiteral * self;
	self = (ValaStringLiteral*) base;
	g_return_if_fail (codegen != NULL);
	vala_code_visitor_visit_string_literal ((ValaCodeVisitor*) codegen, self);
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) codegen, (ValaExpression*) self);
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

ValaStringLiteral*
vala_string_literal_get_format_literal (ValaExpression* expr)
{
	ValaStringLiteral* format_literal = NULL;
	ValaStringLiteral* _tmp0_;
	ValaMethodCall* call = NULL;
	ValaMethodCall* _tmp3_;
	ValaStringLiteral* result = NULL;
	g_return_val_if_fail (expr != NULL, NULL);
	format_literal = BALA_IS_STRING_LITERAL (expr) ? ((ValaStringLiteral*) expr) : NULL;
	_tmp0_ = format_literal;
	if (_tmp0_ != NULL) {
		ValaStringLiteral* _tmp1_;
		ValaStringLiteral* _tmp2_;
		_tmp1_ = format_literal;
		_tmp2_ = _vala_code_node_ref0 (_tmp1_);
		result = _tmp2_;
		return result;
	}
	call = BALA_IS_METHOD_CALL (expr) ? ((ValaMethodCall*) expr) : NULL;
	_tmp3_ = call;
	if (_tmp3_ != NULL) {
		ValaMethodCall* _tmp4_;
		ValaStringLiteral* _tmp5_;
		_tmp4_ = call;
		_tmp5_ = vala_method_call_get_format_literal (_tmp4_);
		result = _tmp5_;
		return result;
	}
	result = NULL;
	return result;
}

static void
vala_string_literal_class_init (ValaStringLiteralClass * klass,
                                gpointer klass_data)
{
	vala_string_literal_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_string_literal_finalize;
	g_type_class_adjust_private_offset (klass, &ValaStringLiteral_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_string_literal_real_accept;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_string_literal_real_is_pure;
	((ValaExpressionClass *) klass)->is_non_null = (gboolean (*) (ValaExpression*)) vala_string_literal_real_is_non_null;
	((ValaCodeNodeClass *) klass)->to_string = (gchar* (*) (ValaCodeNode*)) vala_string_literal_real_to_string;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_string_literal_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_string_literal_real_emit;
}

static void
vala_string_literal_instance_init (ValaStringLiteral * self,
                                   gpointer klass)
{
	self->priv = vala_string_literal_get_instance_private (self);
}

static void
vala_string_literal_finalize (ValaCodeNode * obj)
{
	ValaStringLiteral * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_STRING_LITERAL, ValaStringLiteral);
	_g_free0 (self->priv->_value);
	BALA_CODE_NODE_CLASS (vala_string_literal_parent_class)->finalize (obj);
}

/**
 * Represents a string literal in the source code.
 */
static GType
vala_string_literal_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaStringLiteralClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_string_literal_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaStringLiteral), 0, (GInstanceInitFunc) vala_string_literal_instance_init, NULL };
	GType vala_string_literal_type_id;
	vala_string_literal_type_id = g_type_register_static (BALA_TYPE_LITERAL, "ValaStringLiteral", &g_define_type_info, 0);
	ValaStringLiteral_private_offset = g_type_add_instance_private (vala_string_literal_type_id, sizeof (ValaStringLiteralPrivate));
	return vala_string_literal_type_id;
}

GType
vala_string_literal_get_type (void)
{
	static volatile gsize vala_string_literal_type_id__volatile = 0;
	if (g_once_init_enter (&vala_string_literal_type_id__volatile)) {
		GType vala_string_literal_type_id;
		vala_string_literal_type_id = vala_string_literal_get_type_once ();
		g_once_init_leave (&vala_string_literal_type_id__volatile, vala_string_literal_type_id);
	}
	return vala_string_literal_type_id__volatile;
}

