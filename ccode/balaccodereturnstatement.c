/* valaccodereturnstatement.c generated by valac, the Vala compiler
 * generated from valaccodereturnstatement.vala, do not modify */

/* valaccodereturnstatement.vala
 *
 * Copyright (C) 2006-2008  Jürg Billeter
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

#include "valaccode.h"
#include <glib.h>

#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))

struct _ValaCCodeReturnStatementPrivate {
	ValaCCodeExpression* _return_expression;
};

static gint ValaCCodeReturnStatement_private_offset;
static gpointer vala_ccode_return_statement_parent_class = NULL;

static void vala_ccode_return_statement_real_write (ValaCCodeNode* base,
                                             ValaCCodeWriter* writer);
static void vala_ccode_return_statement_finalize (ValaCCodeNode * obj);
static GType vala_ccode_return_statement_get_type_once (void);

static inline gpointer
vala_ccode_return_statement_get_instance_private (ValaCCodeReturnStatement* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeReturnStatement_private_offset);
}

ValaCCodeExpression*
vala_ccode_return_statement_get_return_expression (ValaCCodeReturnStatement* self)
{
	ValaCCodeExpression* result;
	ValaCCodeExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_return_expression;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_ccode_node_ref0 (gpointer self)
{
	return self ? vala_ccode_node_ref (self) : NULL;
}

void
vala_ccode_return_statement_set_return_expression (ValaCCodeReturnStatement* self,
                                                   ValaCCodeExpression* value)
{
	ValaCCodeExpression* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_ccode_node_ref0 (value);
	_vala_ccode_node_unref0 (self->priv->_return_expression);
	self->priv->_return_expression = _tmp0_;
}

ValaCCodeReturnStatement*
vala_ccode_return_statement_construct (GType object_type,
                                       ValaCCodeExpression* expr)
{
	ValaCCodeReturnStatement* self = NULL;
	self = (ValaCCodeReturnStatement*) vala_ccode_statement_construct (object_type);
	vala_ccode_return_statement_set_return_expression (self, expr);
	return self;
}

ValaCCodeReturnStatement*
vala_ccode_return_statement_new (ValaCCodeExpression* expr)
{
	return vala_ccode_return_statement_construct (BALA_TYPE_CCODE_RETURN_STATEMENT, expr);
}

static void
vala_ccode_return_statement_real_write (ValaCCodeNode* base,
                                        ValaCCodeWriter* writer)
{
	ValaCCodeReturnStatement * self;
	ValaCCodeLineDirective* _tmp0_;
	ValaCCodeLineDirective* _tmp1_;
	ValaCCodeExpression* _tmp2_;
	self = (ValaCCodeReturnStatement*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = vala_ccode_node_get_line ((ValaCCodeNode*) self);
	_tmp1_ = _tmp0_;
	vala_ccode_writer_write_indent (writer, _tmp1_);
	vala_ccode_writer_write_string (writer, "return");
	_tmp2_ = self->priv->_return_expression;
	if (_tmp2_ != NULL) {
		ValaCCodeExpression* _tmp3_;
		vala_ccode_writer_write_string (writer, " ");
		_tmp3_ = self->priv->_return_expression;
		vala_ccode_node_write ((ValaCCodeNode*) _tmp3_, writer);
	}
	vala_ccode_writer_write_string (writer, ";");
	vala_ccode_writer_write_newline (writer);
}

static void
vala_ccode_return_statement_class_init (ValaCCodeReturnStatementClass * klass,
                                        gpointer klass_data)
{
	vala_ccode_return_statement_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_return_statement_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeReturnStatement_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_return_statement_real_write;
}

static void
vala_ccode_return_statement_instance_init (ValaCCodeReturnStatement * self,
                                           gpointer klass)
{
	self->priv = vala_ccode_return_statement_get_instance_private (self);
}

static void
vala_ccode_return_statement_finalize (ValaCCodeNode * obj)
{
	ValaCCodeReturnStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_RETURN_STATEMENT, ValaCCodeReturnStatement);
	_vala_ccode_node_unref0 (self->priv->_return_expression);
	BALA_CCODE_NODE_CLASS (vala_ccode_return_statement_parent_class)->finalize (obj);
}

/**
 * Represents a return statement in the C code.
 */
static GType
vala_ccode_return_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeReturnStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_return_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeReturnStatement), 0, (GInstanceInitFunc) vala_ccode_return_statement_instance_init, NULL };
	GType vala_ccode_return_statement_type_id;
	vala_ccode_return_statement_type_id = g_type_register_static (BALA_TYPE_CCODE_STATEMENT, "ValaCCodeReturnStatement", &g_define_type_info, 0);
	ValaCCodeReturnStatement_private_offset = g_type_add_instance_private (vala_ccode_return_statement_type_id, sizeof (ValaCCodeReturnStatementPrivate));
	return vala_ccode_return_statement_type_id;
}

GType
vala_ccode_return_statement_get_type (void)
{
	static volatile gsize vala_ccode_return_statement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_return_statement_type_id__volatile)) {
		GType vala_ccode_return_statement_type_id;
		vala_ccode_return_statement_type_id = vala_ccode_return_statement_get_type_once ();
		g_once_init_leave (&vala_ccode_return_statement_type_id__volatile, vala_ccode_return_statement_type_id);
	}
	return vala_ccode_return_statement_type_id__volatile;
}

