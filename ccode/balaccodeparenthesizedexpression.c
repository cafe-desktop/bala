/* balaccodeparenthesizedexpression.c generated by balac, the Bala compiler
 * generated from balaccodeparenthesizedexpression.bala, do not modify */

/* balaccodeparenthesizedexpression.bala
 *
 * Copyright (C) 2006  Jürg Billeter
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

#include "balaccode.h"
#include <glib.h>

#define _bala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_ccode_node_unref (var), NULL)))

struct _BalaCCodeParenthesizedExpressionPrivate {
	BalaCCodeExpression* _inner;
};

static gint BalaCCodeParenthesizedExpression_private_offset;
static gpointer bala_ccode_parenthesized_expression_parent_class = NULL;

static void bala_ccode_parenthesized_expression_real_write (BalaCCodeNode* base,
                                                     BalaCCodeWriter* writer);
static void bala_ccode_parenthesized_expression_finalize (BalaCCodeNode * obj);
static GType bala_ccode_parenthesized_expression_get_type_once (void);

static inline gpointer
bala_ccode_parenthesized_expression_get_instance_private (BalaCCodeParenthesizedExpression* self)
{
	return G_STRUCT_MEMBER_P (self, BalaCCodeParenthesizedExpression_private_offset);
}

BalaCCodeExpression*
bala_ccode_parenthesized_expression_get_inner (BalaCCodeParenthesizedExpression* self)
{
	BalaCCodeExpression* result;
	BalaCCodeExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_inner;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_ccode_node_ref0 (gpointer self)
{
	return self ? bala_ccode_node_ref (self) : NULL;
}

void
bala_ccode_parenthesized_expression_set_inner (BalaCCodeParenthesizedExpression* self,
                                               BalaCCodeExpression* value)
{
	BalaCCodeExpression* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _bala_ccode_node_ref0 (value);
	_bala_ccode_node_unref0 (self->priv->_inner);
	self->priv->_inner = _tmp0_;
}

BalaCCodeParenthesizedExpression*
bala_ccode_parenthesized_expression_construct (GType object_type,
                                               BalaCCodeExpression* expr)
{
	BalaCCodeParenthesizedExpression* self = NULL;
	g_return_val_if_fail (expr != NULL, NULL);
	self = (BalaCCodeParenthesizedExpression*) bala_ccode_expression_construct (object_type);
	bala_ccode_parenthesized_expression_set_inner (self, expr);
	return self;
}

BalaCCodeParenthesizedExpression*
bala_ccode_parenthesized_expression_new (BalaCCodeExpression* expr)
{
	return bala_ccode_parenthesized_expression_construct (BALA_TYPE_CCODE_PARENTHESIZED_EXPRESSION, expr);
}

static void
bala_ccode_parenthesized_expression_real_write (BalaCCodeNode* base,
                                                BalaCCodeWriter* writer)
{
	BalaCCodeParenthesizedExpression * self;
	BalaCCodeExpression* _tmp0_;
	self = (BalaCCodeParenthesizedExpression*) base;
	g_return_if_fail (writer != NULL);
	bala_ccode_writer_write_string (writer, "(");
	_tmp0_ = self->priv->_inner;
	bala_ccode_node_write ((BalaCCodeNode*) _tmp0_, writer);
	bala_ccode_writer_write_string (writer, ")");
}

static void
bala_ccode_parenthesized_expression_class_init (BalaCCodeParenthesizedExpressionClass * klass,
                                                gpointer klass_data)
{
	bala_ccode_parenthesized_expression_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeNodeClass *) klass)->finalize = bala_ccode_parenthesized_expression_finalize;
	g_type_class_adjust_private_offset (klass, &BalaCCodeParenthesizedExpression_private_offset);
	((BalaCCodeNodeClass *) klass)->write = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_parenthesized_expression_real_write;
}

static void
bala_ccode_parenthesized_expression_instance_init (BalaCCodeParenthesizedExpression * self,
                                                   gpointer klass)
{
	self->priv = bala_ccode_parenthesized_expression_get_instance_private (self);
}

static void
bala_ccode_parenthesized_expression_finalize (BalaCCodeNode * obj)
{
	BalaCCodeParenthesizedExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_PARENTHESIZED_EXPRESSION, BalaCCodeParenthesizedExpression);
	_bala_ccode_node_unref0 (self->priv->_inner);
	BALA_CCODE_NODE_CLASS (bala_ccode_parenthesized_expression_parent_class)->finalize (obj);
}

/**
 * Represents a parenthesized expression in the C code.
 */
static GType
bala_ccode_parenthesized_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeParenthesizedExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_parenthesized_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeParenthesizedExpression), 0, (GInstanceInitFunc) bala_ccode_parenthesized_expression_instance_init, NULL };
	GType bala_ccode_parenthesized_expression_type_id;
	bala_ccode_parenthesized_expression_type_id = g_type_register_static (BALA_TYPE_CCODE_EXPRESSION, "BalaCCodeParenthesizedExpression", &g_define_type_info, 0);
	BalaCCodeParenthesizedExpression_private_offset = g_type_add_instance_private (bala_ccode_parenthesized_expression_type_id, sizeof (BalaCCodeParenthesizedExpressionPrivate));
	return bala_ccode_parenthesized_expression_type_id;
}

GType
bala_ccode_parenthesized_expression_get_type (void)
{
	static volatile gsize bala_ccode_parenthesized_expression_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_parenthesized_expression_type_id__volatile)) {
		GType bala_ccode_parenthesized_expression_type_id;
		bala_ccode_parenthesized_expression_type_id = bala_ccode_parenthesized_expression_get_type_once ();
		g_once_init_leave (&bala_ccode_parenthesized_expression_type_id__volatile, bala_ccode_parenthesized_expression_type_id);
	}
	return bala_ccode_parenthesized_expression_type_id__volatile;
}

