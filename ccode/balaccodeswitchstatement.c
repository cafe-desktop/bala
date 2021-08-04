/* valaccodeswitchstatement.c generated by valac, the Vala compiler
 * generated from valaccodeswitchstatement.vala, do not modify */

/* valaccodeswitchstatement.vala
 *
 * Copyright (C) 2006-2007  Jürg Billeter
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

struct _ValaCCodeSwitchStatementPrivate {
	ValaCCodeExpression* _expression;
};

static gint ValaCCodeSwitchStatement_private_offset;
static gpointer vala_ccode_switch_statement_parent_class = NULL;

static void vala_ccode_switch_statement_real_write (ValaCCodeNode* base,
                                             ValaCCodeWriter* writer);
static void vala_ccode_switch_statement_finalize (ValaCCodeNode * obj);
static GType vala_ccode_switch_statement_get_type_once (void);

static inline gpointer
vala_ccode_switch_statement_get_instance_private (ValaCCodeSwitchStatement* self)
{
	return G_STRUCT_MEMBER_P (self, ValaCCodeSwitchStatement_private_offset);
}

ValaCCodeExpression*
vala_ccode_switch_statement_get_expression (ValaCCodeSwitchStatement* self)
{
	ValaCCodeExpression* result;
	ValaCCodeExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_expression;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_ccode_node_ref0 (gpointer self)
{
	return self ? vala_ccode_node_ref (self) : NULL;
}

void
vala_ccode_switch_statement_set_expression (ValaCCodeSwitchStatement* self,
                                            ValaCCodeExpression* value)
{
	ValaCCodeExpression* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_ccode_node_ref0 (value);
	_vala_ccode_node_unref0 (self->priv->_expression);
	self->priv->_expression = _tmp0_;
}

ValaCCodeSwitchStatement*
vala_ccode_switch_statement_construct (GType object_type,
                                       ValaCCodeExpression* expression)
{
	ValaCCodeSwitchStatement* self = NULL;
	g_return_val_if_fail (expression != NULL, NULL);
	self = (ValaCCodeSwitchStatement*) vala_ccode_block_construct (object_type);
	vala_ccode_switch_statement_set_expression (self, expression);
	return self;
}

ValaCCodeSwitchStatement*
vala_ccode_switch_statement_new (ValaCCodeExpression* expression)
{
	return vala_ccode_switch_statement_construct (BALA_TYPE_CCODE_SWITCH_STATEMENT, expression);
}

static void
vala_ccode_switch_statement_real_write (ValaCCodeNode* base,
                                        ValaCCodeWriter* writer)
{
	ValaCCodeSwitchStatement * self;
	ValaCCodeLineDirective* _tmp0_;
	ValaCCodeLineDirective* _tmp1_;
	ValaCCodeExpression* _tmp2_;
	self = (ValaCCodeSwitchStatement*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = vala_ccode_node_get_line ((ValaCCodeNode*) self);
	_tmp1_ = _tmp0_;
	vala_ccode_writer_write_indent (writer, _tmp1_);
	vala_ccode_writer_write_string (writer, "switch (");
	_tmp2_ = self->priv->_expression;
	vala_ccode_node_write ((ValaCCodeNode*) _tmp2_, writer);
	vala_ccode_writer_write_string (writer, ")");
	BALA_CCODE_NODE_CLASS (vala_ccode_switch_statement_parent_class)->write ((ValaCCodeNode*) G_TYPE_CHECK_INSTANCE_CAST (self, BALA_TYPE_CCODE_BLOCK, ValaCCodeBlock), writer);
}

static void
vala_ccode_switch_statement_class_init (ValaCCodeSwitchStatementClass * klass,
                                        gpointer klass_data)
{
	vala_ccode_switch_statement_parent_class = g_type_class_peek_parent (klass);
	((ValaCCodeNodeClass *) klass)->finalize = vala_ccode_switch_statement_finalize;
	g_type_class_adjust_private_offset (klass, &ValaCCodeSwitchStatement_private_offset);
	((ValaCCodeNodeClass *) klass)->write = (void (*) (ValaCCodeNode*, ValaCCodeWriter*)) vala_ccode_switch_statement_real_write;
}

static void
vala_ccode_switch_statement_instance_init (ValaCCodeSwitchStatement * self,
                                           gpointer klass)
{
	self->priv = vala_ccode_switch_statement_get_instance_private (self);
}

static void
vala_ccode_switch_statement_finalize (ValaCCodeNode * obj)
{
	ValaCCodeSwitchStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_SWITCH_STATEMENT, ValaCCodeSwitchStatement);
	_vala_ccode_node_unref0 (self->priv->_expression);
	BALA_CCODE_NODE_CLASS (vala_ccode_switch_statement_parent_class)->finalize (obj);
}

/**
 * Represents a switch selection statement in the C code.
 */
static GType
vala_ccode_switch_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeSwitchStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_switch_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeSwitchStatement), 0, (GInstanceInitFunc) vala_ccode_switch_statement_instance_init, NULL };
	GType vala_ccode_switch_statement_type_id;
	vala_ccode_switch_statement_type_id = g_type_register_static (BALA_TYPE_CCODE_BLOCK, "ValaCCodeSwitchStatement", &g_define_type_info, 0);
	ValaCCodeSwitchStatement_private_offset = g_type_add_instance_private (vala_ccode_switch_statement_type_id, sizeof (ValaCCodeSwitchStatementPrivate));
	return vala_ccode_switch_statement_type_id;
}

GType
vala_ccode_switch_statement_get_type (void)
{
	static volatile gsize vala_ccode_switch_statement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_switch_statement_type_id__volatile)) {
		GType vala_ccode_switch_statement_type_id;
		vala_ccode_switch_statement_type_id = vala_ccode_switch_statement_get_type_once ();
		g_once_init_leave (&vala_ccode_switch_statement_type_id__volatile, vala_ccode_switch_statement_type_id);
	}
	return vala_ccode_switch_statement_type_id__volatile;
}

